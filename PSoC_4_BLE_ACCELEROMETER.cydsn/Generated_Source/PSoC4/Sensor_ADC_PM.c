/*******************************************************************************
* File Name: Sensor_ADC_PM.c
* Version 2.40
*
* Description:
*  This file provides Sleep/WakeUp APIs functionality.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Sensor_ADC.h"


/***************************************
* Local data allocation
***************************************/

static Sensor_ADC_BACKUP_STRUCT  Sensor_ADC_backup =
{
    Sensor_ADC_DISABLED
};


/*******************************************************************************
* Function Name: Sensor_ADC_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void Sensor_ADC_SaveConfig(void)
{
    /* All configuration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: Sensor_ADC_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void Sensor_ADC_RestoreConfig(void)
{
    /* All congiguration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: Sensor_ADC_Sleep
********************************************************************************
*
* Summary:
*  Stops the ADC operation and saves the configuration registers and component
*  enable state. Should be called just prior to entering sleep.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  Sensor_ADC_backup - modified.
*
*******************************************************************************/
void Sensor_ADC_Sleep(void)
{
    /* During deepsleep/ hibernate mode keep SARMUX active, i.e. do not open
    *   all switches (disconnect), to be used for ADFT
    */
    Sensor_ADC_SAR_DFT_CTRL_REG |= Sensor_ADC_ADFT_OVERRIDE;
    if((Sensor_ADC_SAR_CTRL_REG  & Sensor_ADC_ENABLE) != 0u)
    {
        if((Sensor_ADC_SAR_SAMPLE_CTRL_REG & Sensor_ADC_CONTINUOUS_EN) != 0u)
        {
            Sensor_ADC_backup.enableState = Sensor_ADC_ENABLED | Sensor_ADC_STARTED;
        }
        else
        {
            Sensor_ADC_backup.enableState = Sensor_ADC_ENABLED;
        }
        Sensor_ADC_StopConvert();
        Sensor_ADC_Stop();
        
        /* Disable the SAR internal pump before entering the chip low power mode */
        if((Sensor_ADC_SAR_CTRL_REG & Sensor_ADC_BOOSTPUMP_EN) != 0u)
        {
            Sensor_ADC_SAR_CTRL_REG &= (uint32)~Sensor_ADC_BOOSTPUMP_EN;
            Sensor_ADC_backup.enableState |= Sensor_ADC_BOOSTPUMP_ENABLED;
        }
    }
    else
    {
        Sensor_ADC_backup.enableState = Sensor_ADC_DISABLED;
    }
}


/*******************************************************************************
* Function Name: Sensor_ADC_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component enable state and configuration registers.
*  This should be called just after awaking from sleep mode.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  Sensor_ADC_backup - used.
*
*******************************************************************************/
void Sensor_ADC_Wakeup(void)
{
    Sensor_ADC_SAR_DFT_CTRL_REG &= (uint32)~Sensor_ADC_ADFT_OVERRIDE;
    if(Sensor_ADC_backup.enableState != Sensor_ADC_DISABLED)
    {
        /* Enable the SAR internal pump  */
        if((Sensor_ADC_backup.enableState & Sensor_ADC_BOOSTPUMP_ENABLED) != 0u)
        {
            Sensor_ADC_SAR_CTRL_REG |= Sensor_ADC_BOOSTPUMP_EN;
        }
        Sensor_ADC_Enable();
        if((Sensor_ADC_backup.enableState & Sensor_ADC_STARTED) != 0u)
        {
            Sensor_ADC_StartConvert();
        }
    }
}
/* [] END OF FILE */
