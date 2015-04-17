/* ========================================
 * 
 * AutoGreen - PSoC_Master
 * main.c
 * (Description)
 * PRJ3 - GRP9
 * 2015-04-15
 *
 * ========================================
*/

// Include files
#include <project.h>
#include "DSP_Class.h"
#include "I2C_Class.h"
#include "PSoC_Master_Class.h"
#include "UART_Class.h"

// Uncomment to test one of these functions on boot
//#define test_initDSP          // Test of initDSP()
//#define test_inputTemp        // Test of inputTemp() and avgTemp()
//#define test_inputHum         // Test of inputHum () and avgHum()
//#define test_inputLight       // Test of inputLight() and avgLight()
//#define test_inputSoilHum     // Test of inputSoilHum() and avgSoilHum()


int main(){
    
    // Init
    initDSP();
    initI2C();
    initPSoC_Master();
    initUART();

    CyGlobalIntEnable;      // Global interrupt enable
    
    // Initialize UART
    UART_Start();
    
    // Clears screen and prints opening msg
    UART_UartPutChar(27);           // ESC command
    UART_UartPutString("[2J");      // clear screen command
    UART_UartPutChar(27);
    UART_UartPutString("[H");       // cursor to home command
    UART_UartPutString("System initialized..\n\r");
    
    #ifdef test_initDSP
        char string[25];
        
        initUART();
        
        uint8 temp = getTemp_DSP();
        sprintf(string,"temp = %d\n\r",temp);
        UART_UartPutString(string);
        uint8 hum = getHum_DSP();
        sprintf(string,"hum = %d\n\r",hum);
        UART_UartPutString(string);
        uint8 light = getLight_DSP();
        sprintf(string,"light = %d\n\r",light);
        UART_UartPutString(string);
        
        uint8 i;
        for(i = 0 ; i < NBR_OF_SOILHUM_SENSORS ; i++)
        {
            uint8 soilHum = getSoilHum_DSP(i);
            sprintf(string,"soilHum( %d ) = %d\n\r",i,soilHum);
            UART_UartPutString(string);
        }
    #endif
        
    #ifdef test_inputTemp
        char string[25];
        int32 testVar = 3030;   // Inputs: 0 - 16383
        uint32 i;
        for(i = 0 ; i<ARRAYSIZE ; i++){
            inputTemp(&testVar);
            
            sprintf(string,"inputTemp( %ld )\n\r",testVar);
            UART_UartPutString(string);
        }
        uint8 temp = getTemp_DSP();
        sprintf(string,"getTemp_DSP() = %d\n\r",temp);
        UART_UartPutString(string);
    #endif

    #ifdef test_inputHum
        char string[25];
        int32 testVar = 3030;   // Inputs: 0 - 16383
        uint32 i;
        for(i = 0 ; i<ARRAYSIZE ; i++){
            inputHum(&testVar);
            
            sprintf(string,"inputHum( %ld )\n\r",testVar);
            UART_UartPutString(string);
        }
        uint8 hum = getHum_DSP();
        sprintf(string,"getHum_DSP() = %d\n\r",hum);
        UART_UartPutString(string);
    #endif
    
    #ifdef test_inputLight
        char string[25];
        int32 testVar = 2;   // Inputs: 0 - 127
        uint32 i;
        for(i = 0 ; i<ARRAYSIZE ; i++){
            inputLight(&testVar);
            
            sprintf(string,"inputLight( %ld )\n\r",testVar);
            UART_UartPutString(string);
        }
        uint8 light = getLight_DSP();
        sprintf(string,"getLight_DSP() = %d\n\r",light);
        UART_UartPutString(string);
    #endif
        
    #ifdef test_inputSoilHum
        char string[25];
        int16 testVar = 0;   // Inputs: 0 - 100 ( This is not decided yet but this will work)
        uint32 i, j;
        for(i = 0 ; i<ARRAYSIZE ; i++){
            for(j = 0 ; j < NBR_OF_SOILHUM_SENSORS ; j++){
                inputSoilHum(j ,&testVar);
                sprintf(string,"inputSoilHum( %lu , %hd )\n\r",j,testVar);
                UART_UartPutString(string);
            }
        }
        for(j = 0 ; j < NBR_OF_SOILHUM_SENSORS ; j++){
            uint8 SoilHum = getSoilHum_DSP(j);
            sprintf(string,"getSoilHum_DSP(%lu) = %d\n\r",j,SoilHum);
            UART_UartPutString(string);
        }
    #endif
    
    for(;;)
    {

    }
    return 0;
}


/* [] END OF FILE */