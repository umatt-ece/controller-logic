#ifndef CAN_MUTEX_MEM_H
#define CAN_MUTEX_MEM_H
///******************************************************************************/
///*!
//   \file
//      Platform Solution API
//   \copyright
//      Copyright (C) 2015  DISTek Integration, Inc.  All Rights Reserved.
//*/
///******************************************************************************/


#include "Platform.h"
#include "Foundation.h"


//! Version of the VIRTEC_STW Header  (Product,Major,minor,build)
#define VIRTEC_STW_VERSION SoftwareVersion("VIRTEC_STW",1,1,3)

//! Structure containing data for one queue element
typedef struct CAN_QueueElement_S
{
   //! Packet being sent
   CAN_Packet_T    Packet;
   //! Callback to call when packet is sent
   ISOBUS_Callback_T  Callback;
} CAN_QueueElement_T;

//! Structure containing all data for a ISO CAN bus
typedef struct CAN_Bus_S
{
   //! Hardware CAN Channel - X_CAN_BUS_01 - X_CAN_BUS_04
   const uint16_t         Channel;
   //! Baudrate - set to 250K by default
   const uint32_t         Baudrate;
   //! Transmit queue
   Queue_T                TxQueue;
   //! CAN bus handle
   void                   *TxHandle;
   //! Size of RX Queue
   Size_T                 RxQueueSize;
   //! Pointer to the CAN receive queue
   void                   *RxHandle;
   //! Pointer to Bridge IP, NULL is disabled
   int8_t                 *IP;
   //! Bridge port number
   int16_t                Port;
} CAN_Bus_T;

/******************************************************************************/
/*!
   \brief    Macro used to initialize a CAN_Bus_T type.
   \param    can_channel        X_CAN_BUS_01 - X_CAN_BUS_04
             tx_queue           Pointer to an array of CAN transmit queues
             rx_queue_size      size of recieve queue for this channel
             priority           PL_0 - PL_14 (PL_0 = MIN)
*/
/******************************************************************************/
#define MAKE_CAN_Bus_T(can_channel, tx_queue, rx_queue_size, priority) \
      {                                                 \
         can_channel,                                   \
         250000,                                        \
         MAKE_Queue_T(tx_queue, priority),              \
         NULL,                                          \
         rx_queue_size,                                 \
         NULL,                                          \
         NULL,                                          \
         0                                              \
      }

//! Structure containing all data for an STW ISO CAN bus
typedef struct STW_CAN_S
{
    //! Contains all Network/CAN bus information
    Network_T  Network;
    //! Structure containing all data for a ISO CAN bus
    CAN_Bus_T  CAN_Handle;
} STW_CAN_T;

/******************************************************************************/
/*!
   \brief    Macro used to initialize a STW_CAN_T type.
   \details  sample use: STW_CAN_T  STW_CAN1 = MAKE_STW_CAN_T(Name_Table_1, CAN1_QueuePacket, X_CAN_BUS_01, CAN1_Queues, CAN1_Rx, PRIORITY_MAX);
   \param    name_table         Pointer to a CAN name table
             queue_packet_fn    Function name to queue packets for transmit on this channel
             can_channel        X_CAN_BUS_01 - X_CAN_BUS_04
             tx_queue           Pointer to an array of CAN transmit queues
             rx_queue_size      Pointer to the CAN receive queue for this channel
             priority           PL_0 - PL_14 (PL_0 = MIN)

*/
/******************************************************************************/
#define MAKE_STW_CAN_T(name_table, queue_packet_fn, can_channel, tx_queue, rx_queue_size, priority)  \
   {                                                                               \
      {                                                                            \
         MAKE_Network_PacketHandlerList_T(priority),                               \
         MAKE_NameTable_T(name_table, Solution_SwTimerList, priority),             \
         queue_packet_fn                                                           \
      },                                                                           \
      MAKE_CAN_Bus_T(can_channel, tx_queue, rx_queue_size, priority)               \
   }

