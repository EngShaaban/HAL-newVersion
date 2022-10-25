/*
 *
 *
 *  Created on: ??þ/??þ/????
 *      Author: Sky-pc
 */






/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  2_RelayModule_Cnfg.h
 *       Module:  tow-relay module
 *       Author:  Shaaban Abdullah
 *  Description:  <Write File DESCRIPTION here>
 *
 *********************************************************************************************************************/
#ifndef HAL_2_RELAYMODULE_2_RELAYMODULE_CNFG_H_
#define HAL_2_RELAYMODULE_2_RELAYMODULE_CNFG_H_

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
	off =  0 ,
	forward,
	backward
}_2relayModulState_t;

typedef struct relay
{
	u8  relayPort ;
	u8  relayPin  ;

}Relay_t;

typedef struct _2relayModul
{

	Relay_t   arr[2];

	void (*off)(struct _2relayModul const*const);
	void (*forwardDir)(struct _2relayModul const*const);
	void (*backwardDir)(struct _2relayModul const*const);


}_2RelayModule_t;


#endif /* HAL_2_RELAYMODULE_2_RELAYMODULE_CNFG_H_ */
/**********************************************************************************************************************
 *  END OF FILE: 2_RelayModule_Cnfg.h
 *********************************************************************************************************************/
