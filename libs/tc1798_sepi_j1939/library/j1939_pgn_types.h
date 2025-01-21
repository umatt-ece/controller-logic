//-----------------------------------------------------------------------------
/*!
   \internal
   \file
   \brief       J1939 PGN configuration module

   Define the Pararameter Groups elements

   \implementation
   project     J1939 Protocolstack
   copyright   STW (c) 2010
   license     use only under terms of contract / confidential

   created     23.04.2010  STW/M.Greiner
   \endimplementation

   \internal
   \history
   Date(dd.mm.yyyy)   Author           Description
   23.04.2010         STW/M.Greiner    file created
   \endhistory
*/
//-----------------------------------------------------------------------------


#ifndef _J1939_PGN_CFG_H_                 // Avoid multiple/recursive inclusion
#define _J1939_PGN_CFG_H_


// -- Includes ----------------------------------------------------------------
#include "j1939_target.h"
#include "j1939_spn.h"

#if defined(__cplusplus)
extern "C" {     // Make sure we have C-declarations in C++ programs
#endif


// -- Defines -----------------------------------------------------------------


// -- Types -------------------------------------------------------------------
typedef struct
{
   uint32                                         u32_Pgn;         // the identification number of the PG
   uint8                                          u8_DefPriority;  // the PG default priority (only relevant for tx)
   uint16                                         u16_PgSize;      // size of the PG data buffer (most time 8 bytes)
   uint16                                         u16_StructSize;  // the size of the structure in application data pool
   uint16                                         u16_RxTimeout;   // the PG default timeout for receiving PGs [ms]
   uint16                                         u16_TxTimeout;   // the PG default transmit cycle time [ms]
   const T_J1939_SPN_description J1939_TRG_HUGE * pt_SpnsConfig;   // array with all defined SPNs for this PG
}
T_J1939_PGN_parameters;                                            // definition of each individual PG

typedef struct
{
   uint8 u8_ValidDataFlag;                            // for Rx PGs: TRUE if data received in the specified cycle time
                                                      //     Tx PGs: TRUE enable cyclic sending
   uint8 u8_NewDataFlag;                              // for Rx PGs: TRUE new data received (application must clear)
                                                      //     Tx PGs: TRUE trigger sending of non cyclic PGs (stack clear after each send)
}
T_J1939_PG_ctrl;                                      // control/state informations for PG



// -- Global Variables --------------------------------------------------------


// -- Function Prototypes -----------------------------------------------------


// -- Implementation ----------------------------------------------------------


#if defined(__cplusplus)
}                // Make sure we have C-declarations in C++ programs
#endif

#endif                // Avoid multiple/recursive inclusion

/*************************** End of file ****************************/
