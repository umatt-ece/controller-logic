//----------------------------------------------------------------------------------------------------------------------
/*!
   \file
   \brief       Diagnostic protocol driver implementation
   \copyright   Copyright 2017 Sensor-Technik Wiedemann GmbH. All rights reserved.
*/
//----------------------------------------------------------------------------------------------------------------------
#ifndef OSY_DPD_DRIVERH
#define OSY_DPD_DRIVERH

/* -- Includes ------------------------------------------------------------------------------------------------------ */
#include "stwtypes.h"
#include "osy_dpd_data.h"
#include "osy_dpd_eventdriventransmissionhandler.h"
#include "osy_udc_global_init.h"

/* -- Includes ------------------------------------------------------------------------------------------------------ */
#ifdef __cplusplus
extern "C"
{
#endif

// Wrapper for CAN TP Channel initialization
// Call first for each channel
/*STW Deviation Coding Rules v4*/
/*Violated Rule: 20.10*/
/*Circumstances: using glue operator ##*/
/*Reason: creating different variable names combined with the same parameter*/
/*Potential risks: none*/
/*Prevention of risks:  nothing to do*/
/*PRQA S 0342 ++*/
/*STW Deviation Coding Rules v4*/
/*Violated Rule: */
/*Circumstances: using more than one ## operator*/
/*Reason: there are more variables to create*/
/*Potential risks: invalid preprocessing token because of different evaluation order*/
/*Prevention of risks: use of only a single ## operator for each variable to create*/
/*PRQA S 0881 ++*/
/*STW Deviation Coding Rules v4*/
/*Violated Rule: 4.9*/
/*Circumstances: use of function like macro*/
/*Reason: use of function not practicable here*/
/*Potential risks: none*/
/*Prevention of risks: nothing to do*/
/*PRQA S 3453 ++*/
/*STW Deviation Coding Rules v4*/
/*Violated Rule: */
/*Circumstances: macro parameter used more than once*/
/*Reason: there are more variables to create depending on the same parameter*/
/*Potential risks: possible side effects*/
/*Prevention of risks:  no unexpected side effects, parameter intentionally used more than once*/
/*PRQA S 3456 ++*/
#define OSY_DPD_CAN_CHANNEL(STRUCT_NAME, BUS_INDEX, NUMBER_OF_RX_INSTANCES, \
                            NUMBER_OF_TX_INSTANCES, BUFFERSIZE_PER_RX_AND_TX_INSTANCE, SIZE_OF_RX_ROUTING_FIFO, \
                            SIZE_OF_TX_FIFO) \
   OSY_UDC_GLOBAL_CAN_TP_INIT((STRUCT_NAME), BUS_INDEX, \
                              (NUMBER_OF_RX_INSTANCES), (NUMBER_OF_TX_INSTANCES), \
                              (BUFFERSIZE_PER_RX_AND_TX_INSTANCE), (BUFFERSIZE_PER_RX_AND_TX_INSTANCE), \
                              (SIZE_OF_RX_ROUTING_FIFO), (SIZE_OF_TX_FIFO))

// Wrapper for Ethernet TP Channel initialization
// Call first for each channel
#define OSY_DPD_ETH_CHANNEL(STRUCT_NAME, BUS_INDEX, NUMBER_OF_RX_INSTANCES, \
                            NUMBER_OF_TX_INSTANCES, BUFFERSIZE_PER_RX_AND_TX_INSTANCE) \
   OSY_UDC_GLOBAL_ETHER_TP_INIT((STRUCT_NAME), BUS_INDEX, (NUMBER_OF_RX_INSTANCES), (NUMBER_OF_TX_INSTANCES), \
                                (BUFFERSIZE_PER_RX_AND_TX_INSTANCE), (BUFFERSIZE_PER_RX_AND_TX_INSTANCE))

