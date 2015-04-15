/* ========================================
 * 
 * AutoGreen - PSoC_Master
 * UART_Class.c
 * (Description)
 * PRJ3 - GRP9
 * 2015-04-15
 *
 * ========================================
*/

// Include files
#include "UART_Class.h"

// Private data members
uint8 receivedCommand;

// Private prototypes


void initUART(void){

}

int8 respondTemp(uint8 temp){
    temp = 0;
    return 0;
}

int8 respondHum(uint8 hum){
    hum = 0;
    return 0;
}

int8 respondLight(uint8 light){
    light = 0;
    return 0;
}

int8 respondSoilHum(uint8 index, uint8 soilHum){
    index = 0;
    soilHum = 0;
    return 0;
}

int8 respondHeat(int8 heatStatus, uint8 onOff){
    heatStatus = 0;
    onOff = 0;
    return 0;
}

int8 respondWin(int8 winStatus){
    winStatus = 0;
    return 0;
}

int8 respondVent(int8 ventStatus){
    ventStatus = 0;
    return 0;
}

int8 respondIrri(int8 irriStatus){
    irriStatus = 0;
    return 0;
}

uint8 dkRequest(void){
    return 0;
}


/* [] END OF FILE */
