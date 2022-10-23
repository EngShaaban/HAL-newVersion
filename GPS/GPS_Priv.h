/*****************************************************************************/
/*****************************************************************************/
/* Title                 :   GPS_Priv                                        */
/* Filename              :   GPS_Priv.h                                      */
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
#ifndef GPS_PRIV_H_
#define GPS_PRIV_H_



#define    GPS_VCC_OUT                 (0U)
#define    GPS_GND_OUT                 (1U)

#define    GPS_LINE_LENGTH             (55U)

#define    LOCK_CLOSE                  (0U)
#define    LOCK_OPEN                   (1U)


typedef union
{
	u8 FLAGS ;

	struct
	{
		u8   GPGGA_LINE_FLAG:           1 ;
		u8   LAT_COMMA_FLAG :           1 ;
		u8   LONG_COMMA_FLAG:           1 ;
		u8   FIRST_DIR_FLAG :           1 ;
		u8   SECOND_DIR_FLAG:           1 ;
		u8   DOT_FLAG       :           1 ;
	}FLAG;

}GPS_FLAGS_t;


typedef struct
{
	f32  GPS_f32Latitude  ;
	f32  GPS_f32Longitude ;

}GPS_READ_t;



/*****************************************************************************/
/********************* PRIVATE FUNCTIONS LIKE MACROS *************************/

#define GPS_CLEAR_ALL_FLAGSE()          GPS_Flags.FLAGS = 0

#define GPS_SET_LINE_FLAG()             GPS_Flags.FLAG.GPGGA_LINE_FLAG  = 1
#define GPS_SET_LAT_FLAG()              GPS_Flags.FLAG.LAT_COMMA_FLAG   = 1
#define GPS_SET_LONG_FLAG()             GPS_Flags.FLAG.LONG_COMMA_FLAG  = 1
#define GPS_SET_DOT_FLAG()              GPS_Flags.FLAG.DOT_FLAG         = 1
#define GPS_SET_FIRST_DIR_FLAG()        GPS_Flags.FLAG.FIRST_DIR_FLAG   = 1
#define GPS_SET_SEC_DIR_FLAG()          GPS_Flags.FLAG.SECOND_DIR_FLAG  = 1

#define GPS_CLEAR_LINE_FLAG()           GPS_Flags.FLAG.GPGGA_LINE_FLAG  = 0
#define GPS_CLEAR_LAT_FLAG()            GPS_Flags.FLAG.LAT_COMMA_FLAG   = 0
#define GPS_CLEAR_LONG_FLAG()           GPS_Flags.FLAG.LONG_COMMA_FLAG  = 0
#define GPS_CLEAR_DOT_FLAG()            GPS_Flags.FLAG.DOT_FLAG         = 0
#define GPS_CLEAR_FIRST_DIR_FLAG()      GPS_Flags.FLAG.FIRST_DIR_FLAG   = 0
#define GPS_CLEAR_SEC_DIR_FLAG()        GPS_Flags.FLAG.SECOND_DIR_FLAG  = 0


/*****************************************************************************/
/********************* PRIVATE FUNCTIONS DECLARATIONS ************************/
typedef enum
{
	STATE_0   ,
	STATE_1   ,
	STATE_2   ,
	STATE_3   ,
	STATE_4   ,
	STATE_5   ,
	STATE_6

}STATE_t;

STATE_t State_0( u8 c );
STATE_t State_1( u8 c );
STATE_t State_2( u8 c );
STATE_t State_3( u8 c );
STATE_t State_4( u8 c );
STATE_t State_5( u8 c );
STATE_t State_6( u8 c );


void BUILDER_vidInit(void );

void BUILDER_vidBuildFram(void* para );

void BUILDER_vidWriteLatArr(void);
void BUILDER_vidWriteLongtArr(void);


void BUILDER_vidLongDDConversion(void);
void BUILDER_vidLatDDConversion(void);

void BUILDER_vidAcquireLock(void);
void BUILDER_vidReleaseLock(void);

u8 BUILDER_u8Check(void);




#endif /* GPS_PRIV_H_ */

/***************************** END OF FILE. **********************************/
/*****************************************************************************/


