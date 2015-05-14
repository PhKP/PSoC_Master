/* ========================================
 * 
 * AutoGreen - PSoC_Master
 * UART_Class.h
 * (Description)
 * PRJ3 - GRP9
 * 2015-04-15
 *
 * ========================================
*/
#ifndef UART_Class_H
#define UART_Class_H

// Include files
#include <project.h>

// Public data members

// Public prototypes
void initUART(void);
int8 respondTemp(uint8 temp);
int8 respondSoilHum(uint8 index, uint8 soilHum);
int8 respondHeat(int8 heatStatus, uint8 onOff);
int8 respondWin(int8 winStatus);
int8 respondVent(int8 ventStatus);
int8 respondIrri(int8 irriStatus);
uint8 dkRequest(void);

#endif /* UART_Class_H */
/* [] END OF FILE */
