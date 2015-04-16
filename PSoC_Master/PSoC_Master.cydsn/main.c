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
    
    while(1);
    
    return 0;
}


/* [] END OF FILE */
