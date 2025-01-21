//-----------------------------------------------------------------------------
/*!
   \file
   \brief       Application specific J1939 PGN EFLP12

   Defines the PGN Engine Fluid Level Pressure 12

   \implementation
   project     J1939 Protocolstack
   copyright   STW (c) 2010
   license     use only under terms of contract / confidential

   created     03.09.2013  STW/J1939-PGen V1.00r0
   \endimplementation
*/
//------------------------------------------------------------------------------


#ifndef _J1939_PGN_EFLP12_H_                // Avoid multiple/recursive inclusion
#define _J1939_PGN_EFLP12_H_


// -- Includes ----------------------------------------------------------------
#include "stwtypes.h"
#include "j1939_pgn_types.h"

#if defined(__cplusplus) 
extern "C" {     // Make sure we have C-declarations in C++ programs
#endif


// -- Defines -----------------------------------------------------------------
#define J1939_PGN_EFLP12       (uint32)64735U          // Engine Fluid Level Pressure 12   EFLP12

// -- Types -------------------------------------------------------------------
typedef struct
{
   T_J1939_PG_ctrl t_Ctrl; // control structure
   //unscaled SPNs
   uint8   u8_EngFuelDeliveryAbsolutePressure;   // SPN 5578: 1 Byte, 4kPa / bit
   uint8   u8_EngFilteredFuelDeliveryPressure;   // SPN 5579: 1 Byte, 4kPa / bit
   uint8   u8_EngFiltrdFuelDeliveryAbsolutePress;   // SPN 5580: 1 Byte, 4kPa / bit
   uint8   u8_EngFuelFilterDegradation;   // SPN 5584: 1 Byte, 1% / bit
   //Scaled Versions
   uint16 u16_EngFuelDeliveryAbsolutePressure_kPa;   // SPN 5578: [0 .. 1000]kPa
   uint16 u16_EngFilteredFuelDeliveryPressure_kPa;   // SPN 5579: [0 .. 1000]kPa
   uint16 u16_EngFiltrdFuelDeliveryAbsltPress_kPa;   // SPN 5580: [0 .. 1000]kPa
}
T_J1939_PGN_EFLP12;   //struct for the PG Engine Fluid Level Pressure 12


// -- Global Variables --------------------------------------------------------
extern const T_J1939_PGN_parameters gt_J1939_PGN_CFG_EFLP12;   //this variable is used to describe the data which doesn't change in the run-time environment


// -- Function Prototypes -----------------------------------------------------


// -- Implementation ----------------------------------------------------------


#if defined(__cplusplus)
}                // Make sure we have C-declarations in C++ programs
#endif

#endif                // Avoid multiple/recursive inclusion

/*************************** End of file ****************************/
