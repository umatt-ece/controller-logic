//-----------------------------------------------------------------------------
/*!
   \file
   \brief       Application specific J1939 PGN IC1

   Defines the PGN Intake Exhaust Conditions 1

   \implementation
   project     J1939 Protocolstack
   copyright   STW (c) 2010
   license     use only under terms of contract / confidential

   created     03.09.2013  STW/J1939-PGen V1.00r0
   \endimplementation
*/
//------------------------------------------------------------------------------


#ifndef _J1939_PGN_IC1_H_                // Avoid multiple/recursive inclusion
#define _J1939_PGN_IC1_H_


// -- Includes ----------------------------------------------------------------
#include "stwtypes.h"
#include "j1939_pgn_types.h"

#if defined(__cplusplus) 
extern "C" {     // Make sure we have C-declarations in C++ programs
#endif


// -- Defines -----------------------------------------------------------------
#define J1939_PGN_IC1       (uint32)65270U          // Intake Exhaust Conditions 1   IC1

// -- Types -------------------------------------------------------------------
typedef struct
{
   T_J1939_PG_ctrl t_Ctrl; // control structure
   //unscaled SPNs
   uint8   u8_ParticulateTrapInletPressure;   // SPN 81:  1 Byte, 0.5kPa / bit
   uint8   u8_BoostPressure;   // SPN 102: 1 Byte, 2kPa / bit
   uint8   u8_IntakeManifold1Temperature;   // SPN 105: 1 Byte, 1°C / bit
   uint8   u8_AirInletPressure;   // SPN 106: 1 Byte, 2kPa / bit
   uint8   u8_AirFilterDifferentialPressure;   // SPN 107: 1 Byte, 0.5kPa / bit
   uint8   u8_CoolantFilterDifferentialPressure;   // SPN 112: 1 Byte, 0.5kPa / bit
   uint16 u16_ExhaustGasTemperature;   // SPN 173: 2 Byte, (1/32)°C / bit
   //Scaled Versions
   uint16 u16_ParticulateTrapInletPres_100Pa;   // SPN 81:  [0 .. 1250]100Pa
   uint16 u16_BoostPressure_kPa;   // SPN 102: [0 .. 500]kPa
   sint16 s16_IntakeManifold1Temperature_degC;   // SPN 105: [-40 .. +210]°C
   uint16 u16_AirInletPressure_kPa;   // SPN 106: [0 .. 500]kPa
   uint16 u16_AirFilterDifferentialPres_100Pa;   // SPN 107: [0 .. 1250]100Pa
   uint16 u16_CoolantFilterDiffPres_100Pa;   // SPN 112: [0 .. 1250]100Pa
   sint16 s16_ExhaustGasTemperature_01degC;   // SPN 173: [-2730 .. +17350]0.1°C
}
T_J1939_PGN_IC1;   //struct for the PG Intake Exhaust Conditions 1


// -- Global Variables --------------------------------------------------------
extern const T_J1939_PGN_parameters gt_J1939_PGN_CFG_IC1;   //this variable is used to describe the data which doesn't change in the run-time environment


// -- Function Prototypes -----------------------------------------------------


// -- Implementation ----------------------------------------------------------


#if defined(__cplusplus)
}                // Make sure we have C-declarations in C++ programs
#endif

#endif                // Avoid multiple/recursive inclusion

/*************************** End of file ****************************/
