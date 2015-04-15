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

    for(;;)
    {

    }
    return 0;
}


/* [] END OF FILE */
