//----------------------------------------------------------------------------------------------------------------------
/*!
   \file
   \brief       UDS session handler
   \copyright   Copyright 2017 Sensor-Technik Wiedemann GmbH. All rights reserved.
*/
//----------------------------------------------------------------------------------------------------------------------
#ifndef OSY_UDS_SESSIONENGINEH
#define OSY_UDS_SESSIONENGINEH

/* -- Includes ------------------------------------------------------------------------------------------------------ */
#include "stwtypes.h"
#include "osy_uds_connectionhandler.h"

/* -- Defines ------------------------------------------------------------------------------------------------------- */
#ifdef __cplusplus
extern "C"
{
#endif

/* -- Types --------------------------------------------------------------------------------------------------------- */
typedef sint16 (* PR_stop_transmissions)(const void * const opv_Connection);

//----------------------------------------------------------------------------------------------------------------------
typedef struct
{
   const uint8 u8_ServiceId;
   const uint8 u8_SubfunctionId; // Set to 0xFF if not in use
   const uint16 u16_RoutineId;   // Set to 0xFFFF if not in use
   const uint8 u8_NecessarySA;
} T_osy_uds_se_service_configuration;

//----------------------------------------------------------------------------------------------------------------------
typedef struct
{
   const uint8 u8_SessionId;
   const uint8 u8_NumberServices;
   const T_osy_uds_se_service_configuration * const pt_ServiceConfiguration; ///< Array with u8_NumberServices entries
} T_osy_uds_se_session_configuration;

//----------------------------------------------------------------------------------------------------------------------
typedef struct
{
   const uint8 u8_NumberSessions;
   const T_osy_uds_se_session_configuration * const pt_SessionConfiguration; ///< Array with u8_NumberSessions entries
   const PR_stop_transmissions pr_stop_transmissions;                        ///< Function pointer to diagnostic server,
                                                                             // unused in flashloader
} T_osy_uds_se_session_engine_configuration;

/* -- Global Variables ---------------------------------------------------------------------------------------------- */

/* -- Function Prototypes ------------------------------------------------------------------------------------------- */

// SessionEngine interface realization
extern sint16 osy_uds_se_init(const T_osy_uds_se_session_engine_configuration * const opt_Configuration);

extern void osy_uds_se_close(void);

extern sint16 osy_uds_se_enter_session(T_osy_uds_ch_connection_data * const opt_Connection, const uint8 ou8_SessionID);

extern sint16 osy_uds_se_leave_session(T_osy_uds_ch_connection_data * const opt_Connection);

extern sint16 osy_uds_se_get_current_session(T_osy_uds_node_identifier const * const opt_ClientIdentifier,
                                             uint8 * const opu8_SessionID);

// SecurityEngine interface realization
extern sint16 osy_uds_se_get_seed(T_osy_uds_ch_connection_data * const opt_Connection, const uint8 ou8_Level,
                                  uint32 * const opu32_Seed);

extern sint16 osy_uds_se_check_key(T_osy_uds_ch_connection_data * const opt_Connection, const uint8 ou8_Level,
                                   const uint32 ou32_Key);

// PermissionEngine interface realization
extern sint16 osy_uds_se_check_permission(T_osy_uds_ch_connection_data const * const opt_Connection,
                                          const uint8 ou8_ServiceId, const uint8 ou8_SubFunctionId,
                                          const uint16 ou16_RoutineId, uint8 * const opu8_Clearance);

/* -- Implementation ------------------------------------------------------------------------------------------------ */

#ifdef __cplusplus
} //end of extern "C"
#endif

#endif
