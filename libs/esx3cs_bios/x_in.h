//-----------------------------------------------------------------------------
/*!
   \internal
   \file       x_in.h
   \brief      input functions

   \implementation
   project     project name
   copyright   STW (c) 1999-201x
   license     use only under terms of contract / confidential

   \created    28.07.2015  Herb
   \endimplementation
*/
//-----------------------------------------------------------------------------

#ifndef _X_IN_H
#define _X_IN_H

/* -- Includes ------------------------------------------------------------ */

#include "x_stdtypes.h"


#ifdef __cplusplus
extern "C" {
#endif

/* -- Defines ------------------------------------------------------------- */

#define X_IN_CH_MAX                    (16u)     // number of main board inputs

// input group IDA35V supports digital inputs with frequency measurement, pulse counter,
// incremental decoder (dedicated pins), NAMUR compatible logic levels and error detection,
// programmable pull-up and pull-down resistors, analog voltage measurement with 35V range
#define X_IN_01                        (0u)      // input group IDA35V, incremental 1 A-signal, frequency avg 1
#define X_IN_02                        (1u)      // input group IDA35V, incremental 1 B-signal
#define X_IN_03                        (2u)      // input group IDA35V, incremental 2 A-signal, frequency avg 2
#define X_IN_04                        (3u)      // input group IDA35V, incremental 2 B-signal

// input group IACV supports analog current measurement 0..25mA or analog voltage measurement with 12V range
// the current or voltage measurement functionality is programmable
// digital input functionality is emulated by software (limited band width)
#define X_IN_05                        (4u)      // input group IACV
#define X_IN_06                        (5u)      // input group IACV
#define X_IN_07                        (6u)      // input group IACV
#define X_IN_08                        (7u)      // input group IACV

// input group IDA5V supports digital inputs with frequency measurement, pulse counter,
// SENT interface, 5V compatible logic levels, programmable pull-up resistors,
// analog voltage measurement with 5V range
#define X_IN_09                        (8u)      // input group IDA5V, SENT1
#define X_IN_10                        (9u)      // input group IDA5V, SENT2
#define X_IN_11                        (10u)     // input group IDA5V, SENT3
#define X_IN_12                        (11u)     // input group IDA5V, SENT4
#define X_IN_13                        (12u)     // input group IDA5V, SENT5
#define X_IN_14                        (13u)     // input group IDA5V, SENT6
#define X_IN_15                        (14u)     // input group IDA5V, SENT7
#define X_IN_16                        (15u)     // input group IDA5V, SENT8


#define X_IN_TYPE_DIGITAL              (0x0000u)   // input is digital type
#define X_IN_TYPE_EVENT_RISING         (0x0001u)   // input is EVENT type (rising edge)
#define X_IN_TYPE_EVENT_FALLING        (0x0002u)   // input is EVENT type (falling edge)
#define X_IN_TYPE_EVENT_BOTH           (0x0003u)   // input is EVENT type (both edges)
#define X_IN_TYPE_FREQUENCY            (0x0004u)   // input is frequency type (only for input group IDA35V and IDA5V)
#define X_IN_TYPE_INCREMENTAL          (0x0008u)   // input is incremental type (only dedicated pin pairs)
#define X_IN_TYPE_CURRENT              (0x0030u)   // input is current type (only for input group IACV)
#define X_IN_TYPE_VOLTAGE              (0x0040u)   // input is voltage type (voltage range depends on input group)
#define X_IN_TYPE_NAMUR                (0x0080u)   // connected sensor is NAMUR compliant and diagnosis will be enabled
                                                   // (will generate an error if voltage feedback is
                                                   // out of specified range during x_in_get_value call, IDA35V only)

#define X_IN_CIRCUIT_ACTIVE_HIGH       (0x0000u)   // input is active high
#define X_IN_CIRCUIT_ACTIVE_LOW        (0x0001u)   // input is active low

// note: using X_IN_CIRCUIT_ACTIVE_LOW on inputs of type X_IN_TYPE_INCREMENTAL
//       reverse the counting direction i.e. it has the same effect
//       as interchanging the A- and B-signal lines by software

#define X_IN_CIRCUIT_PULL_UP           (0x0002u)   // use pull up circuit
#define X_IN_CIRCUIT_NO_PULL_UP        (0x0000u)   // use no pull up circuit
#define X_IN_CIRCUIT_PULL_DOWN         (0x0004u)   // use pull down circuit
#define X_IN_CIRCUIT_NO_PULL_DOWN      (0x0000u)   // use no pull down circuit

#define X_IN_COUNTER_DIR_UP            (1)         // last incremental input count was upward
#define X_IN_COUNTER_DIR_DOWN          (0)         // last incremental input count was downward

#define X_IN_FREQ_AVG_SAMPLES_MIN      (1)         // min. number of samples for average calculation (no average)
#define X_IN_FREQ_AVG_SAMPLES_MAX      (56)        // max. number of samples for average calculation
#define X_IN_FREQ_AVG_MODE_EXCLUDE_MIN (0x0001u)   // exclude min. sample value for average calculation
#define X_IN_FREQ_AVG_MODE_EXCLUDE_MAX (0x0002u)   // exclude max. sample value for average calculation
#define X_IN_FREQ_AVG_MIN              (2500)      // min. frequency measurement limit in milli Hertz
#define X_IN_FREQ_AVG_MAX              (20000000)  // max. frequency measurement limit in milli Hertz

#define X_IN_ERROR_NONE                (0)         // NAMUR diagnosis error status: no error
#define X_IN_ERROR_SHORT_TO_GND        (1)         // NAMUR diagnosis error status: input short to GND detected
#define X_IN_ERROR_OPEN_CIRCUIT        (2)         // NAMUR diagnosis error status: open input circuit detected
#define X_IN_ERROR_SHORT_TO_UB         (3)         // NAMUR diagnosis error status: input short to +UB detected
#define X_IN_ERROR_INPUT_HW            (4)         // NAMUR diagnosis error status: input hardware error detected


/*********************************************************************
 *  STW SEPI functions, data types and error codes are each          *
 *  placed into a separate namespace for C++.                        *
 *  The following #ifdef instruction will load either the standard   *
 *  C - API style or the C++ style with namespaces.                  *
 *********************************************************************/

#ifdef __cplusplus
namespace stw_sepi
{
   #include "./hpp/x_in.hpp"
}
#else


/* -- Types --------------------------------------------------------------- */

typedef struct
{
   uint16   u16_InputType;       // input type configuration
   uint16   u16_InputCircuit;    // input circuit configuration
   uint16   u16_FilterConfig;    // configured filter value for digital debouncing or analog filtering
   uint16   u16_DigitalState;    // digital input state (not filtered)
   sint32   s32_ScaledValue;     // scaled analog value (not filtered)
   uint16   u16_AdcValue;        // analog value in 12bit ADC digits (not filtered)
   uint16   u16_Error;           // error status information, see defines X_IN_ERROR_...
} T_x_in_status;

typedef struct
{
   uint16 u16_AvgSamples;              // number of samples for average calculation [1 ... X_IN_FREQ_AVG_SAMPLES_MAX]
   uint16 u16_AvgMode;                 // average operation mode
   uint16 u16_FilterConfigUs;          // input debounce filter in micro seconds [0 ... 65535]
   uint16 u16_VirtualPeriodThreshold;  // virtual period threshold in per mil [1000 ... 65535]
                                       // u16_VirtualPeriodThreshold < 1000 => virtual period feature deactivated
   uint32 u32_MinFrequency;            // input min frequency measurement limit scaled in milli Hertz
   uint32 u32_MaxFrequency;            // input max frequency measurement limit scaled in milli Hertz
} T_x_t_in_freq_avg_config;


/* -- Types --------------------------------------------------------------- */

// event callback function prototype
typedef void (*PR_x_in_EventCallback)(const uint32 ou32_CallbackParameter, const uint16 ou16_Channel);


/* -- Function Prototypes ------------------------------------------------- */

sint16 x_in_init(const uint16 ou16_Channel, const uint16 ou16_Type, const uint16 ou16_FilterConfig,
                 const uint16 ou16_InputCircuit, const uint32 ou32_CallbackParameter,
                 const PR_x_in_EventCallback opr_EventCallback);
sint16 x_in_get_value(const uint16 ou16_Channel, sint32* const ops32_Value);
sint16 x_in_get_raw_value(const uint16 ou16_Channel, sint32* const ops32_Value);
sint16 x_in_get_status(const uint16 ou16_Channel, T_x_in_status* const opt_Status);
sint16 x_in_get_frequency(const uint16 ou16_Channel, uint32* const opu32_Frequency);
sint16 x_in_get_duty_cycle(const uint16 ou16_Channel, uint32* const opu32_DutyCycle);
sint16 x_in_get_counter(const uint16 ou16_Channel, sint32* const ops32_Counter);
sint16 x_in_set_counter(const uint16 ou16_Channel, const sint32 os32_Counter);
sint16 x_in_get_counter_direction(const uint16 ou16_Channel, uint8* const opu8_CntDir);
sint16 x_t_in_init_frequency_avg(const uint16 ou16_Channel, const T_x_t_in_freq_avg_config* const opt_Config);
sint16 x_t_in_get_frequency_avg(const uint16 ou16_Channel, uint32* const opu32_Frequency);


#endif  //__cplusplus

#ifdef __cplusplus
} /* end of extern "C" */
#endif

#endif  /* _X_IN_H */
