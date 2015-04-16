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

// Private data members
int32 tempTemp;
int32 tempHum;
int16 tempSoilHum[6];
int32 tempLight;

// Private prototypes
CY_ISR_PROTO(timer_ISR);
CY_ISR_PROTO(UART_ISR);

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
    
    
    RedLED_Write(!0);               // Turn off red LED
}

// Timer ISR
CY_ISR(timer_ISR)
{
    RedLED_Write(!1);       // Turn on red LED
    
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
    
    RedLED_Write(!0);       // Turn off red LED
    Timer_ClearInterrupt(Timer_INTR_MASK_TC);   // Clear interrupt
}


// UART ISR
CY_ISR(UART_ISR)
{
    // TODO turn blue led on and off....?
    // TODO insert Kristian T's code here
    UART_ClearRxInterruptSource(UART_GetRxInterruptSourceMasked());     // Clear interrupt flag
}

/* [] END OF FILE */
