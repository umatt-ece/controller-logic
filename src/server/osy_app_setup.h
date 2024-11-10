//-----------------------------------------------------------------------------
/*!
   \file        osy_app_setup.H
   \brief       Initialization and configuration of openSYDE server

   \implementation
   project     openSYDE
   copyright   STW (c) 1999-20xx
   license     use only under terms of contract / confidential

   created     21.11.2017  STW/T.Dedler
   \endimplementation
*/
//-----------------------------------------------------------------------------
#ifndef OSY_APP_SETUP_H
#define OSY_APP_SETUP_H

/* -- Includes ------------------------------------------------------------ */
// general STW includes
#include "stwtypes.h"
#include "stwerrors.h"

// general openSYDE includes
#include "osy_dpd_driver.h"


/* -- Defines ------------------------------------------------------------- */
#ifdef __cplusplus
extern "C"
{
#endif


/* -- Types --------------------------------------------------------------- */


/* -- Global Variables ---------------------------------------------------- */


/* -- Function Prototypes ------------------------------------------------- */
sint16 osy_app_init(const T_osy_dpd_application_information * const opt_OsyApplInfo);
void   osy_app_task(void * const opv_TaskParameter);


/* -- Implementation ------------------------------------------------------ */

#ifdef __cplusplus
} //end of extern "C"
#endif

#endif  /* OSY_APP_SETUP_H */
