/****************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------
 *         File:  Buzzer_interface.h
 *       Module:  Buzzer
 *
 *  Description:  <Write File DESCRIPTION here>
 *
 ***************************************************************************/
#ifndef HAL_BUZZER_BUZZER_INTERFACE_H_
#define HAL_BUZZER_BUZZER_INTERFACE_H_

/***************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **************************************************************************/
typedef struct buzzer
{

	u8   BUZZER_PORT           ;
	u8   BUZZER_PIN            ;
	u8   BUZZER_PIN_INIT_STATE ;

	void   (*On)(struct buzzer*);
	void   (*Off)(struct buzzer*);
	state_e   (*GetState)(struct buzzer*);

}Buzzer_t;

/*******************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 ******************************************************************************/

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
Buzzer_t   BUZZER_vidConstructor( state_e initState ,u8 buzzerPort , u8  buzzerPin);


#endif /* HAL_BUZZER_BUZZER_INTERFACE_H_ */

/*****************************************************************************
 *  END OF FILE: Std_Types.h
 ******************************************************************************/
