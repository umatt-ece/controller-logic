//-----------------------------------------------------------------------------
/*!
   \file
   \brief       Application specific J1939 PGN TI1

   Defines the PGN Aftertreatment 1 Diesel Exhaust Fluid Tank 1 Information

   \implementation
   project     J1939 Protocolstack
   copyright   STW (c) 2010
   license     use only under terms of contract / confidential

   created     03.09.2013  STW/J1939-PGen V1.00r0
   \endimplementation
*/
//------------------------------------------------------------------------------


#ifndef _J1939_PGN_TI1_H_                // Avoid multiple/recursive inclusion
#define _J1939_PGN_TI1_H_


// -- Includes ----------------------------------------------------------------
#include "stwtypes.h"
#include "j1939_pgn_types.h"

#if defined(__cplusplus) 
extern "C" {     // Make sure we have C-declarations in C++ programs
#endif


// -- Defines -----------------------------------------------------------------
#define J1939_PGN_TI1       (uint32)65110U          // Aftertreatment 1 Diesel Exhaust Fluid Tank 1 Information   TI1

// -- Types -------------------------------------------------------------------
typedef struct
{
   T_J1939_PG_ctrl t_Ctrl; // control structure
   //unscaled SPNs
   uint8   u8_CatalystTankLevel;   // SPN 1761: 1 Byte, 0.4% / bit
   uint8   u8_CatalystTankTemperature;   // SPN 3031: 1 Byte, 1°C / bit
   uint8   u8_CatalystTankLevelPreliminaryFMI;   // SPN 3532: 5 Bits
   uint8   u8_AftertreatmentSelectiveCatalyticReductionOperatorInducementActive;   // SPN 5245: 8 states/3 bit
   uint8   u8_Aftertreatment1DieselExhaustFluidTank1TemperaturePreliminaryFMI;   // SPN 4365: Binary
   uint8   u8_AftertreatmentSCROperatorInducementSeverity;   // SPN 5246: 8 states/3 bit
   uint8   u8_Aftertreatment1DieselExhaustFluidTankHeater;   // SPN 3363: 0.4 percent/bit
   uint8   u8_Aftertreatment1DieselExhaustFluidTank1HeaterPreliminaryFMI;   // SPN 4366: Binary
   uint16 u16_CatalystTankLevel2;   // SPN 3517: 2 Byte, 0.1mm / bit
   //Scaled Versions
   uint16 u16_CatalystTankLevel_permil;   // SPN 1761: [0 .. 1000]%%
   sint16 s16_CatalystTankTemperature_degC;   // SPN 3031: [-40 .. +210]°C
   uint16   u16_Aftertreatment1DieselExhaustFluidTankHeater_permil;   // SPN 3363:  [0 .. 1000]_permil
   uint16 u16_CatalystTankLevel2_01mm;   // SPN 3517: [0 .. +64255]0.1mm
}
T_J1939_PGN_TI1;   //struct for the PG Aftertreatment 1 Diesel Exhaust Fluid Tank 1 Information


// -- Global Variables --------------------------------------------------------
extern const T_J1939_PGN_parameters gt_J1939_PGN_CFG_TI1;   //this variable is used to describe the data which doesn't change in the run-time environment


// -- Function Prototypes -----------------------------------------------------


// -- Implementation ----------------------------------------------------------


#if defined(__cplusplus)
}                // Make sure we have C-declarations in C++ programs
#endif

#endif                // Avoid multiple/recursive inclusion

/*************************** End of file ****************************/
