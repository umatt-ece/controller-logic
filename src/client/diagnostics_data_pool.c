//----------------------------------------------------------------------------------------------------------------------
/*!
   \file
   \brief       openSYDE Datapool definition (Source file with constant definitions)

   This file was generated by openSYDE osy_syde_coder_c.exe V1.13r0, MD5-Checksum: 3FF0BA0464B443BC0A1289AE9DC7DCC2.
*/
//----------------------------------------------------------------------------------------------------------------------

/* -- Includes ------------------------------------------------------------------------------------------------------ */
#include <stddef.h>
#include "diagnostics_data_pool.h"

/* -- Defines ------------------------------------------------------------------------------------------------------- */
///ensure file consistency (if compilation fails here the .h file does not match this .c file)
DIAGNOSTICS_PROJECT_ID_2876402797

/* -- Types --------------------------------------------------------------------------------------------------------- */

/* -- Global Variables ---------------------------------------------------------------------------------------------- */
T_Diagnostics_DataPoolValues gt_Diagnostics_DataPoolValues;

/* -- Module Global Variables --------------------------------------------------------------------------------------- */
///Create Datapool definition instance data:
OSY_DPA_CREATE_STATIC_DP_DEFINITION_INSTANCE_DATA(mt_DpDefinitionInstanceData)

///Min/max values:
///Minimum values
static const T_Diagnostics_Diagnostics_Cylinder_Pressures_Values mt_Diagnostics_Cylinder_PressuresMinValues =
{
   -32768,   ///< s16_LH_Outboard_lift_pressure (s16_LH_Outboard_lift_pressure)
   -32768,   ///< s16_LH_Inboard_lift_pressure (LH inboard lift cylinder pressure (psi))
   -32768,   ///< s16_RH_Outboard_lift_Pressure (RH Outboard lift cylinder pressure(psi))
   -32768,   ///< s16_RH_Inboard_lift_Pressure (RH Inboard lift cylinder pressure (psi))
   -32768,   ///< s16_LH_Swing_Bore_Pressure (Variable description)
   -32768,   ///< s16_LH_Swing_Rod_Pressure (Variable description)
   -32768,   ///< s16_RH_Swing_Bore_Pressure (Variable description)
   -32768,   ///< s16_RH_Rod_Bore_Pressure (Variable description)
   -32768,   ///< s16_RollLock_Bore_Pressure (Variable description)
   -32768,   ///< s16_Rolllock_Rod_Pressure (Variable description)
   -32768,   ///< s16_AntiSway_Bore_Pressure (Variable description)
   -32768    ///< s16_AntiSway_Rod_Pressure (Variable description)
};

///Maximum values
static const T_Diagnostics_Diagnostics_Cylinder_Pressures_Values mt_Diagnostics_Cylinder_PressuresMaxValues =
{
   32767,   ///< s16_LH_Outboard_lift_pressure (s16_LH_Outboard_lift_pressure)
   32767,   ///< s16_LH_Inboard_lift_pressure (LH inboard lift cylinder pressure (psi))
   32767,   ///< s16_RH_Outboard_lift_Pressure (RH Outboard lift cylinder pressure(psi))
   32767,   ///< s16_RH_Inboard_lift_Pressure (RH Inboard lift cylinder pressure (psi))
   32767,   ///< s16_LH_Swing_Bore_Pressure (Variable description)
   32767,   ///< s16_LH_Swing_Rod_Pressure (Variable description)
   32767,   ///< s16_RH_Swing_Bore_Pressure (Variable description)
   32767,   ///< s16_RH_Rod_Bore_Pressure (Variable description)
   32767,   ///< s16_RollLock_Bore_Pressure (Variable description)
   32767,   ///< s16_Rolllock_Rod_Pressure (Variable description)
   32767,   ///< s16_AntiSway_Bore_Pressure (Variable description)
   32767    ///< s16_AntiSway_Rod_Pressure (Variable description)
};

