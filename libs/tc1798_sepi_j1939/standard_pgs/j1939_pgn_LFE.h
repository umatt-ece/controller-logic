//-----------------------------------------------------------------------------
/*!
   \file
   \brief       Application specific J1939 PGN LFE

   Defines the PGN Fuel Economy Liquid

   \implementation
   project     J1939 Protocolstack
   copyright   STW (c) 2010
   license     use only under terms of contract / confidential

   created     03.09.2013  STW/J1939-PGen V1.00r0
   \endimplementation
*/
//------------------------------------------------------------------------------


#ifndef _J1939_PGN_LFE_H_                // Avoid multiple/recursive inclusion
#define _J1939_PGN_LFE_H_


// -- Includes ----------------------------------------------------------------
#include "stwtypes.h"
#include "j1939_pgn_types.h"

#if defined(__cplusplus) 
extern "C" {     // Make sure we have C-declarations in C++ programs
#endif


// -- Defines -----------------------------------------------------------------
#define J1939_PGN_LFE       (uint32)65266U          // Fuel Economy Liquid   LFE

// -- Types -------------------------------------------------------------------
typedef struct
{
   T_J1939_PG_ctrl t_Ctrl; // control structure
   //unscaled SPNs
   uint8   u8_EngineThrottlePosition;   // SPN 51:  1 Byte,  0.4% / bit
   uint8   u8_EngineThrottleValve2Position;   // SPN 3673: 0.4 percent/bit
   uint16 u16_EngineFuelRate;   // SPN 183: 2 Byte, (0.05L / h) / bit
   uint16 u16_EngineInstantFuelEconomy;   // SPN 184: 2 Byte, (1000/512 m/L) / bit
   uint16 u16_EngineAverageFuelEconomy;   // SPN 185: 2 Byte, (1000/512 m/L) / bit
   //Scaled Versions
   uint16 u16_EngineThrottlePosition_permil;   //  SPN 51:  [0 .. 1000]%%
   uint16   u16_EngineThrottleValve2Position_permil;   // SPN 3673:  [0 .. 1000]_permil
   uint16 u16_EngineFuelRate_01Lperh;   // SPN 183: [0 .. 32127]0.1L/h
   uint16 u16_EngineInstantFuelEconomy_10mperL;   // SPN 184: [0 .. 12550]10m/L
   uint16 u16_EngineAverageFuelEconomy_10mperL;   // SPN 185: [0 .. 12550]10m/L
}
T_J1939_PGN_LFE;   //struct for the PG Fuel Economy Liquid


// -- Global Variables --------------------------------------------------------
extern const T_J1939_PGN_parameters gt_J1939_PGN_CFG_LFE;   //this variable is used to describe the data which doesn't change in the run-time environment


// -- Function Prototypes -----------------------------------------------------


// -- Implementation ----------------------------------------------------------


#if defined(__cplusplus)
}                // Make sure we have C-declarations in C++ programs
#endif

#endif                // Avoid multiple/recursive inclusion

/*************************** End of file ****************************/
