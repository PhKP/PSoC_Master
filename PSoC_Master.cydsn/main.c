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

//----------main0----------
int main(){
    // Init
    initDSP();
    initI2C();
    initPSoC_Master();
    initUART();
    CyGlobalIntEnable;      // Global interrupt enable

    for(;;){
        uartIntHandler();   // Check if UART flag has been set
        timerIntHandler();  // Check if Timer flag has been set
    }
    return 0;
}
//----------main1----------


/* [] END OF FILE */