///Minimum values
static const T_Diagnostics_Diagnostics_Sensor_Values_Values mt_Diagnostics_Sensor_ValuesMinValues =
{
   -32768,   ///< s16_Hitch_Sensor_Value (Hitch sensor angle value in mv__)
   -32768,   ///< s16_LH_swing_Sensor_Value (LH swing Sensor Value)
   -32768    ///< s16_RH_swing_Sensor_Value (RH Swing Sensor Value)
};

///Maximum values
static const T_Diagnostics_Diagnostics_Sensor_Values_Values mt_Diagnostics_Sensor_ValuesMaxValues =
{
   32767,   ///< s16_Hitch_Sensor_Value (Hitch sensor angle value in mv__)
   32767,   ///< s16_LH_swing_Sensor_Value (LH swing Sensor Value)
   32767    ///< s16_RH_swing_Sensor_Value (RH Swing Sensor Value)
};

///List definitions:
static const T_osy_dpa_element_definition mat_DataPoolDiagnostics_Cylinder_PressuresElements[DIAGNOSTICS_DIAGNOSTICS_CYLINDER_PRESSURES_NUMBER_OF_ELEMENTS] =
{
   { OSY_DPA_ELEMENT_TYPE_SINT16, 0U, 2U, &gt_Diagnostics_DataPoolValues.t_Diagnostics_Cylinder_PressuresValues.s16_s16_LH_Outboard_lift_pressure, &mt_Diagnostics_Cylinder_PressuresMinValues.s16_s16_LH_Outboard_lift_pressure, &mt_Diagnostics_Cylinder_PressuresMaxValues.s16_s16_LH_Outboard_lift_pressure },
   { OSY_DPA_ELEMENT_TYPE_SINT16, 0U, 2U, &gt_Diagnostics_DataPoolValues.t_Diagnostics_Cylinder_PressuresValues.s16_s16_LH_Inboard_lift_pressure, &mt_Diagnostics_Cylinder_PressuresMinValues.s16_s16_LH_Inboard_lift_pressure, &mt_Diagnostics_Cylinder_PressuresMaxValues.s16_s16_LH_Inboard_lift_pressure },
   { OSY_DPA_ELEMENT_TYPE_SINT16, 0U, 2U, &gt_Diagnostics_DataPoolValues.t_Diagnostics_Cylinder_PressuresValues.s16_s16_RH_Outboard_lift_Pressure, &mt_Diagnostics_Cylinder_PressuresMinValues.s16_s16_RH_Outboard_lift_Pressure, &mt_Diagnostics_Cylinder_PressuresMaxValues.s16_s16_RH_Outboard_lift_Pressure },
   { OSY_DPA_ELEMENT_TYPE_SINT16, 0U, 2U, &gt_Diagnostics_DataPoolValues.t_Diagnostics_Cylinder_PressuresValues.s16_s16_RH_Inboard_lift_Pressure, &mt_Diagnostics_Cylinder_PressuresMinValues.s16_s16_RH_Inboard_lift_Pressure, &mt_Diagnostics_Cylinder_PressuresMaxValues.s16_s16_RH_Inboard_lift_Pressure },
   { OSY_DPA_ELEMENT_TYPE_SINT16, 0U, 2U, &gt_Diagnostics_DataPoolValues.t_Diagnostics_Cylinder_PressuresValues.s16_s16_LH_Swing_Bore_Pressure, &mt_Diagnostics_Cylinder_PressuresMinValues.s16_s16_LH_Swing_Bore_Pressure, &mt_Diagnostics_Cylinder_PressuresMaxValues.s16_s16_LH_Swing_Bore_Pressure },
   { OSY_DPA_ELEMENT_TYPE_SINT16, 0U, 2U, &gt_Diagnostics_DataPoolValues.t_Diagnostics_Cylinder_PressuresValues.s16_s16_LH_Swing_Rod_Pressure, &mt_Diagnostics_Cylinder_PressuresMinValues.s16_s16_LH_Swing_Rod_Pressure, &mt_Diagnostics_Cylinder_PressuresMaxValues.s16_s16_LH_Swing_Rod_Pressure },
   { OSY_DPA_ELEMENT_TYPE_SINT16, 0U, 2U, &gt_Diagnostics_DataPoolValues.t_Diagnostics_Cylinder_PressuresValues.s16_s16_RH_Swing_Bore_Pressure, &mt_Diagnostics_Cylinder_PressuresMinValues.s16_s16_RH_Swing_Bore_Pressure, &mt_Diagnostics_Cylinder_PressuresMaxValues.s16_s16_RH_Swing_Bore_Pressure },
   { OSY_DPA_ELEMENT_TYPE_SINT16, 0U, 2U, &gt_Diagnostics_DataPoolValues.t_Diagnostics_Cylinder_PressuresValues.s16_s16_RH_Rod_Bore_Pressure, &mt_Diagnostics_Cylinder_PressuresMinValues.s16_s16_RH_Rod_Bore_Pressure, &mt_Diagnostics_Cylinder_PressuresMaxValues.s16_s16_RH_Rod_Bore_Pressure },
   { OSY_DPA_ELEMENT_TYPE_SINT16, 0U, 2U, &gt_Diagnostics_DataPoolValues.t_Diagnostics_Cylinder_PressuresValues.s16_s16_RollLock_Bore_Pressure, &mt_Diagnostics_Cylinder_PressuresMinValues.s16_s16_RollLock_Bore_Pressure, &mt_Diagnostics_Cylinder_PressuresMaxValues.s16_s16_RollLock_Bore_Pressure },
   { OSY_DPA_ELEMENT_TYPE_SINT16, 0U, 2U, &gt_Diagnostics_DataPoolValues.t_Diagnostics_Cylinder_PressuresValues.s16_s16_Rolllock_Rod_Pressure, &mt_Diagnostics_Cylinder_PressuresMinValues.s16_s16_Rolllock_Rod_Pressure, &mt_Diagnostics_Cylinder_PressuresMaxValues.s16_s16_Rolllock_Rod_Pressure },
   { OSY_DPA_ELEMENT_TYPE_SINT16, 0U, 2U, &gt_Diagnostics_DataPoolValues.t_Diagnostics_Cylinder_PressuresValues.s16_s16_AntiSway_Bore_Pressure, &mt_Diagnostics_Cylinder_PressuresMinValues.s16_s16_AntiSway_Bore_Pressure, &mt_Diagnostics_Cylinder_PressuresMaxValues.s16_s16_AntiSway_Bore_Pressure },
   { OSY_DPA_ELEMENT_TYPE_SINT16, 0U, 2U, &gt_Diagnostics_DataPoolValues.t_Diagnostics_Cylinder_PressuresValues.s16_s16_AntiSway_Rod_Pressure, &mt_Diagnostics_Cylinder_PressuresMinValues.s16_s16_AntiSway_Rod_Pressure, &mt_Diagnostics_Cylinder_PressuresMaxValues.s16_s16_AntiSway_Rod_Pressure }
};

