/*
 * SevenSeg_cnfg.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Sky-pc
 */

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#ifndef HAL_7_SEG_SEVENSEG_CNFG_H_
#define HAL_7_SEG_SEVENSEG_CNFG_H_

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


#define NUMBER_OF_7SEG     4

typedef enum
{
	commonAnode  = 0  ,
	commonCathod
}SevSegType_e;

typedef struct sevenSeg
{
	u8             sevenSeg_ID;
	SevSegType_e   type       ;

	u8             enablePort ;
	u8             enablePin  ;

}SevenSeg_t;

extern  SevenSeg_t    SevenSeg[NUMBER_OF_7SEG] ;

#endif /* HAL_7_SEG_SEVENSEG_CNFG_H_ */
