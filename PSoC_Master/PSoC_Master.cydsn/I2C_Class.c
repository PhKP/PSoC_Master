/* ========================================
 * 
 * AutoGreen - PSoC_Master
 * I2C_Class.c
 * (Description)
 * PRJ3 - GRP9
 * 2015-04-15
 *
 * ========================================
*/

// Include files
#include "I2C_Class.h"

//Debugging
#define BUF_SIZE 60
static const uint8 returnVal = 1;

// Private data members
uint8 irrigationStatus;

// Private prototypes

void initI2C(void){

}

int8 adjustWindow(uint8 pos){
    pos = 0;
    return 0;
}

int8 adjustHeat(uint8 heat){
    char buf[BUF_SIZE];
    sprintf(buf, "adjustHeat() called, adj heat to %d, ret: %d\n\r", heat, returnVal);
    UART_UartPutString(buf);
    return returnVal;
}

int8 adjustVentilation(uint8 speed){
    char buf[BUF_SIZE];
    sprintf(buf, "adjustVentilation() called, adj vent to %d, ret: %d\n\r", speed, returnVal);
    UART_UartPutString(buf);
    return returnVal;
}

int8 adjustIrrigation(uint8 index, uint8 onOff){
    char buf[BUF_SIZE];
    sprintf(buf, "adjustIrrigation() called, adj index %d to %d, ret: %d\n\r", index, onOff, returnVal);
    UART_UartPutString(buf);
    return returnVal;
}

int8 getActuatorStatus(uint8* window, uint8* heat, uint8* vent, uint8* irrigation){
    char buf[BUF_SIZE];
    sprintf(buf, "getActuatorStatus() called, setting all to ret: %d\n\r", returnVal);
    UART_UartPutString(buf);
    
    *window = returnVal;
    *heat = returnVal;
    *vent = returnVal;
    *irrigation = returnVal;
    return returnVal;
}

int8 getTempAndHum(int32* temp, int32* hum){
    char buf[BUF_SIZE];
    sprintf(buf, "getTempAndHum() called, setting all to ret: %d\n\r", returnVal);
    UART_UartPutString(buf);
    
    *temp = returnVal;
    *hum = returnVal;
    return returnVal;
}

int8 getLight(int32* light){
    *light = 0;
    return 0;
}

int8 getSoilHum(uint8 index, int16* soilHum){
    index = 0;
    *soilHum = 0;
    return 0;
}



/* [] END OF FILE */
