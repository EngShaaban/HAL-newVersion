/*
 * 2_RelayModule_Cnfg.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Sky-pc
 */

#ifndef HAL_2_RELAYMODULE_2_RELAYMODULE_CNFG_H_
#define HAL_2_RELAYMODULE_2_RELAYMODULE_CNFG_H_
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

	void (*off)(struct _2relayModul*);
	void (*forwardDir)(struct _2relayModul*);
	void (*backwardDir)(struct _2relayModul*);


}_2RelayModule_t;


#endif /* HAL_2_RELAYMODULE_2_RELAYMODULE_CNFG_H_ */
