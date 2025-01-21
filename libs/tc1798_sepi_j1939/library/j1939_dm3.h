//-----------------------------------------------------------------------------
/*!
   \internal
   \file
   \brief       Handle DM3 datas

   Process DM3 sending and receiving.

   \implementation
   project     J1939 Protocolstack
   copyright   STW (c) 2010
   license     use only under terms of contract / confidential

   created     14.07.2010  STW/M.Greiner
   \endimplementation

   \internal
   \history
   Date(dd.mm.yyyy)   Author           Description
   14.07.2010         STW/M.Greiner    file created
   \endhistory
*/
//-----------------------------------------------------------------------------


#ifndef _J1939_DM3_H_                     // Avoid multiple/recursive inclusion
#define _J1939_DM3_H_


// -- Includes ----------------------------------------------------------------


#if defined(__cplusplus)
extern "C" {     // Make sure we have C-declarations in C++ programs
#endif


// -- Defines -----------------------------------------------------------------
#define J1939_DM3_PGN        (uint32)0xFECCU          // PGN for DM3


// -- Types -------------------------------------------------------------------

//-----------------------------------------------------------------------------
/*!
   \brief    Callback function for executed DM3 command

   If any DM3 request is received, the stack reset the DM2 datas in DTC list
   and after reseting the previous DTC info, call this user callback function.
   This allows the application to update the DTC list information in EEPROM
   if needed.

   \param[in]          opt_DtcListMng   identificate the DTC list which was updated

   \return
    -

   \created            16.01.2012       STW/M.Greiner

   \internal
   \history
   Date(dd.mm.yyyy)    Author           Description
   16.01.2012          STW/M.Greiner    function created
   \endhistory
*/
//-----------------------------------------------------------------------------
typedef void (*PR_J1939_DM3_rx)(const T_J1939_DM_dtc_tx_management* const opt_DtcListMng);


// -- Global Variables --------------------------------------------------------


// -- Function Prototypes -----------------------------------------------------
extern void J1939_dm3_tx_send_clear(const uint16 ou16_Channel, const uint8 ou8_SrcAddress,
                                    const uint8 ou8_DstAddress);
extern void J1939_dm3_rx_init_callback(const PR_J1939_DM3_rx opr_Callback);


// -- Implementation ----------------------------------------------------------


#if defined(__cplusplus)
}                // Make sure we have C-declarations in C++ programs
#endif

#endif                // Avoid multiple/recursive inclusion

/*************************** End of file ****************************/
