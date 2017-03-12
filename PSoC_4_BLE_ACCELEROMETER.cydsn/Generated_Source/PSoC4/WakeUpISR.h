/*******************************************************************************
* File Name: WakeUpISR.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_WakeUpISR_H)
#define CY_ISR_WakeUpISR_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void WakeUpISR_Start(void);
void WakeUpISR_StartEx(cyisraddress address);
void WakeUpISR_Stop(void);

CY_ISR_PROTO(WakeUpISR_Interrupt);

void WakeUpISR_SetVector(cyisraddress address);
cyisraddress WakeUpISR_GetVector(void);

void WakeUpISR_SetPriority(uint8 priority);
uint8 WakeUpISR_GetPriority(void);

void WakeUpISR_Enable(void);
uint8 WakeUpISR_GetState(void);
void WakeUpISR_Disable(void);

void WakeUpISR_SetPending(void);
void WakeUpISR_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the WakeUpISR ISR. */
#define WakeUpISR_INTC_VECTOR            ((reg32 *) WakeUpISR__INTC_VECT)

/* Address of the WakeUpISR ISR priority. */
#define WakeUpISR_INTC_PRIOR             ((reg32 *) WakeUpISR__INTC_PRIOR_REG)

/* Priority of the WakeUpISR interrupt. */
#define WakeUpISR_INTC_PRIOR_NUMBER      WakeUpISR__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable WakeUpISR interrupt. */
#define WakeUpISR_INTC_SET_EN            ((reg32 *) WakeUpISR__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the WakeUpISR interrupt. */
#define WakeUpISR_INTC_CLR_EN            ((reg32 *) WakeUpISR__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the WakeUpISR interrupt state to pending. */
#define WakeUpISR_INTC_SET_PD            ((reg32 *) WakeUpISR__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the WakeUpISR interrupt. */
#define WakeUpISR_INTC_CLR_PD            ((reg32 *) WakeUpISR__INTC_CLR_PD_REG)



#endif /* CY_ISR_WakeUpISR_H */


/* [] END OF FILE */
