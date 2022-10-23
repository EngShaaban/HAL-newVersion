/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Buzzer_private.c
 *        \brief
 *
 *      \details
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/errorStates.h"

#include "../../MCAL/DIO/DIO_interface.h"


#include"Buzzer_interface.h"
#include"Buzzer_private.h"


/*******************************************************************************
 *  GLOBAL FUNCTIONS
 ******************************************************************************/


/******************************************************************************/
/* Syntax          : BUZZER_vidOn(Buzzer_t*)                                  */
/* Description     : utility function to turn the Buzzer ON.                  */
/*                                                                            */
/* Sync\Async      : Synchronous                                              */
/* Reentrancy      : Non Reentrant                                            */
/* Parameters (in) : refBuzzer   reference to Buzzer object                   */
/* Parameters (out): None                                                     */
/* Return value    : None                                                     */
/*                                                                            */
/******************************************************************************/
void      BUZZER_vidOn(Buzzer_t*  refBuzzer)
{
	DIO_enuSetPinValue(refBuzzer->BUZZER_PORT , refBuzzer->BUZZER_PIN , DIO_LOW );
}


/******************************************************************************/
/* Syntax          : BUZZER_vidOff(Buzzer_t*)                                 */
/* Description     : utility function to turn the Buzzer OFF.                 */
/*                                                                            */
/* Sync\Async      : Synchronous                                              */
/* Reentrancy      : Non Reentrant                                            */
/* Parameters (in) : refBuzzer   reference to Buzzer object                   */
/* Parameters (out): None                                                     */
/* Return value    : None                                                     */
/*                                                                            */
/******************************************************************************/
void      BUZZER_vidOff(Buzzer_t*  refBuzzer)
{
	DIO_enuSetPinValue(refBuzzer->BUZZER_PORT , refBuzzer->BUZZER_PIN , DIO_HIGH );
}

/******************************************************************************/
/* Syntax          : BUZZER_vidGetState(Buzzer_t*)                            */
/* Description     : utility function to get the status of Buzzer.            */
/*                                                                            */
/* Sync\Async      : Synchronous                                              */
/* Reentrancy      : Non Reentrant                                            */
/* Parameters (in) : refBuzzer   reference to Buzzer object                   */
/* Parameters (out): None                                                     */
/* Return value    : state_e                                                  */
/*                                                                            */
/******************************************************************************/
state_e   BUZZER_vidGetState(Buzzer_t*  refBuzzer)
{
	state_e  Local_enuState;

	DIO_enuGetPinVlaue(refBuzzer->BUZZER_PORT , refBuzzer->BUZZER_PIN,&Local_enuState);

	return (Local_enuState == ON)?ON:OFF;
}

/**********************************************************************************************************************
 *  END OF FILE: Buzzer_private.c
 *********************************************************************************************************************/

