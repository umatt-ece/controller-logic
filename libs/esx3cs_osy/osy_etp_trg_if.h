//----------------------------------------------------------------------------------------------------------------------
/*!
   \file
   \brief       Ethernet-TP: target driver interface

   Interface to target specific Ethernet driver wrapper functions.

   The target layer needs to provide one TCP port and one UDP port.
   For UDP only broadcast messages need to be accepted.

   The transport protocol uses
   - the TCP port for "point-to-point" communication (i.e. to respond to requests from a client tool).
   - the UDP port for broadcast communication (broadcasts received from a client tool and broadcasts or unicasts
                                               sent into the local network)

   Typical sequence of functions calls from transport protocol:
   - osy_etp_trg_init_communication for communication initialization
   - osy_etp_trg_tcp_retrieve_message to check for incoming new connections and data
   - osy_etp_trg_tcp_send_message to send response data on an already established TCP connection
   - osy_etp_trg_udp_retrieve_message to read data from the UDP port
   - osy_etp_trg_udp_send_message to send data via UDP

   \copyright   Copyright 2017 Sensor-Technik Wiedemann GmbH. All rights reserved.
*/
//----------------------------------------------------------------------------------------------------------------------
#ifndef OSY_ETP_TRG_IFH
#define OSY_ETP_TRG_IFH

/* -- Includes ------------------------------------------------------------------------------------------------------ */
#include "stwtypes.h"
#include "osy_etp_trg.h" //we need the target specific initialization definition

