/*****************************************************************************/
/*****************************************************************************/
/* Title                 :   GPS_Interface                                   */
/* Filename              :   GPS_Interface.h                                 */
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
#ifndef GPS_INTERFACE_H_
#define GPS_INTERFACE_H_

/*****************************************************************************/
/***************************   PUBLIC MACROS  ********************************/
#define GPS_VCC_OUT          0
#define GPS_GND_OUT          1


/****************************************************************************
 ****************************************************************************
 * Function Name   : GPS_enuInit.                                           *
 * Description     : Utility function to initialize the GPS module          *
 *                   according to the PGS Configurable structure.           *
 * Argument Type   : None .                                                 *
 * Return Type     : Error state of type ES_t.                              *
 **....................*****************************************************/
ES_t GPS_enuInit(void);



/**********************************************************************************************************
 **********************************************************************************************************
 * Function Name   : GPS_enuGetLocation.                                                                   *
 * Description     : Utility function to read a valid GPS Location and store it in the buffer to be        *
 *                   Processed.                                                                            *
 * Argument Type   : Argu.1:         Address of f32 variable --->  To pass Latitude value.                 *
 *                   Argu.2:         Address of f32 variable --->  ~  ~   Longitude value.                 *
 *                   Argu.3:         Address of u8 variable  --->  ~  ~  Latitude Direction (E,w,N or S)   *
 *                   Argu.4:         Address of u8 variable  --->  ~  ~ Longitude  ~ (E,w,N or S)          *
 * Return Type     : Error state of type ES_t.                                                             *
 **.....................................................................................................****/
ES_t GPS_enuGetLocation(f32* Copy_pf32Lat , f32* Copy_pf32Long );








#endif /* GPS_INTERFACE_H_ */

/********************************************** END OF FILE. **********************************************/
/**********************************************************************************************************/

