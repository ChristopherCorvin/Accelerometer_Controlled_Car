/*******************************************************************************
* File Name: Sensor_ADC_intClock.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_Sensor_ADC_intClock_H)
#define CY_CLOCK_Sensor_ADC_intClock_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void Sensor_ADC_intClock_StartEx(uint32 alignClkDiv);
#define Sensor_ADC_intClock_Start() \
    Sensor_ADC_intClock_StartEx(Sensor_ADC_intClock__PA_DIV_ID)

#else

void Sensor_ADC_intClock_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void Sensor_ADC_intClock_Stop(void);

void Sensor_ADC_intClock_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 Sensor_ADC_intClock_GetDividerRegister(void);
uint8  Sensor_ADC_intClock_GetFractionalDividerRegister(void);

#define Sensor_ADC_intClock_Enable()                         Sensor_ADC_intClock_Start()
#define Sensor_ADC_intClock_Disable()                        Sensor_ADC_intClock_Stop()
#define Sensor_ADC_intClock_SetDividerRegister(clkDivider, reset)  \
    Sensor_ADC_intClock_SetFractionalDividerRegister((clkDivider), 0u)
#define Sensor_ADC_intClock_SetDivider(clkDivider)           Sensor_ADC_intClock_SetDividerRegister((clkDivider), 1u)
#define Sensor_ADC_intClock_SetDividerValue(clkDivider)      Sensor_ADC_intClock_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define Sensor_ADC_intClock_DIV_ID     Sensor_ADC_intClock__DIV_ID

#define Sensor_ADC_intClock_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define Sensor_ADC_intClock_CTRL_REG   (*(reg32 *)Sensor_ADC_intClock__CTRL_REGISTER)
#define Sensor_ADC_intClock_DIV_REG    (*(reg32 *)Sensor_ADC_intClock__DIV_REGISTER)

#define Sensor_ADC_intClock_CMD_DIV_SHIFT          (0u)
#define Sensor_ADC_intClock_CMD_PA_DIV_SHIFT       (8u)
#define Sensor_ADC_intClock_CMD_DISABLE_SHIFT      (30u)
#define Sensor_ADC_intClock_CMD_ENABLE_SHIFT       (31u)

#define Sensor_ADC_intClock_CMD_DISABLE_MASK       ((uint32)((uint32)1u << Sensor_ADC_intClock_CMD_DISABLE_SHIFT))
#define Sensor_ADC_intClock_CMD_ENABLE_MASK        ((uint32)((uint32)1u << Sensor_ADC_intClock_CMD_ENABLE_SHIFT))

#define Sensor_ADC_intClock_DIV_FRAC_MASK  (0x000000F8u)
#define Sensor_ADC_intClock_DIV_FRAC_SHIFT (3u)
#define Sensor_ADC_intClock_DIV_INT_MASK   (0xFFFFFF00u)
#define Sensor_ADC_intClock_DIV_INT_SHIFT  (8u)

#else 

#define Sensor_ADC_intClock_DIV_REG        (*(reg32 *)Sensor_ADC_intClock__REGISTER)
#define Sensor_ADC_intClock_ENABLE_REG     Sensor_ADC_intClock_DIV_REG
#define Sensor_ADC_intClock_DIV_FRAC_MASK  Sensor_ADC_intClock__FRAC_MASK
#define Sensor_ADC_intClock_DIV_FRAC_SHIFT (16u)
#define Sensor_ADC_intClock_DIV_INT_MASK   Sensor_ADC_intClock__DIVIDER_MASK
#define Sensor_ADC_intClock_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_Sensor_ADC_intClock_H) */

/* [] END OF FILE */
