/*
 * 2_RelayModule_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Sky-pc
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/errorStates.h"

#include"2_RelayModule_private.h"
#include"2_RelayModule_Cnfg.h"



//_2RelayModule_t  relayMod1 ;

//relayMod1 =  _2RelayModule_Constructor(u8 port1_ID,u8 pin1_ID,u8 port2_ID,u8 pin2_ID)

//relayMod1.off(&relayMod1).
void  _2relayModul_off(_2RelayModule_t*  ref2relayMod);
void  _2relayModul_forwardDir(_2RelayModule_t*  ref2relayMod);
void  _2relayModul_backwardDir(_2RelayModule_t*  ref2relayMod);

_2RelayModule_t  _2RelayModule_Constructor(u8 port1_ID,u8 pin1_ID,u8 port2_ID,u8 pin2_ID)
{
	_2RelayModule_t  RelayModule;

	RelayModule.relay_1   = relayConstructor(port1_ID,pin1_ID);
	RelayModule.relay_1->relayInit(RelayModule.relay_1);

	RelayModule.relay_2   = relayConstructor(port2_ID,pin2_ID);
	RelayModule.relay_2->relayInit(RelayModule.relay_2);

	RelayModule.off = _2relayModul_off;
	RelayModule.forwardDir = _2relayModul_forwardDir;
	RelayModule.backwardDir=_2relayModul_backwardDir;

	return 	RelayModule;

}
