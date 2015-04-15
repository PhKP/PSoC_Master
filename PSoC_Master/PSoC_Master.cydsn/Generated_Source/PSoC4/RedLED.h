/*******************************************************************************
* File Name: RedLED.h  
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

#if !defined(CY_PINS_RedLED_H) /* Pins RedLED_H */
#define CY_PINS_RedLED_H

#include "cytypes.h"
#include "cyfitter.h"
#include "RedLED_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    RedLED_Write(uint8 value) ;
void    RedLED_SetDriveMode(uint8 mode) ;
uint8   RedLED_ReadDataReg(void) ;
uint8   RedLED_Read(void) ;
uint8   RedLED_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define RedLED_DRIVE_MODE_BITS        (3)
#define RedLED_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - RedLED_DRIVE_MODE_BITS))

#define RedLED_DM_ALG_HIZ         (0x00u)
#define RedLED_DM_DIG_HIZ         (0x01u)
#define RedLED_DM_RES_UP          (0x02u)
#define RedLED_DM_RES_DWN         (0x03u)
#define RedLED_DM_OD_LO           (0x04u)
#define RedLED_DM_OD_HI           (0x05u)
#define RedLED_DM_STRONG          (0x06u)
#define RedLED_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define RedLED_MASK               RedLED__MASK
#define RedLED_SHIFT              RedLED__SHIFT
#define RedLED_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define RedLED_PS                     (* (reg32 *) RedLED__PS)
/* Port Configuration */
#define RedLED_PC                     (* (reg32 *) RedLED__PC)
/* Data Register */
#define RedLED_DR                     (* (reg32 *) RedLED__DR)
/* Input Buffer Disable Override */
#define RedLED_INP_DIS                (* (reg32 *) RedLED__PC2)


#if defined(RedLED__INTSTAT)  /* Interrupt Registers */

    #define RedLED_INTSTAT                (* (reg32 *) RedLED__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define RedLED_DRIVE_MODE_SHIFT       (0x00u)
#define RedLED_DRIVE_MODE_MASK        (0x07u << RedLED_DRIVE_MODE_SHIFT)


#endif /* End Pins RedLED_H */


/* [] END OF FILE */
