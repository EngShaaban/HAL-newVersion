/*
 * SevenSeg_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Sky-pc
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/errorStates.h"

#include"../../MCAL/DIO/DIO_interface.h"

#include"../7447_Decoder/7447_Decoder_interface.h"

#include"SevenSeg_private.h"
#include"SevenSeg_cnfg.h"


#include<util\delay.h>


void  SevenSeg_vidInit(SevenSeg_t*    sevenSegRef)
{
	Decoder7447_vidInit();

	for(u8 Local_u8iterator = 0 ; Local_u8iterator < NUMBER_OF_7SEG ;Local_u8iterator++ )
	{
		DIO_enuSetPinDirection(sevenSegRef[Local_u8iterator].enablePort,sevenSegRef[Local_u8iterator].enablePin,DIO_OUTPUT_PIN);


		switch(sevenSegRef[Local_u8iterator].type)
		{

		case commonCathod:
			DIO_enuSetPinValue(sevenSegRef[Local_u8iterator].enablePort,
					sevenSegRef[Local_u8iterator].enablePin,
					DIO_LOW);
			break;

		case commonAnode:
			DIO_enuSetPinValue(sevenSegRef[Local_u8iterator].enablePort,
					sevenSegRef[Local_u8iterator].enablePin,
					DIO_HIGH);
			break;

		default:
			break;

		}//_end of switch.
	}//_end of for loop.
}//_end of function.

void  SevenSeg_vidDiplay(u16 Cpy_u16Num )
{

	u8  Local_u8Rem  = 0 ;
    s8 indx = NUMBER_OF_7SEG-1      ;
	u8 Local_u8Buffer[NUMBER_OF_7SEG] = {0} ;

	while(Cpy_u16Num)
	{
		Local_u8Rem  = Cpy_u16Num %10 ;

		Local_u8Buffer[indx] = Local_u8Rem ;

		indx--;

		Cpy_u16Num /=10;
	}

	indx++    ;

	for(; indx < NUMBER_OF_7SEG ;indx++)
	{
		Decoder7447_vidRepresent(Local_u8Buffer[indx] );

		DIO_enuToggelPin(SevenSeg[indx].enablePort,SevenSeg[indx].enablePin);
		_delay_us(100);
		DIO_enuToggelPin(SevenSeg[indx].enablePort,SevenSeg[indx].enablePin);

	}

}//_end SevenSeg_vidInit().
