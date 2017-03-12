/*******************************************************************************
* File Name: Accelerometer_X.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Accelerometer_X_ALIASES_H) /* Pins Accelerometer_X_ALIASES_H */
#define CY_PINS_Accelerometer_X_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Accelerometer_X_0			(Accelerometer_X__0__PC)
#define Accelerometer_X_0_PS		(Accelerometer_X__0__PS)
#define Accelerometer_X_0_PC		(Accelerometer_X__0__PC)
#define Accelerometer_X_0_DR		(Accelerometer_X__0__DR)
#define Accelerometer_X_0_SHIFT	(Accelerometer_X__0__SHIFT)
#define Accelerometer_X_0_INTR	((uint16)((uint16)0x0003u << (Accelerometer_X__0__SHIFT*2u)))

#define Accelerometer_X_INTR_ALL	 ((uint16)(Accelerometer_X_0_INTR))


#endif /* End Pins Accelerometer_X_ALIASES_H */


/* [] END OF FILE */
