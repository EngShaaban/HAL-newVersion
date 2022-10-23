/*
 * 7447_Decoder_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Sky-pc
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/errorStates.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "7447_Decoder_private.h"
#include "7447_Decoder_interface.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : void     Decoder7447_vidInit(void)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : None
*
*******************************************************************************/
void     Decoder7447_vidInit(void)
{
	DIO_enuSetPinDirection(PINA_PORT, PINA_PIN, DIO_OUTPUT_PIN);
	DIO_enuSetPinDirection(PINB_PORT, PINB_PIN, DIO_OUTPUT_PIN);
	DIO_enuSetPinDirection(PINC_PORT, PINC_PIN, DIO_OUTPUT_PIN);
	DIO_enuSetPinDirection(PIND_PORT, PIND_PIN, DIO_OUTPUT_PIN);

	    DIO_enuSetPinValue(PINA_PORT, PINA_PIN, DIO_LOW);
	    DIO_enuSetPinValue(PINB_PORT, PINB_PIN, DIO_LOW);
	    DIO_enuSetPinValue(PINC_PORT, PINC_PIN, DIO_LOW);
	    DIO_enuSetPinValue(PIND_PORT, PIND_PIN, DIO_LOW);

}//End of Decoder7447_vidInit().

Decoder7447_vidRepresent(u8  Cpy_u8Num )
{
	u8 u8_indx   = 0 ;
	u8 u8_binaryBuffer[4]={0};
	u8 u8_rem = 0  ;

	while(Cpy_u8Num)
	{
		u8_rem = Cpy_u8Num % 2 ;
		u8_binaryBuffer[u8_indx] = u8_rem;
		u8_indx++;
		Cpy_u8Num /=2 ;
	}

	DIO_enuSetPinValue(PINA_PORT,PINA_PIN,u8_binaryBuffer[0]);
	DIO_enuSetPinValue(PINB_PORT,PINB_PIN,u8_binaryBuffer[1]);
	DIO_enuSetPinValue(PINC_PORT,PINC_PIN,u8_binaryBuffer[2]);
	DIO_enuSetPinValue(PIND_PORT,PIND_PIN,u8_binaryBuffer[3]);

}//_End of Decoder7447_vidRepresent().
