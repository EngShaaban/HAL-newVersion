


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/errorStates.h"

#include "../../MCAL/USART\USART_Interface.h"

#include "GPS_Cnfg.h"
#include "GPS_Priv.h"

static STATE_t  Current_State = STATE_0 ;

u8 Local_NewChar  = 0 ;

static u8 index   = 0 ;

static u8 Long_u8TempArr[10]={0};

static u8 Lat_u8TempArr[10]={0};

static u8  DDD_u8Long = 0 ;
static f32 MMMMMM_f32Long = 0 ;


static u8  DD_u8Lat = 0 ;
static f32 MMMMMM_f32Lat = 0 ;

static u8 BUILDER_u8WLatIdx= 0 ;
static u8 BUILDER_u8WLongIdx = 0 ;


static u8 BUILDER_u8Lock = LOCK_OPEN ;

GPS_READ_t  GPS_read ;


//USART_enuRecieveByteASync(void (*Cpy_pFunc)(void*) , u8* Cpy_pu8Para );
STATE_t State_0( u8 c )
{

	if( (c == 'L') ){ return STATE_1 ;}

	else{ return  STATE_0  ;}

}

STATE_t State_1( u8 c )
{

	if( (c == 'L') ){ return STATE_2 ;}
	else{ return  STATE_0;  }

}

STATE_t State_2( u8 c )
{
/*
if(BUILDER_u8Lock == LOCK_OPEN ){

	if( (c == ',') ){ return STATE_3 ;}

	else if( (c == 'A') ){return STATE_0 ;}

	else{ return  STATE_2;  }
}else{return  STATE_0;}
*/
	if( (c == ',') ){ return STATE_3 ;}
	else{ return  STATE_0;}
}

STATE_t State_3( u8 c ){

	if( (c == ',') ){ return STATE_4 ;}
	else
	{
		//Read the Latitude.
		return  STATE_3;
	}

}

STATE_t State_4( u8 c )
{
	if( (c == ',') ){ return STATE_5 ;}

	else
	{
		//Read the Latitude Direction.

		return  STATE_4;
	}
}

STATE_t State_5( u8 c )
{

	if( (c == ',') ){ return STATE_6 ;}

	else
	{
		//Read the Long0/.itude.

		return  STATE_5;
	}

}

STATE_t State_6( u8 c )
{

	if( (c == ',') ){ return STATE_0 ;}

	else
	{
		//Read the Latitude Direction.

		return  STATE_6;
	}
}

void BUILDER_vidInit(void )
{
	// USART_enuRecieveByteASync(void (*Cpy_pFunc)(void*) , void* Cpy_pu8Para )

	USART_enuRecieveByteASync( BUILDER_vidBuildFram  , (void*)(&Local_NewChar) );

}

void BUILDER_vidBuildFram(void* para )
{
	Local_NewChar = *((u8*)para);

	if( Current_State == STATE_0 )
	{
		//G PGG A ,187,5404.2675,N,00159.7569,W,1,1
		Current_State = State_0( Local_NewChar );
	}
	else if(Current_State == STATE_1)
	{
		//,187,5404.2675,N,00159.7569,W,1,1
		Current_State = State_1( Local_NewChar );
	}
	else if(Current_State == STATE_2)
	{
		//187,5404.2675,N,00159.7569,W,1,1
		Current_State = State_2( Local_NewChar );

		index = 0 ;
	}
	else if(Current_State == STATE_3)
	{
		/*====================*/
		//_ Read the latitude.
		/*====================*/

		//  5404.2675,N,00159.7569,W,1,1
		Current_State = State_3( Local_NewChar );
		//|| (Local_NewChar == '.')
		//
		if(  (Local_NewChar != ',')&&(Local_NewChar != '.')  && (Local_NewChar >= '0')&& (Local_NewChar <= '9')  )
		{
			if(BUILDER_u8Lock == LOCK_OPEN )
			{
				BUILDER_vidWriteLatArr();
			}
			else
			{}
		}
		else
		{}


	}
	else if(Current_State == STATE_4)
	{
		//N,00159.7569,W,1,1
		//Latidx=0;
		//_ Read the latitude Direction.

		Current_State = State_4( Local_NewChar );

		if( Local_NewChar != ',')
		{
			//USART_enuSendByteSync( (u16 const*const)(&Local_NewChar)  );
			//LatDir[LatDiridx++]= Local_NewChar  ;
		}
		else
		{}
	}
	else if(Current_State == STATE_5)
	{

		//_ Read the Longitude.

		//ddd   mm.mmmm
		//001   59.7569

		Current_State = State_5( Local_NewChar );

		if(  (Local_NewChar != ',')&&(Local_NewChar != '.') && (Local_NewChar >= '0') && (Local_NewChar <= '9') )
		{

			//USART_enuSendByteSync( (u16 const*const)(&Local_NewChar)  );
			if(BUILDER_u8Lock == LOCK_OPEN )
			{
				BUILDER_vidWriteLongtArr();
			}
			else
			{}
		}
		else
		{}
	}
	else if(Current_State == STATE_6)
	{
		if(BUILDER_u8Lock == LOCK_OPEN){
			index = 0 ;
			BUILDER_vidLatDDConversion();
			BUILDER_vidLongDDConversion();
			/*
			for(u8 i =0; i < 9; i++)
			{
				Long_u8TempArr[i] = 0;
				Lat_u8TempArr[i] = 0;
			}
			*/
		}else{}
		//W,1,1

		//_ Read the Longitude Direction.
		Current_State = State_6(Local_NewChar );
	}
	else
	{}


}//End of BUILDER_vidBuildFram().


