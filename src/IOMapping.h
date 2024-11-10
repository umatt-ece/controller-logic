/******************************************************************************/
/*!
   \defgroup   io Input/Output

   Project     278 D200 Drapers\n
   Copyright   MacDon 2015\n
   License     use only under terms of contract / confidential\n

   Date         |    Author     |   Notes
   -------------|---------------|-----------------------------------------------------------------------------------
   08.02.2016   |    MacDon/KP  |   file created. Changes can be seen in version_history.txt\n
   17.12.2018   |    MacDon/BZ  |   Updated to final field test release.  Changes can be seen in version_history.txt

   \file       IOMapping.h
   \brief      input/output definition
   \ingroup   io

*/
/******************************************************************************/


//----------------------------------------------------------------------------
#ifndef IOMAPPING_H_DEFINED
#define IOMAPPING_H_DEFINED

//include STW
//#include "stwtypes.h"
#include "x_in.h"
#include "x_out.h"
#include "x_out_relay.h"

//include file
#include "general.h"



//***********IO Mapping ************************

/*!
    \ingroup    io
    \defgroup   iodefs Inputs and Output Definitions
    \brief      This group contains all information that define inputs and outputs of the system to STW pins/modules.
    @{
*/
    /*!
        \defgroup inputs Inputs
        @{
    */

//Inputs

//#define UNDEFINED                     X_IN_01  //!<    IDA35V
//#define UNDEFINED                     X_IN_02  //!<    IDA35V
//#define UNDEFINED                     X_IN_03  //!<    IDA35V
//#define UNDEFINED                     X_IN_04  //!<    IDA35V
//#define UNDEFINED                     X_IN_05  //!<    IACV
//#define UNDEFINED                     X_IN_06  //!<    IACV
//#define UNDEFINED                     X_IN_07  //!<    IACV
//#define UNDEFINED                     X_IN_08  //!<    IACV
//#define UNDEFINED                     X_IN_09  //!<    IDA5V
//#define UNDEFINED                     X_IN_10  //!<    IDA5V
//#define UNDEFINED                     X_IN_11  //!<    IDA5V
//#define UNDEFINED                     X_IN_12  //!<    IDA5V
//#define UNDEFINED                     X_IN_13  //!<    IDA5V
//#define UNDEFINED                     X_IN_14  //!<    IDA5V
//#define UNDEFINED                     X_IN_15  //!<    IDA5V
//#define UNDEFINED                     X_IN_16  //!<    IDA5V
    /*! @} */

    /*!
        \defgroup outputs Outputs
        @{
    */

//Outputs
//X_OUT_RELAY_01
//#define UNDEFINED             X_OUT_01            //!<    OP2A     EDTK
//#define UNDEFINED                     X_SYS_ADC_I_OUT_01  //!<Current feedback of the output channel
//#define UNDEFINED             X_OUT_02            //!<    OP2A    KT: EDTK
//#define UNDEFINED                     X_SYS_ADC_I_OUT_02  //!<Current feedback of the output channel
//#define UNDEFINED             X_OUT_03            //!<    OP2A
//#define UNDEFINED             X_OUT_04            //!<    OP2A
//#define UNDEFINED             X_OUT_05            //!<    OP2A
//#define UNDEFINED             X_OUT_06            //!<    OP2A
//#define UNDEFINED             X_OUT_07            //!<    OP2A
//#define UNDEFINED             X_OUT_08            //!<    OP2A
//low-side PWM
//#define UNDEFINED             X_OUT_09            //!<    OPL4A
//#define UNDEFINED             X_OUT_10            //!<    OPL4A
//X_OUT_RELAY_01
//#define UNDEFINED             X_OUT_11            //!<    OD2A
//#define UNDEFINED             X_OUT_12            //!<    OD2A
//#define UNDEFINED             X_OUT_13            //!<    OD2A
//#define UNDEFINED             X_OUT_14            //!<    OD2A
//analog output
//#define UNDEFINED             X_OUT_15            //!<    OAV10V
    /*! @} */
/*! @} */

#endif  //IOMAPPING_H_DEFINED
