/*	Author: kma023
 *  Partner(s) Name: none
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif
//bit access functions
unsigned char SetBit(unsigned char x, unsigned char k, unsigned char b) {
	return (b ? x | (0x01 << k) : x & ~(0x01 << k));
}

unsigned char GetBit(unsigned char x, unsigned char k) {
	return ((x & (0x01 << k)) != 0);
}

int main(void) {
	
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	
	unsigned char temp = 0x00;
	unsigned char fuel = 0;
    	while (1) 
	{
		fuel = PINA & 0x0F;
		if (fuel >= 1)
		{
			temp = SetBit(temp, 5, 1); 
		}

		if (fuel >= 3)
		{
			temp = SetBit(temp, 4, 1); 
		}
		
		if (fuel <= 4) // low fuel warning
		{
			temp = SetBit(temp, 6, 1); 
		}
		
		if (fuel >= 5)
		{
			temp = SetBit(temp, 6, 0); 
			temp = SetBit(temp, 3, 1); 
		}

		if (fuel >= 7)
		{
			temp = SetBit(temp, 2, 1);
		}

		if (fuel >= 10)
		{
			temp = SetBit(temp, 1, 1);
		}

		if (fuel >= 13)
		{
			temp = SetBit(temp, 0, 1);
		}

	 		PORTC = temp;	
		
    	}
    	return 1;
}
