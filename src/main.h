/******************************************************************************/
/*!
    \file
        main.h

    \brief
        File to declare variables above all application header.

    \copyright
        Copyright (C) 2025  University of Manitoba Association of Tiny Tractors.  All Rights Reserved.
        License     use only under terms of contract / confidential\n

    History:

    Date (YYYY/MM/DD) |   Author        |   Changes
    ------------------|-----------------|----------------
    2025/01/29        |Zachary DeGraeve | File created
*/
/******************************************************************************/

#ifndef __MAIN_H__
#define __MAIN_H__

/*******************************************************************************
  INCLUDE
*******************************************************************************/
// include standard libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdtypes.h>



/*******************************************************************************
  DEFINES
*******************************************************************************/

/*!
    \brief      Tasking parameters.
    \ingroup    rtos
    \defgroup   tasking Tasking Parameters
@{
*/
// Main control loop
#define MAIN_CONTROLLOOP_TIME_INTERVAL (10u)      //!<main control loop time interval 10 ms.
#define MAIN_CONTROLLOOP_TIME_DELAY    (100u)     //!<main control loop time delay before the task start 100ms.
#define MAIN_CONTROLLOOP_PRIORITY      (1u)       //!<main control loop priority. Larger number, higher priority.

#define MAIN_CONTROLLOOP_STACK_SIZE    (8u*1024u) //!<main control loop stack size 8K.
/*! @} */

/*******************************************************************************
  MACROS
*******************************************************************************/

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
/*!
    \brief    Main control loop
    \ingroup  mainTask
    \defgroup mainLoop Main Control Loop
    @{
*/
//init main control loop cyclic period 10ms
void mainControlCycle( void );
/*! @} */

#endif  //__MAIN_H__






