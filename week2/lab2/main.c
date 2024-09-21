/*
 * main.c
 *
 *  Created on: Sep 21, 2024
 *      Author: sameh
 */

#include "stdTypes.h"
#include <util/delay.h>

#define DDRA *((u8*)0x3A)
#define PORTA *((u8*)0x3B)
#define PINA *((volatile u8*)0x39)

#define DDRB *((u8*)0x37)
#define PORTB *((u8*)0x38)
#define PINB *((volatile u8*)0x36)

int main(void)
{
	int s7[]={0x3F ,0x06, 0X5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
	int count=0;
	DDRA &= ~(1<<0);
	DDRA &= ~(1<<1);

	PORTA |= (1<<0);
	PORTA |= (1<<1);

	DDRB = 0xFF;
	PORTB =0;
	while(1)
	{
		if(count >=0 && count <10)
		{
			if(((PINA>>0)&1)==0)
			{
				count++;
				PORTB =s7[count];
				while(((PINA>>0)&1)==0);
			}
			else if(((PINA>>1)&1)==0)
			{
				count--;
				PORTB =s7[count];
				while(((PINA>>1)&1)==0);
			}
		}
	}
	return 0;
}
