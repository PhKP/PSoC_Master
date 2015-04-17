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

    adjustWindow(0xF);
    CyDelay(5000);
    adjustWindow(0x0);
    CyDelay(5000);
    adjustIrrigation(0x2,1);
    for(;;);
    
    return 0;
}


/* [] END OF FILE */
