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

// Private data members
int32 tempArray[ARRAYSIZE];
int32* tempArrayPtr;
int32 humArray[ARRAYSIZE];
int32* humArrayPtr;
int16 soilHumArray[6][ARRAYSIZE];
int16* soilHumPtr[6];
int32 lightArray[ARRAYSIZE];
int32* lightArrayPtr;
uint8 temp, hum, soilHum[6], light;

// Private prototypes
void avgTemp(void);
void avgHum(void);
void avgSoilHum(uint8 index);
void avgLight(void);

void initDSP(void){

}

uint8 getTemp_DSP(void){
return 0;
}

uint8 getHum_DSP(void){
return 0;
}

uint8 getSoilHum_DSP(uint8 index){
    index = 0;
    return 0;
}

uint8 getLight_DSP(void){
return 0;
}

void avgTemp(void){

}

void avgHum(void){

}

void avgSoilHum(uint8 index){
    index = 0;
}

void avgLight(void){

}

void inputTemp(int32* temp){
    *temp = 0;
}

void inputHum(int32* hum){
    *hum = 0;
}

void inputSoilHum(uint8 index, int16* soilHum){
    index = 0;
    *soilHum = 0;
}

void inputLight(int32* light){
    *light = 0;
}


/* [] END OF FILE */