//----------------------------------------------------------------------------------------------------------------------
/*!
   \file
   \brief       Definition of openSYDE communication stack configuration structures with their messages and signals.
   \copyright   Copyright 2017 Sensor-Technik Wiedemann GmbH. All rights reserved.
*/
//----------------------------------------------------------------------------------------------------------------------
#ifndef OSY_COM_CONFIGURATIONH
#define OSY_COM_CONFIGURATIONH

/* -- Includes ------------------------------------------------------------------------------------------------------ */
#include "stwtypes.h"
#include "osy_dpa_data_pool.h"
#include "osy_com_trg_if.h"

/* -- Includes ------------------------------------------------------------------------------------------------------ */
#ifdef __cplusplus
extern "C"
{
#endif

#define OSY_COM_CONFIG_MAGIC    (0xC011U) ///< "C011unication"

#define OSY_COM_CONFIG_DEFINITION_VERSION (0x0001U)

#define OSY_COM_BYTE_ORDER_LITTLE   (0U)
#define OSY_COM_BYTE_ORDER_BIG      (1U)

#define OSY_COM_COMM_METHOD_CYCLIC              (0U) ///< message is transferred cyclically
#define OSY_COM_COMM_METHOD_ON_CHANGE           (1U) ///< message is transferred on change (with min/max time window)
#define OSY_COM_COMM_METHOD_ON_EVENT            (2U) ///< message is transferred on application call only

///private message status
///message active/inactive
#define OSY_COM_MESSAGE_STATUS_INACTIVE             (0U) ///< message not supervised for Rx/Tx
#define OSY_COM_MESSAGE_STATUS_ACTIVE               (1U) ///< message supervised for Rx/Tx

///message send/receive status:
#define OSY_COM_MESSAGE_STATUS_TX_NOT_SENT          (0U) ///< data not sent yet
#define OSY_COM_MESSAGE_STATUS_TX_SENT              (1U) ///< data sent at least once
#define OSY_COM_MESSAGE_STATUS_TX_SEND_ERROR        (2U) ///< data send error/overflow

#define OSY_COM_MESSAGE_STATUS_RX_INIT              (3U) ///< data not yet received (data not valid)
#define OSY_COM_MESSAGE_STATUS_RX_NEW_DATA          (4U) ///< new data received (data valid)
#define OSY_COM_MESSAGE_STATUS_RX_NO_NEW_DATA       (5U) ///< data previously received, status cleared (data valid)
#define OSY_COM_MESSAGE_STATUS_RX_NEW_DATA_OVERFLOW (6U) ///< new data received with overflow (data valid)
#define OSY_COM_MESSAGE_STATUS_RX_TIMEOUT           (7U) ///< expected maximum time interval exceeded (data not valid)

///message last protocol error:
#define OSY_COM_MESSAGE_ERROR_RX_NO_ERROR           (0U) ///< no error occurred or previously cleared
#define OSY_COM_MESSAGE_ERROR_RX_DLC_ERROR          (1U) ///< CAN DLC error
#define OSY_COM_MESSAGE_ERROR_RX_SEQUENCE_ERROR     (2U) ///< ECeS: message sequence counter error;
///< ECoS: frame sequence error
#define OSY_COM_MESSAGE_ERROR_RX_CRC_ERROR          (3U) ///< ECeS only: message with invalid CRC received
#define OSY_COM_MESSAGE_ERROR_RX_DATA_ERROR         (4U) ///< ECoS only: frame data congruency error

/* -- Types --------------------------------------------------------------------------------------------------------- */

///Definition of one comm signal
typedef struct
{
   const uint8 u8_ByteOrder;              ///< 0 = little endian; 1 = big endian
   const uint8 u8_BitStart;               ///< Bit start position (0..63)
   const uint8 u8_BitSize;                ///< Size of signal in bits (1..64)
   const uint16 u16_DataPoolListIndex;    ///< mapped data pool list
   const uint16 u16_DataPoolElementIndex; ///< mapped data pool element
} T_osy_com_signal_definition;

//----------------------------------------------------------------------------------------------------------------------

///Definition of one comm message
typedef struct
{
   const uint32 u32_MessageId;               ///< CAN message identifier
   const uint8 u8_MessageIdExt;              ///< 0 = 11bit ID; 1 = 29bit ID
   const uint8 u8_MessageDlc;                ///< data length code 0..8 in bytes (payload only)
   const uint8 u8_CommMethod;                ///< transfer trigger (see OSY_COM_COMM_METHOD_* definitions)
   const uint8 u8_NumberOfSignals;           ///< number of signals in this message
   const uint16 u16_ChangeMinimumIntervalMs; ///< For cyclic and change driven RX: not used
   ///< For change driven TX: minimum interval between sending (even if changed)
   const uint16 u16_MaximumIntervalMs; ///< For cyclic TX: message transmission interval
   ///< For cyclic RX: maximum permitted reception interval
   ///< For change driven: maximum interval between sending (even if no change)
   const uint8 u8_MessageCounterGap;                     ///< ECeS only: number of accepted missing messages
   const T_osy_com_signal_definition * const pt_Signals; ///< Table of all signals defined for this message
} T_osy_com_message_definition;

//----------------------------------------------------------------------------------------------------------------------

///Private status of message at run-time
typedef struct
{
   uint32 u32_LastTransferTime; ///< For TX: last time the message was passed to CAN driver
   ///< For RX: last time the message was correctly received and the DP data updated
   uint8 au8_Data[8]; ///< For change-driven TX CL2: last sent data
   ///< For ECoS Rx: data of the first message
   uint8 u8_MessageCounter;        ///< ECeS only: Last sent or next expected message counter
   uint32 u32_TimeStampFirstFrame; ///< ECoS only: Time the first frame was received
   uint8 u8_Status;                ///< transmission status of message
   uint8 u8_LastProtocolError;     ///< RX only: last transmission error based on protocol
   uint8 u8_Active;                ///< 0: inactive; do not supervise reception; do not send in cyclic TX function
   ///< 1: active; supervise reception; send in cyclic TX function
} T_osy_com_message_status_private;

//----------------------------------------------------------------------------------------------------------------------

///Definition of messages of one protocol type on one communication bus
typedef struct
{
   const uint16 u16_MagicMark;     ///< To identify proper configuration instances.
   const uint16 u16_LayoutVersion; ///< Version of the layout of the protocol
   ///< configuration and subordinate elements.
   const uint16 u16_NumTxMessages;                           ///< Number of defined TX messages
   const uint16 u16_NumRxMessages;                           ///< Number of defined RX messages
   const T_osy_com_message_definition * const pt_TxMessages; ///< Table of all defined TX messages
   ///< Points to an array with NumTxMessages entries.
   const T_osy_com_message_definition * const pt_RxMessages; ///< Table of all defined RX messages.
   ///< Points to an array with NumRxMessages entries.
   T_osy_com_message_status_private * const pt_TxMessagesStatusPrivate; ///< Table of run-time instance data for all
   ///< defined TX messages.
   T_osy_com_message_status_private * const pt_RxMessagesStatusPrivate; ///< Table of run-time instance data for all
   ///< defined RX messages.
   const T_osy_dpa_data_pool * const pt_SignalDataPool; ///< References data pool that contains all
   ///< signals used by the signal definitions.
} T_osy_com_protocol_definition;

//----------------------------------------------------------------------------------------------------------------------

///Definition of comm drivers
typedef sint16 (* PR_verify_definition)(const T_osy_com_protocol_definition * const opt_ProtocolDefinition);
typedef sint16 (* PR_compose_tx_message)(const uint8 ou8_CanChannel,
                                         const T_osy_com_trg_can_message * const opt_CanMessage,
                                         T_osy_com_message_status_private * const opt_TxMessageStatusPrivate);
typedef sint16 (* PR_decompose_rx_message)(const T_osy_com_trg_can_message * const opt_CanMessage,
                                           const T_osy_com_message_definition * const opt_RxMessage,
                                           T_osy_com_message_status_private * const opt_RxMessageStatusPrivate,
                                           uint8 opu8_Data[8]);

//----------------------------------------------------------------------------------------------------------------------

///Definition of comm driver interface
typedef struct
{
   PR_verify_definition pr_VerifyDefinition;
   PR_compose_tx_message pr_ComposeTxMessage;
   PR_decompose_rx_message pr_DecomposeRxMessage;
} T_osy_com_driver;

//----------------------------------------------------------------------------------------------------------------------

///Describes used CAN channel and protocol type with according protocol definition
//and holds protocol type specific function pointers.
typedef struct
{
   const uint8 u8_CanChannel;
   const uint8 u8_ProtocolType;
   const T_osy_com_protocol_definition t_ProtocolDefinition;
   const T_osy_com_driver * const pt_Driver;
} T_osy_com_protocol_configuration;

/* -- Global Variables ---------------------------------------------------------------------------------------------- */

/* -- Function Prototypes ------------------------------------------------------------------------------------------- */

/* -- Implementation ------------------------------------------------------------------------------------------------ */

#ifdef __cplusplus
} //end of extern "C"
#endif

#endif
