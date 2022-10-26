/*
 * DC_MOTOR_porg.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Sky-pc
 */

#include"../../MCAL/DIO/DIO_interface.h"

#include"../2_RelayModule/2_RelayModule_Cnfg.h"
#include"../2_RelayModule/2_RelayModule_interface.h"

_2RelayModule_t     relMod1;

void DCMOTOR_vidInit()
{

	relMod1 = _2RelayModule_Constructor(DIO_PORTD ,DIO_PIN6 , DIO_PORTD ,DIO_PIN7 );

}
void DCMOTOR_vidOff()
{
	relMod1.off(&relMod1);
}
void DCMOTOR_vidClockwise()
{
	relMod1.forwardDir(&relMod1);
}
void DCMOTOR_vidAnticlockwise()
{
	relMod1.backwardDir(&relMod1);
}
void DCMOTOR_vidGetstatus()
{
	}
