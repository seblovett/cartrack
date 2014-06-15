/*
 * cartrack.c
 *
 * Created: 15/06/2014 10:40:05
 *  Author: seblovett
 */ 


#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "DebugUsart/Uart.h"
#include "GSM/GSM.h"


int main(void)
{
	DDRB = 0x80;
	Uart_Init();
	printf("\n\n\rCar Track AVR\n\r");
	GSM_Init();
    while(1)
    { 
		PORTB ^= 0x80;
		GSM_Proc();
		_delay_ms(500);
    }
}