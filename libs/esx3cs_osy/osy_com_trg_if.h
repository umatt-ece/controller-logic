//----------------------------------------------------------------------------------------------------------------------
/*!
   \file
   \brief       protocol data exchange stack: target driver interface

   Interface to target specific functions.

   \copyright   Copyright 2017 Sensor-Technik Wiedemann GmbH. All rights reserved.
*/
//----------------------------------------------------------------------------------------------------------------------
#ifndef OSY_COM_TRG_IFH
#define OSY_COM_TRG_IFH

/* -- Includes ------------------------------------------------------------------------------------------------------ */
#include "stwtypes.h"
#include "osy_com_trg_definitions.h"

/* -- Includes ------------------------------------------------------------------------------------------------------ */
#ifdef __cplusplus
extern "C"
{
#endif

/* -- Types --------------------------------------------------------------------------------------------------------- */
///RX filter definition; logic: pass = ((incoming_id & u32_mask) == u32_Filter)
typedef struct
{
   uint8 u8_IdTypeXtd;    ///< 0 -> 11bit; 1 -> 29bit
   uint32 u32_Filter;     ///< ID filter
   uint32 u32_Mask;       ///< ID mask
   uint16 u16_BufferSize; ///< RX buffer size in number of messages
} T_osy_com_rx_filter;

///RX filters definition
typedef struct
{
   uint8 u8_NumFilters;                     ///< number of defined RX filters
   uint16 u16_TxBufferSize;                 ///< TX buffer size in number of messages
   const T_osy_com_rx_filter * pat_Filters; ///< pointer to array with u8_NumFilters filters
} T_osy_com_buffer_config;

///container for one CAN message
typedef struct
{
   uint8 u8_Dlc;       ///< 0 .. 8
   uint8 u8_IdTypeXtd; ///< 0 -> 11bit; 1 -> 29bit
   uint32 u32_Id;      ///< 11bit or 29bit CAN message ID
   uint32 u32_Time;    ///< RX: time stamp of reception in milliseconds (system time) from driver
   ///< TX: reserved (not to be used by driver)
   uint8 au8_Data[8];        ///< message content
} T_osy_com_trg_can_message; ///< CAN message structure

/* -- Global Variables ---------------------------------------------------------------------------------------------- */

/* -- Function Prototypes ------------------------------------------------------------------------------------------- */

//----------------------------------------------------------------------------------------------------------------------
/*! \brief   Initialize CAN channel

   Perform target specific CAN initialization action.
   Does not include the initialization of the CAN channel itself.
   This is the job of the application as multiple protocols will use the same bus.

   Typically the function will initialize:
   - one TX object
   - multiple RX objects matching the specified RX filters

   The protocol type is passed as a parameter. Using this parameter the target layer implementation can
   keep a clean separation between the CAN objects of the individual protocols.
   e.g. make sure CL2 busload does not cause ECeS buffer overloads and vice versa.

   The calling function is responsible to pass valid pointers for the pointer parameters.

   \param[in]   ou8_CanChannel         index of CAN bus
   \param[in]   ou8_ProtocolType       type of comm protocol (OSY_COM_PROTOCOL_TYPE_*)
   \param[in]   opt_Buffers            configuration of buffers to set up (caller guarantees this to be != NULL)
   \param[in]   opt_Parameters         target specific initialization parameters

   \retval C_NO_ERR       initialization successful
   \retval C_RANGE        one of the parameters is out of range
   \retval C_NOACT        initialization failed
*/
//----------------------------------------------------------------------------------------------------------------------
extern sint16 osy_com_trg_init(const uint8 ou8_CanChannel, const uint8 ou8_ProtocolType,
                               const T_osy_com_buffer_config * const opt_Buffers,
                               const T_osy_com_trg_can_init_params * const opt_Parameters);

//----------------------------------------------------------------------------------------------------------------------
/*! \brief   Send one CAN message

   Send one CAN message on specified channel.
   The protocol type is passed as parameter so the implementation can decide which buffer to work with.
   Remote frames are not allowed.

   The calling function is responsible to pass a valid pointer for the pointer parameter.

   \param[in]   ou8_CanChannel    index of CAN bus
   \param[in]   ou8_ProtocolType  type of comm protocol (OSY_COM_PROTOCOL_TYPE_*)
   \param[in]   opt_Message       CAN message to send (caller guarantees this to be != NULL)

   \retval C_NO_ERR       message successfully sent
   \retval C_RANGE        channel out of range
   \retval C_NOACT        could not send message
*/
//----------------------------------------------------------------------------------------------------------------------
extern sint16 osy_com_trg_send_message(const uint8 ou8_CanChannel, const uint8 ou8_ProtocolType,
                                       const T_osy_com_trg_can_message * const opt_Message);

//----------------------------------------------------------------------------------------------------------------------
/*! \brief   Read incoming CAN messages

   Return one incoming CAN message.
   Only CAN messages passing the RX filters set at initialization may be reported.
   The protocol type is passed as parameter so the implementation can decide which buffer(s) to work with.

   The calling function is responsible to pass a valid pointer for the pointer parameter.

   \param[in]   ou8_Channel        index of communication interface to read from
   \param[in]   ou8_ProtocolType   type of comm protocol (OSY_COM_PROTOCOL_TYPE_*)
   \param[out]  opt_Message        read CAN message

   \retval C_NO_ERR   message read
   \retval C_RANGE    channel out of range
   \retval C_NOACT    no new message or error reading message
*/
//----------------------------------------------------------------------------------------------------------------------
extern sint16 osy_com_trg_read_message(const uint8 ou8_CanChannel, const uint8 ou8_ProtocolType,
                                       T_osy_com_trg_can_message * const opt_Message);

//----------------------------------------------------------------------------------------------------------------------
/*! \brief   Get system time in ms

   Return system time in ms since system start.

   \return   System time in ms
*/
//----------------------------------------------------------------------------------------------------------------------
extern uint32 osy_com_trg_get_time_ms(void);

/* -- Implementation ------------------------------------------------------------------------------------------------ */

#ifdef __cplusplus
} //end of extern "C"
#endif

#endif