/******************************************************************************/
/*!
   \brief    Initialize the CAN bus defined in stw_can
   \param    stw_can            Pointer to the structure containing all data for an STW ISO CAN bus
*/
/******************************************************************************/
extern void CAN_Init(STW_CAN_T *stw_can);
extern void CAN_Close(STW_CAN_T *stw_can);

/******************************************************************************/
/*!
   \brief    Periodic task to manage the operations of the CAN bus defined in stw_can
   \param    stw_can            Pointer to the structure containing all data for an STW ISO CAN bus

   \note     The recommended maximum interval for calling is:  (receive buffer size) / 2 (in milliseconds)
*/
/******************************************************************************/
extern void CAN_Task(STW_CAN_T *stw_can);

/******************************************************************************/
/*!
   \brief    Function used to queue a packet for transmit on the CAN bus defined in the stw_can parameter.
   \param    packet             Pointer to the packet which is to be sent
             callback           Pointer to a type which contains method of informing calling app that a packet was sent
             stw_can            Pointer to the structure containing all data for an STW ISO CAN bus

   \note     Not intended for external use.  Called by a CANX_QueuePacket() for a specific channel; e.g. CAN1_QueuePacket()

   \return   bool_t

   \retval   TRUE   Packet successfully queued for transmit
             FALSE  Packet was not queued for transmit
*/
/******************************************************************************/
extern bool_t Can_QueuePacket(const CAN_Packet_T *packet, const ISOBUS_Callback_T *callback, STW_CAN_T *stw_can);


//! Software Timer List at the solution level
extern SoftwareTimerList_T  Solution_SwTimerList;

//! Software ID List at the solution level
extern SoftwareIdList_T Solution_SoftwareId_List;


//! Software Timer List initialization
extern void Timers_Init(void);
//! Software Timer Periodic Task
extern void Timers_Task(void);


//! Initializes the Memory driver
extern void Memory_Init(void);

//! Task for processing the memory sessions
extern void Memory_Task(void);

//! Copies data from source memory address to destination pipe
extern bool_t Memory_Read(Pipe_WriteHandle_T destination, const MemoryPointer_T *source, Size_T size, const ISOBUS_Callback_T *callback);

//! Copies data from source pipe to destination memory address
extern bool_t Memory_Write(const MemoryPointer_T *destination, Pipe_ReadHandle_T source, Size_T size, const ISOBUS_Callback_T *callback);

//! Scheduler List initialization
extern void Scheduler_Init(void);

//! This structure is used to register Scheduler Tasks
typedef struct SchedulerTask_S
{
   //! Member for registering in linked list
   struct LinkedList_Node_S LinkedList_Node;
   //! pointer to task with no arguments
   void (*Task1)(void);
   //! pointer to task with one argument
   void (*Task2)(void*);
   //! pointer to task argument
   void * Pointer1;
   //! task period
   int32_t Period;
   //! internal task counter
   int32_t CountUpTimer;
} SchedulerTask_T;

#define MAKE_SchedluleTask_S(task1,task2,pointer1,period) {MAKE_LinkedList_Node_S(NULL), (void(*)(void))task1, (void(*)(void*))task2, (void*)pointer1, period, 0}

//! Register Scheduler Task
extern bool_t Register_Scheduler_Task(SchedulerTask_T*);

//! Unregister Scheduler Task
extern bool_t Unregister_Scheduler_Task(SchedulerTask_T*);

//! Scheduler run should be called at least every 10ms, but can be called more often.
extern void Scheduler_Run(void);

//
///******************************************************************************/
///*
//   Copyright (C) 2015  DISTek Integration, Inc.  All Rights Reserved.
//   Developed by:
//      DISTek(R) Integration, Inc.
//      6612 Chancellor Drive Suite 600
//      Cedar Falls, IA 50613
//      Tel: 319-859-3600
//*/
///******************************************************************************/
#endif //CAN_MUTEX_MEM_H
