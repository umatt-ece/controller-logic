/******************************************************************************/
/*!
   \file
      Defines Solution level structures

   \copyright
      Copyright (C) 2012  DISTek Integration, Inc.  All Rights Reserved.

   \author
      Chris Thatcher
*/
/******************************************************************************/


#include "VIRTEC_STW.h"
#include "VTClient.h"
#include "x_can.h"


//! ECU ID fields for this hardware
EcuIdFields_T Solution_EcuId_Fields =
   {
      "128999",     //Part No
      "12345678-9",      //Serial No
      "SAMPLE",   //Location
      "ISO_Control",       //Type
      "UMATT",      //Manufacturer Name
      "SAMPLE"     //Hardware Version ID
   };

//! Product ID fields for this hardware
ProductIdFields_T Solution_ProductId_Fields =
   {
      "Penelope",        //Product Identification Code
      "UMATT",       //Product Identification Brand
      "P25"        //Product Identification Model
   };


static SoftwareId_T Foundation_SoftwareIdEntry = MAKE_SoftwareId_T(FOUNDATION_VERSION);

static bool_t SolutionCAN_QueuePacket(const CAN_Packet_T *packet, const ISOBUS_Callback_T *callback);

//!   Array of Name Table entries for CAN1
static NameTableEntry_T SolutionCAN_Name_Table[100];

//!   Execute macros to create queue arrays for CAN1 transmit
//!                    (arrayname,      type,              size)
static MAKE_QUEUE_ARRAY(SolutionCAN_TxArray, CAN_QueueElement_T, 30);


/******************************************************************************/
/*!
   \brief    Call macro to initialize a STW_CAN.
   \details    Name_Table          Pointer to a CAN name table
               CAN_QueuePacket     Function name to queue packets for transmit on this channel
               X_CAN_BUS_01        Hardware CAN channel
               SolutionCAN_TxArray tx_queue - Pointer to an array of CAN transmit queues
               40                  rx_queue_size - receive queue size for this channel
               PRIORITY_MAX        priority - PL_0 - PL_14 (PL_0 = MIN)
*/
/******************************************************************************/

STW_CAN_T SolutionCAN = MAKE_STW_CAN_T(SolutionCAN_Name_Table, SolutionCAN_QueuePacket, X_CAN_BUS_01, SolutionCAN_TxArray, 40, PRIORITY_MAX);//2017-03-13 bzhou:change port from 1 to 3

/******************************************************************************/
/*!
   \brief    Function used to queue a packet for transmit on CAN 3.
   \param    packet             Pointer to the packet which is to be sent
             callback           Pointer to a type which contains method of informing calling app that a packet was sent

   \return   bool_t

   \retval   TRUE   Packet successfully queued for transmit
             FALSE  Packet was not queued for transmit
*/
/******************************************************************************/
static bool_t SolutionCAN_QueuePacket(const CAN_Packet_T *packet, const ISOBUS_Callback_T *callback)
{
   return Can_QueuePacket(packet, callback, &SolutionCAN);
}




/******************************************************************************/
/*!
   \brief    Solution initalization routine

   \details  Initalize the Solution_SoftwareId_List

*/
/******************************************************************************/
void Solution_SoftwareId_Init(void)
{

   //! initalize the Platform Software ID List
   // The Software ID List must be initalized before any software IDs
   //  are registered
   SoftwareIdList_Init(&Solution_SoftwareId_List);
   // note: VTClient and ISOBUS Foundation IDs must be registered by the application
   (void)SoftwareId_Register(&Solution_SoftwareId_List, &Foundation_SoftwareIdEntry);   // ISOBUS Foundation
}


/******************************************************************************/
/*
   Copyright (C) 2012  DISTek Integration, Inc.  All Rights Reserved.

   Developed by:
      DISTek(R) Integration, Inc.
      6612 Chancellor Drive Suite 600
      Cedar Falls, IA 50613
      Tel: 319-859-3600
*/
/******************************************************************************/
