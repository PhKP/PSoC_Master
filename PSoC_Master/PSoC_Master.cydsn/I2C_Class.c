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
    heat = 0;
    return 0;
}

int8 adjustVentilation(uint8 speed){
    speed = 0;
    return 0;
}

int8 adjustIrrigation(uint8 index, uint8 onOff){
    index = 0;
    onOff = 0;
    return 0;
}

int8 getActuatorStatus(uint8* window, uint8* heat, uint8* vent, uint8* irrigation){
    *window = 0;
    *heat = 0;
    *vent = 0;
    *irrigation = 0;
    return 0;
}

int8 getTempAndHum(int32* temp, int32* hum){
    *temp = 0;
    *hum = 0;
    return 0;
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
