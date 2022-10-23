/*
 * SevenSeg_cnfg.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Sky-pc
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/errorStates.h"

#include"../../MCAL/DIO/DIO_interface.h"

#include"SevenSeg_private.h"
#include"SevenSeg_interface.h"
#include"SevenSeg_cnfg.h"




SevenSeg_t    SevenSeg[NUMBER_OF_7SEG]=
{
		{
				.sevenSeg_ID  = 0          ,
				.type         = commonCathod,
				.enablePort   = DIO_PORTC  ,
				.enablePin    = DIO_PIN2   ,
		}
		,
		{
				.sevenSeg_ID  = 1          ,
				.type         = commonCathod,
				.enablePort   = DIO_PORTC  ,
				.enablePin    = DIO_PIN3   ,
		}
		,
		{
				.sevenSeg_ID  = 2          ,
				.type         = commonCathod,
				.enablePort   = DIO_PORTC  ,
				.enablePin    = DIO_PIN5   ,
		}
		,
		{
				.sevenSeg_ID  = 3          ,
				.type         = commonCathod,
				.enablePort   = DIO_PORTC  ,
				.enablePin    = DIO_PIN4   ,
		}


};





