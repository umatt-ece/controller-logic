//-----------------------------------------------------------------------------
/*!
   \file        x_lib.hpp
   \brief       CPP namespace extention for x_lib.h

   This header was automatically created. DO NOT EDIT!

   \implementation
   copyright   STW (c) 1999-20xx
   license     use only under terms of contract / confidential

   created     by hpp_generator.pl
   \endimplementation


   \internal
   \history
   Date(dd.mm.yyyy)  Author                Description
   \endhistory
*/
//-----------------------------------------------------------------------------

#ifndef __X_LIB_HPP
#define __X_LIB_HPP



/* -- Types --------------------------------------------------------------- */


// Application Info Block V3 for applications loaded with openSYDE flashloader
// This is the official application info block for the ESX-3CS
typedef struct
{
   stw_types::charn acn_Magic[8];               // = X_LIB_INFO_APPL_MAGIC
   stw_types::uint8 u8_StructVersion;           // = 3
   stw_types::charn acn_DeviceName[29];         // name of device the application is indented for; e.g. ESX-3CS
   stw_types::charn acn_Date[12];               // date of compilation(format: __DATE__ ANSI C macro)
   stw_types::charn acn_Time[9];                // time of compilation (format: __TIME__ ANSI C macro)
   stw_types::charn acn_ApplicationName[33];    // name of application or data block
   stw_types::charn acn_ApplicationVersion[17]; // version number of application or data block
   stw_types::uint8 u8_LenAdditionalInfo;
   stw_types::charn acn_AdditionalInfo[X_LIB_INFO_ADDITIONAL_MAX]; // length must match u8_LenAdditionalInfo; ASCII only
} T_x_lib_info;


// Library Info Block for C-BIOS version information
typedef struct
{
   stw_types::charn  acn_Name[16];             // library name or short description
   stw_types::charn  acn_VersionString[16];    // version string (format: 1_23r4)
   stw_types::uint8  u8_MajorVersion;          // major version number
   stw_types::uint8  u8_MinorVersion;          // minor version number
   stw_types::uint16 u16_Release;              // release number
   stw_types::uint16 u16_TargetId;             // target hardware identification
   stw_types::uint16 u16_TargetVersion;        // target hardware version
   stw_types::uint16 u16_CompilerMajorVersion; // compiler major version number
   stw_types::uint16 u16_CompilerMinorVersion; // compiler minor version number
   stw_types::uint32 u32_CompilerRelease;      // compiler release number
   stw_types::charn  acn_Date[12];             // date of compilation (format: __DATE__ ANSI C macro)
   stw_types::charn  acn_Time[9];              // time of compilation (format: __TIME__ ANSI C macro)
} T_x_lib_version;


/* -- Global Variables ---------------------------------------------------- */

/* -- Function Prototypes ------------------------------------------------- */

stw_types::sint16 x_lib_get_version(T_x_lib_version* const opt_Version);


#endif  // __X_LIB_HPP
