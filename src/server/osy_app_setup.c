//----------------------------------------------------------------------------------------------------------------------
/*!
   \file        osy_app_setup.c
   \brief       Initialization and configuration of openSYDE server

   This module initializes the openSYDE server according to the needs of the application.

   \implementation
   project     openSYDE
   copyright   STW (c) 1999-20xx
   license     use only under terms of contract / confidential

   created     02.01.2018  STW/T.Dedler
   \endimplementation
*/
//----------------------------------------------------------------------------------------------------------------------

/* -- Includes ------------------------------------------------------------------------------------------------------ */
#include "osy_app_setup.h"

// openSYDE headers
#include "osy_init.h"
#include "osy_trg_init.h"
#include "osy_dph_init.h"
#include "osy_com_engine.h"

// COMM definitions

// needed for runtime measurement
#include "x_sys.h"


/* -- Defines ------------------------------------------------------------------------------------------------------- */
// configuration parameters for CAN Target Layer
#define OSY_APP_CFG_CAN_RX_FIFO             10U  // Rx CAN message FIFO size
#define OSY_APP_CFG_CAN_TX_FIFO             10U  // Tx CAN message FIFO size

#define OSY_APP_NUM_FILTERS                 1U   // number of COMM filters


/* -- Types --------------------------------------------------------------------------------------------------------- */


/* -- Global Variables ---------------------------------------------------------------------------------------------- */


/* -- Module Global Variables --------------------------------------------------------------------------------------- */


/* -- Module Global Function Prototypes ----------------------------------------------------------------------------- */
static const T_osy_dpd_appl_data * m_osy_app_get_dpd_target_data(void);


/* -- Implementation ------------------------------------------------------------------------------------------------ */
//----------------------------------------------------------------------------------------------------------------------
/*!
   \brief   This function assembles the target specific initialization data structure
            for the diagnostic protocol driver

   \return  pointer to the assembled init structure
*/
//----------------------------------------------------------------------------------------------------------------------
static const T_osy_dpd_appl_data * m_osy_app_get_dpd_target_data(void)
{
   /* --- CanTp Target Data Structures --- */
   static T_osy_ctp_trg_can_init_params hat_TrgInitParamsCan[OSY_CTP_TRG_MAX_CAN_INTERFACES] =
   {
      { OSY_APP_CFG_CAN_RX_FIFO,  OSY_APP_CFG_CAN_TX_FIFO },  // CAN1
      { OSY_APP_CFG_CAN_RX_FIFO,  OSY_APP_CFG_CAN_TX_FIFO }   // CAN2
   };


   /* --- Main Target Data Structure --- */
   static const T_osy_dpd_appl_data ht_TargetData =
   {
      &hat_TrgInitParamsCan[0],   // CAN target parameters
      NULL                        // Ethernet has no target specific parameters
   };

   // PRQA S 4139 1  // its the intention of this function to assemble a structure and return only its address
   return &ht_TargetData;
}


//----------------------------------------------------------------------------------------------------------------------
/*!
   \brief   Initialize openSYDE server components

   \param[in]   opt_OsyApplInfo   Application information data

   \return  C_NO_ERR    initialization successful
   \return  any else    initialization error
*/
//----------------------------------------------------------------------------------------------------------------------
sint16 osy_app_init(const T_osy_dpd_application_information * const opt_OsyApplInfo)
{
   sint16 s16_Result;

   /* --- Target Layer --- */
   // select standard C-BIOS as hardware abstraction layer for the openSYDE server
   osy_trg_init_std();

#if defined (OSY_APP_USE_ETHERNET)
   // activate lwIP support to be able to use Ethernet communication
   osy_trg_init_lwip();
#endif


   // --- Diagnostic Protocol Driver ---
   {
      const T_osy_dpd_data      * const pt_dpd_global_data = osy_dpd_get_init_config();
      const T_osy_dpd_appl_data * const pt_dpd_target_data = m_osy_app_get_dpd_target_data();
      s16_Result = osy_dpd_init(pt_dpd_target_data, pt_dpd_global_data);
      const T_osy_dpa_data_pool *const apt_DataPools = osy_dph_get_init_config();
      uint8 u8_NumDP = osy_dph_get_num_data_pools();
      s16_Result = osy_dph_init_data_pools(apt_DataPools,u8_NumDP);

      // set application information
      osy_dpd_set_application_information(opt_OsyApplInfo);
   }

   return s16_Result;
}



//----------------------------------------------------------------------------------------------------------------------
/*!
   \brief   Cyclic openSYDE server task function

   \param[in]   opv_TaskParameter    default task parameter
*/
//----------------------------------------------------------------------------------------------------------------------
//PRQA S 3673 1  // no pointer to const, signature is defined by the task system
void osy_app_task(void * const opv_TaskParameter)
{
   const T_osy_uds_ch_channel_identifier at_ComChannels[3] =
   {
      //            Type                       Index
      {OSY_UDS_CH_CHANNEL_TYPE_CAN,      OSY_CTP_TRG_CAN_01},
      {OSY_UDS_CH_CHANNEL_TYPE_CAN,      OSY_CTP_TRG_CAN_02},
      {OSY_UDS_CH_CHANNEL_TYPE_ETHERNET, OSY_ETP_TRG_ETH_01}
   };

   // PRQA S 3112 3  // avoid compiler warning for unused parameters
   (void)opv_TaskParameter;

   /* --- Handle Communication with openSYDE Tool --- */
   // listen on all interfaces for openSYDE requests
   (void)osy_dpd_task(&at_ComChannels[0]);
   (void)osy_dpd_task(&at_ComChannels[1]);

#if defined (OSY_APP_USE_ETHERNET)
   (void)osy_dpd_task(&at_ComChannels[2]);
#endif
}
