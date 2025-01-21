//-----------------------------------------------------------------------------
/*!
   \internal
   \file       x_sys.h
   \brief      system functions

   \implementation
   project     project name
   copyright   STW (c) 1999-201x
   license     use only under terms of contract / confidential

   \created    29.06.2015  Herb
   \endimplementation
*/
//-----------------------------------------------------------------------------

#ifndef _X_SYS_H
#define _X_SYS_H

/* -- Includes ------------------------------------------------------------ */

#include "x_stdtypes.h"
#include "x_sys_adc.h"


#ifdef __cplusplus
extern "C" {
#endif

/**********************************************************
 * compiler check will be inserted here in post build step
 * do not edit!
 **********************************************************/
#if ((__GNUC__ != 4) || (__GNUC_MINOR__ != 6) || (__GNUC_PATCHLEVEL__ != 4))
   #error This Library should only be used with TRICORE GCC Compiler version 4.6.4
#endif
  

/* -- Defines ------------------------------------------------------------- */

#define X_SYS_SENSOR_SUPPLY_CH_MAX     (2u)           // max. number of sensor supply channels
#define X_SYS_SENSOR_SUPPLY_01         (0u)           // sensor supply output 1 (adjustable 5V...12V output)
#define X_SYS_SENSOR_SUPPLY_02         (1u)           // sensor supply output 2 (fixed 5V output)

#define X_SYS_LED_CH_MAX               (1u)           // max. number of user LED channels
#define X_SYS_LED_01                   (0u)           // user LED1
#define X_SYS_LED_COLOR_RED            (0u)           // LED color = pure red
#define X_SYS_LED_COLOR_ORANGE         (35u)          // LED color = orange
#define X_SYS_LED_COLOR_YELLOW         (70u)          // LED color = yellow
#define X_SYS_LED_COLOR_GREEN          (100u)         // LED color = pure green

#define X_SYS_TEMP_CH_MAX              (2u)           // max. number of temperature channels
#define X_SYS_TEMP_BOARD               (0u)           // get board temperature
#define X_SYS_TEMP_CPU                 (1u)           // get CPU temperature

#define X_SYS_CPUWD_OFF                (0xF0A5u)      // disable internal watchdog

// defines for t_MainboardInfo.u16_Version information
#define X_SYS_HW_VERSION_B             (0x0000u)      // 3CS B-step hardware
#define X_SYS_HW_VERSION_C             (0x0001u)      // 3CS C-step hardware
#define X_SYS_HW_VERSION_C1            (0x0002u)      // 3CS C1-step hardware

// defines for t_MainboardInfo.u16_Type information
#define X_SYS_HW_OPTION_ETH            (0x0001u)      // assembly option 'Ethernet'
#define X_SYS_HW_OPTION_RS232          (0x0002u)      // assembly option 'RS232' (i.e. no LIN)
#define X_SYS_HW_OPTION_CAN_4PIN       (0x0004u)      // assembly option 'CAN1 with 4 pins' (i.e. no CAN2)
#define X_SYS_HW_OPTION_CAN_WU         (0x0008u)      // assembly option 'CAN wakeup'

#define X_SYS_COMPONENT_LIBRARY        (0)            // API Version
#define X_SYS_COMPONENT_FLASH_LOADER   (1)            // FLASH LOADER Version
#define X_SYS_COMPONENT_EEPROM_MAPPING (2)            // EEPROM Mapping Version
#define X_SYS_COMPONENT_SSV            (3)            // SSV Version
#define X_SYS_COMPONENT_SSV_PROGRAM    (4)            // SSV Program Version (since SSV Version v2.07r0)
#define X_SYS_COMPONENT_MAINBOARD      (5)            // Mainboard HW version
#define X_SYS_COMPONENT_CPU            (6)            // TriCore CPU Version
#define X_SYS_COMPONENT_BOOTMANAGER    (7)            // Bootmanager Version
#define X_SYS_COMPONENT_CHANNEL_MAX    (8)

#define X_SYS_WAKEUP_KL15              (0x00000001u)  // ECU wakeup flag for wakeup via KL15
#define X_SYS_WAKEUP_CAN1              (0x00000002u)  // ECU wakeup flag for wakeup via CAN1


/*********************************************************************
 *  STW SEPI functions, data types and error codes are each          *
 *  placed into a separate namespace for C++.                        *
 *  The following #ifdef instruction will load either the standard   *
 *  C - API style or the C++ style with namespaces.                  *
 *********************************************************************/

#ifdef __cplusplus
namespace stw_sepi
{
   #include "./hpp/x_sys.hpp"
}
#else


/* -- Types --------------------------------------------------------------- */

typedef struct
{
   uint16 u16_Type;              // type information
   uint16 u16_Version;           // version information
} T_x_sys_info;

typedef struct                   // information about last CPU trap
{
   uint16   u16_Class;           // trap class
   uint16   u16_Id;              // trap ID
   uint32   u32_Address;         // address where this trap occurred (NULL = no trap)
} T_x_sys_trap;

typedef struct
{
   uint8  au8_SerialNumber[6];            // STW serial number BCD coded
   uint32 u32_ArticleNumber;              // STW article number
   charn  acn_DeviceID[17];               // name of ECU, max. 16 characters + zero-termination
   uint8  au8_CommissioningDate[3];       // date of first commissioning BCD: dd.mm.yy
   uint8  au8_LastTestDate[3];            // date of last ECU test BCD: dd.mm.yy
   charn  acn_CompanyID[6];               // company ID, max. 5 characters + zero-termination
   charn  acn_ArticleVersion[17];         // STW article version, max. 16 characters + zero-termination
   charn  acn_InternalSerialNumber[11];   // internal serial number, max. 10 characters + zero-termination
} T_x_sys_logistic_data;

typedef struct
{
   uint16 u16_Line;                       // instruction line, where the error happened
   sint16 s16_Error;                      // error that the instruction returned
} T_x_sys_init_err;

typedef struct
{
   uint32 u32_WakeupEvent;                // wakeup event that activated the ECU
   uint32 u32_WakeupFeedback;             // feedback of wakeup signals which are currently active
   uint32 u32_WakeupEnable;               // enabled wakeup sources
} T_x_sys_wakeup_status;

typedef struct
{
   T_x_sys_info            t_MainboardInfo;           // main board type and version information
   T_x_sys_info            t_CpuInfo;                 // CPU type and version information
   T_x_sys_info            t_SupervisorInfo;          // system supervisor type and version information
   T_x_sys_logistic_data   t_LogisticData;            // logistic data (usually from System EEPROM)
   uint16                  u16_CpuFreq;               // CPU clock frequency in MHz
   uint16                  u16_SysFreq;               // system (peripheral) clock frequency in MHz
   uint32                  u32_RamSize;               // RAM size in kbyte (external RAM)
   uint32                  u32_RomSize;               // ROM size in kbyte (external ROM)
   uint32                  u32_EepromSize;            // EEPROM size in byte
   uint32                  u32_HeapSize;              // heap size in byte
   uint32                  u32_HeapSizeInternal;      // internal heap size in byte
   uint32                  u32_LastReset;             // cause of last reset
   T_x_sys_trap            t_LastTrap;                // info: last trap, not handled by application
   T_x_sys_init_err        t_InitErr;                 // detailed error number set in case of a x_sys_init error
} T_x_sys_system_information;

typedef void (*PR_x_sys_OffReactionCallback)(const uint32 ou32_CallbackParameter);


/* -- Function Prototypes ------------------------------------------------- */

// ECU init
sint16 x_sys_init(T_x_sys_system_information* const opt_SysInfo);
// read system information
sint16 x_sys_get_system_information(T_x_sys_system_information * const opt_SysInfo);
// get system component type/version information
sint16 x_sys_get_component_info(const uint16 ou16_Component, T_x_sys_info * const opt_Info);
// get ECU wakeup status information
sint16 x_sys_get_wakeup_status(T_x_sys_wakeup_status * const opt_WakeupStatus);
// initialize ECU wakeup feature
sint16 x_sys_set_wakeup(const uint32 ou32_WakeupSource);
// install callback on ignition (KL15) signal off
sint16 x_sys_init_off_reaction(const uint32 ou32_CallbackParameter, const PR_x_sys_OffReactionCallback opr_OffCallback);

// shut down ECU
sint16 x_sys_close(void);
// force system reset initiated by TriCore CPU
void   x_sys_reset(void);
// reload CPU internal watchdog with timeout value in ms
sint16 x_sys_trigger_cpu_watchdog(const uint16 ou16_WDTimeout);
// lock all interrupt levels potentially used by application code
uint32 x_sys_enter_critical(void);
// unlock all interrupt levels potentially used by application code
void x_sys_leave_critical(const uint32 ou32_PreviousState);

// read ignition (KL15) signal
sint16 x_sys_get_ignition(uint8* const opu8_OnOff);
// set / clear power hold signal
sint16 x_sys_stay_alive(const uint8 ou8_OnOff);
// set ECU user LED
sint16 x_sys_set_led(const uint16 ou16_Channel, const uint8 ou8_OnOff, const uint16 ou16_Color);
// set ext. sensor supply in mV
sint16 x_sys_set_sensor_supply(const uint16 ou16_Channel, const sint32 os32_Voltage);
// read board or CPU temperature in x10 degree Celsius
sint16 x_sys_get_temperature(const uint16 ou16_Channel, sint16* const ops16_Value);

// read raw ADC value (not filtered) from channel ou16_Channel
sint16 x_sys_get_adc_raw_value(const uint16 ou16_Channel, uint16* const opu16_Value);
// read raw scaled ADC value (not filtered) from channel ou16_Channel
sint16 x_sys_get_adc_raw_value_scaled(const uint16 ou16_Channel, sint32* const ops32_Value);
// read ADC value (filtered) from channel ou16_Channel
sint16 x_sys_get_adc_value(const uint16 ou16_Channel, uint16* const opu16_Value);
// read scaled ADC value (filtered) from channel ou16_Channel
sint16 x_sys_get_adc_value_scaled(const uint16 ou16_Channel, sint32* const ops32_Value);
// set ADC channel filter behavior
sint16 x_sys_set_adc_filter(const uint16 ou16_Channel, const uint16 ou16_Filter);
// get ADC channel filter configuration
sint16 x_sys_get_adc_filter(const uint16 ou16_Channel, uint16* const opu16_Filter);

// read system time in milli seconds
uint32 x_sys_get_time_ms(void);
// read system time in micro seconds
uint64 x_sys_get_time_us(void);
// delay in micro seconds
void   x_sys_delay_us(const uint32 ou32_Delay_us);
// read 56bit system timer (resolution 20.0ns)
uint64 x_sys_get_timer(void);

// read module identifier input
sint16 x_sys_get_mid_input(uint16 * const opu16_Id);


#endif  //__cplusplus

#ifdef __cplusplus
} /* end of extern "C" */
#endif

#endif  /* _X_SYS_H */
