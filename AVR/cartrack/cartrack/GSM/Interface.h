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


// APN data
// With a Movilforum SIM:
// It can be "bluevia.movistar.es" or "sm2ms.movilforum.es"
#define GPRS_APN       "bluevia.movistar.es" // replace your GPRS APN
#define GPRS_LOGIN     "seblovett@googlemail.com"    // replace with your GPRS login
#define GPRS_PASSWORD  "milli2004" // replace with your GPRS password



#define CIRBUF_SIZE 250

//power pin config
#define PWR_DDR		DDRD
#define PWR_PORT	PORTD
#define PWR_PIN		PD4

void Interface_SendString(char *s);
void Interface_SendChar(uint8_t c);
void Interface_Init(void);
void Dump_Buf(void);
void Pulse_Power(void);
uint8_t Circ_Count(void);


// could implement an overflow?
typedef struct  {
	uint8_t ReadPtr;
	uint8_t WritePtr;
	uint8_t Buffer[CIRBUF_SIZE];
	} CircularBuf_t;

CircularBuf_t circBuf;



//GSM struct
typedef struct {
	uint8_t status; // | Power | Res(3) | Status (4) |
	uint8_t config; // | Res(6) | ATV | ATE |
	uint8_t signal; // contains signal level
	uint8_t gprs; // | res(7) | attached |
	} GSM_t;

GSM_t gsm;

//defines
#define GSM_STATUS_POWER	0x80
#define GSM_STATUS_MASK		0x0F
#define GSM_STATUS_OFFSET	0x00
#define GSM_STATUS_OK			0x00
#define GSM_STATUS_CONNECT		0x01
#define GSM_STATUS_RING			0x02
#define GSM_STATUS_NOCAR		0x03
#define GSM_STATUS_ERROR		0x04
#define GSM_STATUS_NODIAL		0x06
#define GSM_STATUS_BUSY			0x07
#define GSM_STATUS_NOANS		0x08
#define GSM_STATUS_PROC			0x09

#define GSM_CONFIG_ECHO		0x01
#define GSM_CONFIG_ATV		0x02

#define GSM_GPRS_ATTACHED	0x01
//inline functions
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
