/* ========================================
 * 
 * AutoGreen - PSoC_Master
 * DSP_Class.c
 * Digital signal processing
 * PRJ3 - GRP9
 * 2015-04-15
 *
 * ========================================
*/

// Include files
#include "DSP_Class.h"

//----------PrivateDataMembers0----------
// Private data members
int32 tempArray[ARRAYSIZE];
int32* tempArrayPtr;
int32 humArray[ARRAYSIZE];
int32* humArrayPtr;
int16 soilHumArray[NBR_OF_SOILHUM_SENSORS][ARRAYSIZE];
int16* soilHumPtr[NBR_OF_SOILHUM_SENSORS];
int32 lightArray[ARRAYSIZE];
int32* lightArrayPtr;
uint8 temp, hum, soilHum[NBR_OF_SOILHUM_SENSORS], light;
//----------PrivateDataMembers1----------

// Private prototypes
void avgTemp(void);
void avgHum(void);
void avgSoilHum(uint8 index);
void avgLight(void);

// Init: All datamebers are initialized with -1, meaning they are empty
void initDSP(void){
    {
        uint8 i;
        for(i = 0 ; i<ARRAYSIZE ; i++){
            tempArray[i] = EMPTY;
            humArray[i] = EMPTY;
            {
                uint8 j;
                for(j = 0 ; j<NBR_OF_SOILHUM_SENSORS ; j++){
                    soilHumArray[j][i] = EMPTY;
                }
            }
            lightArray[i] = EMPTY;
            
        }
    }
    tempArrayPtr = & tempArray[0];
    humArrayPtr = & humArray[0];
    {
        uint8 k;
        for(k = 0 ; k<NBR_OF_SOILHUM_SENSORS ; k++){
            soilHumPtr[k] = & soilHumArray[k][0];
            soilHum[k] = 0; 
            }
    }
    lightArrayPtr = & lightArray[0];
    temp = 0;
    hum = 0;
    light = 0;
}

//----------getTemp_DSP0----------
uint8 getTemp_DSP(void){
    return temp;
}
//----------getTemp_DSP1----------

uint8 getHum_DSP(void){
    return hum;
}

uint8 getSoilHum_DSP(uint8 index){
    return soilHum[index];
}

uint8 getLight_DSP(void){
    return light;
}

//----------avgTemp0----------
void avgTemp(void){
    uint8 skip = 0;
    int64 total = 0;
    {
        uint8 i;
        for(i = 0 ; i<ARRAYSIZE ; i++){
            if(tempArray[i]>=0){
                total += tempArray[i];
            }
            else{
                skip++;
            }
        }
    }
    // Makes sure that enough datapoints are pressent
    if(ARRAYSIZE-skip>=NMR_OF_VALID_DATAPOINTS_NEEDED){    
        int32 avg = total/(ARRAYSIZE-skip);     // Calculate the average value
        
        // temp is limited to 1 and 200
        if (avg>200){
            temp = 200;
        }
        else if (avg < 1){
            temp = 1;
        }
        else{
            temp = (uint8)avg;
        }
    }
    else{
        temp = 0;
    }
}
//----------avgTemp1----------

void avgHum(void){
    uint8 skip = 0;
    int64 total = 0;
    {
        uint8 i;
        for(i = 0 ; i<ARRAYSIZE ; i++){
            if(humArray[i]>=0){
                total += humArray[i];
            }
            else{
                skip++;
            }
        }
    }
    // Makes sure that enough datapoits are pressent
    if(ARRAYSIZE-skip>=NMR_OF_VALID_DATAPOINTS_NEEDED){    
        float avg = total/(ARRAYSIZE-skip);                     // Calculate the average value
        float humInRH = (avg/(16380-2))*100;                // Conversion formula from datasheet
        
        // humInRH is limited to 1 and 100 RH
        if(humInRH <= 0){
            humInRH = 1;
        }
        else if(humInRH > 100){
            humInRH = 100;
        }
        else{
            hum = humInRH;
        }
    }
    else{
    hum = 0;
    }
}

