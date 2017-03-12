/*******************************************************************************
* File Name: Accelerometer_X.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "Accelerometer_X.h"

static Accelerometer_X_BACKUP_STRUCT  Accelerometer_X_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: Accelerometer_X_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function must be called for SIO and USBIO
*  pins. It is not essential if using GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet Accelerometer_X_SUT.c usage_Accelerometer_X_Sleep_Wakeup
*******************************************************************************/
void Accelerometer_X_Sleep(void)
{
    #if defined(Accelerometer_X__PC)
        Accelerometer_X_backup.pcState = Accelerometer_X_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            Accelerometer_X_backup.usbState = Accelerometer_X_CR1_REG;
            Accelerometer_X_USB_POWER_REG |= Accelerometer_X_USBIO_ENTER_SLEEP;
            Accelerometer_X_CR1_REG &= Accelerometer_X_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Accelerometer_X__SIO)
        Accelerometer_X_backup.sioState = Accelerometer_X_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        Accelerometer_X_SIO_REG &= (uint32)(~Accelerometer_X_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: Accelerometer_X_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep().
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to Accelerometer_X_Sleep() for an example usage.
*******************************************************************************/
void Accelerometer_X_Wakeup(void)
{
    #if defined(Accelerometer_X__PC)
        Accelerometer_X_PC = Accelerometer_X_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            Accelerometer_X_USB_POWER_REG &= Accelerometer_X_USBIO_EXIT_SLEEP_PH1;
            Accelerometer_X_CR1_REG = Accelerometer_X_backup.usbState;
            Accelerometer_X_USB_POWER_REG &= Accelerometer_X_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Accelerometer_X__SIO)
        Accelerometer_X_SIO_REG = Accelerometer_X_backup.sioState;
    #endif
}


/* [] END OF FILE */
