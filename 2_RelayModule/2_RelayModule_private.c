/*
 * 2_RelayModule_private.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Sky-pc
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/errorStates.h"

#include"../../MCAL/DIO/DIO_interface.h"

#include"2_RelayModule_private.h"
#include"2_RelayModule_Cnfg.h"


void RelayInit(struct relay* ref)
{
	DIO_enuSetPinDirection(ref->relayPort,  ref->relayPin,  DIO_OUTPUT_PIN);
	DIO_enuSetPinValue(ref->relayPort,  ref->relayPin,  DIO_LOW);
}
void RelayOn(struct relay* ref)
{
	DIO_enuSetPinValue(ref->relayPort,ref->relayPin,DIO_HIGH);
}
void RelayOff(struct relay* ref)
{
	DIO_enuSetPinValue(ref->relayPort,ref->relayPin,DIO_LOW);
}
Relay_t* relayConstructor(u8 port_ID,u8 pin_ID)
{
	Relay_t relay;

	relay.relayPort = port_ID;
	relay.relayPin  = pin_ID ;

	relay.relayInit = RelayInit;
	relay.relayOn   = RelayOn  ;
	relay.relayOff  = RelayOff ;

	return &relay;
}


/****************_2relayModul************************/

void  _2relayModul_off(_2RelayModule_t*  ref2relayMod){
	ref2relayMod->relay_1->relayOff(ref2relayMod->relay_1);
	ref2relayMod->relay_2->relayOff(ref2relayMod->relay_2);
}

void  _2relayModul_forwardDir(_2RelayModule_t*  ref2relayMod){
	ref2relayMod->relay_1->relayOn(ref2relayMod->relay_1);
	ref2relayMod->relay_2->relayOff(ref2relayMod->relay_2);

}
void  _2relayModul_backwardDir(_2RelayModule_t*  ref2relayMod){
	ref2relayMod->relay_1->relayOff(ref2relayMod->relay_1);
	ref2relayMod->relay_2->relayOn(ref2relayMod->relay_2);

}




