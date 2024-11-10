/******************************************************************************/
/*!
    \file
        platform_config.h

    \brief
        Simple header file which contains the necessary platform configuration
        options.

    \copyright
        Copyright (C) 2023  MacDon Inustries Ltd.  All Rights Reserved.
        License     use only under terms of contract / confidential\n

    History:

    Date (YYYY/MM/DD) |   Author      |   Changes
    ------------------|---------------|----------------
    2023/03/31        | Ivan Ciric    | File branched from project 278 (ETDK) to create ISOBUS template project.
*/
/******************************************************************************/

#ifndef __PLATFORM_CONFIG_H__
#define __PLATFORM_CONFIG_H__

/*******************************************************************************
  INCLUDE
*******************************************************************************/
/* include STW libraries */
#include "stwtypes.h"
#include "x_can.h"
#include "x_can_types.h"
#include "x_eep.h"
#include "x_esx3cs.h"
#include "x_in.h"
#include "x_lib.h"
#include "x_os.h"
#include "x_out.h"
#include "x_out_relay.h"
#include "x_ser.h"
#include "x_ssv.h"
#include "x_sys.h"
#include "x_tim.h"
#include "x_uti.h"

/*
 * include VIRTEC project libraries.
 *
 * Note: platform.h, Foundation.h, and VTClient.h must be included in that exact order!
 */
#include "platform.h"
#include "Foundation.h"
#include "VIRTEC_STW.h"

/*******************************************************************************
  DEFINES
*******************************************************************************/

/*******************************************************************************
  MACROS
*******************************************************************************/

/*******************************************************************************
  TYPEDEFS
*******************************************************************************/
//! Unsigned 64-bit integer
typedef uint64 uint64_t;

//! Signed 64-bit integer
typedef sint64 int64_t;

/*******************************************************************************
  ENUMS
*******************************************************************************/

/*******************************************************************************
  STRUCTS
*******************************************************************************/

/*******************************************************************************
  CONSTANTS
*******************************************************************************/

/*******************************************************************************
  EXTERNS
*******************************************************************************/

/*******************************************************************************
  PROTOTYPES
*******************************************************************************/

#endif  //__PLATFORM_CONFIG_H__
