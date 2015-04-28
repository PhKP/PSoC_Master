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
//#define TEMP_AND_HUM_SENSOR_ADDRESS 0x27             // TODO This is old
#define TEMP_SENSOR_ADDRESS 0x48                       // For LM75 temp sensor with A0 = 0, A1 = 0 and A3 = 0
#define ACTUATOR_ADRESS 0x42
#define LIGHT_SENSOR_COMMAND_ADDRESS 0x00
#define LIGHT_SENSOR_CONTROL_ADDRESS 0x01
#define LIGHT_SENSOR_LSB 0x04  
#define LIGHT_SENSOR_MSB 0x05

//Uncomment to enable debugging
//#define debugging 

// Private data members
static uint8 irrigationStatus = 0b11000000;
static int size = 1;

// Private prototypes

void initI2C(void){
    I2C_Start();                    // Starts I2C component
    I2C_I2CMasterClearStatus();     // Clear status flags
    CyGlobalIntEnable;
    
    // Light sensor init.
    /*sensor is set up to internal integration timing, light count data in signed and 2^(8) clock cycles.*/
    uint8 lightCommand[size], lightControl[size];
    lightCommand[0] = 0b10001010;       //ADC-normal, Normal operation, Internal timing, signed output, n = 8 (intern)
    lightControl[0] = 0b00001100;       // Lux-range = 128000. Calculation: ((range(k)?*(100k/100k))/2^8)*data
	uint8 result;
    // lux range is set to 128.000 lux if REXT is set up to 50K resistor.
    //uint8 lightControl = 0b00001100;
    
    result = I2C_I2CMasterWriteBuf(LIGHT_SENSOR_COMMAND_ADDRESS, lightCommand, size, I2C_I2C_MODE_COMPLETE_XFER);
    
    if (result == I2C_I2C_MSTR_NO_ERROR){
        result = I2C_I2CMasterWriteBuf(LIGHT_SENSOR_CONTROL_ADDRESS, lightControl, size, I2C_I2C_MODE_COMPLETE_XFER);
    }
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
    uint8 irriTransfer[size];
    uint8 temp = 0xFF;
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
 
    getActuatorStatus(NULL, NULL, NULL, &temp);
    
    if (result == I2C_I2C_MSTR_NO_ERROR){
        if(temp == irrigationStatus){
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
    uint8 result = 0;
    int RDbuf = 2;
    uint8 dataget[RDbuf];
    
    //I2C_I2CMasterClearStatus();     // Clear status flags TODO test
    
    while (0u == (I2C_I2CMasterStatus() & I2C_I2C_MSTAT_WR_CMPLT)); //Wait for the bus to be ready
    
    CyDelay(60);
    
    I2C_I2CMasterClearReadBuf();
    result = I2C_I2CMasterReadBuf(ACTUATOR_ADRESS, dataget, RDbuf, I2C_I2C_MODE_COMPLETE_XFER);
    
    while (0u == (I2C_I2CMasterStatus() & I2C_I2C_MSTAT_RD_CMPLT)); //Wait for the dataget array to be updated
    
    if ((result == I2C_I2C_MSTR_NO_ERROR) && (I2C_I2CMasterGetReadBufSize() != 0)){
        if (window){                                   // Expecting to receive MSB first 
            *window = (dataget[0] >> 4);      // Shifting out the 4 least significant bits.
            #ifdef debugging
                UART_UartPutChar(*window+48);
            #endif
        }
        if (heat){
            *heat = ((dataget[0] & 0b00001110) >> 1);       // Ignoring everything but bit 1-3 and shifting 1 right.
            #ifdef debugging
                UART_UartPutChar(*heat+48);
            #endif
        }
        if (vent){
            if ((dataget[0] & 0b00000001) == 0b00000001){        // Maybe we can find a smarter way to do this?
                *vent = (dataget[1] >> 6) | 0b00000100;          // The if statements checks if bit 1 of dataget[0] is 1 or not and then sends it onwards.
                #ifdef debugging
                    UART_UartPutChar(*vent+48);                         // Shifting 5 right so only 2 bits are left and adding bit 1 of dataget[0] in the 3rd bit.
                #endif
            }                                                    
            else {
                *vent = (dataget[1] >> 6) | 0b00000000;          // shifting 5 right since only the to most significant bits are relevant.
                #ifdef debugging
                    UART_UartPutChar(*vent+48);
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

/*
int8 getTempAndHum(int32* temp, int32* hum){
    int32 RDbuf = 4;
    uint8 dataget[RDbuf];
    uint8 result = 0;
    
    result = I2C_I2CMasterReadBuf(TEMP_AND_HUM_SENSOR_ADDRESS, dataget, RDbuf, I2C_I2C_MODE_COMPLETE_XFER);
    
    if (result == I2C_I2C_MSTR_NO_ERROR){
        // Expecting to receive MSB first.
        *hum = ((dataget[0] << 8) | dataget[1]);   
        *temp = (((dataget[2] << 8) | dataget[3]) >> 2);
        return 0;   // No error 
    }
    else {
        return -1;
    }
}
*/

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
        return -1;
    }

    // The data is converted directly to UART protocol because of the ,5 resolution
    *temp = (dataget[0]*2)+(dataget[1] >> 7)+40;

    return 0;
}

int8 getLight(int32* light){
    
    /* 
    Command register: Adress 0x00.
    Bit 7: resets '0' or enables '1' ADC.
    Bit 6: Power down mode. Normal operation '0' or power down mode '1'.
    Bit 5: Decides whether integration time (ADC is of integration type) is done internally '0' or externally. Page 6 in datasheet has formulas
    Bit 4: Has to be zero.
    Bit 3-2: Photodiode select 0:0 and 0:1 = disable ADC. 1:0 = Light count DATA output in signed (n-1)bit, n is decided in bit 1:0. Last mode 1:1 is no operation.
    Bit 1-0: Prescaler or number of clockcycles 2^(n). 0:0 = 2^(16), 0:1 = 2^(12), 1:0 = 2^(8) and 1:1 = 2^(4).
    
    RW Control register: Adress 0x01.
    Bit 3-2: Set lux range. watch table in page 6.
    All other bits has to be zero.
    
    I2C Sensor data reg: Adress 0x04(LSB) and 0x05()
    The sensor sends a 15 bit value that can be acceMSBssed by the adresses 0x04 and 0x05
    these registers are automatically refreshed each new integration period.
    */
    
    uint8 dataget[size];
    uint8 result = 0;
    
    I2C_I2CMasterClearReadBuf();
    result = I2C_I2CMasterReadBuf(LIGHT_SENSOR_MSB, dataget, size, I2C_I2C_MODE_COMPLETE_XFER); 
    while (0u == (I2C_I2CMasterStatus() & I2C_I2C_MSTAT_RD_CMPLT));
        
    if (result == I2C_I2C_MSTR_NO_ERROR){
        // Expecting to receive MSB first.
        *light = (dataget[0] << 7);     // TODO: TEST THIS WITH THE PROPER SENSOR!!
        result = I2C_I2CMasterReadBuf(LIGHT_SENSOR_LSB, dataget, size, I2C_I2C_MODE_COMPLETE_XFER);
        while (0u == (I2C_I2CMasterStatus() & I2C_I2C_MSTAT_RD_CMPLT)); //Wait for the data to be ready
        if (result == I2C_I2C_MSTR_NO_ERROR){
            *light |= dataget[0]; 
            return 0;   // No error 
        }
        else {
            return -1;
        }
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