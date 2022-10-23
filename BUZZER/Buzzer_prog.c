/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file   Buzzer_prog.c
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

/******************************************************************************/
/*  Syntax          : BUZZER_vidConstructor(state_e ,u8, u8)                  */
/*  Description     : utility function to construct object of type buzzer and */
/*                    initialize it according to its parameter list           */
/*                                                                            */
/*  Sync\Async      : Synchronous                                             */
/*  Reentrancy      : Non Reentrant                                           */
/*  Parameters (in) : 1_ initState variable of type state_e                   */
/*                       ---> Options: ON or OFF                              */
/*                                                                            */
/*                    2_ buzzerPort variable of type u8                       */
/*                       ---> Options:    DIO_PORTA    DIO_PORTC              */
/*                                        DIO_PORTB    DIO_PORTD              */
/*                                                                            */
/*                    3_ buzzerPin variable of type u8                        */
/*                    ---> Options:     DIO_PIN0    DIO_PIN4                  */
/*                                      DIO_PIN1    DIO_PIN5                  */
/*                                      DIO_PIN2    DIO_PIN6                  */
/*                                      DIO_PIN3    DIO_PIN7                  */
/*  Parameters (out): None                                                    */
/*  Return value:   : variable of type Buzzer_t                               */
/*                                                                            */
/******************************************************************************/
Buzzer_t   BUZZER_vidConstructor(state_e initState ,u8 buzzerPort , u8  buzzerPin)
{
	Buzzer_t   Local_Buzzer  ;

	Local_Buzzer.BUZZER_PORT        = buzzerPort;
	Local_Buzzer.BUZZER_PIN         = buzzerPin;

	DIO_enuSetPinDirection(buzzerPort,buzzerPin,DIO_OUTPUT_PIN);

	if( initState == ON )
	{
		DIO_enuSetPinValue(buzzerPort,buzzerPin,DIO_LOW);
	}
	else
	{
		DIO_enuSetPinValue(buzzerPort,buzzerPin,DIO_HIGH);
	}

	Local_Buzzer.On       = BUZZER_vidOn;
	Local_Buzzer.Off      = BUZZER_vidOff;
	Local_Buzzer.GetState =BUZZER_vidGetState;


	return Local_Buzzer ;
}//_end of BUZZER_vidConstructor().

/**********************************************************************************************************************
 *  END OF FILE: Buzzer_prog.c
 *********************************************************************************************************************/
