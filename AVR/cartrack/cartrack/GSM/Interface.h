/*
 * Interface.h
 *
 * Created: 15/06/2014 12:05:45
 *  Author: seblovett
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <util/delay.h>

#ifndef INTERFACE_H_
#define INTERFACE_H_

#define CIRBUF_SIZE 128

//power pin config
#define PWR_DDR		DDRD
#define PWR_PORT	PORTD
#define PWR_PIN		PD4

void Interface_SendString(char *s);
void Interface_SendChar(uint8_t c);
void Interface_Init(void);
void Dump_Buf(void);
void Pulse_Power(void);


// could implement an overflow?
typedef struct  {
	uint8_t ReadPtr;
	uint8_t WritePtr;
	uint8_t Buffer[CIRBUF_SIZE];
	} CircularBuf_t;

CircularBuf_t circBuf;

__inline__ void Circ_Write_Char(uint8_t c)
{
	//check if full
	if(circBuf.WritePtr == (CIRBUF_SIZE -1)	) //wp is at end
	{
		if (circBuf.ReadPtr != 0)
		{
			circBuf.Buffer[circBuf.WritePtr] = c;
			circBuf.WritePtr = 0; //move to the beginning
		}
		//else it is full, data is discarded
	}
	else if (circBuf.WritePtr != (circBuf.ReadPtr - 1))
	{
		circBuf.Buffer[circBuf.WritePtr++] = c;
	}
	//else wp is one below rp - buffer is full
}

__inline__ uint8_t Circ_Read_Char()
{
	//check if there is data to be read
	if(circBuf.ReadPtr == circBuf.WritePtr) //no data
	{
		return 0;
	}
	else
	{
		if(circBuf.ReadPtr == (CIRBUF_SIZE -1)) //at the end
		{
			circBuf.ReadPtr = 0;
			return circBuf.Buffer[CIRBUF_SIZE -1];
		}
		else
			return circBuf.Buffer[circBuf.ReadPtr++];
	}
}


uint8_t Circ_Count(void);
// //__inline__ uint8_t Circ_Count()
// {
// 	uint8_t retval;
// 	if (circBuf.ReadPtr <= circBuf.WritePtr) //not wrapped
// 		retval = circBuf.WritePtr - circBuf.ReadPtr; //return the diff
// 	else
// 		retval = (circBuf.WritePtr + (CIRBUF_SIZE - circBuf.ReadPtr)); //if it is wrapped
// 	return retval;
// }

__inline__ void Timer_start(void)
{
	TCNT1 = 0x0000; //reset timer
	TIFR1 |= (1 << TOV1); //clear overflow flag
	TCCR1B = (1 << CS02) | (1 << CS00);
}

__inline__ void Timer_stop(void)
{
	TCNT1 = 0x0000; //reset timer
	TIFR1 |= (1 << TOV1); //clear overflow flag
	TCCR1B = 0;//
}

__inline__ uint8_t Timer_Ovf(void)
{
	return (TIFR1 & (1 << TOV1)); //mask the timer overflow out
}

#endif /* INTERFACE_H_ */
