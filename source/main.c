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
	DDRC = 0xFF; PORTB = 0x00;
	
	unsigned char temp = 0x00;
	unsigned char fuel = 0;
    	while (1) 
	{
		fuel = PINA & 0x0F;
		if (fuelLevel >= 1)
		{
			tmpC = SetBit(tmpC, 5, 1); 
		}

		if (fuelLevel >= 3)
		{
			tmpC = SetBit(tmpC, 4, 1); 
		}
		
		if (fuelLevel <= 4) // low fuel warning
		{
			tmpC = SetBit(tmpC, 6, 1); 
		}
		
		if (fuelLevel >= 5)
		{
			tmpC = SetBit(tmpC, 6, 0); 
			tmpC = SetBit(tmpC, 3, 1); 
		}

		if (fuelLevel >= 7)
		{
			tmpC = SetBit(tmpC, 2, 1);
		}

		if (fuelLevel >= 10)
		{
			tmpC = SetBit(tmpC, 1, 1);
		}

		if (fuelLevel >= 13)
		{
			tmpC = SetBit(tmpC, 0, 1);
		}

	 		PORTC = tmpC;	
		
    	}
    	return 1;
}
