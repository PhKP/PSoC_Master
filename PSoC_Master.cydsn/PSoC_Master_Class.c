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
#define TIME_BETWEEN_TIMER_INT 2000 // Time between every interrupt in ms

// Private data members
int32 tempTemp;
int16 tempSoilHum[6];

// Private prototypes
CY_ISR_PROTO(timer_ISR);
CY_ISR_PROTO(UART_ISR);

//----------flags0----------
// Buffers / flags
typedef enum {IDLE, ADJW, ADJH, ADJV, ADJI, RESP_SOIL_HUM} state;
volatile state theState = IDLE;
volatile int8 irrigationIndex = 0;
uint8 buff;
uint8 uartInt = 0;
uint8 timerInt = 0;
//----------flags1----------

void initPSoC_Master(void){
	tempTemp = 0;
    tempSoilHum[0] = 0;
    tempSoilHum[1] = 0;
    tempSoilHum[2] = 0;
    tempSoilHum[3] = 0;
    tempSoilHum[4] = 0;
    tempSoilHum[5] = 0;
	
    // ISR
    UART_ISR_StartEx(UART_ISR);     // Starts UART interrupt component
    timer_ISR_StartEx(timer_ISR);   // Starts timer interrupt component
    
    UART_Start();                   //  Starts UART component
    Timer_Start();                  // Starts timer component
    
    // Setup of timer interrupt
    uint32 maxPeriod = 0xFFFFFFFF;  // The max period ((2^32)-1) = 179s
    uint32 period = TIME_BETWEEN_TIMER_INT * 24000;
    
    if (period > maxPeriod){
        period = maxPeriod;
    }
    
    Timer_WritePeriod(period);
    
    RedLED_Write(LED_OFF);              // Turn off red LED
    BlueLED_Write(LED_OFF);             // Turn off blue LED

}

// Timer ISR
CY_ISR(timer_ISR){
    timerInt = 1;
    RedLED_Write(LED_ON);   // Turn on red LED
    Timer_ReadStatusRegister(); // Resets the interrupt
}

//----------UART_ISR0----------
// UART ISR
CY_ISR(UART_ISR){
    uartInt = 1;
    BlueLED_Write(LED_ON);       // Turn on blue LED
    buff = dkRequest();
    UART_ClearRxInterruptSource(UART_GetRxInterruptSourceMasked());     // Clear interrupt flag
}
//----------UART_ISR1----------

//----------uartIntHandler0----------
void uartIntHandler(void){
    if (uartInt){
        uartInt = 0;
        
        if(theState == IDLE){
            switch (buff){
                case 'T':{ //RequestTemp
                    respondTemp(getTemp_DSP());		
                    break;
                }
//----------uartIntHandler1----------
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
                case 'S':{
                    theState = RESP_SOIL_HUM;
                    break;
                }
                default:{
                    // Do nothing - let the DevKit8000 timeout
                    break;
                }
            }
        }
//----------uartIntHandler2----------
        else if(theState == ADJW){
            if(buff-CONVERT_TO_ASCII == 1){
                respondWin(adjustWindow(0xFF));
            }
            else{
                respondWin(adjustWindow(0x00));
            }
            theState = IDLE;
        }
//----------uartIntHandler3----------
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
                irrigationIndex = buff - CONVERT_TO_ASCII;
            }
            else{
                if (buff-CONVERT_TO_ASCII == 1){
                    respondIrri(adjustIrrigation(irrigationIndex - 1, 0xFF));
                }
                else if(buff - CONVERT_TO_ASCII == 0){
                    respondIrri(adjustIrrigation(irrigationIndex - 1, 0x00));
                }
                else{
                    respondIrri(-1); //Bad argument
                }
                irrigationIndex = 0;
                theState = IDLE;
            }
        }
        else if(theState == RESP_SOIL_HUM){
            uint8 temp = buff - CONVERT_TO_ASCII - 1; //incoming number is in ASCII 1-6, DSP works in 0-5.
            if (temp <= 5 && temp >= 0){
                respondSoilHum(temp, getSoilHum_DSP(temp));
                theState = IDLE;
            }
        }
        buff = 0;
        BlueLED_Write(LED_OFF);         // Turn off blue LED
    }
}


//----------timerIntHandler0----------
void timerIntHandler(void){
    if(timerInt){
        timerInt = 0;           // Reset flag
        
        // Measure temp and input to DSP class 
        getTemp(&tempTemp);
        inputTemp(&tempTemp);
        
        // Measure soilhum and input to DSP class 
        {
            uint8 i;
            for(i = 0; i<6 ; i++){
                getSoilHum(i, &tempSoilHum[i]);
                inputSoilHum(i, &tempSoilHum[i]);
            }
        }
        
        RedLED_Write(LED_OFF);                      // Turn off red LED    
    }    
}
//----------timerIntHandler1----------
/* [] END OF FILE */