static const T_osy_dpa_element_definition mat_DataPoolDiagnostics_Sensor_ValuesElements[DIAGNOSTICS_DIAGNOSTICS_SENSOR_VALUES_NUMBER_OF_ELEMENTS] =
{
   { OSY_DPA_ELEMENT_TYPE_SINT16, 0U, 2U, &gt_Diagnostics_DataPoolValues.t_Diagnostics_Sensor_ValuesValues.s16_s16_Hitch_Sensor_Value, &mt_Diagnostics_Sensor_ValuesMinValues.s16_s16_Hitch_Sensor_Value, &mt_Diagnostics_Sensor_ValuesMaxValues.s16_s16_Hitch_Sensor_Value },
   { OSY_DPA_ELEMENT_TYPE_SINT16, 0U, 2U, &gt_Diagnostics_DataPoolValues.t_Diagnostics_Sensor_ValuesValues.s16_s16_LH_swing_Sensor_Value, &mt_Diagnostics_Sensor_ValuesMinValues.s16_s16_LH_swing_Sensor_Value, &mt_Diagnostics_Sensor_ValuesMaxValues.s16_s16_LH_swing_Sensor_Value },
   { OSY_DPA_ELEMENT_TYPE_SINT16, 0U, 2U, &gt_Diagnostics_DataPoolValues.t_Diagnostics_Sensor_ValuesValues.s16_s16_RH_swing_Sensor_Value, &mt_Diagnostics_Sensor_ValuesMinValues.s16_s16_RH_swing_Sensor_Value, &mt_Diagnostics_Sensor_ValuesMaxValues.s16_s16_RH_swing_Sensor_Value }
};

