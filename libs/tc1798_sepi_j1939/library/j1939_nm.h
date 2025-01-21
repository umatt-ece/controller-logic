//-----------------------------------------------------------------------------
/*!
   \internal
   \file
   \brief      J1939 network management module

   Handle the address claiming for local and remote nodes.

   \implementation
   project     J1939 Protocolstack
   copyright   STW (c) 2011
   license     use only under terms of contract / confidential

   created     17.05.2011  STW/M.Greiner
   \endimplementation

   \internal
   \history
   Date(dd.mm.yyyy)   Author           Description
   17.05.2011         STW/M.Greiner    file created
   \endhistory
*/
//------------------------------------------------------------------------------


#ifndef _J1939_NM_H_               // Avoid multiple/recursive inclusion
#define _J1939_NM_H_


// -- Includes ----------------------------------------------------------------
#include "stwtypes.h"
#include "stwerrors.h"


#if defined(__cplusplus)
extern "C" {     // Make sure we have C-declarations in C++ programs
#endif


// -- Defines -----------------------------------------------------------------

// states of a local node                // Set from:  Description:
#define J1939_NM_STATE_NODE_OFF     0    // App,Stack  Node is turned off. This is the start state.
#define J1939_NM_STATE_CLAIM_WAIT   1    //     Stack  After AddrClaim send, wait 250ms before validate Addr.
#define J1939_NM_STATE_CLAIM_OK     2    //     Stack  Node is online and ready to communicate.
#define J1939_NM_STATE_NO_ADDR      3    //     Stack  Node has no valid Addr. Respond to NM messages with Addr=253.
#define J1939_NM_STATE_ERROR        4    //     Stack  Error condition detected in network management
#define J1939_NM_STATE_START_CLAIM  5    // App        Application initiate AddrClaim sequence.
#define J1939_NM_STATE_START_STATIC 6    // App        Node is started in static mode (use static Addr)


// -- Types -------------------------------------------------------------------
typedef struct
{
   // byte 8
   uint8  u8_ArbAddrCapable;             // Range: 0,1
                                         //   0 - node is not self configurable
                                         //   1 - node is self configurable
   uint8  u8_IndustryGroup;              // Range: 0..7 - defined and assigned by ISO
                                         // Associate NAME with particular industry group
   uint8  u8_VehicleSystemInst;          // Range: 0..15
                                         // Work in combination with VehicleSystem field
                                         // Assigns a number to each instance of the VehicleSystem
   // byte 7
   uint8  u8_VehicleSystem;              // Range: 0..127 - defined and assigned by ISO
                                         // Closely associated with IndustryGroup.
   // byte 6
   uint8  u8_Function;                   // Range: 0..255 - defined and assigned by ISO
                                         // 0  ..127 - definition is independent from any other fields
                                         // 128..253 - definition depends on IndustryGroup and VehicleSytem
   // byte 5
   uint8  u8_FunctionInst;               // Range: 0..31
                                         // Work in combination with Function field
                                         // Assigns a number to each instance of the Function
   uint8  u8_EcuInst;                    // Range: 0..7
                                         // Assigns a number to each instance of the ECU
   // Byte 4,3
   uint16 u16_ManufacturerCode;          // Range: 0..2047 - defined and assigned by ISO
                                         // Identificate the ECU manufacturer
   // Byte 2,1
   uint32 u32_IdentityNr;                // Range: 0..2097151
                                         // Assigned by the ECU manufacturer
}
T_J1939_NM_name;                         // store the node NAME fields (each node has unique NAME)

typedef struct
{
   uint8  u8_CurrentNetAddr;             // the actual node address in network
   uint32 u32_EventTime;                 // time of the next event, dependent from state [ms]
}
T_J1939_NM_mngmt_local_node;             // internal management datas for stack state machines

typedef struct
{
   // *************** configuration ***************
   // node description
   uint16          u16_Channel;          // the bus number
   uint8           u8_AppAddr;           // the constant node address used in application
                                         // if AddrClaim is on, can differ from Network NodeAddress
   T_J1939_NM_name t_Name;               // the node name description, parsed only on initialisation
   uint8           u8_NetAddr;           // the network address (first used on address claim)
   uint8           u8_NrAlternAddr;      // select address from range [u8_NetAddr .. u8_NetAddr+u8_NrAlternAddr]

   // ****************** runtime ******************
   uint8                       u8_State; // Node State: J1939_NM_STATE_*
   T_J1939_NM_mngmt_local_node t_Mngmt;  // Internal management datas
}
T_J1939_NM_local_nodes;                  // management structure of a entry in the network management
                                         // array for local nodes


//-----------------------------------------------------------------------------
/*!
   \brief    Callback function for received AddressClaim message

   If any AddressClaim message is received, the stack call the registered
   callback function from this type.

   \param[in]          ou16_Channel     bus number
   \param[in]          ou8_NodeAddr     the node address of the address claim transmiter
   \param[in]          opu8_Name        pointer to a buffer with 8 byte size with the node NAME

   \return
    -

   \created            16.01.2012       STW/M.Greiner

   \internal
   \history
   Date(dd.mm.yyyy)    Author           Description
   08.01.2014          STW/M.Greiner    function created
   13.02.2015          STW/FE           #98, merged from arm_cortex branch
   \endhistory
*/
//-----------------------------------------------------------------------------
typedef void (*PR_J1939_NM_rx_addr_claim)(const uint16 ou16_Channel, const uint8 ou8_NodeAddr,
                                          const uint8 * const opu8_Name);


// -- Global Variables --------------------------------------------------------


// -- Function Prototypes -----------------------------------------------------
extern void J1939_nm_rx_addr_claim_init_callback(const PR_J1939_NM_rx_addr_claim opr_Callback);


// -- Implementation ----------------------------------------------------------


#if defined(__cplusplus)
}                // Make sure we have C-declarations in C++ programs
#endif

#endif                // Avoid multiple/recursive inclusion

/*************************** End of file ****************************/
