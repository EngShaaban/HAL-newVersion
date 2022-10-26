/******************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------*/
/**        \file  DC_MOTOR_porg.c
 *        \brief
 *
 *      \details
 *
 *
 *****************************************************************************************************************/

/******************************************************************************************************************
 *  INCLUDES
 *****************************************************************************************************************/
#include"../../MCAL/DIO/DIO_interface.h"

#include"../2_RelayModule/2_RelayModule_Cnfg.h"
#include"../2_RelayModule/2_RelayModule_interface.h"

#include"DC_MOTRO_Cnfg.h"


/******************************************************************************************************************
 *  LOCAL DATA
 *****************************************************************************************************************/
static _2RelayModule_t     relMod[MAX_NUM_OF_DC_MOTORS];
static DC_MotorState       motorCurrentState[MAX_NUM_OF_DC_MOTORS]={DC_MOTOR_OFF};


/******************************************************************************************************************/
/*  Syntax          : DCMOTOR_vidInit(<name of the motors array>)                                                 */
/*  ......      Ex:                                                                                               */
/*              +==================================================================+                              */
/*              |  DCMOTOR_vidInit(DcMotorArr);                                    |                              */
/*              +==================================================================+                              */
/*                                                                                                                */
/*  Description     : utility function to turn a specific motor off.                                              */
/*                                                                                                                */
/*                                                                                                                */
/*  Sync\Async      : Synchronous                                                                                 */
/*  Reentrancy      : Non Reentrant                                                                               */
/*  Parameters (in) : name of the configuration array 'DcMotorArr' that exists in DC_MOTRO_Cnfg.c  file           */
/*                                                                                                                */
/*  Parameters (out): None                                                                                        */
/*  Return value    :     None                                                                                    */
/*                                                                                                                */
/******************************************************************************************************************/
void DCMOTOR_vidInit(DC_MOTOR_t const* ref)
{
	for( u8 iterator = 0 ; iterator < MAX_NUM_OF_DC_MOTORS ; iterator++ )
	{
		relMod[iterator] = _2RelayModule_Constructor(
				(ref+iterator)->controlPins.port1_id,
				(ref+iterator)->controlPins.pin1_id,
				(ref+iterator)->controlPins.port2_id,
				(ref+iterator)->controlPins.pin2_id);

		switch( (ref+iterator)->initState )
		{
		case DC_MOTOR_OFF: relMod[iterator].off(&relMod[iterator]);

		break;

		case DC_MOTOR_CLOCKWISE: relMod[iterator].forwardDir(&relMod[iterator]);

		motorCurrentState[iterator]=DC_MOTOR_CLOCKWISE;
		break;

		case DC_MOTOR_ANTICLOCKWISE: relMod[iterator].backwardDir(&relMod[iterator]);

		motorCurrentState[iterator]=DC_MOTOR_ANTICLOCKWISE;
		break;

		default:  /*enjoy of doing nothing.*/
			break;

		}//_end of switch.

	}//_end of for.

}//_end of function.

/******************************************************************************************************************/
/*  Syntax          : DCMOTOR_vidOff(<MOTOR_ID>)                                                                  */
/*           Ex:                                                                                                  */
/*              +==================================================================+                              */
/*              |  DCMOTOR_vidOff(0);          //_turn motor num.0  OFF.           |                              */
/*              +==================================================================+                              */
/*                                                                                                                */
/*  Description     : when this function is called, the specific motor will be turned off.                        */
/*  Sync\Async      : Synchronous                                                                                 */
/*  Reentrancy      : Non Reentrant                                                                               */
/*  Parameters (in) : the ID of motor.                                                                            */
/*                                                                                                                */
/*  Parameters (out): None                                                                                        */
/*  Return value    : None                                                                                        */
/*                                                                                                                */
/******************************************************************************************************************/
void DCMOTOR_vidOff(u8 motor_ID)
{
	relMod[motor_ID].off(&relMod[motor_ID]);
	motorCurrentState[motor_ID]=DC_MOTOR_OFF;
}//_end of function.


/******************************************************************************************************************/
/*  Syntax          : DCMOTOR_vidClockwise(<MOTOR_ID>)                                                            */
/*           Ex:                                                                                                  */
/*              +===========================================================================================+     */
/*              |  DCMOTOR_vidClockwise(1);          //_turn motor num.1  in clockwise direction.           |     */
/*              +===========================================================================================+     */
/*                                                                                                                */
/*  Description     : when this function is called, the specific motor will be turn in clockwise direction.       */
/*  Sync\Async      : Synchronous                                                                                 */
/*  Reentrancy      : Non Reentrant                                                                               */
/*  Parameters (in) : the ID of motor.                                                                            */
/*                                                                                                                */
/*  Parameters (out): None                                                                                        */
/*  Return value    : None                                                                                        */
/*                                                                                                                */
/******************************************************************************************************************/
void DCMOTOR_vidClockwise(u8 motor_ID)
{
	relMod[motor_ID].forwardDir(&relMod[motor_ID]);

	motorCurrentState[motor_ID]=DC_MOTOR_CLOCKWISE;

}//_end of function.

/******************************************************************************************************************/
/*  Syntax          : DCMOTOR_vidAnticlockwise(<MOTOR_ID>)                                                        */
/*           Ex:                                                                                                  */
/*              +===========================================================================================+     */
/*              |  DCMOTOR_vidAnticlockwise(1);          //_turn motor num.1  in clockwise direction.       |     */
/*              +===========================================================================================+     */
/*                                                                                                                */
/*  Description     : when this function is called, the specific motor will be turn in Anticlockwise direction.   */
/*  Sync\Async      : Synchronous                                                                                 */
/*  Reentrancy      : Non Reentrant                                                                               */
/*  Parameters (in) : the ID of motor.                                                                            */
/*                                                                                                                */
/*  Parameters (out): None                                                                                        */
/*  Return value    : None                                                                                        */
/*                                                                                                                */
/******************************************************************************************************************/
void DCMOTOR_vidAnticlockwise(u8 motor_ID)
{
	relMod[motor_ID].backwardDir(&relMod[motor_ID]);
	motorCurrentState[motor_ID]=DC_MOTOR_ANTICLOCKWISE;
}//_end of function.

/******************************************************************************************************************/
/*  Syntax          : DCMOTOR_vidGetstatus(<MOTOR_ID>)                                                            */
/*           Ex:                                                                                                  */
/*              +===========================================================================================+     */
/*              |  DCMOTOR_vidGetstatus(1);          //_get the motor current status.                       |     */
/*              +===========================================================================================+     */
/*                                                                                                                */
/*  Description     : when this function is called, the current status of the specific motor will be returned out.*/
/*  Sync\Async      : Synchronous                                                                                 */
/*  Reentrancy      : Non Reentrant                                                                               */
/*  Parameters (in) : the ID of motor.                                                                            */
/*                                                                                                                */
/*  Parameters (out): None                                                                                        */
/*  Return value    : variable of type 'DC_MotorState' ,and that will be:       DC_MOTOR_ANTICLOCKWISE            */
/*                                                                              DC_MOTOR_CLOCKWISE                */
/*                                                                              DC_MOTOR_OFF                      */
/*                                                                                                                */
/******************************************************************************************************************/
DC_MotorState DCMOTOR_vidGetstatus(u8 motor_ID)
{
	return motorCurrentState[motor_ID];
}//_end of function.


/**********************************************************************************************************************
 *  END OF FILE: DC_MOTOR_porg.c
 *********************************************************************************************************************/

