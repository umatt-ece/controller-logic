//-----------------------------------------------------------------------------
/*!
   \file
   \brief       Application specific J1939 PGN AMB

   Defines the PGN Ambient Conditions

   \implementation
   project     J1939 Protocolstack
   copyright   STW (c) 2010
   license     use only under terms of contract / confidential

   created     03.09.2013  STW/J1939-PGen V1.00r0
   \endimplementation
*/
//------------------------------------------------------------------------------


#ifndef _J1939_PGN_AMB_H_                // Avoid multiple/recursive inclusion
#define _J1939_PGN_AMB_H_


// -- Includes ----------------------------------------------------------------
#include "stwtypes.h"
#include "j1939_pgn_types.h"

#if defined(__cplusplus) 
extern "C" {     // Make sure we have C-declarations in C++ programs
#endif


// -- Defines -----------------------------------------------------------------
#define J1939_PGN_AMB       (uint32)65269U          // Ambient Conditions   AMB

// -- Types -------------------------------------------------------------------
typedef struct
{
   T_J1939_PG_ctrl t_Ctrl; // control structure
   //unscaled SPNs
   uint8   u8_BarometricPressure;   // SPN 108: 1 Byte, 0.5kPa / bit
   uint8   u8_AirInletTemperature;   // SPN 172: 1 Byte, 1°C / bit
   uint16 u16_CabInteriorTemperature;   // SPN 170: 2 Byte, 2 Byte, (1/32)°C / bit
   uint16 u16_AmbientAirTemperature;   // SPN 171: 2 Byte, 2 Byte, (1/32)°C / bit
   uint16 u16_RoadSurfaceTemperature;   // SPN 79:  2 Byte, 2 Byte, (1/32)°C / bit
   //Scaled Versions
   uint16 u16_BarometricPressure_100Pa;   // SPN 108: [0 .. 1250]100Pa
   sint16 s16_AirInletTemperature_degC;   // SPN 172: [-40 .. +210]°C
   sint16 s16_CabInteriorTemperature_01degC;   // SPN 170: [-2730 .. +17350]0.1°C
   sint16 s16_AmbientAirTemperature_01degC;   // SPN 171: [-2730 .. +17350]0.1°C
   sint16 s16_RoadSurfaceTemperature_01degC;   // SPN 79:  [-2730 .. +17350]0.1°C
}
T_J1939_PGN_AMB;   //struct for the PG Ambient Conditions


// -- Global Variables --------------------------------------------------------
extern const T_J1939_PGN_parameters gt_J1939_PGN_CFG_AMB;   //this variable is used to describe the data which doesn't change in the run-time environment


// -- Function Prototypes -----------------------------------------------------


// -- Implementation ----------------------------------------------------------


#if defined(__cplusplus)
}                // Make sure we have C-declarations in C++ programs
#endif

#endif                // Avoid multiple/recursive inclusion

/*************************** End of file ****************************/