void BUILDER_vidWriteLatArr(void)
{
	Lat_u8TempArr[BUILDER_u8WLatIdx]= Local_NewChar - '0';
	BUILDER_u8WLatIdx++;


}//end of BUILDER_vidWriteLatArr().

void BUILDER_vidWriteLongtArr(void)
{
	Long_u8TempArr[BUILDER_u8WLongIdx]= Local_NewChar - '0';
	BUILDER_u8WLongIdx++;

}

/******************************************************************************
 *                                                                            *
 *     ddd   mm.mmmm  ----> ddd + (mm.mmmm/60)                                *
 * 	   001   59.7569  ----> 001 + (59.7569/60)                                *
 *                                                                            *
 *                                                                            *
 ******************************************************************************/

void BUILDER_vidLatDDConversion(void)
{
	BUILDER_vidAcquireLock();
	//BUILDER_u8Lock = LOCK_CLOSE;
	/* ====================================
	 * Latitude Decimal Degree Conversion.
       ====================================*/

	GPS_read.GPS_f32Latitude = 0.0;
	DD_u8Lat      = 0 ;
	MMMMMM_f32Lat = 0.0 ;

	//f32 Local_f32temp = 0.0;


	DD_u8Lat      = (Lat_u8TempArr[0] * 10) ;
	DD_u8Lat     += (Lat_u8TempArr[1] * 1 )  ;


	MMMMMM_f32Lat  = ((f32)Lat_u8TempArr[2] * 100000.0) ;
	MMMMMM_f32Lat += ((f32)Lat_u8TempArr[3] * 10000.0 ) ;
	MMMMMM_f32Lat += ((f32)Lat_u8TempArr[4] * 1000.0  ) ;
	MMMMMM_f32Lat += ((f32)Lat_u8TempArr[5] * 100.0   ) ;
	MMMMMM_f32Lat += ((f32)Lat_u8TempArr[6] * 10.0    ) ;
	MMMMMM_f32Lat += ((f32)Lat_u8TempArr[7] * 1.0     ) ;
//(f32)DDD_u8Long +(MMMMMM_f32Lat/10000/60);
	f32 Local_f32temp = (f32)DD_u8Lat +(MMMMMM_f32Lat/600000);

	GPS_read.GPS_f32Latitude = Local_f32temp ;

	//(*((volatile  u8*const)0x37))= DD_u8Lat ;

	BUILDER_u8WLatIdx = 0 ;

	//BUILDER_vidReleaseLock();


}//End of BUILDER_inlineVidLongDDConversion().



void BUILDER_vidLongDDConversion(void)
{
	//BUILDER_vidAcquireLock();
	//BUILDER_u8Lock = LOCK_CLOSE;
	/* ====================================
	 * Longitude Decimal Degree Conversion.
       ====================================*/
	GPS_read.GPS_f32Longitude = 0.0;
	DDD_u8Long     = 0  ;
	MMMMMM_f32Long = 0.0  ;

	f32 Local_f32temp = 0.0;

	DDD_u8Long      = Long_u8TempArr[0] * 100 ;
	DDD_u8Long     += Long_u8TempArr[1] * 10 ;
	DDD_u8Long     += Long_u8TempArr[2] * 1 ;

	MMMMMM_f32Long  = ((f32)Long_u8TempArr[3] * 100000.0) ;
	MMMMMM_f32Long += ((f32)Long_u8TempArr[4] * 10000.0 ) ;
	MMMMMM_f32Long += ((f32)Long_u8TempArr[5] * 1000.0  ) ;
	MMMMMM_f32Long += ((f32)Long_u8TempArr[6] * 100.0   ) ;
	MMMMMM_f32Long += ((f32)Long_u8TempArr[7] * 10.0    ) ;
	MMMMMM_f32Long += ((f32)Long_u8TempArr[8] * 1.0   ) ;

	Local_f32temp = (f32)DDD_u8Long +(MMMMMM_f32Long/600000);

	 GPS_read.GPS_f32Longitude = Local_f32temp ;

	//Long_u8TempArr[4]            Long_u8TempArr
	//(*((volatile  u8*const)0x34))= DDD_u8Long;

	BUILDER_u8WLongIdx = 0;


	BUILDER_vidReleaseLock();
	//BUILDER_u8Lock = LOCK_OPEN;

}//End of BUILDER_inlineVidLongDDConversion().

void BUILDER_vidAcquireLock(void)
{
	BUILDER_u8Lock = LOCK_CLOSE ;
}
void BUILDER_vidReleaseLock(void)
{
	BUILDER_u8Lock = LOCK_OPEN ;
}
u8 BUILDER_u8Check(void)
{
	return BUILDER_u8Lock;
}



