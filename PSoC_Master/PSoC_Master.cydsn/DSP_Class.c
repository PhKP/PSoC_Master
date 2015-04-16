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
#include <stdio.h>
#include "DSP_Class.h"

//Debug definitions!
#define BUF_SIZE 50
static const uint8 returnVal = 1;

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
    char buf[BUF_SIZE];
    sprintf(buf, "getTemp_DSP() called, returns %d\n\r", returnVal);
    UART_UartPutString(buf);
    return returnVal;
}

uint8 getHum_DSP(void){
    char buf[BUF_SIZE];
    sprintf(buf, "getHum_DSP() called, returns %d\n\r", returnVal);
    UART_UartPutString(buf);
    return returnVal;
}

uint8 getSoilHum_DSP(uint8 index){
    char buf[BUF_SIZE];
    sprintf(buf, "getSoilHum_DSP() called, index = %d, returns %d\n\r", index, returnVal);
    UART_UartPutString(buf);
    return returnVal;
}

uint8 getLight_DSP(void){
    char buf[BUF_SIZE];
    sprintf(buf, "getLight_DSP() called, returns %d\n\r", returnVal);
    UART_UartPutString(buf);
    return returnVal;
}

void avgTemp(void){
    UART_UartPutString("avgTemp called\n\r");
}

void avgHum(void){
    UART_UartPutString("avgHum called\n\r");
}

void avgSoilHum(uint8 index){
    char buf[BUF_SIZE];
    sprintf(buf, "avgSoilHum() called, index =  %d\n\r", index);
    UART_UartPutString(buf);
}

void avgLight(void){
    UART_UartPutString("avgLight called\n\r");
}

void inputTemp(int32* temp){
    *temp = returnVal;
    char buf[BUF_SIZE];
    sprintf(buf, "inputTemp() called, returns %d via temp\n\r", (uint8)*temp);
    UART_UartPutString(buf);
}

void inputHum(int32* hum){
    *hum = returnVal;
    char buf[BUF_SIZE];
    sprintf(buf, "inputHum() called, returns %d via hum\n\r", (uint8)*hum);
    UART_UartPutString(buf);
}

void inputSoilHum(uint8 index, int16* soilHum){
    *soilHum = returnVal;
    char buf[BUF_SIZE];
    sprintf(buf, "inputSoilHum() called, index %d, returns %d via soilHum\n\r", index, (uint8)*soilHum);
    UART_UartPutString(buf);
}

void inputLight(int32* light){
    *light = returnVal;
    char buf[BUF_SIZE];
    sprintf(buf, "inputHum() called, returns %d via light\n\r", (uint8)*light);
    UART_UartPutString(buf);
}


/* [] END OF FILE */