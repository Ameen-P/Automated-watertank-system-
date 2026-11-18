 #include<lpc21xx.h>
#include"header.h"
void delay_sec(unsigned int sec)
{
T0PR=15000000-1;
T0TC=0;
T0PC=0;
T0TCR=0X00;
T0TCR=0X01;
while(T0TC<sec);
T0TCR=0X00;
}
void delay_ms(unsigned int m_s)
{
T0PR=15000-1;
T0TC=0;
T0PC=0;
T0TCR=0X00;
T0TCR=0X01;
while(T0TC<m_s);
T0TCR=0x00;
}

void delay_us(unsigned int m_s)
{
T0PR=14;
T0TC=0;
T0PC=0;
T0TCR=0X00;
T0TCR=0X01;
while(T0TC<m_s);
T0TCR=0x00;
}

