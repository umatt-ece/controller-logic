//-----------------------------------------------------------------------------
/*!
   \file
   \brief       Application specific J1939 PGN CCVS

   Defines the PGN Cruise Control Vehicle Speed 1

   \implementation
   project     J1939 Protocolstack
   copyright   STW (c) 2010
   license     use only under terms of contract / confidential

   created     03.09.2013  STW/J1939-PGen V1.00r0
   \endimplementation
*/
//------------------------------------------------------------------------------


#ifndef _J1939_PGN_CCVS_H_                // Avoid multiple/recursive inclusion
#define _J1939_PGN_CCVS_H_


// -- Includes ----------------------------------------------------------------
#include "stwtypes.h"
#include "j1939_pgn_types.h"

#if defined(__cplusplus) 
extern "C" {     // Make sure we have C-declarations in C++ programs
#endif


// -- Defines -----------------------------------------------------------------
#define J1939_PGN_CCVS       (uint32)65265U          // Cruise Control Vehicle Speed 1   CCVS

// -- Types -------------------------------------------------------------------
typedef struct
{
   T_J1939_PG_ctrl t_Ctrl; // control structure
   //unscaled SPNs
   uint8   u8_TwoSpeedAxleSwitch;   // SPN 69:   2 Bits
   uint8   u8_ParkingBrakeSwitch;   // SPN 70: 4 states/2 bit
   uint8   u8_CruiseControlPauseSwitch;   // SPN 1633: 2 Bits
   uint8   u8_ParkBrakeReleaseInhibitRequest;   // SPN 3807: 4 states/2 bit
   uint8   u8_CruiseControlActive;   // SPN 595:  2 Bits
   uint8   u8_CruiseControlEnableSwitch;   // SPN 596:  2 Bits
   uint8   u8_BrakeSwitch;   // SPN 597:  2 Bits
   uint8   u8_ClutchSwitch;   // SPN 598:  2 Bits
   uint8   u8_CruiseControlSetSwitch;   // SPN 599:  2 Bits
   uint8   u8_CruiseControlCoastSwitch;   // SPN 600:  2 Bits
   uint8   u8_CruiseControlResumeSwitch;   // SPN 601:  2 Bits
   uint8   u8_CruiseControlAccelerateSwitch;   // SPN 602:  2 Bits
   uint8   u8_CruiseControlSetSpeed;   // SPN 86:   1 Byte, (1km/h) / bit
   uint8   u8_PTOState;   // SPN 976:  5 Bits
   uint8   u8_CruiseControlStates;   // SPN 527:  3 Bits
   uint8   u8_IdleIncrementSwitch;   // SPN 968:  2 Bits
   uint8   u8_IdleDecrementSwitch;   // SPN 967:  2 Bits
   uint8   u8_EngineTestModeSwitch;   // SPN 966:  2 Bits
   uint8   u8_EngineShutdownOverrideSwitch;   // SPN 1237: 2 Bits
   uint16 u16_WheelBasedVehicleSpeed;   // SPN 84:   2 Byte, ((1/256)km/h) / bit
   //Scaled Versions
   uint16 u16_WheelBasedVehicleSpeed_10mperh;   // SPN 84:   [0 .. 25099]10m/h
}
T_J1939_PGN_CCVS;   //struct for the PG Cruise Control Vehicle Speed 1


// -- Global Variables --------------------------------------------------------
extern const T_J1939_PGN_parameters gt_J1939_PGN_CFG_CCVS;   //this variable is used to describe the data which doesn't change in the run-time environment


// -- Function Prototypes -----------------------------------------------------


// -- Implementation ----------------------------------------------------------


#if defined(__cplusplus)
}                // Make sure we have C-declarations in C++ programs
#endif

#endif                // Avoid multiple/recursive inclusion

/*************************** End of file ****************************/
