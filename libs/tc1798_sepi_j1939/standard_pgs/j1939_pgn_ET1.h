//-----------------------------------------------------------------------------
/*!
   \file
   \brief       Application specific J1939 PGN ET1

   Defines the PGN Engine Temperature 1

   \implementation
   project     J1939 Protocolstack
   copyright   STW (c) 2010
   license     use only under terms of contract / confidential

   created     03.09.2013  STW/J1939-PGen V1.00r0
   \endimplementation
*/
//------------------------------------------------------------------------------


#ifndef _J1939_PGN_ET1_H_                // Avoid multiple/recursive inclusion
#define _J1939_PGN_ET1_H_


// -- Includes ----------------------------------------------------------------
#include "stwtypes.h"
#include "j1939_pgn_types.h"

#if defined(__cplusplus) 
extern "C" {     // Make sure we have C-declarations in C++ programs
#endif


// -- Defines -----------------------------------------------------------------
#define J1939_PGN_ET1       (uint32)65262U          // Engine Temperature 1   ET1

// -- Types -------------------------------------------------------------------
typedef struct
{
   T_J1939_PG_ctrl t_Ctrl; // control structure
   //unscaled SPNs
   uint8   u8_EngineCoolantTemp;   // SPN 110:  1 Byte, 1°C / bit
   uint8   u8_FuelTemp;   // SPN 174:  1 Byte, 1°C / bit
   uint8   u8_EngineIntercoolerTemp;   // SPN 52:   1 Byte, 1°C / bit
   uint8   u8_EngIntercoolerThermostatOpn;   // SPN 1134: 1 Byte, 1 Byte, 0.4% / bit
   uint16 u16_EngineOilTemp1;   // SPN 175:  2 Byte, (1/32)°C / bit
   uint16 u16_TurboOilTemp;   // SPN 176:  2 Byte, (1/32)°C / bit
   //Scaled Versions
   sint16 s16_EngineCoolantTemp_degC;   // SPN 110:  [-40 .. +210]°C
   sint16 s16_FuelTemp_degC;   // SPN 174:  [-40 .. +210]°C
   sint16 s16_EngineIntercoolerTemp_degC;   // SPN 52:   [-40 .. +210]°C
   uint16 u16_EngIntercoolerThermostatOpn_permil;   // SPN 1134: [0 .. 1000]%%
   sint16 s16_EngineOilTemp1_01degC;   // SPN 175:  [-2730 .. +17350]0.1°C
   sint16 s16_TurboOilTemp_01degC;   // SPN 176:  [-2730 .. +17350]0.1°C
}
T_J1939_PGN_ET1;   //struct for the PG Engine Temperature 1


// -- Global Variables --------------------------------------------------------
extern const T_J1939_PGN_parameters gt_J1939_PGN_CFG_ET1;   //this variable is used to describe the data which doesn't change in the run-time environment


// -- Function Prototypes -----------------------------------------------------


// -- Implementation ----------------------------------------------------------


#if defined(__cplusplus)
}                // Make sure we have C-declarations in C++ programs
#endif

#endif                // Avoid multiple/recursive inclusion

/*************************** End of file ****************************/
