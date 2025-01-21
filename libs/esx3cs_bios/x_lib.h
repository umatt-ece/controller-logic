//-----------------------------------------------------------------------------
/*!
   \internal
   \file       x_lib.h
   \brief      library and application version information


   \implementation
   project     project name
   copyright   STW (c) 1999-200x
   license     use only under terms of contract / confidential

   \created     04.04.2006  Herb
   \endimplementation

*/
//-----------------------------------------------------------------------------

#ifndef _X_LIB_H
#define _X_LIB_H

/* -- Includes ------------------------------------------------------------ */

#include "x_stdtypes.h"


#ifdef __cplusplus
extern "C" {
#endif


/* -- Defines ------------------------------------------------------------- */

#define X_LIB_VERSION_STRING     "ESX-3CS C-BIOS"  // short description (max. 15 chars)
// note: do not parenthesize this values because of the stringify operator
#define X_LIB_VERSION_MAJOR      3                 // library version
#define X_LIB_VERSION_MINOR      2                 // library minor version
#define X_LIB_VERSION_RELEASE    0                 // library release

// memory attributes for library and application information data
// const data marked with this memory attributes are stored in special
// memory areas, defined by the linker script:
// define memory attribute for BIOS library information
#define X_LIB_MEM_BIOS_INFO      __attribute__ ((section (".extlibinfo")))
// define memory attribute for driver and application library information
#define X_LIB_MEM_DRIVER_INFO    __attribute__ ((section (".extlibinfo")))
// define memory attribute for application information data
#define X_LIB_MEM_APPL_INFO      __attribute__ ((section (".application_info")))

// magic codes to distinguish the type of information stored in T_x_lib_info:
// tag to identify STW BIOS libraries, shall not be used by application
#define  X_LIB_INFO_BIOS_MAGIC               "Lx_?zg1"
// tag to identify driver and application libraries (e.g. CAN-Protocols)
#define  X_LIB_INFO_DRIVER_MAGIC             "Lx_?zg2"
// tag to identify application information
#define  X_LIB_INFO_APPL_MAGIC               "Lx_?zg."

// common application information
#define X_LIB_INFO_STRUCT_VERSION            (0x03u)
#define X_LIB_INFO_ADDITIONAL_MAX            (0xFFu)
#define X_LIB_INFO_DEVICE_ID                 "ESX-3CS"     // library target device id


// define GNU patchlevel if not available (used by library information)
#ifndef __GNUC_PATCHLEVEL__
// note: do not parenthesize this value because of the stringify operator
#define __GNUC_PATCHLEVEL__      0
#endif


/***************************************************************************
 * example for application information blocks:
 * (to be defined inside a application)
 ***************************************************************************/
/*
#define PROJECT_NAME       "DEMO_APPL"    // max. 14 chars
#define VERSION_MAJOR      1              // example for version information defines
#define VERSION_MINOR      23
#define VERSION_RELEASE    4

// --- Application Info Block ---
X_LIB_MEM_APPL_INFO const T_x_lib_info gt_x_application_info =
{
   X_LIB_INFO_APPL_MAGIC,           // magic code identifies data with application info
   X_LIB_INFO_STRUCT_VERSION,       // information struct version
   X_LIB_INFO_DEVICE_ID,            // device name (max 28 chars)
   __DATE__,                        // compile date
   __TIME__,                        // compile time
   PROJECT_NAME,                    // project name (max. 32 chars)
                                    // project version
   XSTR(VERSION_MAJOR) "_" XSTR(VERSION_MINOR) "r" XSTR(VERSION_RELEASE),
   X_LIB_INFO_ADDITIONAL_MAX,       // length of additional information
   "COMPILER_ID: GCC V"XSTR(__GNUC__)"."XSTR(__GNUC_MINOR__)"."XSTR(__GNUC_PATCHLEVEL__)
};

*/

/*********************************************************************
 *  STW SEPI functions, data types and error codes are each          *
 *  placed into a separate namespace for C++.                        *
 *  The following #ifdef instruction will load either the standard   *
 *  C - API style or the C++ style with namespaces.                  *
 *********************************************************************/

#ifdef __cplusplus
namespace stw_sepi
{
   #include "./hpp/x_lib.hpp"
}
#else


/* -- Types --------------------------------------------------------------- */


// Application Info Block V3 for applications loaded with openSYDE flashloader
// This is the official application info block for the ESX-3CS
typedef struct
{
   charn acn_Magic[8];               // = X_LIB_INFO_APPL_MAGIC
   uint8 u8_StructVersion;           // = 3
   charn acn_DeviceName[29];         // name of device the application is indented for; e.g. ESX-3CS
   charn acn_Date[12];               // date of compilation(format: __DATE__ ANSI C macro)
   charn acn_Time[9];                // time of compilation (format: __TIME__ ANSI C macro)
   charn acn_ApplicationName[33];    // name of application or data block
   charn acn_ApplicationVersion[17]; // version number of application or data block
   uint8 u8_LenAdditionalInfo;
   charn acn_AdditionalInfo[X_LIB_INFO_ADDITIONAL_MAX]; // length must match u8_LenAdditionalInfo; ASCII only
} T_x_lib_info;


// Library Info Block for C-BIOS version information
typedef struct
{
   charn  acn_Name[16];             // library name or short description
   charn  acn_VersionString[16];    // version string (format: 1_23r4)
   uint8  u8_MajorVersion;          // major version number
   uint8  u8_MinorVersion;          // minor version number
   uint16 u16_Release;              // release number
   uint16 u16_TargetId;             // target hardware identification
   uint16 u16_TargetVersion;        // target hardware version
   uint16 u16_CompilerMajorVersion; // compiler major version number
   uint16 u16_CompilerMinorVersion; // compiler minor version number
   uint32 u32_CompilerRelease;      // compiler release number
   charn  acn_Date[12];             // date of compilation (format: __DATE__ ANSI C macro)
   charn  acn_Time[9];              // time of compilation (format: __TIME__ ANSI C macro)
} T_x_lib_version;


/* -- Global Variables ---------------------------------------------------- */

/* -- Function Prototypes ------------------------------------------------- */

sint16 x_lib_get_version(T_x_lib_version* const opt_Version);


#endif  //__cplusplus

#ifdef __cplusplus
} /* end of extern "C" */
#endif

#endif  /* _XS_LIB_H */
