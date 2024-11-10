/******************************************************************************/
/*!
   \file       general.h
   \brief      File to manage all .h/.c files

   Project     278 D200 Drapers\n
   Copyright   MacDon 2015\n
   License     use only under terms of contract / confidential\n

    Date (YYYY/MM/DD) |   Author      |   Changes
    ------------------|---------------|----------------
    2017/01/13        |    MacDon/BZ  | File created
    2018/12/20        |    MacDon/BZ  | Updated to final field test release.  Changes can be seen in version_history.txt
    2023/04/14        | Ivan Ciric    | File branched from project 278 (ETDK) to create ISOBUS template project.

*/
/******************************************************************************/

#ifndef __GENERAL_H__
#define __GENERAL_H__

/*******************************************************************************
  INCLUDE
*******************************************************************************/

/*******************************************************************************
  DEFINES
*******************************************************************************/
// application software version: major, minor, patch
#define APP_SW_VER_MAJOR            1
#define APP_SW_VER_MINOR            0
#define APP_SW_VER_PATCH            0

#define APP_SOFTWARE_NAME           "264805"
#define APP_SOFTWARE_VERSION        "V"XSTR(APP_SW_VER_MAJOR)"."XSTR(APP_SW_VER_MINOR)"."XSTR(APP_SW_VER_PATCH)


// Options used in this project
#define ISO_VT_RUNNING             1 // 1 - VT connected; 0 - No VT required, to save RAM and CPU workload
#define MACHINE_TEST_CAN_MESSAGE   1
//#define CONTROLLER_3CS             1


/*******************************************************************************
  MACROS
*******************************************************************************/
/*!
    \brief      This macro helps perform static_assert functions for compilers\n
                that are older than the C11 standard.\n
                For compilers that use C11 or later, this is not needed,\n
                as static_assert is built into the standard library.
    @{
 */
#define TOKENPASTE1( a, b )        a ## b            // "##" is the "Token Pasting Operator"
#define TOKENPASTE2( a, b )        TOKENPASTE1(a, b) // expand then paste
#define static_assert( x, msg )    enum { TOKENPASTE2(ASSERT_line_,__LINE__) = 1 / (msg && (x)) }
/*! @} */

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

#endif //__GENERAL_H__






