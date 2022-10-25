/*
 * 2_RelayModule_private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Sky-pc
 */

#ifndef HAL_2_RELAYMODULE_2_RELAYMODULE_PRIVATE_H_
#define HAL_2_RELAYMODULE_2_RELAYMODULE_PRIVATE_H_


typedef struct relay
{
	/*_ relay attributes.*/
	u8  relayPort ;
	u8  relayPin  ;

	/*_ relay actions.*/
	void (*relayInit)(struct relay*);
	void (*relayOn)(struct relay*);
	void (*relayOff)(struct relay*);

}Relay_t;

Relay_t* relayConstructor(u8 port_ID,u8 pin_ID);


//void  _2relayModul_off(struct _2relayModul* );
//void  _2relayModul_forwardDir(struct _2relayModul*);
//void  _2relayModul_backwardDir(struct _2relayModul*);


#endif /* HAL_2_RELAYMODULE_2_RELAYMODULE_PRIVATE_H_ */
