/*******************************************************************************
* File Name: Sensor_ADC.h
* Version 2.40
*
* Description:
*  This file contains the function prototypes and constants used in
*  the Sequencing Successive Approximation ADC Component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_ADC_SAR_SEQ_Sensor_ADC_H)
#define CY_ADC_SAR_SEQ_Sensor_ADC_H

#include "cytypes.h"
#include "CyLib.h"


/***************************************
*      Data Struct Definition
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 enableState;
} Sensor_ADC_BACKUP_STRUCT;


/**************************************
*    Enumerated Types and Parameters
**************************************/

/*  Clock Source setting constants */
#define Sensor_ADC__EXTERNAL 0
#define Sensor_ADC__INTERNAL 1

/*  Sample Mode setting constants */
#define Sensor_ADC__FREERUNNING 0
#define Sensor_ADC__HARDWARESOC 1

/*  Reference type setting constants */
#define Sensor_ADC__VDDA_2 0
#define Sensor_ADC__VDDA 1
#define Sensor_ADC__INTERNAL1024 2
#define Sensor_ADC__INTERNAL1024BYPASSED 3
#define Sensor_ADC__INTERNALVREF 4
#define Sensor_ADC__INTERNALVREFBYPASSED 5
#define Sensor_ADC__VDDA_2BYPASSED 6
#define Sensor_ADC__EXTERNALVREF 7

/* Input buffer gain setting constants */
#define Sensor_ADC__DISABLED 0
#define Sensor_ADC__ONE 1
#define Sensor_ADC__TWO 2
#define Sensor_ADC__FOUR 3
#define Sensor_ADC__EIGHT 4
#define Sensor_ADC__SIXTEEN 5

/* Negative input setting sonstants in single ended mode */
#define Sensor_ADC__VSS 0
#define Sensor_ADC__VREF 1
#define Sensor_ADC__OTHER 2

/* Compare mode setting constants:
*    Mode0 - Disable
*    Mode1 - Result < Low_Limit
*    Mode2 - Low_Limit <= Result < High_Limit
*    Mode3 - High_Limit <= Result
*    Mode4 - (Result < Low_Limit) or (High_Limit <= Result)
*/
#define Sensor_ADC__MODE0 0
#define Sensor_ADC__MODE1 1
#define Sensor_ADC__MODE2 2
#define Sensor_ADC__MODE3 3

#define Sensor_ADC__RES8 0
#define Sensor_ADC__RES10 1

#define Sensor_ADC__RIGHT 0
#define Sensor_ADC__LEFT 1

#define Sensor_ADC__FSIGNED 1
#define Sensor_ADC__FUNSIGNED 0

#define Sensor_ADC__ACCUMULATE 0
#define Sensor_ADC__FIXEDRESOLUTION 1



/***************************************
*   Conditional Compilation Parameters
****************************************/ 

#define Sensor_ADC_CY_SAR_IP_VER0               	(0u)
#define Sensor_ADC_CY_SAR_IP_VER1               	(1u)

#if (CY_PSOC4_4100 || CY_PSOC4_4200)
    #define Sensor_ADC_CY_SAR_IP_VER              (Sensor_ADC_CY_SAR_IP_VER0)
#else /* Other devices */
    #define Sensor_ADC_CY_SAR_IP_VER              (Sensor_ADC_CY_SAR_IP_VER1)
#endif  /* (CY_PSOC4_4100 || CY_PSOC4_4200) */


/***************************************
*    Initial Parameter Constants
***************************************/
#define Sensor_ADC_DEFAULT_SAMPLE_MODE_SEL        (0u)
#define Sensor_ADC_DEFAULT_VREF_SEL               (1u)
#define Sensor_ADC_DEFAULT_NEG_INPUT_SEL          (0u)
#define Sensor_ADC_DEFAULT_ALT_RESOLUTION_SEL     (1u)
#define Sensor_ADC_DEFAULT_JUSTIFICATION_SEL      (0u)
#define Sensor_ADC_DEFAULT_DIFF_RESULT_FORMAT_SEL (0u)
#define Sensor_ADC_DEFAULT_SE_RESULT_FORMAT_SEL   (1u)
#define Sensor_ADC_DEFAULT_CLOCK_SOURCE           (1u)
#define Sensor_ADC_DEFAULT_VREF_MV_VALUE          (3300)
#define Sensor_ADC_DEFAULT_BUFFER_GAIN            (0u)
#define Sensor_ADC_DEFAULT_AVG_SAMPLES_NUM        (2u)
#define Sensor_ADC_DEFAULT_AVG_SAMPLES_DIV        (int16)(0x100u >> (7u - 2u))
#define Sensor_ADC_DEFAULT_AVG_MODE               (0u)
#define Sensor_ADC_MAX_RESOLUTION                 (12u)
#define Sensor_ADC_DEFAULT_LOW_LIMIT              (0u)
#define Sensor_ADC_DEFAULT_HIGH_LIMIT             (2047u)
#define Sensor_ADC_DEFAULT_COMPARE_MODE           (0u)
#define Sensor_ADC_DEFAULT_ACLKS_NUM              (8u)
#define Sensor_ADC_DEFAULT_BCLKS_NUM              (8u)
#define Sensor_ADC_DEFAULT_CCLKS_NUM              (8u)
#define Sensor_ADC_DEFAULT_DCLKS_NUM              (8u)
#define Sensor_ADC_TOTAL_CHANNELS_NUM             (3u)
#define Sensor_ADC_SEQUENCED_CHANNELS_NUM         (3u)
#define Sensor_ADC_DEFAULT_EN_CHANNELS            (7u)
#define Sensor_ADC_NOMINAL_CLOCK_FREQ             (1000000)
#define Sensor_ADC_INJ_CHANNEL_ENABLED            (0u)
#define Sensor_ADC_IRQ_REMOVE                     (0u)

