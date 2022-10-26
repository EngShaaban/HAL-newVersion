/*******************************************************************************************************************

 *  FILE DESCRIPTION
 *  ----------------------------------------------------------------------------------------------------------------
 *         File:  DC_MOTRO_Cnfg.c
 *       Module:  -
 *       Author:  Shaaban Abdullah
 *  Description:  <Write File DESCRIPTION here>
 *
 ******************************************************************************************************************/

/******************************************************************************************************************
 *  INCLUDES
 *****************************************************************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/errorStates.h"

#include"../../MCAL/DIO/DIO_interface.h"

#include"../2_RelayModule/2_RelayModule_Cnfg.h"
#include"../2_RelayModule/2_RelayModule_interface.h"

#include"DC_MOTOR_private.h"
#include"DC_MOTRO_Cnfg.h"

DC_MOTOR_t DcMotorArr[MAX_NUM_OF_DC_MOTORS]=
{
		//_Configuration for motor 0 number 0.
		{
				//_motors id's MUST starts form 0.
				.motor_ID =    0   ,

				//_configure the motor 0 initial status.
				.initState= DC_MOTOR_OFF  ,

				//_confugue the pin will be used by mcu to control this motor.
				.controlPins=
				{
						//_ here i use PD6 and PD7
						.port1_id =DIO_PORTD,
						.pin1_id  =DIO_PIN6,

						.port2_id =DIO_PORTD,
						.pin2_id  =DIO_PIN7,
				}

		}//_end of motor 0 configurations.

		,
	/*	//_Configuration for motor number 1.                 */
	/*	{                                                    */
	/*			.motor_ID =    1          ,                  */
    /*                                                       */
	/*			//_configure the motor 1 initial status.     */
	/*			.initState= DC_MOTOR_OFF ,                   */
    /*                                                       */
	/*			.controlPins=                                */
	/*			{                                            */
	/*					//_ here i use PD4 and PD5           */
	/*					.port1_id =DIO_PORTD,                */
	/*					.pin1_id  =DIO_PIN4,                 */
    /*                                                       */
	/*					.port2_id =DIO_PORTD,                */
	/*					.pin2_id  =DIO_PIN5,                 */
	/*			}                                            */
    /*                                                       */
	/*	}//_end of motor 1 configurations.                   */
};
