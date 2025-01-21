//-----------------------------------------------------------------------------
/*!
   \file
   \brief       Application specific J1939 PGN DD

   Defines the PGN Dash Display

   \implementation
   project     J1939 Protocolstack
   copyright   STW (c) 2010
   license     use only under terms of contract / confidential

   created     03.09.2013  STW/J1939-PGen V1.00r0
   \endimplementation
*/
//------------------------------------------------------------------------------


#ifndef _J1939_PGN_DD_H_                // Avoid multiple/recursive inclusion
#define _J1939_PGN_DD_H_


// -- Includes ----------------------------------------------------------------
#include "stwtypes.h"
#include "j1939_pgn_types.h"

#if defined(__cplusplus) 
extern "C" {     // Make sure we have C-declarations in C++ programs
#endif


// -- Defines -----------------------------------------------------------------
#define J1939_PGN_DD       (uint32)65276U          // Dash Display   DD

// -- Types -------------------------------------------------------------------
typedef struct
{
   T_J1939_PG_ctrl t_Ctrl; // control structure
   //unscaled SPNs
   uint8   u8_WasherFluidLevel;   // SPN 80:  1 Byte, 0.4% / bit
   uint8   u8_FuelLevel;   // SPN 96:  1 Byte, 0.4% / bit
   uint8   u8_FuelFilterDifferentialPressure;   // SPN 95:  1 Byte, 2kPa / bit
   uint8   u8_EngineOilFilterDiffPressure;   // SPN 99:  1 Byte, 0.5kPa / bit
   uint8   u8_FuelLevel2;   // SPN 38: 0.4 percent/bit
   uint16 u16_CargoAmbientTemperature;   // SPN 169: 2 Byte, (1/32)°C / bit
   //Scaled Versions
   uint16 u16_WasherFluidLevel_permil;   // SPN 80:  [0 .. 1000]%%
   uint16 u16_FuelLevel_permil;   // SPN 96:  [0 .. 1000]%%
   uint16 u16_FuelFilterDiffPres_kPa;   // SPN 95:  [0 .. 500]kPa
   uint16 u16_EngineOilFilterDiffPres_100Pa;   // SPN 99:  [0 .. 1250]100Pa
   uint16   u16_FuelLevel2_permil;   // SPN 38:  [0 .. 1000]_permil
   sint16 s16_CargoAmbientTemp_01degC;   // SPN 169: [-2730 .. +17350]0.1°C
}
T_J1939_PGN_DD;   //struct for the PG Dash Display


// -- Global Variables --------------------------------------------------------
extern const T_J1939_PGN_parameters gt_J1939_PGN_CFG_DD;   //this variable is used to describe the data which doesn't change in the run-time environment


// -- Function Prototypes -----------------------------------------------------


// -- Implementation ----------------------------------------------------------


#if defined(__cplusplus)
}                // Make sure we have C-declarations in C++ programs
#endif

#endif                // Avoid multiple/recursive inclusion

/*************************** End of file ****************************/