/* Determines whether the configuration contains external negative input. */
#define Sensor_ADC_SINGLE_PRESENT                 (0u)
#define Sensor_ADC_CHANNELS_MODE                  (0u)
#define Sensor_ADC_MAX_CHANNELS_EN_MASK           (0xffffu >> (16u - Sensor_ADC_SEQUENCED_CHANNELS_NUM))


/***************************************
*        Function Prototypes
***************************************/

void Sensor_ADC_Start(void);
void Sensor_ADC_Stop(void);
void Sensor_ADC_Init(void);
void Sensor_ADC_Enable(void);
void Sensor_ADC_StartConvert(void);
void Sensor_ADC_StopConvert(void);
uint32 Sensor_ADC_IsEndConversion(uint32 retMode);
int16 Sensor_ADC_GetResult16(uint32 chan);
void Sensor_ADC_SetChanMask(uint32 mask);
void Sensor_ADC_SetLowLimit(uint32 lowLimit);
void Sensor_ADC_SetHighLimit(uint32 highLimit);
void Sensor_ADC_SetLimitMask(uint32 mask);
void Sensor_ADC_SetSatMask(uint32 mask);
void Sensor_ADC_SetOffset(uint32 chan, int16 offset);
void Sensor_ADC_SetGain(uint32 chan, int32 adcGain);
#if(Sensor_ADC_INJ_CHANNEL_ENABLED)
    void Sensor_ADC_EnableInjection(void);
#endif /* Sensor_ADC_INJ_CHANNEL_ENABLED */
#if(Sensor_ADC_DEFAULT_JUSTIFICATION_SEL == Sensor_ADC__RIGHT)
    int16 Sensor_ADC_CountsTo_mVolts(uint32 chan, int16 adcCounts);
    int32 Sensor_ADC_CountsTo_uVolts(uint32 chan, int16 adcCounts);
    float32 Sensor_ADC_CountsTo_Volts(uint32 chan, int16 adcCounts);
#endif /* End Sensor_ADC_DEFAULT_JUSTIFICATION_SEL == Sensor_ADC__RIGHT */
void Sensor_ADC_Sleep(void);
void Sensor_ADC_Wakeup(void);
void Sensor_ADC_SaveConfig(void);
void Sensor_ADC_RestoreConfig(void);

CY_ISR_PROTO( Sensor_ADC_ISR );


/**************************************
*           API Constants
**************************************/
/* Constants for Sleep mode states */
#define Sensor_ADC_DISABLED                   (0x00u)
#define Sensor_ADC_ENABLED                    (0x01u)
#define Sensor_ADC_STARTED                    (0x02u)
#define Sensor_ADC_BOOSTPUMP_ENABLED          (0x04u)

/*   Constants for IsEndConversion() "retMode" parameter  */
#define Sensor_ADC_RETURN_STATUS              (0x01u)
#define Sensor_ADC_WAIT_FOR_RESULT            (0x02u)
#define Sensor_ADC_RETURN_STATUS_INJ          (0x04u)
#define Sensor_ADC_WAIT_FOR_RESULT_INJ        (0x08u)

#define Sensor_ADC_MAX_FREQUENCY              (18000000)       /*18Mhz*/

#define Sensor_ADC_RESOLUTION_12              (12u)
#define Sensor_ADC_RESOLUTION_10              (10u)
#define Sensor_ADC_RESOLUTION_8               (8u)

#define Sensor_ADC_10US_DELAY                 (10u)

#define Sensor_ADC_10V_COUNTS                 (10.0F)
#define Sensor_ADC_10MV_COUNTS                (10000)
#define Sensor_ADC_10UV_COUNTS                (10000000L)


/***************************************
* Global variables external identifier
***************************************/

extern uint8 Sensor_ADC_initVar;
extern volatile int16 Sensor_ADC_offset[Sensor_ADC_TOTAL_CHANNELS_NUM];
extern volatile int32 Sensor_ADC_countsPer10Volt[Sensor_ADC_TOTAL_CHANNELS_NUM];


/***************************************
*              Registers
***************************************/

#define Sensor_ADC_SAR_CTRL_REG                (*(reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_CTRL )
#define Sensor_ADC_SAR_CTRL_PTR                ( (reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_CTRL )

#define Sensor_ADC_SAR_SAMPLE_CTRL_REG         (*(reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_SAMPLE_CTRL )
#define Sensor_ADC_SAR_SAMPLE_CTRL_PTR         ( (reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_SAMPLE_CTRL )

#define Sensor_ADC_SAR_SAMPLE_TIME01_REG       (*(reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_SAMPLE_TIME01 )
#define Sensor_ADC_SAR_SAMPLE_TIME01_PTR       ( (reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_SAMPLE_TIME01 )

#define Sensor_ADC_SAR_SAMPLE_TIME23_REG       (*(reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_SAMPLE_TIME23 )
#define Sensor_ADC_SAR_SAMPLE_TIME23_PTR       ( (reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_SAMPLE_TIME23 )

#define Sensor_ADC_SAR_RANGE_THRES_REG         (*(reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_RANGE_THRES )
#define Sensor_ADC_SAR_RANGE_THRES_PTR         ( (reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_RANGE_THRES )

#define Sensor_ADC_SAR_RANGE_COND_REG          (*(reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_RANGE_COND )
#define Sensor_ADC_SAR_RANGE_COND_PTR          ( (reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_RANGE_COND )

#define Sensor_ADC_SAR_CHAN_EN_REG             (*(reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_CHAN_EN )
#define Sensor_ADC_SAR_CHAN_EN_PTR             ( (reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_CHAN_EN )

#define Sensor_ADC_SAR_START_CTRL_REG          (*(reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_START_CTRL )
#define Sensor_ADC_SAR_START_CTRL_PTR          ( (reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_START_CTRL )

#define Sensor_ADC_SAR_DFT_CTRL_REG            (*(reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_DFT_CTRL )
#define Sensor_ADC_SAR_DFT_CTRL_PTR            ( (reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_DFT_CTRL )

