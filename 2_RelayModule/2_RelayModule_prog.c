/*
 * 2_RelayModule_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Sky-pc
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/errorStates.h"

#include"../../MCAL/DIO/DIO_interface.h"

#include"2_RelayModule_private.h"
#include"2_RelayModule_Cnfg.h"



//_2RelayModule_t  relayMod1 ;

//relayMod1 =  _2RelayModule_Constructor(u8 port1_ID,u8 pin1_ID,u8 port2_ID,u8 pin2_ID)

//relayMod1.Off(&relayMod1);

void Off(struct  _2relayModul*   ref)
{
	DIO_enuSetPinValue(ref->arr[0].relayPort,ref->arr[0].relayPin,DIO_HIGH);
	DIO_enuSetPinValue(ref->arr[1].relayPort,ref->arr[1].relayPin,DIO_HIGH);
}
void forwardDir(struct _2relayModul*  ref )
{
	DIO_enuSetPinValue(ref->arr[0].relayPort,ref->arr[0].relayPin,DIO_HIGH);
	DIO_enuSetPinValue(ref->arr[1].relayPort,ref->arr[1].relayPin,DIO_LOW);
}
void backwardDir(struct _2relayModul* ref)
{
	DIO_enuSetPinValue(ref->arr[0].relayPort,ref->arr[0].relayPin,DIO_LOW);
	DIO_enuSetPinValue(ref->arr[1].relayPort,ref->arr[1].relayPin,DIO_HIGH);
}

_2RelayModule_t  _2RelayModule_Constructor(u8 port1_ID,u8 pin1_ID,u8 port2_ID,u8 pin2_ID)
{
	_2RelayModule_t  RelayModule;

	RelayModule.arr[0].relayPort= port1_ID;
	RelayModule.arr[0].relayPin= pin1_ID;

	RelayModule.arr[1].relayPort= port2_ID;
	RelayModule.arr[1].relayPin= pin2_ID;

	/*************************************/
	DIO_enuSetPinDirection(RelayModule.arr[0].relayPort,RelayModule.arr[0].relayPin,DIO_OUTPUT_PIN);
	DIO_enuSetPinDirection(RelayModule.arr[1].relayPort,RelayModule.arr[1].relayPin,DIO_OUTPUT_PIN);

	DIO_enuSetPinValue(RelayModule.arr[0].relayPort,RelayModule.arr[0].relayPin,DIO_HIGH);
	DIO_enuSetPinValue(RelayModule.arr[1].relayPort,RelayModule.arr[1].relayPin,DIO_HIGH);

	/*************************************/

	RelayModule.off = Off ;
	RelayModule.forwardDir=forwardDir;
	RelayModule.backwardDir=backwardDir;

	return 	RelayModule;

}
