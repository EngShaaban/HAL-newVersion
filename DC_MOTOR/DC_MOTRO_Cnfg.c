/*
 * DC_MOTRO_Cnfg.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Sky-pc
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/errorStates.h"

#include"../DC_MOTOR/DC_MOTRO_Cnfg.h"
#include"../DC_MOTOR/DC_MOTRO_interface.h"

#include"DC_MOTOR_private.h"
#include"DC_MOTRO_Cnfg.h"

DC_MOTOR_t DcMotorArr[MAX_NUM_OF_DC_MOTORS]=
{
		{
				.initState= DC_MOTOR_OFF  ,

		}
};