#define Sensor_ADC_SAR_CHAN_CONFIG_REG         (*(reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_CHAN_CONFIG00 )
#define Sensor_ADC_SAR_CHAN_CONFIG_PTR         ( (reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_CHAN_CONFIG00 )
#define Sensor_ADC_SAR_CHAN_CONFIG_IND         Sensor_ADC_cy_psoc4_sar__SAR_CHAN_CONFIG00

#define Sensor_ADC_SAR_CHAN_WORK_REG           (*(reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_CHAN_WORK00 )
#define Sensor_ADC_SAR_CHAN_WORK_PTR           ( (reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_CHAN_WORK00 )

#define Sensor_ADC_SAR_CHAN_RESULT_REG         (*(reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_CHAN_RESULT00 )
#define Sensor_ADC_SAR_CHAN_RESULT_PTR         ( (reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_CHAN_RESULT00 )
#define Sensor_ADC_SAR_CHAN_RESULT_IND         Sensor_ADC_cy_psoc4_sar__SAR_CHAN_RESULT00

#define Sensor_ADC_SAR_CHAN0_RESULT_REG         (*(reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_CHAN_RESULT00 )
#define Sensor_ADC_SAR_CHAN0_RESULT_PTR         ( (reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_CHAN_RESULT00 )

#define Sensor_ADC_SAR_CHAN1_RESULT_REG         (*(reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_CHAN_RESULT01 )
#define Sensor_ADC_SAR_CHAN1_RESULT_PTR         ( (reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_CHAN_RESULT01 )

#define Sensor_ADC_SAR_CHAN2_RESULT_REG         (*(reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_CHAN_RESULT02 )
#define Sensor_ADC_SAR_CHAN2_RESULT_PTR         ( (reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_CHAN_RESULT02 )

#define Sensor_ADC_SAR_CHAN3_RESULT_REG         (*(reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_CHAN_RESULT03 )
#define Sensor_ADC_SAR_CHAN3_RESULT_PTR         ( (reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_CHAN_RESULT03 )

#define Sensor_ADC_SAR_CHAN4_RESULT_REG         (*(reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_CHAN_RESULT04 )
#define Sensor_ADC_SAR_CHAN4_RESULT_PTR         ( (reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_CHAN_RESULT04 )

#define Sensor_ADC_SAR_CHAN5_RESULT_REG         (*(reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_CHAN_RESULT05 )
#define Sensor_ADC_SAR_CHAN5_RESULT_PTR         ( (reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_CHAN_RESULT05 )

#define Sensor_ADC_SAR_CHAN6_RESULT_REG         (*(reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_CHAN_RESULT06 )
#define Sensor_ADC_SAR_CHAN6_RESULT_PTR         ( (reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_CHAN_RESULT06 )

#define Sensor_ADC_SAR_CHAN7_RESULT_REG         (*(reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_CHAN_RESULT07 )
#define Sensor_ADC_SAR_CHAN7_RESULT_PTR         ( (reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_CHAN_RESULT07 )

#if(Sensor_ADC_CY_SAR_IP_VER != Sensor_ADC_CY_SAR_IP_VER0)
    #define Sensor_ADC_SAR_CHAN8_RESULT_REG     (*(reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_CHAN_RESULT08 )
    #define Sensor_ADC_SAR_CHAN8_RESULT_PTR     ( (reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_CHAN_RESULT08 )

    #define Sensor_ADC_SAR_CHAN9_RESULT_REG     (*(reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_CHAN_RESULT09 )
    #define Sensor_ADC_SAR_CHAN9_RESULT_PTR     ( (reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_CHAN_RESULT09 )

    #define Sensor_ADC_SAR_CHAN10_RESULT_REG    (*(reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_CHAN_RESULT10 )
    #define Sensor_ADC_SAR_CHAN10_RESULT_PTR    ( (reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_CHAN_RESULT10 )

    #define Sensor_ADC_SAR_CHAN11_RESULT_REG    (*(reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_CHAN_RESULT11 )
    #define Sensor_ADC_SAR_CHAN11_RESULT_PTR    ( (reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_CHAN_RESULT11 )

    #define Sensor_ADC_SAR_CHAN12_RESULT_REG    (*(reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_CHAN_RESULT12 )
    #define Sensor_ADC_SAR_CHAN12_RESULT_PTR    ( (reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_CHAN_RESULT12 )

    #define Sensor_ADC_SAR_CHAN13_RESULT_REG    (*(reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_CHAN_RESULT13 )
    #define Sensor_ADC_SAR_CHAN13_RESULT_PTR    ( (reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_CHAN_RESULT13 )

    #define Sensor_ADC_SAR_CHAN14_RESULT_REG    (*(reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_CHAN_RESULT14 )
    #define Sensor_ADC_SAR_CHAN14_RESULT_PTR    ( (reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_CHAN_RESULT14 )

    #define Sensor_ADC_SAR_CHAN15_RESULT_REG    (*(reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_CHAN_RESULT15 )
    #define Sensor_ADC_SAR_CHAN15_RESULT_PTR    ( (reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_CHAN_RESULT15 )
#endif /* (Sensor_ADC_CY_SAR_IP_VER != Sensor_ADC_CY_SAR_IP_VER0) */

#define Sensor_ADC_SAR_CHAN_WORK_VALID_REG     (*(reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_CHAN_WORK_VALID)
#define Sensor_ADC_SAR_CHAN_WORK_VALID_PTR     ( (reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_CHAN_WORK_VALID)

#define Sensor_ADC_SAR_CHAN_RESULT_VALID_REG  ( *(reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_CHAN_RESULT_VALID )
#define Sensor_ADC_SAR_CHAN_RESULT_VALID_PTR  ( (reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_CHAN_RESULT_VALID )

#define Sensor_ADC_SAR_STATUS_REG              (*(reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_STATUS )
#define Sensor_ADC_SAR_STATUS_PTR              ( (reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_STATUS )

#define Sensor_ADC_SAR_AVG_START_REG           (*(reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_AVG_STAT )
#define Sensor_ADC_SAR_AVG_START_PTR           ( (reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_AVG_STAT )

