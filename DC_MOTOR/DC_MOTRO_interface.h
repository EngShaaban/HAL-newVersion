/*******************************************************************************************************************

 *  FILE DESCRIPTION
 *  ----------------------------------------------------------------------------------------------------------------
 *         File:  DC_MOTRO_interface.h
 *       Module:  -
 *       Author:  Shaaban Abdullah
 *  Description:  <Write File DESCRIPTION here>
 *
 ******************************************************************************************************************/

#ifndef HAL_DC_MOTOR_DC_MOTRO_INTERFACE_H_
#define HAL_DC_MOTOR_DC_MOTRO_INTERFACE_H_


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
void DCMOTOR_vidInit(struct dc_motor const*);

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
void DCMOTOR_vidOff(u8);

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
void DCMOTOR_vidClockwise(u8);

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
void DCMOTOR_vidAnticlockwise(u8);


/******************************************************************************************************************/
/*  Syntax          : DCMOTOR_vidGetstatus(<MOTOR_ID>)                                                            */
/*           Ex:                                                                                                  */
/*              +===========================================================================================+     */
/*              |  DC_MotorState motOneStatuse = DCMOTOR_vidGetstatus(1);  //_get the motor current status. |     */
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
DC_MotorState DCMOTOR_vidGetstatus(u8);

#endif /* HAL_DC_MOTOR_DC_MOTRO_INTERFACE_H_ */

/**********************************************************************************************************************
 *  END OF FILE: DC_MOTRO_interface.h
 *********************************************************************************************************************/

