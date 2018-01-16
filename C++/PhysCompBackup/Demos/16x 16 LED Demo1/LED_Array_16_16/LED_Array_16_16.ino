//***************************************************************************

//***********************************************************************/
#include <Arduino.h>

//IO    
#define LEDARRAY_D 2
#define LEDARRAY_C 3
#define LEDARRAY_B 4
#define LEDARRAY_A 5
#define LEDARRAY_G 6
#define LEDARRAY_DI 7
#define LEDARRAY_CLK 8
#define LEDARRAY_LAT 9


unsigned char Display_Buffer[2];
const unsigned char  Word1[1][32] = 
{

0xFF,0x86,0xF6,0xF6,0x86,0xBF,0xBC,0xBD,0x85,0xF5,0xF4,0xF7,0xF7,0xF7,0xD7,0xEC,
0xFF,0x07,0xF7,0xF7,0x07,0xBF,0x03,0xBB,0xBB,0xBB,0x03,0xBF,0xB7,0xBB,0x81,0x3B,/*"强",1*/
};


void setup()
{
	pinMode(LEDARRAY_D, OUTPUT); 
	pinMode(LEDARRAY_C, OUTPUT);
	pinMode(LEDARRAY_B, OUTPUT);
	pinMode(LEDARRAY_A, OUTPUT);
	pinMode(LEDARRAY_G, OUTPUT);
	pinMode(LEDARRAY_DI, OUTPUT);
	pinMode(LEDARRAY_CLK, OUTPUT);
	pinMode(LEDARRAY_LAT, OUTPUT);
}

void loop()
{
	Display(Word1);	
}



//************************************************************

//*************************************************************
void Display(const unsigned char dat[][32])					
{
	unsigned char i;

	for( i = 0 ; i < 16 ; i++ )
	{
		digitalWrite(LEDARRAY_G, HIGH);		
		
		Display_Buffer[0] = dat[0][i];		
		Display_Buffer[1] = dat[0][i+16];

		Send(Display_Buffer[1]);
		Send(Display_Buffer[0]);

		digitalWrite(LEDARRAY_LAT, HIGH);					 
		delayMicroseconds(1);
	
		digitalWrite(LEDARRAY_LAT, LOW);
		delayMicroseconds(1);

		Scan_Line(i);							

		digitalWrite(LEDARRAY_G, LOW);
		
		delayMicroseconds(100);;			
	}	
}

//****************************************************

//****************************************************
void Scan_Line( unsigned char m)
{	
	switch(m)
	{
		case 0:			
			digitalWrite(LEDARRAY_D, LOW);digitalWrite(LEDARRAY_C, LOW);digitalWrite(LEDARRAY_B, LOW);digitalWrite(LEDARRAY_A, LOW); 					
			break;
		case 1:					
			digitalWrite(LEDARRAY_D, LOW);digitalWrite(LEDARRAY_C, LOW);digitalWrite(LEDARRAY_B, LOW);digitalWrite(LEDARRAY_A, HIGH); 		
			break;
		case 2:					
			digitalWrite(LEDARRAY_D, LOW);digitalWrite(LEDARRAY_C, LOW);digitalWrite(LEDARRAY_B, HIGH);digitalWrite(LEDARRAY_A, LOW); 		
			break;
		case 3:					
			digitalWrite(LEDARRAY_D, LOW);digitalWrite(LEDARRAY_C, LOW);digitalWrite(LEDARRAY_B, HIGH);digitalWrite(LEDARRAY_A, HIGH); 		
			break;
		case 4:
			digitalWrite(LEDARRAY_D, LOW);digitalWrite(LEDARRAY_C, HIGH);digitalWrite(LEDARRAY_B, LOW);digitalWrite(LEDARRAY_A, LOW); 		
			break;
		case 5:
			digitalWrite(LEDARRAY_D, LOW);digitalWrite(LEDARRAY_C, HIGH);digitalWrite(LEDARRAY_B, LOW);digitalWrite(LEDARRAY_A, HIGH); 		
			break;
		case 6:
			digitalWrite(LEDARRAY_D, LOW);digitalWrite(LEDARRAY_C, HIGH);digitalWrite(LEDARRAY_B, HIGH);digitalWrite(LEDARRAY_A, LOW); 		
			break;
		case 7:
			digitalWrite(LEDARRAY_D, LOW);digitalWrite(LEDARRAY_C, HIGH);digitalWrite(LEDARRAY_B, HIGH);digitalWrite(LEDARRAY_A, HIGH); 		
			break;
		case 8:
			digitalWrite(LEDARRAY_D, HIGH);digitalWrite(LEDARRAY_C, LOW);digitalWrite(LEDARRAY_B, LOW);digitalWrite(LEDARRAY_A, LOW); 		
			break;
		case 9:
			digitalWrite(LEDARRAY_D, HIGH);digitalWrite(LEDARRAY_C, LOW);digitalWrite(LEDARRAY_B, LOW);digitalWrite(LEDARRAY_A, HIGH); 		
			break;	
		case 10:
			digitalWrite(LEDARRAY_D, HIGH);digitalWrite(LEDARRAY_C, LOW);digitalWrite(LEDARRAY_B, HIGH);digitalWrite(LEDARRAY_A, LOW); 		
			break;
		case 11:
			digitalWrite(LEDARRAY_D, HIGH);digitalWrite(LEDARRAY_C, LOW);digitalWrite(LEDARRAY_B, HIGH);digitalWrite(LEDARRAY_A, HIGH); 		
			break;
		case 12:
			digitalWrite(LEDARRAY_D, HIGH);digitalWrite(LEDARRAY_C, HIGH);digitalWrite(LEDARRAY_B, LOW);digitalWrite(LEDARRAY_A, LOW); 		
			break;
		case 13:
			digitalWrite(LEDARRAY_D, HIGH);digitalWrite(LEDARRAY_C, HIGH);digitalWrite(LEDARRAY_B, LOW);digitalWrite(LEDARRAY_A, HIGH); 		
			break;
		case 14:
			digitalWrite(LEDARRAY_D, HIGH);digitalWrite(LEDARRAY_C, HIGH);digitalWrite(LEDARRAY_B, HIGH);digitalWrite(LEDARRAY_A, LOW); 		
			break;
		case 15:
			digitalWrite(LEDARRAY_D, HIGH);digitalWrite(LEDARRAY_C, HIGH);digitalWrite(LEDARRAY_B, HIGH);digitalWrite(LEDARRAY_A, HIGH); 		
			break;
		default : break;	
	}
}

//****************************************************
      
//****************************************************
void Send( unsigned char dat)
{
	unsigned char i;
	digitalWrite(LEDARRAY_CLK, LOW);
	delayMicroseconds(1);;	
	digitalWrite(LEDARRAY_LAT, LOW);
	delayMicroseconds(1);;

	for( i = 0 ; i < 8 ; i++ )
	{
		if( dat&0x01 )
		{
			digitalWrite(LEDARRAY_DI, HIGH);	
		}
		else
		{
			digitalWrite(LEDARRAY_DI, LOW);
		}

		delayMicroseconds(1);
		digitalWrite(LEDARRAY_CLK, HIGH);				  
			delayMicroseconds(1);
		digitalWrite(LEDARRAY_CLK, LOW);
			delayMicroseconds(1);		
		dat >>= 1;
			
	}			
}
