/* ========================================
 * 
 * AutoGreen - PSoC_Master
 * PSoC_Master_Class.c
 * (Description)
 * PRJ3 - GRP9
 * 2015-04-15
 *
 * ========================================
*/

// Include files
#include "PSoC_Master_Class.h"
#include "DSP_Class.h"
#include "I2C_Class.h"
#include "UART_Class.h"

//Definitions
#define CONVERT_TO_ASCII 48
#define LED_ON 0
#define LED_OFF 1

// Private data members
int32 tempTemp;
int32 tempHum;
int16 tempSoilHum[6];
int32 tempLight;
uint8 newByte = 0;
uint8 buff;


// Private prototypes
CY_ISR_PROTO(timer_ISR);
CY_ISR_PROTO(UART_ISR);

// Buffers / flags
typedef enum {IDLE, ADJW, ADJH, ADJV, ADJI} state;
volatile state theState = IDLE;
volatile int8 irrigationIndex = 0;
uint8 blueLEDState, redLEDState;

void initPSoC_Master(void){
	tempTemp = 0;
    tempHum = 0;
    tempSoilHum[0] = 0;
    tempSoilHum[1] = 0;
    tempSoilHum[2] = 0;
    tempSoilHum[3] = 0;
    tempSoilHum[4] = 0;
    tempSoilHum[5] = 0;
    tempLight = 0;
	
    // ISR
    UART_ISR_StartEx(UART_ISR);     // Starts UART interrupt component
    timer_ISR_StartEx(timer_ISR);   // Starts timer interrupt component
    
    UART_Start();                   //  Starts UART component
    Timer_Start();                  // Starts timer component
    
    RedLED_Write(LED_OFF);              // Turn off red LED
    BlueLED_Write(LED_OFF);             // Turn off blue LED
    blueLEDState = LED_OFF;
    redLEDState = LED_OFF;
}

// Timer ISR
CY_ISR(timer_ISR){
    RedLED_Write(LED_ON);           // Turn on red LED
    
    getTempAndHum(&tempTemp, &tempHum);
    inputTemp(&tempTemp);
    inputHum(&tempHum);
    {
        uint8 i;
        for(i = 0; i<6 ; i++){
            getSoilHum(i, &tempSoilHum[i]);
            inputSoilHum(i,&tempSoilHum[i]);
        }
    }
    getLight(&tempLight);
    inputLight(&tempLight);
    
    RedLED_Write(LED_OFF);              // Turn off red LED
    Timer_ClearInterrupt(Timer_INTR_MASK_TC);   // Clear interrupt
}

// UART ISR
CY_ISR(UART_ISR){
    newByte = 1;
    buff = dkRequest();
    UART_ClearRxInterruptSource(UART_GetRxInterruptSourceMasked());     // Clear interrupt flag
}

void intHandler(){
    if (newByte){
        newByte = 0;
        BlueLED_Write(LED_ON);       // Turn on blue LED
        
        if(theState == IDLE){
            switch (buff){
                case 'T':{ //RequestTemp
                    respondTemp(getTemp_DSP());		
                    break;
                }
                case 'L':{ //RequestLight
                    respondLight(getLight_DSP());
                    break;
                }
                case 'A':{ //RequestAirhum
                    respondHum(getHum_DSP());
                    break;
                }        
                case 'H':{ //TurnHeatOn
                    // 0x7 is the maximum value.
                    respondHeat(adjustHeat(0x7), 'H');
                    break;
                }
                case 'K':{ //TurnHeatOff
                    // 0x0 is the minimum value.
                    respondHeat(adjustHeat(0x0), 'K');
                    break;
                }
                case 'W':{ //AdjustWindow
                    theState = ADJW;
                    break;
                }
                case 'V':{ //Ventilation
                    theState = ADJV;
                    break;
                }
                case 'F':{ //Watering
                    theState = ADJI;
                    break;
                }
                /*case 'S':{ //
                    respondSoilHum(); //TODO: Add stuff here
                    break;
                }*/
                default:{
                    // Do nothing - let the DevKit8000 timeout
                    break;
                }
            }
        }
        else if(theState == ADJW){
            if(buff-CONVERT_TO_ASCII == 1){
                respondWin(adjustWindow(0xFF));
            }
            else{
                respondWin(adjustWindow(0x00));
            }
            theState = IDLE;
        }
        else if(theState == ADJV){
            if(buff-CONVERT_TO_ASCII == 1){
                respondVent(adjustVentilation(0xFF));
            }
            else{
                respondVent(adjustVentilation(0x00));
            }
            theState = IDLE;
        }
        else if(theState == ADJI){
            if (!irrigationIndex){
                irrigationIndex = buff;
            }
            else{
                if (buff-CONVERT_TO_ASCII == 1){
                    respondIrri(adjustIrrigation(irrigationIndex-CONVERT_TO_ASCII-1, 0xFF));
                }
                else{
                    respondIrri(adjustIrrigation(irrigationIndex-CONVERT_TO_ASCII-1, 0x00));
                }
                irrigationIndex = 0;
                theState = IDLE;
            }
        }
        buff = 0;
        BlueLED_Write(LED_OFF);         // Turn off blue LED
    }
}


/* [] END OF FILE */