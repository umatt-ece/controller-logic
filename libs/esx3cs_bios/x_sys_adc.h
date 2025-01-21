//-----------------------------------------------------------------------------
/*!
   \internal
   \file       x_sys_adc.h
   \brief      defines for ESX-3CS ADC channels

   \implementation
   project     project name
   copyright   STW (c) 1999-201x
   license     use only under terms of contract / confidential

   \created    03.04.2017  Dedler
   \endimplementation
*/
//-----------------------------------------------------------------------------

#ifndef _X_SYS_ADC_H
#define _X_SYS_ADC_H

#ifdef __cplusplus
extern "C" {
#endif


/* -- Defines ------------------------------------------------------------- */

#define X_SYS_ADC_CH_MAX         (66U)           // max. number of ADC channels

// analog channels for ESX-3CS:
// ADC0
#define X_SYS_ADC_UI_IN_05        (0U)           // analog input from X_IN_05 / IACV1 (0..12V or 0..25mA)
#define X_SYS_ADC_UI_IN_06        (1U)           // analog input from X_IN_06 / IACV2 (0..12V or 0..25mA)
#define X_SYS_ADC_U_8V5           (2U)           // voltage feedback internal 8.5V supply voltage
#define X_SYS_ADC_U_6V            (3U)           // voltage feedback internal 6V supply voltage
#define X_SYS_ADC_U_IN_09         (4U)           // voltage input from X_IN_09 / IDA5V1 (0..5V)
#define X_SYS_ADC_U_IN_10         (5U)           // voltage input from X_IN_10 / IDA5V2 (0..5V)
#define X_SYS_ADC_U_IN_11         (6U)           // voltage input from X_IN_11 / IDA5V3 (0..5V)
#define X_SYS_ADC_U_IN_12         (7U)           // voltage input from X_IN_12 / IDA5V4 (0..5V)
#define X_SYS_ADC_I_OUT_10        (8U)           // current feedback from X_OUT_10 / OPL4A2
#define X_SYS_ADC_U_UC1           (9U)           // voltage feedback UB1 power supply internal, after safety relay
#define X_SYS_ADC_U_IN_01        (10U)           // voltage input from X_IN_01 / IDA35V1 (0..35V)
#define X_SYS_ADC_U_IN_02        (11U)           // voltage input from X_IN_02 / IDA35V2 (0..35V)
#define X_SYS_ADC_U_IMID1        (12U)           // voltage feedback from module identifier input IMID1
#define X_SYS_ADC_U_IMID2        (13U)           // voltage feedback from module identifier input IMID2
#define X_SYS_ADC_U_OUT_11       (14U)           // voltage feedback from X_OUT_11 / OD2A1
#define X_SYS_ADC_U_OUT_12       (15U)           // voltage feedback from X_OUT_12 / OD2A2

// ADC1
#define X_SYS_ADC_U_OUT_13       (16U)           // voltage feedback from X_OUT_13 / OD2A3
#define X_SYS_ADC_U_OUT_14       (17U)           // voltage feedback from X_OUT_14 / OD2A4
#define X_SYS_ADC_UI_IN_07       (18U)           // analog input from X_IN_07 / IACV3 (0..12V or 0..25mA)
#define X_SYS_ADC_UI_IN_08       (19U)           // analog input from X_IN_08 / IACV4 (0..12V or 0..25mA)
#define X_SYS_ADC_I_OUT_01       (20U)           // current feedback from X_OUT_01 / OP2A1
#define X_SYS_ADC_I_OUT_02       (21U)           // current feedback from X_OUT_02 / OP2A2
#define X_SYS_ADC_I_OUT_03       (22U)           // current feedback from X_OUT_03 / OP2A3
#define X_SYS_ADC_I_OUT_04       (23U)           // current feedback from X_OUT_04 / OP2A4
#define X_SYS_ADC_I_OUT_05       (24U)           // current feedback from X_OUT_05 / OP2A5
#define X_SYS_ADC_I_OUT_06       (25U)           // current feedback from X_OUT_06 / OP2A6
#define X_SYS_ADC_I_OUT_07       (26U)           // current feedback from X_OUT_07 / OP2A7
#define X_SYS_ADC_I_OUT_08       (27U)           // current feedback from X_OUT_08 / OP2A8
#define X_SYS_ADC_U_OUT_15       (28U)           // voltage feedback from X_OUT_15 / OAV10V
#define X_SYS_ADC_U_UB1          (29U)           // voltage feedback UB power supply
#define X_SYS_ADC_U_13V5         (30U)           // voltage feedback internal 13.5V supply voltage
#define X_SYS_ADC_U_UF           (31U)           // voltage feedback UE power supply internal, after KL15 power switch

// ADC2
#define X_SYS_ADC_U_IN_03        (32U)           // voltage input from X_IN_03 / IDA35V3 (0..35V)
#define X_SYS_ADC_U_IN_04        (33U)           // voltage input from X_IN_04 / IDA35V4 (0..35V)
#define X_SYS_ADC_U_MINUS_2V     (34U)           // voltage feedback internal -2V supply voltage
#define X_SYS_ADC_U_EXT_5V       (35U)           // voltage feedback 5V sensor supply
#define X_SYS_ADC_I_OUT_09       (36U)           // current feedback from X_OUT_09 / OPL4A1
#define X_SYS_ADC_U_EXT_ADJ      (37U)           // voltage feedback adjustable 5V...12V sensor supply
#define X_SYS_ADC_I_OUT_11       (38U)           // current feedback from X_OUT_11 / OD2A1
#define X_SYS_ADC_I_OUT_12       (39U)           // current feedback from X_OUT_12 / OD2A2
#define X_SYS_ADC_I_OUT_13       (40U)           // current feedback from X_OUT_13 / OD2A3
#define X_SYS_ADC_I_OUT_14       (41U)           // current feedback from X_OUT_14 / OD2A4
#define X_SYS_ADC_U_IN_13        (42U)           // analog input from X_IN_13 / IDA5V5 (0..5V)
#define X_SYS_ADC_U_IN_14        (43U)           // analog input from X_IN_14 / IDA5V6 (0..5V)
#define X_SYS_ADC_U_IN_15        (44U)           // analog input from X_IN_15 / IDA5V7 (0..5V)
#define X_SYS_ADC_U_IN_16        (45U)           // analog input from X_IN_16 / IDA5V8 (0..5V)
#define X_SYS_ADC_U_22V          (46U)           // voltage feedback internal 22V supply voltage
#define X_SYS_ADC_U_3V3          (47U)           // voltage feedback internal 3.3V supply voltage

// ADC3
#define X_SYS_ADC_U_1V3          (48U)           // voltage feedback internal 1.3V supply voltage
#define X_SYS_ADC_U_IOFFS        (49U)           // voltage feedback internal current offset voltage
#define X_SYS_ADC_I_UB1          (50U)           // current feedback UB power supply (sum current at main switch)
#define X_SYS_ADC_U_OL_LIMIT     (51U)           // threshold for digital feedback of the outputs (OL = open load)
#define X_SYS_ADC_U_5V           (52U)           // voltage feedback internal 5V supply voltage (CAN, outputs)
#define X_SYS_ADC_TEMP_ECU       (53U)           // ECU board temperature signal
#define X_SYS_ADC_U_OC_LIMIT_HS  (54U)           // feedback for high side over current limit threshold
#define X_SYS_ADC_U_SSVREF       (55U)           // voltage feedback internal SSV reference voltage
#define X_SYS_ADC_U_OUT_09       (56U)           // voltage feedback from X_OUT_09 / OPL4A1
#define X_SYS_ADC_U_OUT_10       (57U)           // voltage feedback from X_OUT_10 / OPL4A2
#define X_SYS_ADC_U_OC_LIMIT_LS  (58U)           // feedback for low side over current limit threshold
#define X_SYS_ADC_U_5V_TRAC      (59U)           // voltage feedback for internal 5V supply voltage (TriCore, OAV10V)
#define X_SYS_ADC_U_LIN_SUPPLY   (60U)           // voltage feedback for LIN power supply
// X_SYS_ADC_SPARE1              (61U)              unused ADC channel, connected to GND
// X_SYS_ADC_SPARE2              (62U)              unused ADC channel, connected to GND
// X_SYS_ADC_SPARE3              (63U)              unused ADC channel, connected to GND

// other analog inputs
#define X_SYS_ADC_TEMP_CPU       (64U)            // CPU die temperature signal
#define X_SYS_ADC_NULL           (65U)            // virtual ADC channel, returns zero


#ifdef __cplusplus
} /* end of extern "C" */
#endif

#endif  /* _X_SYS_ADC_H */