#define Sensor_ADC_SAR_INTR_REG                (*(reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_INTR )
#define Sensor_ADC_SAR_INTR_PTR                ( (reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_INTR )

#define Sensor_ADC_SAR_INTR_SET_REG            (*(reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_INTR_SET )
#define Sensor_ADC_SAR_INTR_SET_PTR            ( (reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_INTR_SET )

#define Sensor_ADC_SAR_INTR_MASK_REG           (*(reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_INTR_MASK )
#define Sensor_ADC_SAR_INTR_MASK_PTR           ( (reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_INTR_MASK )

#define Sensor_ADC_SAR_INTR_MASKED_REG         (*(reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_INTR_MASKED )
#define Sensor_ADC_SAR_INTR_MASKED_PTR         ( (reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_INTR_MASKED )

#define Sensor_ADC_SAR_SATURATE_INTR_REG       (*(reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_SATURATE_INTR )
#define Sensor_ADC_SAR_SATURATE_INTR_PTR       ( (reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_SATURATE_INTR )

#define Sensor_ADC_SAR_SATURATE_INTR_SET_REG   (*(reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_SATURATE_INTR_SET )
#define Sensor_ADC_SAR_SATURATE_INTR_SET_PTR   ( (reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_SATURATE_INTR_SET )

#define Sensor_ADC_SAR_SATURATE_INTR_MASK_REG (*(reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_SATURATE_INTR_MASK )
#define Sensor_ADC_SAR_SATURATE_INTR_MASK_PTR ( (reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_SATURATE_INTR_MASK )

