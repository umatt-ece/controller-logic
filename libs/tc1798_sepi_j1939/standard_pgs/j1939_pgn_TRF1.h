//-----------------------------------------------------------------------------
/*!
   \file
   \brief       Application specific J1939 PGN TRF1

   Defines the PGN Transmission Fluids 1

   \implementation
   project     J1939 Protocolstack
   copyright   STW (c) 2010
   license     use only under terms of contract / confidential

   created     03.09.2013  STW/J1939-PGen V1.00r0
   \endimplementation
*/
//------------------------------------------------------------------------------


#ifndef _J1939_PGN_TRF1_H_                // Avoid multiple/recursive inclusion
#define _J1939_PGN_TRF1_H_


// -- Includes ----------------------------------------------------------------
#include "stwtypes.h"
#include "j1939_pgn_types.h"

#if defined(__cplusplus) 
extern "C" {     // Make sure we have C-declarations in C++ programs
#endif


// -- Defines -----------------------------------------------------------------
#define J1939_PGN_TRF1       (uint32)65272U          // Transmission Fluids 1   TRF1

// -- Types -------------------------------------------------------------------
typedef struct
{
   T_J1939_PG_ctrl t_Ctrl; // control structure
   //unscaled SPNs
   uint8   u8_ClutchPressure;   // SPN 123:  1 Byte, 16kPa / bit
   uint8   u8_TransmissionOilLevel;   // SPN 124:  1 Byte, 0.4% / bit
   uint8   u8_TransmFilterDiffPres;   // SPN 126:  1 Byte, 2kPa / bit
   uint8   u8_TransmissionOilPressue;   // SPN 127:  1 Byte, 16kPa / bit
   uint8   u8_TransmOilLevelHighLow;   // SPN 3027: 1 Byte, 0.5L / bit
   uint8   u8_TransmOilLevelCountdownTimer;   // SPN 3028: 4 Bits
   uint8   u8_TransmOilLevelMeasurStatus;   // SPN 3026: 4 Bits
   uint16 u16_TransmOilTemperature;   // SPN 177:  2 Byte, (1/32)°C / bit
   //Scaled Versions
   uint16 u16_ClutchPressure_kPa;   // SPN 123:  [0 .. 4000]kPa
   uint16 u16_TransmissionOilLevel_permil;   // SPN 124:  [0 .. 1000]%%
   uint16 u16_TransmFilterDiffPres_kPa;   // SPN 126:  [0 .. 500]kPa
   uint16 u16_TransmissionOilPressue_kPa;   // SPN 127:  [0 .. 4000]kPa
   sint16 s16_TransmOilLevelHighLow_01L;   // SPN 3027: [-625 .. +625]0.1L
   sint16 s16_TransmOilTemperature_01degC;   // SPN 177:  [-2730 .. +17350]0.1°C
}
T_J1939_PGN_TRF1;   //struct for the PG Transmission Fluids 1


// -- Global Variables --------------------------------------------------------
extern const T_J1939_PGN_parameters gt_J1939_PGN_CFG_TRF1;   //this variable is used to describe the data which doesn't change in the run-time environment


// -- Function Prototypes -----------------------------------------------------


// -- Implementation ----------------------------------------------------------


#if defined(__cplusplus)
}                // Make sure we have C-declarations in C++ programs
#endif

#endif                // Avoid multiple/recursive inclusion

/*************************** End of file ****************************/
