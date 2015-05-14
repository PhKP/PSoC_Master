/* ========================================
 * 
 * AutoGreen - PSoC_Master
 * I2C_Class.h
 * (Description)
 * PRJ3 - GRP9
 * 2015-04-15
 *
 * ========================================
*/
#ifndef I2C_Class_H
#define I2C_Class_H

// Include files
#include <project.h>
#include <stdio.h>

// Public data members

// Public prototypes
void initI2C(void);
int8 adjustWindow(uint8 pos);
int8 adjustHeat(uint8 heat);
int8 adjustVentilation(uint8 speed);
int8 adjustIrrigation(uint8 index, uint8 onOff);
int8 getActuatorStatus(uint8* window, uint8* heat, uint8* vent, uint8* irrigation);
int8 getTemp(int32* temp);
int8 getSoilHum(uint8 index, int16* soilHum);


#endif /* I2C_Class_H */
/* [] END OF FILE */
