/*
 * Interface.h
 *
 * Created: 15/06/2014 12:05:45
 *  Author: seblovett
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>

#ifndef INTERFACE_H_
#define INTERFACE_H_

#define CIRBUF_SIZE 128

void Interface_SendString(char *s);
void Interface_SendChar(uint8_t c);
void Interface_Init(void);
void Dump_Buf(void);
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

#endif /* INTERFACE_H_ */
