/*****************************************************************************/
/*****************************************************************************/
/* Title                 :   GPS_Cnfg                                        */
/* Filename              :   GPS_Cnfg.h                                     */
/* Author                :   Shaban Abdullah Awad                            */
/* Created on            :   Mar 15, 2022                                    */
/* Version               :   0.0.0                                           */
/* Toolchain             :   avr-gcc (4.3.3)                                 */
/* Target                :   ATmega32                                        */
/* Notes                 :   None                                            */
/*                                                                           */
/*****************************************************************************/

/*****************************************************************************/
/****************************   FILE GUARDE  *********************************/
#ifndef GPS_CNFG_H_
#define GPS_CNFG_H_


typedef enum
{
	gps_on   ,
	gps_off  ,

}GPS_STATE_t;


typedef struct
{
	u8   GPS_STATE_t ;

	u8   GPS_VCC_PORT;
	u8   GPS_VCC_PIN;

	u8   GPS_GND_PORT;
	u8   GPS_GND_PIN;

}GPS_t;



extern GPS_t  GPS;


#endif /* GPS_CNFG_H_ */
/***************************** END OF FILE. **********************************/
/*****************************************************************************/

