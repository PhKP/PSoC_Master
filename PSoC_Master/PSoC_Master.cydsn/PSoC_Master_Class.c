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
#define actuator_err 0
#define CONVERT_TO_ASCII 48

// Private data members
int32 tempTemp;
int32 tempHum;
int16 tempSoilHum[6];
int32 tempLight;

// Private prototypes
typedef enum {IDLE, ADJW, ADJH, ADJV, ADJI} state;
volatile state theState = IDLE;
CY_ISR_PROTO(UART_ISR);


//Global variables
volatile int8 irrigationIndex = 0;
int32 tempTemp = 0;
int32 tempHum = 0;
int16 tempSoilHum[6] = {0};
int32 tempLight = 0;

void initPSoC_Master(void){
    UART_ISR_StartEx(UART_ISR);
}

// UART ISR
CY_ISR(UART_ISR){
    uint8 buff;
    buff = dkRequest();
    
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
        respondWin(adjustWindow(buff-CONVERT_TO_ASCII));
        theState = IDLE;
    }
    else if(theState == ADJV){
        respondVent(adjustVentilation(buff-CONVERT_TO_ASCII));
        theState = IDLE;
    }
    else if(theState == ADJI){
        if (!irrigationIndex){
            irrigationIndex = buff;
        }
        else{
            respondIrri(adjustIrrigation(irrigationIndex-CONVERT_TO_ASCII-1, buff-CONVERT_TO_ASCII-1));
            irrigationIndex = 0;
            theState = IDLE;
        }
    }
    
    UART_ClearRxInterruptSource(UART_GetRxInterruptSourceMasked());     // Clear interrupt flag
}


/* [] END OF FILE */
