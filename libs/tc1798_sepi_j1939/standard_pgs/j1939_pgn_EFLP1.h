//-----------------------------------------------------------------------------
/*!
   \file
   \brief       Application specific J1939 PGN EFLP1

   Defines the PGN Engine Fluid Level Pressure 1

   \implementation
   project     J1939 Protocolstack
   copyright   STW (c) 2010
   license     use only under terms of contract / confidential

   created     03.09.2013  STW/J1939-PGen V1.00r0
   \endimplementation
*/
//------------------------------------------------------------------------------


#ifndef _J1939_PGN_EFLP1_H_                // Avoid multiple/recursive inclusion
#define _J1939_PGN_EFLP1_H_


// -- Includes ----------------------------------------------------------------
#include "stwtypes.h"
#include "j1939_pgn_types.h"

#if defined(__cplusplus) 
extern "C" {     // Make sure we have C-declarations in C++ programs
#endif


// -- Defines -----------------------------------------------------------------
#define J1939_PGN_EFLP1       (uint32)65263U          // Engine Fluid Level Pressure 1   EFLP1

// -- Types -------------------------------------------------------------------
typedef struct
{
   T_J1939_PG_ctrl t_Ctrl; // control structure
   //unscaled SPNs
   uint8   u8_EngineFuelDelivPressure;   // SPN 94:  1 Byte, 4kPa / bit
   uint8   u8_EngineExtCcasePressure;   // SPN 22:  1 Byte, 50Pa / bit
   uint8   u8_EngineOilLevel;   // SPN 98:  1 Byte, 0.4% / bit
   uint8   u8_EngineOilPressure;   // SPN 100: 1 Byte, 4kPa / bit
   uint8   u8_EngineCoolantPressure;   // SPN 109: 1 Byte, 2kPa / bit
   uint8   u8_EngineCoolantLevel;   // SPN 111: 1 Byte, 0.4% / bit
   uint16 u16_EngineCcasePressure;   // SPN 101: 2 Byte, 1/128kPa / bit
   //Scaled Versions
   uint16 u16_EngineFuelDelivPressure_kPa;   // SPN 94:  [0 .. 1000]kPa
   uint16 u16_EngineExtCcasePressure_Pa;   // SPN 22:  [0 .. 12500]Pa
   uint16 u16_EngineOilLevel_permil;   // SPN 98:  [0 .. 1000]%%
   uint16 u16_EngineOilPressure_kPa;   // SPN 100: [0 .. 1000]kPa
   uint16 u16_EngineCoolantPressure_kPa;   // SPN 109: [0 .. 500]kPa
   uint16 u16_EngineCoolantLevel_permil;   // SPN 111: [0 .. 1000]%%
   sint16 s16_EngineCcasePressure_10Pa;   // SPN 101: [-25000 .. +25199]10Pa (dPa)
}
T_J1939_PGN_EFLP1;   //struct for the PG Engine Fluid Level Pressure 1


// -- Global Variables --------------------------------------------------------
extern const T_J1939_PGN_parameters gt_J1939_PGN_CFG_EFLP1;   //this variable is used to describe the data which doesn't change in the run-time environment


// -- Function Prototypes -----------------------------------------------------


// -- Implementation ----------------------------------------------------------


#if defined(__cplusplus)
}                // Make sure we have C-declarations in C++ programs
#endif

#endif                // Avoid multiple/recursive inclusion

/*************************** End of file ****************************/
