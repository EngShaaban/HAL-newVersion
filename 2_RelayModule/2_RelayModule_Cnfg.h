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

typedef struct _2relayModul{

	struct relay*                    relay_1;
	struct relay*                    relay_2;


	void (*off)(struct _2relayModul*);
	void (*forwardDir)(struct _2relayModul*);
	void (*backwardDir)(struct _2relayModul*);


}_2RelayModule_t;


#endif /* HAL_2_RELAYMODULE_2_RELAYMODULE_CNFG_H_ */
