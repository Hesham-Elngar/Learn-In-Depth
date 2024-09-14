/*
 * section_1.c
 *
 * Created: 7/14/2024 10:34:02 AM
 * Author : super magic
 */ 
#include<util/delay.h>
#include "MemoryMap.h"
#define F_CPU 8000000UL
#define  get_bit(reg,bit) ((reg>>bit)&1)
int main(void)
{
	DDRA|=0xff;
	DDRC|=0x01;
    while (1) 
    {
		if (get_bit(PINC,0)==1)
		{
			
				for(int i=0;i<8;++i)
				{
					PORTA |= (1<<i);
					_delay_ms(100);
				}
				while(get_bit(PINC,0)==0);
				for(int i=7;i>=0;--i)
				{
					PORTA &= ~(1<<i);
					_delay_ms(100);
				}
				while(get_bit(PINC,0)==0);
		}
    }
}

