//-----------------------------------------------------------------------------
/*!
   \file
   \brief       Application specific J1939 PGN RF

   Defines the PGN Retarder Fluids

   \implementation
   project     J1939 Protocolstack
   copyright   STW (c) 2010
   license     use only under terms of contract / confidential

   created     03.09.2013  STW/J1939-PGen V1.00r0
   \endimplementation
*/
//------------------------------------------------------------------------------


#ifndef _J1939_PGN_RF_H_                // Avoid multiple/recursive inclusion
#define _J1939_PGN_RF_H_


// -- Includes ----------------------------------------------------------------
#include "stwtypes.h"
#include "j1939_pgn_types.h"

#if defined(__cplusplus) 
extern "C" {     // Make sure we have C-declarations in C++ programs
#endif


// -- Defines -----------------------------------------------------------------
#define J1939_PGN_RF       (uint32)65275U          // Retarder Fluids   RF

// -- Types -------------------------------------------------------------------
typedef struct
{
   T_J1939_PG_ctrl t_Ctrl; // control structure
   //unscaled SPNs
   uint8   u8_HydraulicRetarderPressure;   // SPN 119: 1 Byte, 16kPa / bit
   uint8   u8_HydraulicRetarderOilTemp;   // SPN 120: 1 Byte, 1°C / bit
   uint8   u8_DrivelineRetarderOverheatIndicator;   // SPN 5346: 4 states/2 bit
   uint8   u8_RetarderCoolantOutletTemperature;   // SPN 5656: 1 deg C/bit, with offset: -40 C
   //Scaled Versions
   uint16 u16_HydraulicRetarderPres_kPa;   // SPN 119: [0 .. 4000]kPa
   sint16 s16_HydraulicRetarderOilTemp_degC;   // SPN 120: [-40 .. +210]°C
   sint16   s16_RetarderCoolantOutletTemperature_C;   // SPN 5656:  [-40 .. 210]_C
}
T_J1939_PGN_RF;   //struct for the PG Retarder Fluids


// -- Global Variables --------------------------------------------------------
extern const T_J1939_PGN_parameters gt_J1939_PGN_CFG_RF;   //this variable is used to describe the data which doesn't change in the run-time environment


// -- Function Prototypes -----------------------------------------------------


// -- Implementation ----------------------------------------------------------


#if defined(__cplusplus)
}                // Make sure we have C-declarations in C++ programs
#endif

#endif                // Avoid multiple/recursive inclusion

/*************************** End of file ****************************/