// Initialization of T_dpd_connection_instance
// Call second for each connection
#define OSY_DPD_CONNECTION_INSTANCE_INIT(STRUCT_NAME, NUMBER_OF_INSTANCE, MAX_NUMBER_OF_EVENT_DRIVEN_TRANSMISSIONS) \
   static T_osy_dpd_ed_transmission hat_DpdTransmission ## NUMBER_OF_INSTANCE[ \
      MAX_NUMBER_OF_EVENT_DRIVEN_TRANSMISSIONS]; \
   static uint16 hau16_CyclicTransmissionRates ## NUMBER_OF_INSTANCE[3] = \
   {  \
      100U, \
      500U,  \
      1000U  \
   }; \
   static T_osy_dpd_connection_instance(STRUCT_NAME) = \
   { \
      { \
         (MAX_NUMBER_OF_EVENT_DRIVEN_TRANSMISSIONS), \
         hat_DpdTransmission ## NUMBER_OF_INSTANCE, \
         &hau16_CyclicTransmissionRates ## NUMBER_OF_INSTANCE[0] \
      }, \
      NULL \
   };

// Initialization of T_dpd_data for function dpd_dr_init
// Call third once
#define OSY_DPD_GLOBAL_DATA_INIT(STRUCT_NAME, MAX_NUMBER_OF_CAN_CHANNELS, MAX_NUMBER_OF_ETHERNET_CHANNELS, \
                                 MAX_NUMBER_OF_CONNECTIONS, \
                                 STRUCT_DPD_CONNECTION_INSTANCE_ARRAY_POINTER, \
                                 STRUCT_GLOBAL_CAN_TP_INIT_ARRAY_POINTER, \
                                 STRUCT_GLOBAL_ETHER_TP_INIT_ARRAY_POINTER) \
   OSY_UDC_GLOBAL_UDS_INIT((ht_UdcInitConfiguration), (MAX_NUMBER_OF_CONNECTIONS), \
                           (MAX_NUMBER_OF_CAN_CHANNELS), (MAX_NUMBER_OF_ETHERNET_CHANNELS)) \
   static const T_osy_dpd_data(STRUCT_NAME) = \
   { \
      (MAX_NUMBER_OF_CONNECTIONS), \
      (STRUCT_DPD_CONNECTION_INSTANCE_ARRAY_POINTER), \
      (MAX_NUMBER_OF_CAN_CHANNELS), \
      (MAX_NUMBER_OF_ETHERNET_CHANNELS), \
      &ht_UdcInitConfiguration, \
      (STRUCT_GLOBAL_CAN_TP_INIT_ARRAY_POINTER), \
      (STRUCT_GLOBAL_ETHER_TP_INIT_ARRAY_POINTER) \
   };
/*PRQA S 0342,0881,3412,3453,3456 --*/

/* -- Types --------------------------------------------------------------------------------------------------------- */
typedef struct
{
   T_osy_ctp_trg_can_init_params * pt_CanTargetInitParams; ///< points to array with target specific init parameter for
   /// all CAN channels
   T_osy_etp_trg_eth_init_params * pt_EthTargetInitParams; ///< points to array with target specific init parameter for
   /// all Ethernet channels
} T_osy_dpd_appl_data;

///application name and version
typedef struct
{
   charn acn_Name[33];    ///< name of application (32 chars + zero termination)
   charn acn_Version[17]; ///< version of application (16 chars + zero termination)
} T_osy_dpd_application_information;

/* -- Global Variables ---------------------------------------------------------------------------------------------- */

/* -- Function Prototypes ------------------------------------------------------------------------------------------- */
extern sint16 osy_dpd_init(const T_osy_dpd_appl_data * const opt_DpdApplData, const T_osy_dpd_data * const opt_DpdData);
extern void osy_dpd_set_application_information(const T_osy_dpd_application_information * const opt_ApplInformation);
extern sint16 osy_dpd_task(const T_osy_uds_ch_channel_identifier * const opt_Channel);

/* -- Implementation ------------------------------------------------------------------------------------------------ */

#ifdef __cplusplus
} //end of extern "C"
#endif

#endif
