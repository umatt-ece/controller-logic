/******************************************************************************/
/*!
    \file
        testing.c

   \brief
        testing functions to collect pressure values and report over CAN Bus

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


#include "main.h"

/** \fn sint16 s16_Init_testSensors (void)
 * \brief Testing intilization use to intialize I & O
 *
 * \param None
 *
 * \return sint16 a variable tracking any error with Intialization.
 *
 */

sint16 s16_Init_testSensors(void)

{
    sint16 s16_error;


    //Initalize all pressure sensors
    //Sample code:   s16_error |= x_in_init(SAMPLE,X_IN_TYPE_VOLTAGE,0,0,0,NULL);




    return s16_error;



}

/** \fn sint16 s16_convert_PressureValue (sint16 s16_rawSensorValue)
 * \brief Converts a raw sensor value into psi.
 *
 * \param sint16 a variable tracking the raw sensor value of a specific sensor.
 *
 * \return sint16 a variable tracking the psi value calculated from the sensor value.
 *
 */

sint16 s16_convert_PressureValue(sint16 s16_rawSensorValue)

{
    sint16 s16_SensorValuePsi;



    // Convert Mv reading into psi reading for STW ratiometric pressure sensor 102057
    s16_SensorValuePsi = (1.5)*s16_rawSensorValue - 750;

    if(s16_SensorValuePsi<0)

    {
        s16_SensorValuePsi = 0;
    }


    return s16_SensorValuePsi;


}

/** \fn sint16 s16_get_pressureValue (sint16 s16_SensorChannel)
 * \brief Finds the raw sensor value from a given sensor channel.
 *
 * \param sint16 a variable tracking the sensor channel to be read from.
 *
 * \return sint16 a variable tracking the raw sensor value of a specific sensor.
 *
 */

sint16 s16_get_pressureValue (sint16 s16_SensorChannel)
{
    sint16 s16_pressureRawValue;
    sint16 s16_pressureValuepsi;

    x_in_get_value(s16_SensorChannel, &s16_pressureRawValue);

    s16_pressureValuepsi = s16_convert_PressureValue(s16_pressureRawValue);


    return s16_pressureValuepsi;


}
