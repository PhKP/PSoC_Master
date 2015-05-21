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
#define CONVERT_TO_ASCII 48
#define TEMP_SENSOR_ADDRESS 0x48            // For LM75 temp sensor with A0 = 0, A1 = 0 and A3 = 0
#define SOILHUM_SENSOR_ADDRESS 0x32
#define ACTUATOR_ADRESS 0x42
//#define debugging // Uncomment to enable debugging

// Private data members
uint8 irrigationStatus = 0;

// Private prototypes

// Buffers / flags
static int size = 1;

void initI2C(void){
    I2C_Start();                    // Starts I2C component
    I2C_I2CMasterClearStatus();     // Clear status flags
}

int8 adjustWindow(uint8 pos){
    uint8 openWindow[size], closeWindow[size];
    openWindow[0] = 0xF;
    closeWindow[0] = 0x0;
    uint8 result = 0;
    uint8 tempWindow = 0;
        
    if(pos == 0xFF){
        // Open window     -                write function  (adress,      dataToSend, NumberOfBytes, I2C_Mode)
        result = I2C_I2CMasterWriteBuf(ACTUATOR_ADRESS,openWindow,size,I2C_I2C_MODE_COMPLETE_XFER);
    }
    else if(pos == 0x0){
        // Close window
        result = I2C_I2CMasterWriteBuf(ACTUATOR_ADRESS,closeWindow,size,I2C_I2C_MODE_COMPLETE_XFER);  // This goes wrong, see if you can figure it out tomorrow??
    }
    while (0u == (I2C_I2CMasterStatus() & I2C_I2C_MSTAT_WR_CMPLT)); //Wait for the bus to be ready
    CyDelay(60);
    
    if ((result == I2C_I2C_MSTR_NO_ERROR) && (!getActuatorStatus(&tempWindow, NULL, NULL, NULL))){
        if (tempWindow == pos >> 4 ){  //hacky solution when dealing with fully open/closed window
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
    uint8 temp = 0xFF;
    
    I2C_I2CMasterClearStatus();
    
    if(heat == 0b111){
        // Turn on heat
        result = I2C_I2CMasterWriteBuf(ACTUATOR_ADRESS,turnHeatOn,size,I2C_I2C_MODE_COMPLETE_XFER);
    }
    else if(heat == 0b0){
        // Turn off heat
        result = I2C_I2CMasterWriteBuf(ACTUATOR_ADRESS,turnOffHeat,size,I2C_I2C_MODE_COMPLETE_XFER);
    }
    while (0u == (I2C_I2CMasterStatus() & I2C_I2C_MSTAT_WR_CMPLT)); //Wait for the bus to be ready
    CyDelay(60);

    if ((result == I2C_I2C_MSTR_NO_ERROR) && (!getActuatorStatus(NULL, &temp, NULL, NULL))){
        if (temp == heat){
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
    uint8 temp = 0xFF;
        
    if(speed == 0xFF){
        // Turn vent on
        result = I2C_I2CMasterWriteBuf(ACTUATOR_ADRESS,turnOnVent,size,I2C_I2C_MODE_COMPLETE_XFER);
    }
    else if(speed == 0b0){
        // Turn vent off
        result = I2C_I2CMasterWriteBuf(ACTUATOR_ADRESS,turnOffVent,size,I2C_I2C_MODE_COMPLETE_XFER);
    }
    while (0u == (I2C_I2CMasterStatus() & I2C_I2C_MSTAT_WR_CMPLT)); //Wait for the bus to be ready
    CyDelay(60);
    
    if ((result == I2C_I2C_MSTR_NO_ERROR) && (!getActuatorStatus(NULL, NULL, &temp, NULL))){
        if (temp == speed >> 5){ //Hacky solution when not dealing with more than 2 steps
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
    uint8 irriTransfer[1];
    uint8 result;
    
    //getActuatorStatus(NULL, NULL, NULL, &irrigationStatus);

        /* In order for this code to function properly, the static int "irrigation" 
        has to get updated each time this function is called. */
    if (onOff == 0xFF){    // Irrigation turn on
        irriTransfer[0] = (irrigationStatus |= (1 << index)) | 0b11000000;
    }
    else if (onOff == 0x00){   // Irrigation turn off
        irriTransfer[0] = (irrigationStatus &= ~(1 << index)) | 0b11000000;
    }
    else{
        return -1; // Bad argument.
    }
    
    result = I2C_I2CMasterWriteBuf(ACTUATOR_ADRESS, irriTransfer, 1, I2C_I2C_MODE_COMPLETE_XFER);
    while (0u == (I2C_I2CMasterStatus() & I2C_I2C_MSTAT_WR_CMPLT)); //Wait for the bus to be ready
    CyDelay(60);
    
    getActuatorStatus(NULL, NULL, NULL, irriTransfer);
    
    if (result == I2C_I2C_MSTR_NO_ERROR){
        if(irrigationStatus == irriTransfer[0]){
            return 0;
        }
    }
    return -1;
}

//----------getActuatorStatus0----------
int8 getActuatorStatus(uint8* window, uint8* heat, uint8* vent, uint8* irrigation){
    uint8 result = 0;
    uint8 dataget[2] = {0, 0};
    
    CyDelay(60);
    I2C_I2CMasterClearReadBuf();
    result = I2C_I2CMasterReadBuf(ACTUATOR_ADRESS, dataget, 2, I2C_I2C_MODE_COMPLETE_XFER);
    
    while (0u == (I2C_I2CMasterStatus() & I2C_I2C_MSTAT_RD_CMPLT)); //Wait for the dataget array to be updated
    
    if ((result == I2C_I2C_MSTR_NO_ERROR) && (I2C_I2CMasterGetReadBufSize() != 0)){
//----------getActuatorStatus1----------
        if (window){                                   // Expecting to receive MSB first                                
            *window = (dataget[0] >> 4);      // Shifting out the 4 least significant bits.
            #ifdef debugging
                UART_UartPutChar(*window+CONVERT_TO_ASCII);
            #endif
        }
        if (heat){
            *heat = ((dataget[0] & 0b00001110) >> 1);       // Ignoring everything but bit 1-3 and shifting 1 right.
            #ifdef debugging
                UART_UartPutChar(*heat+CONVERT_TO_ASCII);
            #endif
        }
        if (vent){
            if ((dataget[0] & 0b00000001) == 0b00000001){        // Maybe we can find a smarter way to do this?
                *vent = (dataget[1] >> 6) | 0b00000100;          // The if statements checks if bit 1 of dataget[0] is 1 or not and then sends it onwards.
                #ifdef debugging
                    UART_UartPutChar(*vent+CONVERT_TO_ASCII);                         // Shifting 5 right so only 2 bits are left and adding bit 1 of dataget[0] in the 3rd bit.
                #endif
            }                                                    
            else {
                *vent = (dataget[1] >> 6) | 0b00000000;          // shifting 5 right since only the to most significant bits are relevant.
                #ifdef debugging
                    UART_UartPutChar(*vent+CONVERT_TO_ASCII);
                #endif
            }
        }
        if (irrigation){
            *irrigation = (dataget[1] & 0b00111111);             // Ignoring two most significant bits.
            #ifdef debugging
                UART_UartPutChar(*irrigation);
            #endif
        }   
        return 0;
    }
    else {
        return -1;   
    }
}


//----------getTemp0----------
int8 getTemp(int32* temp){

    uint8 dataget[2] = {0,0};
    uint32 errorStatus[2] = {9,9};      // For debugging and error handling
    
    I2C_I2CMasterClearReadBuf();
    errorStatus[0] = I2C_I2CMasterSendStart(TEMP_SENSOR_ADDRESS, I2C_I2C_READ_XFER_MODE);
    if (errorStatus[0] == I2C_I2C_MSTR_NO_ERROR){
        dataget[0] = I2C_I2CMasterReadByte(I2C_I2C_ACK_DATA);
        dataget[1] = I2C_I2CMasterReadByte(I2C_I2C_NAK_DATA);
        errorStatus[1] = I2C_I2CMasterSendStop();
    }
    else{
        I2C_I2CMasterSendStop();
        *temp = -1;
        return -1;
    }

    // The data is converted directly to UART protocol because of the ,5 resolution
    *temp = (dataget[0]*2)+(dataget[1] >> 7)+40;

    return 0;
}
//----------getTemp1----------

int8 getSoilHum(uint8 index, int16* soilHum){
    uint32 result;
    uint8 soilTransfer[1] = {index};
    
    /*pseudo kode
    write, address, 0-5 (LSB)
    read, address, 7 = status, 0-6 = value (1-100)*/
    
    result = I2C_I2CMasterWriteBuf(SOILHUM_SENSOR_ADDRESS, soilTransfer, 1, I2C_I2C_MODE_COMPLETE_XFER);
    while (0u == (I2C_I2CMasterStatus() & I2C_I2C_MSTAT_WR_CMPLT));
        
    if (result == I2C_I2C_MSTR_NO_ERROR){
        CyDelay(60);
        result = I2C_I2CMasterReadBuf(SOILHUM_SENSOR_ADDRESS, soilTransfer, 1, I2C_I2C_MODE_COMPLETE_XFER);
        while (0u == (I2C_I2CMasterStatus() & I2C_I2C_MSTAT_RD_CMPLT)); //Wait for the data to be ready
        if (result == I2C_I2C_MSTR_NO_ERROR && (I2C_I2CMasterGetReadBufSize() != 0)){
            if ((soilTransfer[0] >> 7) == 0){
                *soilHum = soilTransfer[0];
                return 0;
            }
                        
        }
    }
    *soilHum = -1;
    return -1;
}

/* [] END OF FILE */