/* -- Defines ------------------------------------------------------------------------------------------------------- */
#ifdef __cplusplus
extern "C"
{
#endif

#define OSY_ETP_MP_UDP_PORT   (13400U)
#define OSY_ETP_MP_TCP_PORT   (13400U)

/* -- Types --------------------------------------------------------------------------------------------------------- */

/* -- Global Variables ---------------------------------------------------------------------------------------------- */

/* -- Function Prototypes ------------------------------------------------------------------------------------------- */

//----------------------------------------------------------------------------------------------------------------------
/*!
   \brief   Initialize communication channel

   Perform target specific communication initialization action.

   Sockets for UDP and TCP communication shall be configured.
   The required port is 13400 for both.
   The sockets shall be bound to the IP of the specified bus.
   The UDP socket shall be configures to received broadcasts.

   The communication interface itself is typically not initialized by this function
    as multiple protocols use the same physical interface.

   The target layer implementation must store the handles for both, UDP and TCP
   connections, to use them for communication.

   \param[in]   ou8_BusNumber          ETH bus number (0 = first supported bus, ...)
   \param[in]   opt_InitParameters     target specific initialization parameters

   \retval C_NO_ERR   initialization successful
   \retval C_RANGE    one of the parameters is out of range (or NULL)
   \retval C_NOACT    initialization failed
*/
//----------------------------------------------------------------------------------------------------------------------
extern sint16 osy_etp_trg_init_communication(const uint8 ou8_BusNumber,
                                             const T_osy_etp_trg_eth_init_params * const opt_InitParameters);

//----------------------------------------------------------------------------------------------------------------------
/*!
   \brief   Read incoming TCP data

   Return incoming TCP data provide the according handle to calling function.

   Steps:
   - if not yet connected check whether a client wants to connect and accept that connection
   - if connected check for incoming data on that connection

   Only one concurrent TCP connection per channel is supported at a time.
   The function shall not return any data unless it can provide as many data bytes as specified.

   The "handle" parameter can be used to report the handle for the opened connection to the transport protocol.
   The transport protocol will report this value back to subsequent calls of "osy_etp_trg_tcp_send_message" and
   "osy_etp_trg_tcp_close_connection". Using this parameter is optional if all the connection data is held statically
   in this target layer module.

   \param[in]     ou8_BusNumber       ETH bus number (0 = first supported bus, ...)
   \param[in]     ou16_Size           the expected number of bytes to read
   \param[out]    opu8_Message        read message
   \param[out]    oppv_Handle         handle of current communication path

   \retval C_NO_ERR   message retrieved (ou16_Size bytes were placed in opu8_Message)
   \retval C_RANGE    one of the parameters is out of range (or NULL)
   \retval C_CONFIG   communication not initialized
   \retval C_NOACT    no new message or error reading message
   \retval C_TIMEOUT  connection is no more valid (broken) and shall be closed by UDS stack
*/
//----------------------------------------------------------------------------------------------------------------------
extern sint16 osy_etp_trg_tcp_retrieve_message(const uint8 ou8_BusNumber, const uint16 ou16_Size,
                                               uint8 * const opu8_Message, void ** const oppv_Handle);

//----------------------------------------------------------------------------------------------------------------------
/*!
   \brief   Read incoming UDP messages

   Return incoming UDP messages.
   Only broadcast messages need to be accepted.
   The "SockAddr" information returned by this function will be passed back by the stack in
   in a subsequent call of osy_etp_trg_udp_send_message()

   \param[in]     ou8_BusNumber       ETH bus number (0 = first supported bus, ...)
   \param[in,out] opu16_Size          size of available buffer/size of retrieved message
   \param[out]    opu8_Message        read message (caller guarantees a valid buffer matching the size parameter)
   \param[out]    opt_SockAddr        socket address related to sender of request (caller guarantees a valid pointer)

   \retval C_NO_ERR   message retrieved
   \retval C_RANGE    one of the parameters is out of range
   \retval C_CONFIG   communication not initialized
   \retval C_NOACT    no new message or error reading message
*/
//----------------------------------------------------------------------------------------------------------------------
extern sint16 osy_etp_trg_udp_retrieve_message(const uint8 ou8_BusNumber, uint16 * const opu16_Size,
                                               uint8 * const opu8_Message,
                                               T_osy_etp_trg_eth_sockaddr * const opt_SockAddr);

//----------------------------------------------------------------------------------------------------------------------
/*!
   \brief   Send a TCP message

   Send a TCP message on specified channel by the use of the provided handle.

   \param[in]   ou8_BusNumber       ETH bus number (0 = first supported bus, ...)
   \param[in]   ou16_Size           size of message
   \param[in]   opu8_Message        message to send (caller guarantees a valid buffer matching the size parameter)
   \param[in]   opv_Handle          handle of current communication path

   \retval C_NO_ERR   message successfully sent
   \retval C_RANGE    one of the parameters is out of range (or NULL)
   \retval C_CONFIG   communication not initialized
   \retval C_NOACT    could not send message
*/
//----------------------------------------------------------------------------------------------------------------------
extern sint16 osy_etp_trg_tcp_send_message(const uint8 ou8_BusNumber, const uint16 ou16_Size,
                                           const uint8 * const opu8_Message, const void * const opv_Handle);

//----------------------------------------------------------------------------------------------------------------------
/*!
   \brief   Send a UDP message

   Send a UDP message on a specified channel.
   Target port is 13400.

   Depending on the situation the function shall send the message to one specific IP address or as broadcase:
   * if SockAddr is NULL: send as broadcast
   * if SockAddr is not NULL and the original sender identified in SockAddr is in the same subnet: send as unicast
   * if SockAddr is not NULL and the original sender identified in SockAddr is in another subnet: send as broadcast

   \param[in]   ou8_BusNumber       ETH bus number (0 = first supported bus, ...)
   \param[in]   ou16_Size           size of message
   \param[in]   opu8_Message        message to send (caller guarantees a valid buffer matching the size parameter)
   \param[in]   opt_SockAddr        socket address related to sender of original request

   \retval C_NO_ERR   message successfully sent
   \retval C_RANGE    one of the parameters is out of range
   \retval C_CONFIG   communication not initialized
   \retval C_NOACT    could not send message
*/
//----------------------------------------------------------------------------------------------------------------------
extern sint16 osy_etp_trg_udp_send_message(const uint8 ou8_BusNumber, const uint16 ou16_Size,
                                           const uint8 * const opu8_Message,
                                           const T_osy_etp_trg_eth_sockaddr * const opt_SockAddr);

//----------------------------------------------------------------------------------------------------------------------
/*!
   \brief   Closing TCP communication channel

   Perform target specific communication closing action.

   The active TCP connection opened by function osy_etp_trg_tcp_retrieve_message()
   shall be closed.

   \param[in]   ou8_BusNumber  ETH bus number (0 = first supported bus, ...)
   \param[in]   opv_Handle     handle for connection to close

   \retval C_NO_ERR   closing successful
   \retval C_RANGE    one of the parameters is out of range (or NULL)
   \retval C_NOACT    closing failed
*/
//----------------------------------------------------------------------------------------------------------------------
extern sint16 osy_etp_trg_tcp_close_connection(const uint8 ou8_BusNumber, void * const opv_Handle);

//----------------------------------------------------------------------------------------------------------------------
/*!
   \brief   Set IP address

   Perform target specific configuration of IPv4 address.
   The configured value shall be stored on the target permanently (e.g. in NVM).
   The new IP address shall be applied after the next system start.

   \param[in]   ou8_BusNumber           ETH bus number (0 = first supported bus, ...)
   \param[in]   opu8_IpAddress          array of 4 bytes containing the new IPv4 address
   \param[in]   opu8_NetMask            array of 4 bytes containing the new IPv4 net mask
   \param[in]   opu8_DefaultGateway     array of 4 bytes containing the new IPv4 default gateway

   \retval C_NO_ERR   storing new IP address successful
   \retval C_RANGE    one of the parameters is out of range (or NULL)
   \retval C_NOACT    storing new IP address failed
*/
//----------------------------------------------------------------------------------------------------------------------
extern sint16 osy_etp_trg_set_ip_address(const uint8 ou8_BusNumber, const uint8 opu8_IpAddress[4],
                                         const uint8 opu8_NetMask[4], const uint8 opu8_DefaultGateway[4]);

//----------------------------------------------------------------------------------------------------------------------
/*!
   \brief   Set routing between two channels

   Perform target specific routing of IPv4 TCP messages.
   All messages for the net of the target channel shall be forwarded.

   This will be only available if the target provides such a gateway functionality.

   \param[in]   ou8_SourceBusNumber      Source ETH bus number (0 = first supported bus, ...)
   \param[in]   ou8_TargetBusNumber      Target ETH bus number (0 = first supported bus, ...)
   \param[in]   opu8_TargetIpAddress     Target IP address
   \param[in]   opv_Handle               Handle of current communication path

   \retval C_NO_ERR   setup routing successful
   \retval C_RANGE    one of the parameters is out of range
   \retval C_NOACT    setup routing failed
   \retval C_BUSY     routing setup already in progress
*/
//----------------------------------------------------------------------------------------------------------------------
extern sint16 osy_etp_trg_setup_routing(const uint8 ou8_SourceBusNumber, const uint8 ou8_TargetBusNumber,
                                        const uint8 opu8_TargetIpAddress[4], void * const opv_Handle);


//----------------------------------------------------------------------------------------------------------------------
/*!
   \brief   Check the status of the routing setup procedure.

   This function shall be called cyclically be the client after setting up a
   Ethernet to Ethernet routing to chekc the progress.

   It shall return "in progress" until the routing has been set up or an error
   occured.

   If the routing is set up (TCP connection to routing target established), the
   function shall return "conected". From this time on, all data from the client
   is forwardet to the target until the client or the target close their connection.

   \param[in]   ou8_SourceBusNumber     Bus number of interface connected to the client
   \param[in]   opv_Handle              Handle of current communication path

   \retval eRoutingIdle(0)          No routing setup in progress
   \retval eRoutingInProgress(1)    Routing setup in progress
   \retval eRoutingError(2)         An error occured, routing setup aborted
   \retval eRoutingConnected(3)     Connectio to target established, all further requests
                                    from client are forwared to target now
*/
//----------------------------------------------------------------------------------------------------------------------
extern uint8 osy_etp_trg_get_routing_status(const uint8 ou8_SourceBusNumber, void * const opv_Handle);

//----------------------------------------------------------------------------------------------------------------------
/*!
   \brief   Clear entire routing

   Clear all target specific routing configuration.
   Messages for the net of the target channel shall not be forwarded anymore.

   This will be only available if the target provides such a gateway functionality.

   \retval C_NO_ERR   clear routing successful
   \retval C_RANGE    one of the parameters is out of range
   \retval C_WARN     no routing active
   \retval C_NOACT    clear routing failed
*/
//----------------------------------------------------------------------------------------------------------------------
extern sint16 osy_etp_trg_clear_routing(void);

/* -- Implementation ------------------------------------------------------------------------------------------------ */

#ifdef __cplusplus
} //end of extern "C"
#endif

#endif
