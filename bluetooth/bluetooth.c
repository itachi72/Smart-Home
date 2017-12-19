/*
 * bluetooth.c
 *
 * Created: 27-12-2015 18:27:12
 *  Author: HCL
 */ 


#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

//I AM NOT ABLE TO TRANSMIT A STRING...
void init(void)
{
	UBRRL=0X33;
	UCSRB=(1<<RXEN)|(1<<TXEN);
	UCSRC=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
} 
void tx(unsigned char a)
{
	UDR=a;
	while((UCSRA&(1<<TXC))==0);
}
unsigned char rx()
{int i=0;
	unsigned string *b;
	*b=UDR;
	while(!(UCSRA&(1<<RXC)));
	/*while(*b!='\0')
	{
	}
	do 
	{b=UDR;
		while(!(UCSRA&(1<<RXC)));
		b++;
	} ;*/
	return(*b);
}

int main(void)
{  unsigned char *p;
	DDRD=0X02;
	DDRA=0XFF;
	init();
	while(1)
    {
       *p=rx();
	   if(*p=='n')
	   PORTA=0X0f;
	   /*else if(*p=="Neelu"|*p=="neelu"|*p=="NEELU")
	   {
		   PORTA=0X01;
		   _delay_ms(1000);
	   }
	   else if(*p=="Sapna"|*p=="Mummy")
	   {
		   PORTA=0X02;
	   }
	   else if(*p=="Rachna"|*p=="Sweety")
      {		   PORTA=0X04;
	   }
	   else if(*p=="Anju"|*p=="Atul")
	   {
		   PORTA=0X08;
	   }*/
	   
	   else
	   PORTA=0X00;
}
}