void avgSoilHum(uint8 index){
    uint8 skip = 0;
    int64 total = 0;
    {
        uint8 i;
        for(i = 0 ; i<ARRAYSIZE ; i++){
            if(soilHumArray[index][i]>=0){
                total += soilHumArray[index][i];
            }
            else{
                skip++;
            }
        }
    }
    // Makes sure that enough datapoits are pressent
    if(ARRAYSIZE-skip>=NMR_OF_VALID_DATAPOINTS_NEEDED){    
        float avg = total/(ARRAYSIZE-skip);         // Calculate the average value (assuming input from sensor is in RH)
        float soilHumInRH = avg;                    // Takes care of conversion ( NB no conversion in this version)
        
        // soilHumInRH is limited to 1 and 100 RH
        if(soilHumInRH <= 0){
            soilHumInRH = 1;
        }
        else if(soilHumInRH > 100){
            soilHumInRH = 100;
        }
        soilHum[index] = (uint8)soilHumInRH/10;
    }
    else{
    soilHum[index] = 0;
    }
}

void avgLight(void){
    uint8 skip = 0;
    int64 total = 0;
    {
        uint8 i;
        for(i = 0 ; i<ARRAYSIZE ; i++){
            if(lightArray[i]>=0){
                total += lightArray[i];
            }
            else{
                skip++;
            }
        }
    }
    // Makes sure that enough datapoits are pressent
    if(ARRAYSIZE-skip>=NMR_OF_VALID_DATAPOINTS_NEEDED){    
        float avg = total/(ARRAYSIZE-skip);                              // Calculate the average value
        
        // Conversion to lux formula from datasheet
        // Range = 128000, R_EXT = 100kOhm, n = 7 and DATA max 128
        int32 lightInLux = ((128000*(100/100))/(128))*avg;
        
        uint8 lightInUartVarSteps = lightInLux/1000;     // Conversion to UART ready value, 1 = 1000 lux
        
        // lightInLux is limited to 1 and 100 RH
        if(lightInUartVarSteps <= 0){
            lightInUartVarSteps = 1;
        }
        else if(lightInUartVarSteps > 100){
            lightInUartVarSteps = 100;
        }
        light = lightInUartVarSteps;
    }
    else{
    light = 0;
    }
  }

//----------inputTemp0----------
void inputTemp(int32* temp){
    *tempArrayPtr = *temp;      // The input value is written to the array
    tempArrayPtr++;             // The pointer is moved to the next place in array
    if(tempArrayPtr > &tempArray[ARRAYSIZE-1]){
        tempArrayPtr = &tempArray[0];   // If the pointer is pointing past the end of the array it's reset
    }
    
    avgTemp();      // The average value is calculated and onverted into temp(globel) 
}
//----------inputTemp1----------

void inputHum(int32* hum){
    *humArrayPtr = *hum;        // The input value is written to the array
    humArrayPtr++;              // The pointer is moved to the next place in array
    if(humArrayPtr > &humArray[ARRAYSIZE-1]){
        humArrayPtr = &humArray[0];     // If the pointer is pointing past the end of the array it's reset
    }
    
    avgHum();      // The average value is calculated and onverted into hum(globel)
}


void inputSoilHum(uint8 index, int16* soilHum){
    *soilHumPtr[index] = *soilHum;          // The input value is written to the array
    soilHumPtr[index]++;                    // The pointer is moved to the next place in array
    if(soilHumPtr[index] > &soilHumArray[index][ARRAYSIZE-1]){
        soilHumPtr[index] = &soilHumArray[index][0];            // If the pointer is pointing past the end of the array it's reset
    }
    
    avgSoilHum(index);          // The average value is calculated and onverted into soilHum(globel)
}

void inputLight(int32* light){
    *lightArrayPtr = *light;        // The input value is written to the array
    lightArrayPtr++;                // The pointer is moved to the next place in array
    if(lightArrayPtr > &lightArray[ARRAYSIZE-1]){
        lightArrayPtr = &lightArray[0];     // If the pointer is pointing past the end of the array it's reset
    }
    
    avgLight();      // The average value is calculated and onverted into hum(globel)
}

/* [] END OF FILE */