///list of lists:
static const T_osy_dpa_list_definition mat_DataPoolLists[DIAGNOSTICS_NUMBER_OF_LISTS] =
{
   { DIAGNOSTICS_DIAGNOSTICS_CYLINDER_PRESSURES_NUMBER_OF_ELEMENTS, DIAGNOSTICS_DIAGNOSTICS_CYLINDER_PRESSURES_NUMBER_OF_DATA_SETS, 0U, 0x00000000U, sizeof(T_Diagnostics_Diagnostics_Cylinder_Pressures_Values), &mat_DataPoolDiagnostics_Cylinder_PressuresElements[0], &gt_Diagnostics_DataPoolValues.t_Diagnostics_Cylinder_PressuresValues, NULL },
   { DIAGNOSTICS_DIAGNOSTICS_SENSOR_VALUES_NUMBER_OF_ELEMENTS, DIAGNOSTICS_DIAGNOSTICS_SENSOR_VALUES_NUMBER_OF_DATA_SETS, 0U, 0x00000000U, sizeof(T_Diagnostics_Diagnostics_Sensor_Values_Values), &mat_DataPoolDiagnostics_Sensor_ValuesElements[0], &gt_Diagnostics_DataPoolValues.t_Diagnostics_Sensor_ValuesValues, NULL }
};

///Datapool definition:
static const T_osy_dpa_data_pool_definition mt_DataPoolDefinition =
{
   OSY_DPA_DATA_POOL_DEFINITION_VERSION,
   OSY_DPA_DATA_POOL_TYPE_DIAGNOSIS,
   { 0x00U, 0x00U, 0x00U }, ///< Datapool definition version V0.0r0
   "Diagnostics",  ///< name of Datapool
   DIAGNOSTICS_NUMBER_OF_LISTS,
   0x22df1b57U, ///< CRC of Datapool definition
   0x00000000U,  ///< NVM start address
   0U,  ///< number of bytes occupied in NVM
   &mat_DataPoolLists[0],
   &mt_DpDefinitionInstanceData
};

///Information about process and Datapool:
static const T_osy_dpa_remote_data_pool_info mt_DataPoolInfo =
{
   0U,  ///< Identification ID of our own process
   DIAGNOSTICS_DATA_POOL_INDEX  ///< Index of Datapool within process identified by ProcessId
};

///Create Datapool instance data:
OSY_DPA_CREATE_STATIC_DP_INSTANCE_DATA(mt_DpInstanceData, &mt_DataPoolDefinition)

const T_osy_dpa_data_pool gt_Diagnostics_DataPool =
{
   OSY_DPA_DATA_POOL_MAGIC,  ///< identification of valid DP definition
   DIAGNOSTICS_DATA_POOL_INDEX,  ///< Datapool index within this process
   0U,  ///< it's local ...
   &mt_DataPoolInfo,  ///<  info about local Datapool
   &mt_DpInstanceData  ///< run-time data
};

/* -- Module Global Function Prototypes ----------------------------------------------------------------------------- */

/* -- Implementation ------------------------------------------------------------------------------------------------ */
