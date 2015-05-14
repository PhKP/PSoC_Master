/* ========================================
 * 
 * AutoGreen - PSoC_Master
 * DSP_Class.h
 * Digital signal processing
 * PRJ3 - GRP9
 * 2015-04-15
 *
 * ========================================
*/
#ifndef DSP_Class_H
#define DSP_Class_H

// Include files
#include <project.h>

// Definitions
#define ARRAYSIZE 2
#define NMR_OF_VALID_DATAPOINTS_NEEDED 2
#define NBR_OF_SOILHUM_SENSORS 6
#define EMPTY -1

// Public data members

// Public prototypes
void initDSP(void);
uint8 getTemp_DSP(void);
uint8 getSoilHum_DSP(uint8 index);
void inputTemp(int32* temp);
void inputSoilHum(uint8 index, int16* soilHum);

#endif /* DSP_Class_H */
/* [] END OF FILE */