#define Sensor_ADC_SAR_SATURATE_INTR_MASKED_REG \
                                                 (*(reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_SATURATE_INTR_MASKED )
#define Sensor_ADC_SAR_SATURATE_INTR_MASKED_PTR \
                                                 ( (reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_SATURATE_INTR_MASKED )

#define Sensor_ADC_SAR_RANGE_INTR_REG          (*(reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_RANGE_INTR )
#define Sensor_ADC_SAR_RANGE_INTR_PTR          ( (reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_RANGE_INTR )

#define Sensor_ADC_SAR_RANGE_INTR_SET_REG      (*(reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_RANGE_INTR_SET )
#define Sensor_ADC_SAR_RANGE_INTR_SET_PTR      ( (reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_RANGE_INTR_SET )

#define Sensor_ADC_SAR_RANGE_INTR_MASK_REG     (*(reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_RANGE_INTR_MASK )
#define Sensor_ADC_SAR_RANGE_INTR_MASK_PTR     ( (reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_RANGE_INTR_MASK )

#define Sensor_ADC_SAR_RANGE_INTR_MASKED_REG   (*(reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_RANGE_INTR_MASKED )
#define Sensor_ADC_SAR_RANGE_INTR_MASKED_PTR   ( (reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_RANGE_INTR_MASKED )

#define Sensor_ADC_SAR_INTR_CAUSE_REG          (*(reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_INTR_CAUSE )
#define Sensor_ADC_SAR_INTR_CAUSE_PTR          ( (reg32 *) Sensor_ADC_cy_psoc4_sar__SAR_INTR_CAUSE )

#if(Sensor_ADC_INJ_CHANNEL_ENABLED)
    #define Sensor_ADC_SAR_INJ_CHAN_CONFIG_REG \
                                                 (*(reg32 *) Sensor_ADC_cy_psoc4_sarmux_8__SAR_INJ_CHAN_CONFIG )
    #define Sensor_ADC_SAR_INJ_CHAN_CONFIG_PTR    \
                                                 ( (reg32 *) Sensor_ADC_cy_psoc4_sarmux_8__SAR_INJ_CHAN_CONFIG )

    #define Sensor_ADC_SAR_INJ_RESULT_REG    (*(reg32 *) Sensor_ADC_cy_psoc4_sarmux_8__SAR_INJ_RESULT )
    #define Sensor_ADC_SAR_INJ_RESULT_PTR    ( (reg32 *) Sensor_ADC_cy_psoc4_sarmux_8__SAR_INJ_RESULT )
#endif /* Sensor_ADC_INJ_CHANNEL_ENABLED */
    
#define Sensor_ADC_MUX_SWITCH0_REG           (*(reg32 *)  Sensor_ADC_cy_psoc4_sar__SAR_MUX_SWITCH0 )
#define Sensor_ADC_MUX_SWITCH0_PTR           ( (reg32 *)  Sensor_ADC_cy_psoc4_sar__SAR_MUX_SWITCH0 )

#define Sensor_ADC_MUX_SWITCH_HW_CTRL_REG    (*(reg32 *)  Sensor_ADC_cy_psoc4_sar__SAR_MUX_SWITCH_HW_CTRL )
#define Sensor_ADC_MUX_SWITCH_HW_CTRL_PTR    ( (reg32 *)  Sensor_ADC_cy_psoc4_sar__SAR_MUX_SWITCH_HW_CTRL )

#define Sensor_ADC_PUMP_CTRL_REG             (*(reg32 *)  Sensor_ADC_cy_psoc4_sar__SAR_PUMP_CTRL )
#define Sensor_ADC_PUMP_CTRL_PTR             ( (reg32 *)  Sensor_ADC_cy_psoc4_sar__SAR_PUMP_CTRL )

#define Sensor_ADC_ANA_TRIM_REG              (*(reg32 *)  Sensor_ADC_cy_psoc4_sar__SAR_ANA_TRIM )
#define Sensor_ADC_ANA_TRIM_PTR              ( (reg32 *)  Sensor_ADC_cy_psoc4_sar__SAR_ANA_TRIM )

#define Sensor_ADC_WOUNDING_REG              (*(reg32 *)  Sensor_ADC_cy_psoc4_sar__SAR_WOUNDING )
#define Sensor_ADC_WOUNDING_PTR              ( (reg32 *)  Sensor_ADC_cy_psoc4_sar__SAR_WOUNDING )


/**************************************
*       Register Constants
**************************************/
#define Sensor_ADC_INTC_NUMBER                (Sensor_ADC_IRQ__INTC_NUMBER)
#define Sensor_ADC_INTC_PRIOR_NUMBER          (Sensor_ADC_IRQ__INTC_PRIOR_NUM)

/* defines for CTRL register */
#define Sensor_ADC_VREF_INTERNAL1024          (0x00000040Lu)
#define Sensor_ADC_VREF_EXTERNAL              (0x00000050Lu)
#define Sensor_ADC_VREF_VDDA_2                (0x00000060Lu)
#define Sensor_ADC_VREF_VDDA                  (0x00000070Lu)
#define Sensor_ADC_VREF_INTERNAL1024BYPASSED  (0x000000C0Lu)
#define Sensor_ADC_VREF_VDDA_2BYPASSED        (0x000000E0Lu)
#define Sensor_ADC_VREF_INTERNALVREF          (0x00000040Lu)
#define Sensor_ADC_VREF_INTERNALVREFBYPASSED  (0x000000C0Lu)

#define Sensor_ADC_NEG_VSSA_KELVIN            (0x00000000Lu)
#define Sensor_ADC_NEG_VSSA                   (0x00000200Lu)
#define Sensor_ADC_NEG_VREF                   (0x00000E00Lu)
#if(Sensor_ADC_TOTAL_CHANNELS_NUM > 1u)
    #define Sensor_ADC_NEG_OTHER              (uint16)((uint16)Sensor_ADC_cy_psoc4_sarmux_8__VNEG << 9u)
#else
    #define Sensor_ADC_NEG_OTHER              (0)
#endif /* Sensor_ADC_TOTAL_CHANNELS_NUM > 1u */

#define Sensor_ADC_SAR_HW_CTRL_NEGVREF        (0x00002000Lu)

#define Sensor_ADC_BOOSTPUMP_EN               (0x00100000Lu)

#define Sensor_ADC_NORMAL_PWR                 (0x00000000Lu)
#define Sensor_ADC_HALF_PWR                   (0x01000000Lu)
#define Sensor_ADC_MORE_PWR                   (0x02000000Lu)
#define Sensor_ADC_QUARTER_PWR                (0x03000000Lu)
#define Sensor_ADC_DEEPSLEEP_ON               (0x08000000Lu)

#define Sensor_ADC_DSI_SYNC_CONFIG            (0x10000000Lu)
#define Sensor_ADC_DSI_MODE                   (0x20000000Lu)
#define Sensor_ADC_SWITCH_DISABLE             (0x40000000Lu)
#define Sensor_ADC_ENABLE                     (0x80000000Lu)

/* defines for STATUS register */
#define Sensor_ADC_STATUS_BUSY                (0x80000000Lu)

/* defines for SAMPLE_CTRL register */
#define Sensor_ADC_ALT_RESOLUTION_10BIT       (0x00000001Lu)
#define Sensor_ADC_ALT_RESOLUTION_8BIT        (0x00000000Lu)

#define Sensor_ADC_DATA_ALIGN_LEFT            (0x00000002Lu)
#define Sensor_ADC_DATA_ALIGN_RIGHT           (0x00000000Lu)

#define Sensor_ADC_SE_SIGNED_RESULT           (0x00000004Lu)
#define Sensor_ADC_SE_UNSIGNED_RESULT         (0x00000000Lu)

#define Sensor_ADC_DIFF_SIGNED_RESULT         (0x00000008Lu)
#define Sensor_ADC_DIFF_UNSIGNED_RESULT       (0x00000000Lu)

#define Sensor_ADC_AVG_CNT_OFFSET             (4u)
#define Sensor_ADC_AVG_CNT_MASK               (0x00000070Lu)
#define Sensor_ADC_AVG_SHIFT                  (0x00000080Lu)

#define Sensor_ADC_CONTINUOUS_EN              (0x00010000Lu)
#define Sensor_ADC_DSI_TRIGGER_EN             (0x00020000Lu)
#define Sensor_ADC_DSI_TRIGGER_LEVEL          (0x00040000Lu)
#define Sensor_ADC_DSI_SYNC_TRIGGER           (0x00080000Lu)
#define Sensor_ADC_EOS_DSI_OUT_EN             (0x80000000Lu)

/* defines for SAMPLE_TIME01 / SAMPLE_TIME23 registers */
#define Sensor_ADC_SAMPLE_TIME13_OFFSET       (16u)
#define Sensor_ADC_SAMPLE_TIME02_MASK         (0x000003FFLu)
#define Sensor_ADC_SAMPLE_TIME13_MASK         (0x03FF0000Lu)

/* defines for RANGE_THRES registers */
#define Sensor_ADC_RANGE_HIGH_OFFSET          (16u)
#define Sensor_ADC_RANGE_HIGH_MASK            (0xFFFF0000Lu)
#define Sensor_ADC_RANGE_LOW_MASK             (0x0000FFFFLu)

/* defines for RANGE_COND register */
/* Compare mode setting constants:
*    BELOW   - Result < Low_Limit
*    INSIDE  - Low_Limit <= Result < High_Limit
*    ABOVE   - High_Limit <= Result
*    OUTSIDE - (Result < Low_Limit) or (High_Limit <= Result)
*/
#define Sensor_ADC_CMP_MODE_BELOW             (0x00000000Lu)
#define Sensor_ADC_CMP_MODE_INSIDE            (0x40000000Lu)
#define Sensor_ADC_CMP_MODE_ABOVE             (0x80000000Lu)
#define Sensor_ADC_CMP_MODE_OUTSIDE           (0xC0000000Lu)
#define Sensor_ADC_CMP_OFFSET                 (30u)

/* defines for _START_CTRL register */
#define Sensor_ADC_FW_TRIGGER                 (0x00000001Lu)

/* defines for DFT_CTRL register */
#define Sensor_ADC_DLY_INC                    (0x00000001Lu)
#define Sensor_ADC_HIZ                        (0x00000002Lu)
#define Sensor_ADC_DFT_INC_MASK               (0x000F0000Lu)
#define Sensor_ADC_DFT_OUTC_MASK              (0x00700000Lu)
#define Sensor_ADC_SEL_CSEL_DFT_MASK          (0x0F000000Lu)

/* configuration for clock speed > 9 Mhz based on
* characterization results
*/
#define Sensor_ADC_SEL_CSEL_DFT_CHAR          (0x03000000Lu)
#define Sensor_ADC_EN_CSEL_DFT                (0x10000000Lu)
#define Sensor_ADC_DCEN                       (0x20000000Lu)
#define Sensor_ADC_ADFT_OVERRIDE              (0x80000000Lu)

/* defines for CHAN_CONFIG / DIE_CHAN_CONFIG register
*  and channelsConfig parameter
*/
#define Sensor_ADC_SARMUX_VIRT_SELECT         (0x00000070Lu)
#define Sensor_ADC_DIFFERENTIAL_EN            (0x00000100Lu)
#define Sensor_ADC_ALT_RESOLUTION_ON          (0x00000200Lu)
#define Sensor_ADC_AVERAGING_EN               (0x00000400Lu)

#define Sensor_ADC_SAMPLE_TIME_SEL_SHIFT      (12u)
#define Sensor_ADC_SAMPLE_TIME_SEL_MASK       (0x00003000Lu)

#define Sensor_ADC_CHANNEL_CONFIG_MASK        (0x00003700Lu)

/* for CHAN_CONFIG only */
#define Sensor_ADC_DSI_OUT_EN                 (0x80000000Lu)

/* for INJ_CHAN_CONFIG only */
#define Sensor_ADC_INJ_TAILGATING             (0x40000000Lu)
#define Sensor_ADC_INJ_CHAN_EN                (0x80000000Lu)

/* defines for CHAN_WORK register */
#define Sensor_ADC_SAR_WRK_MAX_12BIT          (0x00001000Lu)
#define Sensor_ADC_SAR_WRK_MAX_10BIT          (0x00000400Lu)
#define Sensor_ADC_SAR_WRK_MAX_8BIT           (0x00000100Lu)

/* defines for CHAN_RESULT register */
#define Sensor_ADC_RESULT_MASK                (0x0000FFFFLu)
#define Sensor_ADC_SATURATE_INTR_MIR          (0x20000000Lu)
#define Sensor_ADC_RANGE_INTR_MIR             (0x40000000Lu)
#define Sensor_ADC_CHAN_RESULT_VALID_MIR      (0x80000000Lu)

/* defines for INTR_MASK register */
#define Sensor_ADC_EOS_MASK                   (0x00000001Lu)
#define Sensor_ADC_OVERFLOW_MASK              (0x00000002Lu)
#define Sensor_ADC_FW_COLLISION_MASK          (0x00000004Lu)
#define Sensor_ADC_DSI_COLLISION_MASK         (0x00000008Lu)
#define Sensor_ADC_INJ_EOC_MASK               (0x00000010Lu)
#define Sensor_ADC_INJ_SATURATE_MASK          (0x00000020Lu)
#define Sensor_ADC_INJ_RANGE_MASK             (0x00000040Lu)
#define Sensor_ADC_INJ_COLLISION_MASK         (0x00000080Lu)

/* defines for INJ_RESULT register */
#define Sensor_ADC_INJ_COLLISION_INTR_MIR     (0x10000000Lu)
#define Sensor_ADC_INJ_SATURATE_INTR_MIR      (0x20000000Lu)
#define Sensor_ADC_INJ_RANGE_INTR_MIR         (0x40000000Lu)
#define Sensor_ADC_INJ_EOC_INTR_MIR           (0x80000000Lu)

/* defines for MUX_SWITCH0 register */
#define Sensor_ADC_MUX_FW_VSSA_VMINUS         (0x00010000Lu)

/* defines for PUMP_CTRL register */
#define Sensor_ADC_PUMP_CTRL_ENABLED          (0x80000000Lu)

/* additional defines for channelsConfig parameter */
#define Sensor_ADC_IS_SATURATE_EN_MASK        (0x00000001Lu)
#define Sensor_ADC_IS_RANGE_CTRL_EN_MASK      (0x00000002Lu)

/* defines for WOUNDING register */
#define Sensor_ADC_WOUNDING_12BIT             (0x00000000Lu)
#define Sensor_ADC_WOUNDING_10BIT             (0x00000001Lu)
#define Sensor_ADC_WOUNDING_8BIT              (0x00000002Lu)

/* Trim value based on characterization */
#define Sensor_ADC_TRIM_COEF                  (2u)

#if(Sensor_ADC_MAX_RESOLUTION == Sensor_ADC_RESOLUTION_10)
    #define Sensor_ADC_ALT_WOUNDING           Sensor_ADC_WOUNDING_10BIT
#else
    #define Sensor_ADC_ALT_WOUNDING           Sensor_ADC_WOUNDING_8BIT
#endif /* Sensor_ADC_MAX_RESOLUTION == Sensor_ADC_RESOLUTION_10 */

#if(Sensor_ADC_DEFAULT_VREF_SEL == Sensor_ADC__VDDA_2)
    #define Sensor_ADC_DEFAULT_VREF_SOURCE    Sensor_ADC_VREF_VDDA_2
#elif(Sensor_ADC_DEFAULT_VREF_SEL == Sensor_ADC__VDDA)
    #define Sensor_ADC_DEFAULT_VREF_SOURCE    Sensor_ADC_VREF_VDDA
#elif(Sensor_ADC_DEFAULT_VREF_SEL == Sensor_ADC__INTERNAL1024)
    #define Sensor_ADC_DEFAULT_VREF_SOURCE    Sensor_ADC_VREF_INTERNAL1024
#elif(Sensor_ADC_DEFAULT_VREF_SEL == Sensor_ADC__INTERNAL1024BYPASSED)
    #define Sensor_ADC_DEFAULT_VREF_SOURCE    Sensor_ADC_VREF_INTERNAL1024BYPASSED
#elif(Sensor_ADC_DEFAULT_VREF_SEL == Sensor_ADC__INTERNALVREF)
    #define Sensor_ADC_DEFAULT_VREF_SOURCE    Sensor_ADC_VREF_INTERNALVREF
#elif(Sensor_ADC_DEFAULT_VREF_SEL == Sensor_ADC__INTERNALVREFBYPASSED)
    #define Sensor_ADC_DEFAULT_VREF_SOURCE    Sensor_ADC_VREF_INTERNALVREFBYPASSED
#elif(Sensor_ADC_DEFAULT_VREF_SEL == Sensor_ADC__VDDA_2BYPASSED)
    #define Sensor_ADC_DEFAULT_VREF_SOURCE    Sensor_ADC_VREF_VDDA_2BYPASSED
#else
    #define Sensor_ADC_DEFAULT_VREF_SOURCE    Sensor_ADC_VREF_EXTERNAL
#endif /* Sensor_ADC_DEFAULT_VREF_SEL == Sensor_ADC__VDDA_2 */

#if(Sensor_ADC_DEFAULT_NEG_INPUT_SEL == Sensor_ADC__VSS)
    /* Connect NEG input of SARADC to VSSA close to the SARADC for single channel mode */
    #if(Sensor_ADC_TOTAL_CHANNELS_NUM == 1u)
        #define Sensor_ADC_DEFAULT_SE_NEG_INPUT    Sensor_ADC_NEG_VSSA
    #else
        #define Sensor_ADC_DEFAULT_SE_NEG_INPUT    Sensor_ADC_NEG_VSSA_KELVIN
    #endif /* (Sensor_ADC_TOTAL_CHANNELS_NUM == 1u) */
    /* Do not connect VSSA to VMINUS when one channel in differential mode used */
    #if((Sensor_ADC_TOTAL_CHANNELS_NUM == 1u) && (Sensor_ADC_CHANNELS_MODE != 0u))
        #define Sensor_ADC_DEFAULT_MUX_SWITCH0     0u
    #else    /* miltiple channels or one single channel */
        #define Sensor_ADC_DEFAULT_MUX_SWITCH0     Sensor_ADC_MUX_FW_VSSA_VMINUS
    #endif /* (Sensor_ADC_TOTAL_CHANNELS_NUM == 1u) */
#elif(Sensor_ADC_DEFAULT_NEG_INPUT_SEL == Sensor_ADC__VREF)
    /* Do not connect VNEG to VREF when one channel in differential mode used */
    #if((Sensor_ADC_TOTAL_CHANNELS_NUM == 1u) && (Sensor_ADC_CHANNELS_MODE != 0u))
        #define Sensor_ADC_DEFAULT_SE_NEG_INPUT    0u
    #else    /* miltiple channels or one single channel */
        #define Sensor_ADC_DEFAULT_SE_NEG_INPUT    Sensor_ADC_NEG_VREF
    #endif /* (Sensor_ADC_TOTAL_CHANNELS_NUM == 1u) */
    #define Sensor_ADC_DEFAULT_MUX_SWITCH0     0u
#elif (Sensor_ADC_SINGLE_PRESENT != 0u)
    #define Sensor_ADC_DEFAULT_SE_NEG_INPUT    Sensor_ADC_NEG_OTHER
    #define Sensor_ADC_DEFAULT_MUX_SWITCH0     0u
#else
    #define Sensor_ADC_DEFAULT_SE_NEG_INPUT    0u
    #define Sensor_ADC_DEFAULT_MUX_SWITCH0     0u
#endif /* Sensor_ADC_DEFAULT_NEG_INPUT_SEL == Sensor_ADC__VREF */

/* If the SAR is configured for multiple channels, always set SAR_HW_CTRL_NEGVREF to 1 */
#if(Sensor_ADC_TOTAL_CHANNELS_NUM == 1u)
    #define Sensor_ADC_DEFAULT_HW_CTRL_NEGVREF 0u
#else
    #define Sensor_ADC_DEFAULT_HW_CTRL_NEGVREF Sensor_ADC_SAR_HW_CTRL_NEGVREF
#endif /* (Sensor_ADC_TOTAL_CHANNELS_NUM == 1u) */


#if(Sensor_ADC_DEFAULT_ALT_RESOLUTION_SEL == Sensor_ADC__RES8)
    #define Sensor_ADC_DEFAULT_ALT_RESOLUTION     (Sensor_ADC_ALT_RESOLUTION_8BIT)
    #define Sensor_ADC_DEFAULT_MAX_WRK_ALT        (Sensor_ADC_SAR_WRK_MAX_8BIT)
#else
    #define Sensor_ADC_DEFAULT_ALT_RESOLUTION     (Sensor_ADC_ALT_RESOLUTION_10BIT)
    #define Sensor_ADC_DEFAULT_MAX_WRK_ALT        (Sensor_ADC_SAR_WRK_MAX_10BIT)
#endif /* End Sensor_ADC_DEFAULT_ALT_RESOLUTION_SEL == Sensor_ADC__RES8 */

#if(Sensor_ADC_DEFAULT_JUSTIFICATION_SEL == Sensor_ADC__RIGHT)
    #define Sensor_ADC_DEFAULT_JUSTIFICATION  Sensor_ADC_DATA_ALIGN_RIGHT
#else
    #define Sensor_ADC_DEFAULT_JUSTIFICATION  Sensor_ADC_DATA_ALIGN_LEFT
#endif /* Sensor_ADC_DEFAULT_JUSTIFICATION_SEL == Sensor_ADC__RIGHT */

#if(Sensor_ADC_DEFAULT_DIFF_RESULT_FORMAT_SEL == Sensor_ADC__FSIGNED)
    #define Sensor_ADC_DEFAULT_DIFF_RESULT_FORMAT Sensor_ADC_DIFF_SIGNED_RESULT
#else
    #define Sensor_ADC_DEFAULT_DIFF_RESULT_FORMAT Sensor_ADC_DIFF_UNSIGNED_RESULT
#endif /* Sensor_ADC_DEFAULT_DIFF_RESULT_FORMAT_SEL == Sensor_ADC__FSIGNED */

#if(Sensor_ADC_DEFAULT_SE_RESULT_FORMAT_SEL == Sensor_ADC__FSIGNED)
    #define Sensor_ADC_DEFAULT_SE_RESULT_FORMAT Sensor_ADC_SE_SIGNED_RESULT
#else
    #define Sensor_ADC_DEFAULT_SE_RESULT_FORMAT Sensor_ADC_SE_UNSIGNED_RESULT
#endif /* Sensor_ADC_DEFAULT_SE_RESULT_FORMAT_SEL == Sensor_ADC__FSIGNED */

#if(Sensor_ADC_DEFAULT_SAMPLE_MODE_SEL == Sensor_ADC__FREERUNNING)
    #define Sensor_ADC_DSI_TRIGGER        0u
#else /* Firmware trigger */
    #define Sensor_ADC_DSI_TRIGGER        (Sensor_ADC_DSI_TRIGGER_EN | Sensor_ADC_DSI_SYNC_TRIGGER)
#endif /* End Sensor_ADC_DEFAULT_SAMPLE_MODE == Sensor_ADC__FREERUNNING */

#if(Sensor_ADC_INJ_CHANNEL_ENABLED)
    #define Sensor_ADC_SAR_INTR_MASK      (Sensor_ADC_EOS_MASK | Sensor_ADC_INJ_EOC_MASK)
#else
    #define Sensor_ADC_SAR_INTR_MASK      (Sensor_ADC_EOS_MASK)
#endif /* Sensor_ADC_INJ_CHANNEL_ENABLED*/

#if(Sensor_ADC_DEFAULT_AVG_MODE == Sensor_ADC__FIXEDRESOLUTION)
    #define Sensor_ADC_AVG_SHIFT_MODE     Sensor_ADC_AVG_SHIFT
#else
    #define Sensor_ADC_AVG_SHIFT_MODE     0u
#endif /* End Sensor_ADC_DEFAULT_AVG_MODE */

#define Sensor_ADC_COMPARE_MODE           (uint32)((uint32)(Sensor_ADC_DEFAULT_COMPARE_MODE) \
                                                << Sensor_ADC_CMP_OFFSET)

#if(Sensor_ADC_TOTAL_CHANNELS_NUM > 1u)
    #define Sensor_ADC_DEFAULT_SWITCH_CONF    0u
#else /* Disable SAR sequencer from enabling routing switches in single channel mode */
    #define Sensor_ADC_DEFAULT_SWITCH_CONF    Sensor_ADC_SWITCH_DISABLE
#endif /* End Sensor_ADC_TOTAL_CHANNELS_NUM > 1 */

#define Sensor_ADC_DEFAULT_POWER \
       ((Sensor_ADC_NOMINAL_CLOCK_FREQ > (Sensor_ADC_MAX_FREQUENCY / 4)) ? Sensor_ADC_NORMAL_PWR : \
       ((Sensor_ADC_NOMINAL_CLOCK_FREQ > (Sensor_ADC_MAX_FREQUENCY / 8)) ? Sensor_ADC_HALF_PWR : \
                                                                                       Sensor_ADC_QUARTER_PWR))

#define Sensor_ADC_DEFAULT_CTRL_REG_CFG       (Sensor_ADC_DEFAULT_VREF_SOURCE \
                                                   | Sensor_ADC_DEFAULT_SE_NEG_INPUT \
                                                   | Sensor_ADC_DEFAULT_HW_CTRL_NEGVREF \
                                                   | Sensor_ADC_DEFAULT_POWER \
                                                   | Sensor_ADC_DSI_SYNC_CONFIG \
                                                   | Sensor_ADC_DEFAULT_SWITCH_CONF)

