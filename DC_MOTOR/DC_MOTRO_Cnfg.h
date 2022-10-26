/*******************************************************************************************************************

 *  FILE DESCRIPTION
 *  ----------------------------------------------------------------------------------------------------------------
 *         File:  DC_MOTRO_Cnfg.h
 *       Module:  -
 *       Author:  Shaaban Abdullah
 *  Description:  <Write File DESCRIPTION here>
 *
 ******************************************************************************************************************/

#ifndef HAL_DC_MOTOR_DC_MOTRO_CNFG_H_
#define HAL_DC_MOTOR_DC_MOTRO_CNFG_H_

/******************************************************************************************************************
 *   GLOBAL CONSTANT MACROS
 *****************************************************************************************************************/
#define MAX_NUM_OF_DC_MOTORS     1    //_Spacify the number of DC_motors in your system.





/******************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *****************************************************************************************************************/
typedef enum dcMotorStatus
{
	DC_MOTOR_OFF  = 0  ,
	DC_MOTOR_CLOCKWISE ,
	DC_MOTOR_ANTICLOCKWISE

}DC_MotorState;

/*****************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 ****************************************************************************************************************/
typedef struct dcMotorControl
{
	u8     port1_id;
	u8     pin1_id ;

	u8     port2_id;
	u8     pin2_id ;
}MotorControl_t;

typedef struct dc_motor
{
	u8               motor_ID  ;

	DC_MotorState    initState ;

	MotorControl_t   controlPins;

}DC_MOTOR_t;

extern DC_MOTOR_t DcMotorArr[MAX_NUM_OF_DC_MOTORS];


#endif /* HAL_DC_MOTOR_DC_MOTRO_CNFG_H_ */

/****************************************************************************************************************
 *  END OF FILE: Std_Types.h
 ***************************************************************************************************************/

