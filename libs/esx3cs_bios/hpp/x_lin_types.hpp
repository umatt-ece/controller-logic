//-----------------------------------------------------------------------------
/*!
   \file        x_lin_types.hpp
   \brief       CPP namespace extention for x_lin_types.h

   This header was automatically created. DO NOT EDIT!

   \implementation
   copyright   STW (c) 1999-20xx
   license     use only under terms of contract / confidential

   created     by hpp_generator.pl
   \endimplementation


   \internal
   \history
   Date(dd.mm.yyyy)  Author                Description
   \endhistory
*/
//-----------------------------------------------------------------------------

#ifndef __X_LIN_TYPES_HPP
#define __X_LIN_TYPES_HPP



// LIN Message Payload
typedef struct
{
   stw_types::uint8        u8_Id;            //!< LIN message Identifier (0...0x3F, without parity bits)
   stw_types::uint8        u8_Dlc;           //!< Data Length Code (0..8)
   stw_types::uint32       u32_Time;         //!< Timestamp = time in ms since last reset when service was finished
   stw_types::uint8        au8_Data[8];      //!< Message data
} T_x_lin_msg;

// LIN Service Request Data
typedef struct
{
   T_x_lin_msg  t_Msg;                //!< LIN message payload
   stw_types::uint8        u8_ServiceType;       //!< RX/TX/TX_WAKEUP message
   stw_types::uint8        u8_ChecksumType;      //!< Classic (data bytes only) or Enhanced (data bytes plus PID)
   stw_types::uint16       u16_MessageTimeoutMs; //!< Timeout in ms for the data field and checksum
   stw_types::uint16       u16_Status;           //!< Service status (X_LIN_SERVICE_STATUS_...)
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
typedef stw_types::sint16 (*PR_x_lin_EventCallback)(const stw_types::uint32 ou32_CallbackParameter, const stw_types::uint16 ou16_Channel,
                                                    T_x_lin_service * const opt_Service);

//-----------------------------------------------------------------------------
/*!
   \brief   Signature of the callback function which is called when a wakeup signal has
            been received

   \param[in]        ou32_CallbackParameter          User defined callback parameter
   \param[in]        ou16_Channel                    LIN bus channel number
*/
//-----------------------------------------------------------------------------
typedef void (*PR_x_lin_WakeupCallback)(const stw_types::uint32 ou32_CallbackParameter, const stw_types::uint16 ou16_Channel);

// LIN Configuration
typedef struct
{
   stw_types::uint32   u32_Bitrate;                        //!< Bitrate in bit/s, max 20000
   stw_types::uint32   u32_InterFrameSpace;                //!< Minimum time between two frames in us
   stw_types::uint16   u16_RequestBufSize;                 //!< Request buffer size in number of T_x_lin_service
   stw_types::uint16   u16_ResponseBufSize;                //!< Response buffer size in number of T_x_lin_service
   stw_types::uint32   u32_RequestCallbackParameter;       //!< Request callback parameter
   PR_x_lin_EventCallback pr_RequestCallback;   //!< Request callback function pointer
   stw_types::uint32   u32_ResponseCallbackParameter;      //!< Response callback parameter
   PR_x_lin_EventCallback pr_ResponseCallback;  //!< Response callback function pointer
   stw_types::uint32 u32_WakeupCallbackParameter;          //!< Wakeup callback parameter
   PR_x_lin_WakeupCallback pr_WakeupCallback;   //!< Wakeup callback function pointer
} T_x_lin_config;

// LIN Bus Status
typedef struct
{
   T_x_lin_config t_Config;         //!< Configuration parameters set with x_lin_init
   stw_types::uint8    u8_OverflowCount;       //!< number of lost messages due to FIFO overflow since last status request
   stw_types::uint8    u8_WakeupState;         //!< flag to indicate a received wakeup since last status request
   stw_types::uint8    u8_BusState;            //!< Current bus state X_LIN_BUS_STATE_...
} T_x_lin_status;


/* -- Global Variables ---------------------------------------------------- */


/* -- Implementation ------------------------------------------------------ */


#endif  // __X_LIN_TYPES_HPP
