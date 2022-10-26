/*
 * DC_MOTRO_Cnfg.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Sky-pc
 */

#ifndef HAL_DC_MOTOR_DC_MOTRO_CNFG_H_
#define HAL_DC_MOTOR_DC_MOTRO_CNFG_H_

#define MAX_NUM_OF_DC_MOTORS     1

typedef enum dcMotorStatus
{
	DC_MOTOR_OFF  = 0  ,
	DC_MOTOR_CLOCKWISE ,
	DC_MOTOR_ANTICLOCKWISE

}DC_MotorState;

typedef struct dcMotorControl
{
	u8     port1_id;
	u8     pin1_id ;

	u8     port2_id;
	u8     pin2_id ;
}MotorControl_t;

typedef struct dc_motor
{
	DC_MotorState    initState ;


}DC_MOTOR_t;
extern DC_MOTOR_t DcMotorArr[MAX_NUM_OF_DC_MOTORS];
#endif /* HAL_DC_MOTOR_DC_MOTRO_CNFG_H_ */
