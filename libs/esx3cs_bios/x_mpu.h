//-----------------------------------------------------------------------------
/*!
   \internal
   \file       x_mpu.h
   \brief      memory protection unit support


   \implementation
   project     project name
   copyright   STW (c) 1999-200x
   license     use only under terms of contract / confidential

   \created     28.06.2006  Herb
   \endimplementation

   */
//-----------------------------------------------------------------------------

#ifndef _X_MPU_H
#define _X_MPU_H

/* -- Includes ------------------------------------------------------------ */

#include "x_stdtypes.h"
#include "x_mpu_types.h"
#include "x_memclass.h"

#ifdef __cplusplus
extern "C" {
#endif


/* -- Defines ------------------------------------------------------------- */

// Use this macros to declare application defined HEAP areas that can be read and write protected by the MPU
// PRQA S 3453 2  // QA-C: Macros cannot be replaced by functions
#define X_MPU_CREATE_STATIC_HEAP_INT_DSPR(HeapSize) MEM_APPL_STATIC_HEAP_INT_DSPR uint8 gau8_x_mpu_IntDsprHeap[HeapSize]
#define X_MPU_CREATE_STATIC_HEAP_EXT_RAM(HeapSize)  MEM_APPL_STATIC_HEAP_EXT_RAM  uint8 gau8_x_mpu_ExtRamHeap[HeapSize]

/*********************************************************************
 *  STW SEPI functions, data types and error codes are each          *
 *  placed into a separate namespace for C++.                        *
 *  The following #ifdef instruction will load either the standard   *
 *  C - API style or the C++ style with namespaces.                  *
 *********************************************************************/

#ifdef __cplusplus
namespace stw_sepi
{
   #include "./hpp/x_mpu.hpp"
}
#else


/* -- Global Variables ---------------------------------------------------- */

/* -- Types --------------------------------------------------------------- */

/* -- Function Prototypes ------------------------------------------------- */

sint16 x_t_mpu_init_static(void);
sint16 x_t_mpu_get_mode(uint16 * const opu16_MpuMode);



#endif  //__cplusplus

#ifdef __cplusplus
} /* end of extern "C" */
#endif

#endif  /* _X_MPU_H */
