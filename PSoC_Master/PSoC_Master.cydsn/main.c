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

//uncomment to test one of these functions on boot
//#define test_respondTemp
//#define test_respondHum
//#define test_respondLight
//#define test_respondSoilHum //Not done yet
//#define test_respondHeat
//#define test_respondWin
//#define test_respondVent
//#define test_respondIrri

int main(){
    // Init
    initDSP();
    initI2C();
    initPSoC_Master();
    initUART();

    CyGlobalIntEnable;      // Global interrupt enable
    
    //Clears screen and prints opening msg
    UART_UartPutChar(27);       // ESC command
    UART_UartPutString("[2J");    // clear screen command
    UART_UartPutChar(27);
    UART_UartPutString("[H");     // cursor to home command
    UART_UartPutString("System initialized..\n\r");
    
    #ifdef test_respondTemp
        {uint16 i;
        for (i = 0; i < 256; i++){
            char buf[10];
            sprintf(buf, "\n\r%d: ", i);
            UART_UartPutString(buf);
            respondTemp(i);
        }}
        CyDelay(100);
    #endif
    #ifdef test_respondHum
        {uint16 i;
        for (i = 0; i < 256; i++){
            char buf[10];
            sprintf(buf, "\n\r%d: ", i);
            UART_UartPutString(buf);
            respondHum(i);
        }}
        CyDelay(100);
    #endif
    #ifdef test_respondLight
        {uint16 i;
        for (i = 0; i < 256; i++){
            char buf[10];
            sprintf(buf, "\n\r%d: ", i);
            UART_UartPutString(buf);
            respondTemp(i);
        }}
        CyDelay(100);
    #endif
    #ifdef test_respondSoilHum //TODO: Make this testing routine
        {uint16 i;
        for (i = 0; i < 256; i++){
            char buf[10];
            sprintf(buf, "\n\r%d: ", i);
            UART_UartPutString(buf);
            respondSoilHum(5, i);
        }}
        CyDelay(100);
    #endif
    
    while(1);
    
    return 0;
}


/* [] END OF FILE */
