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

// Definitions
#define TEMP_AND_HUM_SENSOR_ADDRESS 0x27
#define ACTUATOR_ADRESS 0x42
#define LIGHT_SENSOR_COMMAND_ADDRESS 0x00
#define LIGHT_SENSOR_CONTROL_ADDRESS 0x01
#define LIGHT_SENSOR_ADDRESS_LSB 0x04  
#define LIGHT_SENSOR_ADDRESS_MSB 0x05

// Private data members
static uint8 irrigationStatus = 0b11000000;
static int size = 1;

// Private prototypes

void initI2C(void){
    I2C_Start();                    // Starts I2C component
    I2C_I2CMasterClearStatus();     // Clear status flags
    CyGlobalIntEnable;
}

int8 adjustWindow(uint8 pos){
    uint8 openWindow[size], closeWindow[size];
    openWindow[0] = 0xF;
    closeWindow[0] = 0x0;
    uint8 result = 0;
    uint8 *tempWindow = 0;
        
    if(pos == 0xF){
        // Open window     -                write function  (adress,      dataToSend, NumberOfBytes, I2C_Mode)
        result = I2C_I2CMasterWriteBuf(ACTUATOR_ADRESS,openWindow,size,I2C_I2C_MODE_COMPLETE_XFER);
    }
    else if(pos == 0x0){
        // Close window
        result = I2C_I2CMasterWriteBuf(ACTUATOR_ADRESS,closeWindow,size,I2C_I2C_MODE_COMPLETE_XFER);  // This goes wrong, see if you can figure it out tomorrow??
    }
    
    getActuatorStatus(tempWindow, NULL, NULL, NULL);
    
    if (result == 0){
        if (*tempWindow == pos){ 
            return 0;	
        }
        else {
            return -1;
        }
    }
    else {
        return -1;
    }
}

int8 adjustHeat(uint8 heat){
    uint8 turnHeatOn[size], turnOffHeat[size];
    turnHeatOn[0] = 0b01000111;
    turnOffHeat[0] = 0b01000000;
    uint8 result = 0;
    uint8 temp;
    uint8 *tempHeat = &temp;
    
    
    if(heat == 0b111){
        // Turn on heat
        result = I2C_I2CMasterWriteBuf(ACTUATOR_ADRESS,turnHeatOn,size,I2C_I2C_MODE_COMPLETE_XFER);
    }
    else if(heat == 0b0){
        // Turn off heat
        result = I2C_I2CMasterWriteBuf(ACTUATOR_ADRESS,turnOffHeat,size,I2C_I2C_MODE_COMPLETE_XFER);
    }
    
    getActuatorStatus(NULL, tempHeat, NULL, NULL);
    
    if (result == I2C_I2C_MSTR_NO_ERROR){
        if (*tempHeat == heat){
            return 0;
        }
        else {
            return -1;   
        }
    }
    else {
        return -1;
    }
}

int8 adjustVentilation(uint8 speed){
    uint8 turnOnVent[size], turnOffVent[size];
    turnOnVent[0] = 0b10000111;
    turnOffVent[0] = 0b10000000;
    uint8 result = 0;
    uint8 temp;
    uint8 *vent = &temp;
        
    if(speed == 0b111){
        // Turn vent on
        result = I2C_I2CMasterWriteBuf(ACTUATOR_ADRESS,turnOnVent,size,I2C_I2C_MODE_COMPLETE_XFER);
    }
    else if(speed == 0b0){
        // Turn vent off
        result = I2C_I2CMasterWriteBuf(ACTUATOR_ADRESS,turnOffVent,size,I2C_I2C_MODE_COMPLETE_XFER);
    }
    
    getActuatorStatus(NULL, NULL, vent, NULL);
    
    if (result == I2C_I2C_MSTR_NO_ERROR){
        if (*vent == speed){
            return 0;
            }
        else {
            return -1;       
        }
    }
    else {
        return -1;
    }
}

