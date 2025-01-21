//-----------------------------------------------------------------------------
/*!
   \file        x_lin_types.h
   \brief       definition of common data types for LIN master communication

   \implementation
   project     project name
   copyright   STW (c) 1999-201x
   license     use only under terms of contract / confidential

   created     04.07.2017  STW/T.Dedler
   \endimplementation
*/

#ifndef _X_LIN_TYPES_H
#define _X_LIN_TYPES_H

/* -- Includes ------------------------------------------------------------ */
#include "stwtypes.h"


#ifdef __cplusplus
extern "C" {
#endif


/* -- Defines ------------------------------------------------------------- */
// LIN Service Types (T_x_lin_service::u8_ServiceType)
#define X_LIN_SERVICE_TYPE_RX                (0)
#define X_LIN_SERVICE_TYPE_TX                (1)
#define X_LIN_SERVICE_TYPE_TX_WAKEUP         (2)

// LIN Checksum Types (T_x_lin_service::u8_ChecksumType)
#define X_LIN_CHECKSUM_TYPE_CLASSIC          (0)
#define X_LIN_CHECKSUM_TYPE_ENHANCED         (1)

// LIN Service Status (T_x_lin_service::u16_Status)
#define X_LIN_SERVICE_STATUS_OK              (0)  //!< LIN request sent successfully
#define X_LIN_SERVICE_STATUS_TIMEOUT_ERR     (1)  //!< LIN request failed with timeout
#define X_LIN_SERVICE_STATUS_CHECKSUM_ERR    (2)  //!< LIN request failed with checksum error
#define X_LIN_SERVICE_STATUS_ECHO_ERR        (3)  //!< LIN request failed because of wrong echo
#define X_LIN_SERVICE_STATUS_HW_ERR          (4)  //!< LIN request failed because of communication errors

// LIN Bus States (T_x_lin_status::u8_BusState)
#define X_LIN_BUS_STATE_UNINITIALIZED        (0x00u)
#define X_LIN_BUS_STATE_ACTIVE               (0x01u)
#define X_LIN_BUS_STATE_SLEEP                (0x02u)
#define X_LIN_BUS_STATE_SHUTDOWN             (0x03u)


/* -- Types --------------------------------------------------------------- */
/*********************************************************************
 *  STW SEPI functions, data types and error codes are each          *
 *  placed into a separate namespace for C++.                        *
 *  The following #ifdef instruction will load either the standard   *
 *  C - API style or the C++ style with namespaces.                  *
 *********************************************************************/
#ifdef __cplusplus
namespace stw_sepi
{
   #include "./hpp/x_lin_types.hpp"
}
#else


// LIN Message Payload
typedef struct
{
   uint8        u8_Id;            //!< LIN message Identifier (0...0x3F, without parity bits)
   uint8        u8_Dlc;           //!< Data Length Code (0..8)
   uint32       u32_Time;         //!< Timestamp = time in ms since last reset when service was finished
   uint8        au8_Data[8];      //!< Message data
} T_x_lin_msg;

// LIN Service Request Data
typedef struct
{
   T_x_lin_msg  t_Msg;                //!< LIN message payload
   uint8        u8_ServiceType;       //!< RX/TX/TX_WAKEUP message
   uint8        u8_ChecksumType;      //!< Classic (data bytes only) or Enhanced (data bytes plus PID)
   uint16       u16_MessageTimeoutMs; //!< Timeout in ms for the data field and checksum
   uint16       u16_Status;           //!< Service status (X_LIN_SERVICE_STATUS_...)
} T_x_lin_service;

//-----------------------------------------------------------------------------
/*!
   \brief   Signature of the callback function called for a LIN event (RX or TX event)

   \note
   The request callback is called when a LIN request is read from the FIFO for processing.
   For Tx Frames, this can be used to fill in the latest data into the LIN frame to be sent.

   The response callback is called after a LIN request has been processed and the response is available.
   The return value determines, if the message shall be put into the response FIFO

   \param[in]        ou32_CallbackParameter          User defined callback parameter
   \param[in]        ou16_Channel                    LIN bus channel number
   \param[in]        opt_Service                     LIN request data

   \return
   C_NO_ERROR  Store frame in response FIFO
   !C_NO_ERROR Discard received frame
*/
//-----------------------------------------------------------------------------
typedef sint16 (*PR_x_lin_EventCallback)(const uint32 ou32_CallbackParameter, const uint16 ou16_Channel,
                                         T_x_lin_service * const opt_Service);

//-----------------------------------------------------------------------------
/*!
   \brief   Signature of the callback function which is called when a wakeup signal has
            been received

   \param[in]        ou32_CallbackParameter          User defined callback parameter
   \param[in]        ou16_Channel                    LIN bus channel number
*/
//-----------------------------------------------------------------------------
typedef void (*PR_x_lin_WakeupCallback)(const uint32 ou32_CallbackParameter, const uint16 ou16_Channel);

// LIN Configuration
typedef struct
{
   uint32   u32_Bitrate;                        //!< Bitrate in bit/s, max 20000
   uint32   u32_InterFrameSpace;                //!< Minimum time between two frames in us
   uint16   u16_RequestBufSize;                 //!< Request buffer size in number of T_x_lin_service
   uint16   u16_ResponseBufSize;                //!< Response buffer size in number of T_x_lin_service
   uint32   u32_RequestCallbackParameter;       //!< Request callback parameter
   PR_x_lin_EventCallback pr_RequestCallback;   //!< Request callback function pointer
   uint32   u32_ResponseCallbackParameter;      //!< Response callback parameter
   PR_x_lin_EventCallback pr_ResponseCallback;  //!< Response callback function pointer
   uint32 u32_WakeupCallbackParameter;          //!< Wakeup callback parameter
   PR_x_lin_WakeupCallback pr_WakeupCallback;   //!< Wakeup callback function pointer
} T_x_lin_config;

// LIN Bus Status
typedef struct
{
   T_x_lin_config t_Config;         //!< Configuration parameters set with x_lin_init
   uint8    u8_OverflowCount;       //!< number of lost messages due to FIFO overflow since last status request
   uint8    u8_WakeupState;         //!< flag to indicate a received wakeup since last status request
   uint8    u8_BusState;            //!< Current bus state X_LIN_BUS_STATE_...
} T_x_lin_status;


/* -- Global Variables ---------------------------------------------------- */


/* -- Implementation ------------------------------------------------------ */


#endif  //__cplusplus

#ifdef __cplusplus
} /* end of extern "C" */
#endif

#endif // _X_LIN_TYPES_H

/*! \} */
