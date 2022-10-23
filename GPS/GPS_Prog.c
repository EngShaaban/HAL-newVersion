/*****************************************************************************/
/*****************************************************************************/
/* Title                 :   GPS_Prog                                        */
/* Filename              :   GPS_Prog.c                                      */
/* Author                :   Shaban Abdullah Awad                            */
/* Created on            :   Mar 15, 2022                                    */
/* Version               :   0.0.0                                           */
/* Toolchain             :   avr-gcc (4.3.3)                                 */
/* Target                :   ATmega32                                        */
/* Notes                 :   None                                            */
/*                                                                           */
/*****************************************************************************/

/*****************************************************************************/
/******************************  INCLUDES  ***********************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/errorStates.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/USART/USART_Interface.h"


#include "GPS_Priv.h"
#include "GPS_Cnfg.h"



static GPS_FLAGS_t  GPS_Flags ;

extern GPS_READ_t  GPS_read ;


/****************************************************************************
 ****************************************************************************
 * Function Name   : GPS_enuInit.                                           *
 * Description     : Utility function to initialize the GPS module          *
 *                   according to the PGS Configurable structure.           *
 * Argument Type   : None .                                                 *
 * Return Type     : Error state of type ES_t.                              *
 **....................*****************************************************/
ES_t GPS_enuInit(void)
{

	ES_t Local_enuErrorState = ES_NOK ;


	//Read the Status of gps module and make the appropriate configuration.
	switch( GPS.GPS_STATE_t )
	{
	case gps_on :

		/****************************************************************************
		 *-Initialize the Direction of pins that the gps module is connected on to  *
		 * be an output pins and Set the suitable value for each.                                                       *
		 ****************************************************************************/
/*		if( ((GPS.GPS_VCC_PORT) != GPS_VCC_OUT ) && ((GPS.GPS_GND_PORT) != GPS_GND_OUT ) )
		{
			DIO_enuSetPinDirection( GPS.GPS_VCC_PORT , GPS.GPS_VCC_PIN , DIO_OUTPUT_PIN );
			DIO_enuSetPinValue( GPS.GPS_VCC_PORT , GPS.GPS_VCC_PIN , DIO_HIGH );

			DIO_enuSetPinDirection( GPS.GPS_GND_PORT , GPS.GPS_GND_PIN , DIO_OUTPUT_PIN );
			DIO_enuSetPinValue( GPS.GPS_GND_PORT , GPS.GPS_GND_PIN , DIO_LOW );

		}
		else
		{
			//_If This is the case then the GPS Module Powered from out source.
		}
*/
		GPS_CLEAR_ALL_FLAGSE();

		//Initiate the UART to receive read the gps output.

		Local_enuErrorState = ES_OK ;

		break ;

	case gps_off :
		//Do nothing.
		Local_enuErrorState = ES_OK ;
		break ;

	default:
		break;

	}//End of switch.


	BUILDER_vidInit();



	return Local_enuErrorState ;

}//End of GPS_enuInit(void).


/******************************************************************************************************************
 ******************************************************************************************************************
 * Function Name   : GPS_enuGetLocation.                                                                           *
 * Description     : Utility function to read a valid GPS Location and store it in the buffer to be                *
 *                   Processed.                                                                                    *
 * Argument Type   : Argu.1:         Address of f32 variable --->  To pass Latitude value.                         *
 *                   Argu.2:         Address of f32 variable --->  ~  ~   Longitude value.                         *
 *                   Argu.3:         Address of u8 variable  --->  ~  ~  Latitude Direction (E,w,N or S)           *
 *                   Argu.4:         Address of u8 variable  --->  ~  ~ Longitude  ~ (E,w,N or S)                  *
 * Return Type     : Error state of type ES_t.                                                                     *
 **.....................................................................................................************/

ES_t GPS_enuGetLocation(f32* Copy_pf32Lat , f32* Copy_pf32Long )
{
	ES_t Local_enuErrorState = ES_NOK ;
	while(BUILDER_u8Check() != LOCK_OPEN);
	//*Copy_pf32Lat = 0.0;
	//*Copy_pf32Long = 0.0;
	*Copy_pf32Lat = GPS_read.GPS_f32Latitude;
	*Copy_pf32Long = GPS_read.GPS_f32Longitude;



	return Local_enuErrorState ;

}//End of GPS_enuGetLocation.

/***************************** END OF FILE. **********************************/
/*****************************************************************************/

