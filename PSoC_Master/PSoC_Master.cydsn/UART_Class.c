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

// Init
void initUART(void){
    UART_Start();                   // Starts UART component
}

int8 respondTemp(uint8 temp){
    if(temp){
        // If temp is between 1 and 200(both inclusive) "T" and temp is sent to DevKit8000
        UART_UartPutChar('T');
        UART_UartPutChar(temp);
        return 0;
    }
    else{
        // If temp isn't between 1 and 200(both inclusive) "XT" is sent to DevKit8000
        UART_UartPutChar('X');
        UART_UartPutChar('T');
        return -1;
    }
}

int8 respondHum(uint8 hum){
    if(hum){
        // If hum is between 1 and 100(both inclusive) "A" and hum is sent to DevKit8000
        UART_UartPutChar('A');
        UART_UartPutChar(hum);
        return 0;
    }
    else{
        // If temp isn't between 1 and 100(both inclusive) "XA" is sent to DevKit8000
        UART_UartPutChar('X');
        UART_UartPutChar('A');
        return -1;
    }
}

int8 respondLight(uint8 light){
    if(light){
        // If light is between 1 and 100(both inclusive) "L" and light is sent to DevKit8000
        UART_UartPutChar('L');
        UART_UartPutChar(light);
        return 0;
    }
    else{
        // If light isn't between 1 and 100(both inclusive) "XL" is sent to DevKit8000
        UART_UartPutChar('X');
        UART_UartPutChar('L');
        return -1;
    }
}

int8 respondSoilHum(uint8 index, uint8 soilHum){
    if(soilHum){
        // If soilHum is between 1 and 10(both inclusive) "S", the index number and soilHum is sent to DevKit8000
        UART_UartPutChar('S');
        UART_UartPutChar(index);
        UART_UartPutChar(soilHum);
        return 0;
    }
    else{
        // If soilHum isn't between 1 and 10(both inclusive) "XS" is sent to DevKit8000
        UART_UartPutChar('X');
        UART_UartPutChar('S');
        return -1;
    }
}

int8 respondHeat(int8 heatStatus, uint8 onOff){
    if(heatStatus == 0){
        // If heatStatus is 0 then onOff('H' or 'K') is sent to DevKit8000
        UART_UartPutChar(onOff);
        return 0;
    }
    else{
        // If heatStatus isn't 0 then 'X' and onOff('H' or 'K') is sent to DevKit8000
        UART_UartPutChar('X');
        UART_UartPutChar(onOff);
        return -1;
    }
}

int8 respondWin(int8 winStatus){
    if(winStatus == 0){
        // If winStatus is 0 then 'W' is sent to DevKit8000
        UART_UartPutChar('W');
        return 0;
    }
    else{
        // If heatStatus isn't 0 then "XW" is sent to DevKit8000
        UART_UartPutChar('X');
        UART_UartPutChar('W');
        return -1;
    }
}

int8 respondVent(int8 ventStatus){
    if(ventStatus == 0){
        // If ventStatus is 0 then 'V' is sent to DevKit8000
        UART_UartPutChar('V');
        return 0;
    }
    else{
        // If ventStatus isn't 0 then "XV" is sent to DevKit8000
        UART_UartPutChar('X');
        UART_UartPutChar('V');
        return -1;
    }
}

int8 respondIrri(int8 irriStatus){
    if(irriStatus == 0){
        // If irriStatus is 0 then 'F' is sent to DevKit8000
        UART_UartPutChar('F');
        return 0;
    }
    else{
        // If irriStatus isn't 0 then "XF" is sent to DevKit8000
        UART_UartPutChar('X');
        UART_UartPutChar('F');
        return -1;
    }
}

uint8 dkRequest(void){
    // Reads the UART buffer
    return UART_UartGetChar();
}

/* [] END OF FILE */