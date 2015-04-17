/*******************************************************************************
* File Name: BlueLED.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "BlueLED.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        BlueLED_PC =   (BlueLED_PC & \
                                (uint32)(~(uint32)(BlueLED_DRIVE_MODE_IND_MASK << (BlueLED_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (BlueLED_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: BlueLED_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void BlueLED_Write(uint8 value) 
{
    uint8 drVal = (uint8)(BlueLED_DR & (uint8)(~BlueLED_MASK));
    drVal = (drVal | ((uint8)(value << BlueLED_SHIFT) & BlueLED_MASK));
    BlueLED_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: BlueLED_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  BlueLED_DM_STRONG     Strong Drive 
*  BlueLED_DM_OD_HI      Open Drain, Drives High 
*  BlueLED_DM_OD_LO      Open Drain, Drives Low 
*  BlueLED_DM_RES_UP     Resistive Pull Up 
*  BlueLED_DM_RES_DWN    Resistive Pull Down 
*  BlueLED_DM_RES_UPDWN  Resistive Pull Up/Down 
*  BlueLED_DM_DIG_HIZ    High Impedance Digital 
*  BlueLED_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void BlueLED_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(BlueLED__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: BlueLED_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro BlueLED_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 BlueLED_Read(void) 
{
    return (uint8)((BlueLED_PS & BlueLED_MASK) >> BlueLED_SHIFT);
}


/*******************************************************************************
* Function Name: BlueLED_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 BlueLED_ReadDataReg(void) 
{
    return (uint8)((BlueLED_DR & BlueLED_MASK) >> BlueLED_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(BlueLED_INTSTAT) 

    /*******************************************************************************
    * Function Name: BlueLED_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 BlueLED_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(BlueLED_INTSTAT & BlueLED_MASK);
		BlueLED_INTSTAT = maskedStatus;
        return maskedStatus >> BlueLED_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
