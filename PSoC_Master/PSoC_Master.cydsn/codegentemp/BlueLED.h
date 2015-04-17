/*******************************************************************************
* File Name: BlueLED.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_BlueLED_H) /* Pins BlueLED_H */
#define CY_PINS_BlueLED_H

#include "cytypes.h"
#include "cyfitter.h"
#include "BlueLED_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    BlueLED_Write(uint8 value) ;
void    BlueLED_SetDriveMode(uint8 mode) ;
uint8   BlueLED_ReadDataReg(void) ;
uint8   BlueLED_Read(void) ;
uint8   BlueLED_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define BlueLED_DRIVE_MODE_BITS        (3)
#define BlueLED_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - BlueLED_DRIVE_MODE_BITS))

#define BlueLED_DM_ALG_HIZ         (0x00u)
#define BlueLED_DM_DIG_HIZ         (0x01u)
#define BlueLED_DM_RES_UP          (0x02u)
#define BlueLED_DM_RES_DWN         (0x03u)
#define BlueLED_DM_OD_LO           (0x04u)
#define BlueLED_DM_OD_HI           (0x05u)
#define BlueLED_DM_STRONG          (0x06u)
#define BlueLED_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define BlueLED_MASK               BlueLED__MASK
#define BlueLED_SHIFT              BlueLED__SHIFT
#define BlueLED_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define BlueLED_PS                     (* (reg32 *) BlueLED__PS)
/* Port Configuration */
#define BlueLED_PC                     (* (reg32 *) BlueLED__PC)
/* Data Register */
#define BlueLED_DR                     (* (reg32 *) BlueLED__DR)
/* Input Buffer Disable Override */
#define BlueLED_INP_DIS                (* (reg32 *) BlueLED__PC2)


#if defined(BlueLED__INTSTAT)  /* Interrupt Registers */

    #define BlueLED_INTSTAT                (* (reg32 *) BlueLED__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define BlueLED_DRIVE_MODE_SHIFT       (0x00u)
#define BlueLED_DRIVE_MODE_MASK        (0x07u << BlueLED_DRIVE_MODE_SHIFT)


#endif /* End Pins BlueLED_H */


/* [] END OF FILE */
