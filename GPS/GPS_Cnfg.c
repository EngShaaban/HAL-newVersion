/*
 * GPS_Cnfg.c
 *
 *  Created on: Mar 15, 2022
 *      Author: SHAABAN
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/errorStates.h"


#include "../../MCAL/DIO/DIO_interface.h"

#include "GPS_Priv.h"
#include "GPS_Cnfg.h"

// GPS_VCC_OUT
// GPS_GND_OUT

GPS_t  GPS =
{
		.GPS_STATE_t =      gps_on     ,

		.GPS_VCC_PORT=      GPS_VCC_OUT  ,
		.GPS_VCC_PIN =      GPS_VCC_OUT   ,

		.GPS_GND_PORT=      GPS_GND_OUT  ,
        .GPS_GND_PIN =      GPS_GND_OUT   ,
};
