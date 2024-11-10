/******************************************************************************/
/*!
    \file
        testing.h

   \brief
        header file for testing.c file

    \ingroup


    \copyright
        Copyright (C) 2024  MacDon Inustries Ltd.  All Rights Reserved.
        License     use only under terms of contract / confidential\n

    History:

    Date (YYYY/MM/DD) |   Author      |   Changes
    ------------------|---------------|----------------
    2024/01/12        | Matt Stephens | Initial release
*/
/******************************************************************************/

#ifndef TESTING_H_INCLUDED
#define TESTING_H_INCLUDED

sint16 s16_Init_testSensors(void);
sint16 s16_get_pressureValue (sint16 s16_SensorChannel);
sint16 s16_convert_PressureValue(sint16 s16_sensorRawValue);
void populate_can_test(void);


#endif // TESTING_H_INCLUDED