int8 adjustIrrigation(uint8 index, uint8 onOff){
    uint8 irriTransfer[size];
    uint8 temp;
    uint8 *irrigation = &temp;
    uint8 result = 0;

        /* In order for this code to function properly, the static int "irrigation" 
        has to get updated each time this function is called. */
    if (onOff == 1){    // Irrigation turn on
        irriTransfer[0] = (irrigationStatus |= (1 << index));
        irrigationStatus = irriTransfer[0];
    }
    else if (onOff == 0){   // Irrigation turn off
        irriTransfer[0] = (irrigationStatus &= ~(1 << index));
        irrigationStatus = irriTransfer[0];
    }
    else{
    // Bad argument.
    return -1;
    }
    
    result = I2C_I2CMasterWriteBuf(ACTUATOR_ADRESS, irriTransfer,size,I2C_I2C_MODE_COMPLETE_XFER);
 
    getActuatorStatus(NULL, NULL, NULL, irrigation);
    
    if (result == I2C_I2C_MSTR_NO_ERROR){
        if(*irrigation == irrigationStatus){
            return 0;
        }
        else {
            return -1;
        }
    }
    else {
        return -1;
    }
}

int8 getActuatorStatus(uint8* window, uint8* heat, uint8* vent, uint8* irrigation){
    uint8 dataget[2];
    uint8 result = 0;
    
    CyDelay(10); // This is only for test purposes
    
    result = I2C_I2CMasterReadBuf(ACTUATOR_ADRESS, dataget, 2, I2C_I2C_MODE_COMPLETE_XFER);
    
    if (result == I2C_I2C_MSTR_NO_ERROR){
        if (window)
        {                                   // Expecting to receive MSB first 
            *window = (dataget[0] >> 3);      // Shifting out the 3 least significant bits.
        }
        if (heat){              
            *heat = ((dataget[0] & 0b00001110) >> 1);       // Ignoring everything but bit 1-3 and shifting 1 right.
        }
        if (vent){
            if ((dataget[0] & 0b00000001) == 0b00000001){   // Maybe we can find a smarter way to do this?
                *vent = (dataget[1] >> 5) | 0b00000100;                                           // The if statements checks if bit 1 of dataget[0] is 1 or not and then sends it onwards.
            }                                                    // Shifting 5 right so only 2 bits are left and adding bit 1 of dataget[0] in the 3rd bit.
            else {
                *vent = (dataget[1] >> 5) | 0b00000000;         // shifting 5 right since only the to most significant bits are relevant.
            }
        }
        if (irrigation){
            *irrigation = (dataget[1] & 0b00111111);        // Ignoring two most significant bits.
        }   
        return 0;
    }
    else {
        return -1;   
    }
}

int8 getTempAndHum(int32* temp, int32* hum){
    uint8 dataget[4];
    uint8 result = 0;
    
    result = I2C_I2CMasterReadBuf(TEMP_AND_HUM_SENSOR_ADDRESS, dataget, 4, I2C_I2C_MODE_COMPLETE_XFER);
    
    if (result == I2C_I2C_MSTR_NO_ERROR){
        // Expecting to receive MSB first.
        *temp = ((dataget[0] << 7) | dataget[1]);   
        *hum = ((dataget[2] << 7) | dataget[3]);
        return 0;   // No error 
    }
    else {
        return -1;
    }
}

int8 getLight(int32* light){
    uint8 dataget[2];
    uint8 result = 0;
    
    result = I2C_I2CMasterReadBuf(LIGHT_SENSOR_ADDRESS_MSB, (uint8*) dataget, 2, I2C_I2C_MODE_COMPLETE_XFER); 
        
    if (result == I2C_I2C_MSTR_NO_ERROR){
        // Expecting to receive MSB first.
        *light = (dataget[0] << 7);     // TODO: TEST THIS WITH THE PROPER SENSOR!!
        *light = *light | dataget[1];  
        return 0;   // No error 
	}
    else {
        return -1;
    }
}

int8 getSoilHum(uint8 index, int16* soilHum){   // TODO: THIS HAS NOT BEEN IMPLEMENTED.
    index = 0;
    *soilHum = 0;
    return 0;
}



/* [] END OF FILE */