/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  2_RelayModule_prog.c
 *        \brief
 *        Author  Shaaban Abdullah
 *      \details
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/errorStates.h"

#include"../../MCAL/DIO/DIO_interface.h"

#include"2_RelayModule_private.h"
#include"2_RelayModule_Cnfg.h"


/********************************************************************************
 *  LOCAL FUNCTIONS
 *******************************************************************************/
void Off(struct  _2relayModul const*const  ref)
{
	DIO_enuSetPinValue(ref->arr[0].relayPort,ref->arr[0].relayPin,DIO_HIGH);
	DIO_enuSetPinValue(ref->arr[1].relayPort,ref->arr[1].relayPin,DIO_HIGH);
}
void forwardDir(struct _2relayModul const*const  ref )
{
	DIO_enuSetPinValue(ref->arr[0].relayPort,ref->arr[0].relayPin,DIO_HIGH);
	DIO_enuSetPinValue(ref->arr[1].relayPort,ref->arr[1].relayPin,DIO_LOW);
}
void backwardDir(struct _2relayModul const*const  ref)
{
	DIO_enuSetPinValue(ref->arr[0].relayPort,ref->arr[0].relayPin,DIO_LOW);
	DIO_enuSetPinValue(ref->arr[1].relayPort,ref->arr[1].relayPin,DIO_HIGH);
}
/*******************************************************************************
 *  GLOBAL FUNCTIONS
 ******************************************************************************/


/******************************************************************************************************************/
/*  Syntax          : _2RelayModule_Constructor(<PORTn_id> , <PINyn_id> , <PORTm_id> , <PINym_id>)                */
/*                    <PORTn_id> , <PINyn_id>    ----> to configure the first relay in the Module                 */
/*                    <PORTm_id> , <PINym_id>    ----> to configure the second relay in the Module                */
/*                                                                                                                */
/*  ex:                                                                                                           */
/*     +-----------------------------------------------------------------------------------------------------+    */
/*     |  _2RelayModule_t  relMod1 = _2RelayModule_Constructor(DIO_PORTD ,DIO_PIN6 , DIO_PORTD ,DIO_PIN7 );  |    */
/*     +-----------------------------------------------------------------------------------------------------+    */
/*                                                                                                                */
/*  Description     : Tow-relay Module Construction function according to its                                     */
/*                    parameter list.                                                                             */
/*                                                                                                                */
/*  Sync\Async      : Synchronous                                                                                 */
/*  Reentrancy      : Non Reentrant                                                                               */
/*  Parameters (in) : port1_ID or port2_ID --> Any valid port id:   DIO_PORTA  DIO_PORTC                          */
/*                                                                  DIO_PORTB  DIO_PORTD                          */
/*                                                                                                                */
/*                    pin1_ID or pin2_ID --> Any valid pin id:      DIO_PIN0   DIO_PIN4                           */
/*                                                                  DIO_PIN1   DIO_PIN5                           */
/*                                                                  DIO_PIN2   DIO_PIN6                           */
/*                                                                  DIO_PIN3   DIO_PIN7                           */
/*                                                                                                                */
/*  Parameters (out): None                                                                                        */
/*  Return value:     variable of type _2RelayModule_t                                                            */
/*                                                                                                                */
/******************************************************************************************************************/
_2RelayModule_t  _2RelayModule_Constructor(u8 port1_ID,u8 pin1_ID,u8 port2_ID,u8 pin2_ID)
{
	_2RelayModule_t  RelayModule;

	/*************************************************************************************************************/
	/*1_ initiate the relays structure by the parameter list.                                                    */
	/*-----------------------------------------------------------------------------------------------------------*/
	RelayModule.arr[0].relayPort= port1_ID;
	RelayModule.arr[0].relayPin= pin1_ID;

	RelayModule.arr[1].relayPort= port2_ID;
	RelayModule.arr[1].relayPin= pin2_ID;
	/*************************************************************************************************************/


	/*************************************************************************************************************/
	/*2_ Set the direction of initial values of relays.                                                          */
	/*-----------------------------------------------------------------------------------------------------------*/
	DIO_enuSetPinDirection(RelayModule.arr[0].relayPort,RelayModule.arr[0].relayPin,DIO_OUTPUT_PIN);
	DIO_enuSetPinDirection(RelayModule.arr[1].relayPort,RelayModule.arr[1].relayPin,DIO_OUTPUT_PIN);

	DIO_enuSetPinValue(RelayModule.arr[0].relayPort,RelayModule.arr[0].relayPin,DIO_HIGH);
	DIO_enuSetPinValue(RelayModule.arr[1].relayPort,RelayModule.arr[1].relayPin,DIO_HIGH);
	/*************************************************************************************************************/

	/*************************************************************************************************************/
	/*3_ initiate the pointers of functions that represents the action of tow-relay module.                      */
	/*-----------------------------------------------------------------------------------------------------------*/
	RelayModule.off = Off ;
	RelayModule.forwardDir=forwardDir;
	RelayModule.backwardDir=backwardDir;
	/*************************************************************************************************************/

	/*_now i'm ready to go.*/
	return 	RelayModule;

}

/*******************************************************************************************************************
 *  END OF FILE: F2_RelayModule_prog.c
 *******************************************************************************************************************/

