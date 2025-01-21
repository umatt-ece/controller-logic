//-----------------------------------------------------------------------------
/*!
   \internal
   \file       x_out.h
   \brief      output functions

   \implementation
   project     project name
   copyright   STW (c) 1999-201x
   license     use only under terms of contract / confidential

   \created    06.08.2015  Herb
   \endimplementation
*/
//-----------------------------------------------------------------------------

#ifndef _X_OUT_H
#define _X_OUT_H

/* -- Includes ------------------------------------------------------------ */

#include "x_stdtypes.h"
#include "x_out_relay.h"

#ifdef __cplusplus
extern "C" {
#endif


/* -- Defines ------------------------------------------------------------- */

#define X_OUT_CH_MAX                   (15u)       // number of main board outputs

#define X_OUT_01                       (0u)        // output group OP2A, high side PWM, current control
#define X_OUT_02                       (1u)        // output group OP2A, high side PWM, current control
#define X_OUT_03                       (2u)        // output group OP2A, high side PWM, current control
#define X_OUT_04                       (3u)        // output group OP2A, high side PWM, current control
#define X_OUT_05                       (4u)        // output group OP2A, high side PWM, current control
#define X_OUT_06                       (5u)        // output group OP2A, high side PWM, current control
#define X_OUT_07                       (6u)        // output group OP2A, high side PWM, current control
#define X_OUT_08                       (7u)        // output group OP2A, high side PWM, current control
#define X_OUT_09                       (8u)        // output group OPL4A, low side, PWM current control
#define X_OUT_10                       (9u)        // output group OPL4A, low side, PWM current control
#define X_OUT_11                       (10u)       // output group OD2A, high side, PWM
#define X_OUT_12                       (11u)       // output group OD2A, high side, PWM
#define X_OUT_13                       (12u)       // output group OD2A, high side, PWM
#define X_OUT_14                       (13u)       // output group OD2A, high side, PWM
#define X_OUT_15                       (14u)       // output group OAV10V, analog signal output

#define X_OUT_TYPE_DIGITAL             (0u)        // output is of digital type
#define X_OUT_TYPE_PWM                 (1u)        // output is of PWM type
#define X_OUT_TYPE_CONTROL_CURRENT     (2u)        // output is of type current control
#define X_OUT_TYPE_VOLTAGE             (3u)        // output is of type analog signal

#define X_OUT_STATE_OVERCURRENT        (0x0001u)   // output state: over current error flag
#define X_OUT_STATE_PWR_OVERVOLTAGE    (0x0002u)   // output state: power supply overvoltage
#define X_OUT_STATE_PWR_GND_ERROR      (0x0004u)   // output state: power supply GND offset to high (reserved)
#define X_OUT_STATE_PWR_OVERCURRENT    (0x0008u)   // output state: power supply over current
#define X_OUT_STATE_PWR_SSV_ERROR      (0x0010u)   // output state: SSV caused relay deactivation
#define X_OUT_STATE_DIGITAL_FB         (0x0100u)   // output state: digital feedback signal

#define X_OUT_EVENT_OVERCURRENT        (0u)        // output event: over current occurred
#define X_OUT_EVENT_RECOVERY           (1u)        // output event: over current recovery time elapsed

                                                         // set value for current controlled outputs:
#define X_OUT_VALUE_CONTROL_100_PERCENT   (0x7FFFFFFF)   // set output to 100% and disable control loop

/*********************************************************************
 *  STW SEPI functions, data types and error codes are each          *
 *  placed into a separate namespace for C++.                        *
 *  The following #ifdef instruction will load either the standard   *
 *  C - API style or the C++ style with namespaces.                  *
 *********************************************************************/

#ifdef __cplusplus
namespace stw_sepi
{
   #include "./hpp/x_out.hpp"
}
#else


/* -- Types --------------------------------------------------------------- */

typedef struct
{
   uint16   u16_OutputType;         // the configured output type
   sint32   s32_MaxValue;           // value that defines 100% output
   sint32   s32_OutValue;           // output value (depends on type)
   uint32   u32_OutFrequency;       // output frequency
   uint32   u32_SetTime;            // system time when output was set (milli seconds since system start)
   uint32   u32_OutState;           // output state (bit coded)
} T_x_out_status;

typedef struct
{
   sint32   s32_Setpoint;           // current control setpoint (also control start value)
   sint32   s32_P_Value;            // proportional gain in 0.001 KR
   sint16   s16_I_Value;            // integral time Ti in ms
   sint16   s16_D_Value;            // derivation time Td in ms
   sint16   s16_SampleTime;         // current control sample time T in ms
   sint16   s16_OutputLimitMin;     // minimum output duty cycle in 0.01%
   sint16   s16_OutputLimitMax;     // maximum output duty cycle in 0.01%
} T_x_out_pid_parameters;


/* -- Types --------------------------------------------------------------- */

// error callback function prototype
typedef void (*PR_x_out_ErrorCallback)(const uint32 ou32_CallbackParameter, const uint16 ou16_Channel,
                                       const uint16 ou16_Event);


/* -- Function Prototypes ------------------------------------------------- */

sint16 x_out_init(const uint16 ou16_Channel, const uint16 ou16_Type, const sint32 os32_MaxValue,
                  const uint32 ou32_CallbackParameter, const PR_x_out_ErrorCallback opr_ErrorCallback);
sint16 x_out_set_control_parameters(const uint16 ou16_Channel, const T_x_out_pid_parameters* const opt_Parameters);
sint16 x_out_get_control_parameters(const uint16 ou16_Channel, T_x_out_pid_parameters* const opt_Parameters);
sint16 x_out_set_value(const uint16 ou16_Channel, const sint32 os32_Value);
sint16 x_out_set_frequency(const uint16 ou16_Channel, const uint32 ou32_Frequency);
sint16 x_out_get_current(const uint16 ou16_Channel, sint32* const ops32_Current);
sint16 x_out_get_voltage(const uint16 ou16_Channel, sint32* const ops32_Voltage);
sint16 x_out_get_status(const uint16 ou16_Channel, T_x_out_status * const opt_Status);
sint16 x_out_reset_error(const uint16 ou16_Channel);
sint16 x_out_set_value_ramping(const uint16 ou16_Channel, const sint32 os32_Value,
                               const uint32 ou32_DeltaOutput, const uint32 ou32_DeltaTime);
sint16 x_t_out_init_group(const uint16 ou16_Channel, const uint32 ou32_Mask);
sint16 x_t_out_reset_group(const uint16 ou16_Channel);
sint16 x_t_out_set_dither(const uint16 ou16_Channel, uint16 ou16_DitherAmplidute);


#endif  //__cplusplus

#ifdef __cplusplus
} /* end of extern "C" */
#endif

#endif  /* _X_OUT_H */
