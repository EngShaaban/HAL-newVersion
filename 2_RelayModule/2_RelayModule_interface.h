/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  2_RelayModule_interface.h
 *       Module:  2_RelayModule
 *
 *  Description:  <Write File DESCRIPTION here>
 *
 *********************************************************************************************************************/
#ifndef HAL_2_RELAYMODULE_2_RELAYMODULE_INTERFACE_H_
#define HAL_2_RELAYMODULE_2_RELAYMODULE_INTERFACE_H_

/******************************************************************************************************************/
/*  Syntax          : _2RelayModule_Constructor(<PORTn_id> , <PINyn_id> , <PORTm_id> , <PINym_id>)                */
/*                    <PORTn_id> , <PINyn_id>    ----> to configure the first relay in the Module                 */
/*                    <PORTm_id> , <PINym_id>    ----> to configure the second relay in the Module                */
/*                                                                                                                */
/*  ex:                                                                                                           */
/*     +=====================================================================================================+    */
/*     |   _2RelayModule_t  relMod1 = _2RelayModule_Constructor(DIO_PORTD ,DIO_PIN6 , DIO_PORTD ,DIO_PIN7 ); |    */
/*     +=====================================================================================================+    */
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
_2RelayModule_t  _2RelayModule_Constructor(u8,u8,u8,u8 );

#endif /* HAL_2_RELAYMODULE_2_RELAYMODULE_INTERFACE_H_ */

/**********************************************************************************************************************
 *  END OF FILE: 2_RelayModule_interface.h
 *********************************************************************************************************************/