#define Sensor_ADC_DEFAULT_SAMPLE_CTRL_REG_CFG (Sensor_ADC_DEFAULT_DIFF_RESULT_FORMAT \
                                                    | Sensor_ADC_DEFAULT_SE_RESULT_FORMAT \
                                                    | Sensor_ADC_DEFAULT_JUSTIFICATION \
                                                    | Sensor_ADC_DEFAULT_ALT_RESOLUTION \
                                           | (uint8)(Sensor_ADC_DEFAULT_AVG_SAMPLES_NUM \
                                                   << Sensor_ADC_AVG_CNT_OFFSET) \
                                                    | Sensor_ADC_AVG_SHIFT_MODE \
                                                    | Sensor_ADC_DSI_TRIGGER \
                                                    | Sensor_ADC_EOS_DSI_OUT_EN)

#define Sensor_ADC_DEFAULT_RANGE_THRES_REG_CFG (Sensor_ADC_DEFAULT_LOW_LIMIT \
            | (uint32)((uint32)Sensor_ADC_DEFAULT_HIGH_LIMIT << Sensor_ADC_RANGE_HIGH_OFFSET))

#define Sensor_ADC_DEFAULT_SAMPLE_TIME01_REG_CFG (Sensor_ADC_DEFAULT_ACLKS_NUM \
            | (uint32)((uint32)Sensor_ADC_DEFAULT_BCLKS_NUM << Sensor_ADC_SAMPLE_TIME13_OFFSET))

#define Sensor_ADC_DEFAULT_SAMPLE_TIME23_REG_CFG (Sensor_ADC_DEFAULT_CCLKS_NUM \
            | (uint32)((uint32)Sensor_ADC_DEFAULT_DCLKS_NUM << Sensor_ADC_SAMPLE_TIME13_OFFSET))


#endif /* End CY_ADC_SAR_SEQ_Sensor_ADC_H */


/* [] END OF FILE */
