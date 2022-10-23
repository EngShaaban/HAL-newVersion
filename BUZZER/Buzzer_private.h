/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Buzzer_private.h
 *       Module:  Buzzer
 *
 *  Description:  <Write File DESCRIPTION here>
 *
 *********************************************************************************************************************/
#ifndef HAL_BUZZER_BUZZER_PRIVATE_H_
#define HAL_BUZZER_BUZZER_PRIVATE_H_

/**********************************************************************************************************************
 *  PRIVATE FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void      BUZZER_vidOn(Buzzer_t*        refBuzzer);
void      BUZZER_vidOff(Buzzer_t*       refBuzzer);
state_e   BUZZER_vidGetState(Buzzer_t*  refBuzzer);


#endif /* HAL_BUZZER_BUZZER_PRIVATE_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/