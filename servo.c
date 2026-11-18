#include<lpc21xx.h>

#include "header.h"


#define SERVO (1<<8)	 // 1<<7
/*
void servo_init(void)

{

PINSEL0|=1<<17;			//2<<14


PWMPR = 14;

PWMMR0=20000;

PWMMR4=1500;

PWMMCR = (1<<1);
//PWMPCR = (1<<12);
PWMLER =(1<<0)|(1<<4);

PWMPCR = (1<<12);

//PWMTCR = (1<<1);

PWMTCR =(1<<0)|(1<<3);

}


void servo_0deg(void)

{

PWMMR4=1000;

PWMLER=(1<<4);

}


void servo_90deg(void)

{

  PWMMR4=1500;

PWMLER=(1<<4);

}

void servo_180deg(void)

{

  PWMMR4=2000;

PWMLER=(1<<4);

}	*/


void servo_init(void)
{
   PINSEL0=(PINSEL0 & ~(3 <<16))|(2<<16);

   PWMTCR=(1<<1);
   PWMPR=14;

   PWMMR0=20000;

   PWMMR4=1500;
   PWMMCR=(1<<1);
   PWMLER=(1<<0)|(1<<4);
   PWMPCR=(1<<12);
   PWMTCR=(1<<0)|(1<<3);

		 }

void servo_0deg(void)

{

PWMMR4=1000;

PWMLER=(1<<4);

}


void servo_90deg(void)

{

  PWMMR4=1500;

PWMLER=(1<<4);

}

void servo_180deg(void)

{

  PWMMR4=2000;

PWMLER=(1<<4);
}
