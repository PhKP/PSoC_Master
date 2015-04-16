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

    
    // Public data members
    
    
    // Public prototypes
    void initDSP(void);
    uint8 getTemp_DSP(void);
    uint8 getHum_DSP(void);
    uint8 getSoilHum_DSP(uint8 index);
    uint8 getLight_DSP(void);
    void inputTemp(int32* temp);
    void inputHum(int32* hum);
    void inputSoilHum(uint8 index, int16* soilHum);
    void inputLight(int32* light);

#endif /* DSP_Class_H */
/* [] END OF FILE */