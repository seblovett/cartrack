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


#define GPRS_APN	"bluevia.movistar.es" //! The APN to use
#define CIRBUF_SIZE 250		//! Size of the circular buffer. Maximum of 254.

/** \defgroup powerpin "Power Pin Configuration" */
/* @{ */ 
#define PWR_DDR		DDRD	//! DDR the power connection is on
#define PWR_PORT	PORTD	//!	PORT the power connection is on
#define PWR_PIN		PD4		//! Pin the power connection is on
/* @} */


void Interface_SendString(char *s);
void Interface_SendChar(uint8_t c);
void Interface_Init(void);
void Dump_Buf(void);
void Pulse_Power(void);
uint8_t Circ_Count(void);


//! @todo implement an overflow status in the circular buffer
typedef struct  {
	uint8_t ReadPtr; //! Read pointer
	uint8_t WritePtr;	//! Write pointer
	uint8_t Buffer[CIRBUF_SIZE]; //Circular buffer
	} CircularBuf_t;

CircularBuf_t circBuf;



//GSM struct
typedef struct {
	uint8_t status; //! Holds the status of the GSM modem | Power | Res(3) | Status (4) |
	uint8_t config; //! Holds some on the configuration of the GSM modem | Res(6) | ATV | ATE |
	uint8_t signal; //! The signal strength of the modem
	uint8_t gprs; //! GPRS status of the modem | res(7) | attached |
	} GSM_t;

GSM_t gsm;

/** \defgroup gsmdefs "Masks and Offsets for the GSM_t struct */
/* @{ */
#define GSM_STATUS_POWER	0x80
#define GSM_STATUS_POWER_Off 7
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

/* @} */

/** \defgroup gsminlines "Inline Functions for the Interface" */
/* @{ */
	
/** @brief Writes a uint8_t to the circular buffer
 *	@param c - the uint8_t to write.
 *	Will only write the data to the buffer if there is space in the buffer. 
 *	Else, it is discarded.
 *	Write pointer is incremented upon successful write.
 */
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


/** @brief Reads a uint8_t from the circular buffer
 *	@retval the data from the buffer.
 *	Will only read if there is data in the buffer. 
 *	Else, 0 is returned
 *	Read pointer is incremented upon successful read.
 */
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



/** @brief Starts the timer 
 *	Timer count and overflow are reset before the timer is started.
 */
__inline__ void Timer_start(void)
{
	TCNT1 = 0x0000; //reset timer
	TIFR1 |= (1 << TOV1); //clear overflow flag
	TCCR1B = (1 << CS02) | (1 << CS00);
}

/** @brief Stops the timer 
 *	Timer count and overflow are reset after the timer is stopped.
 */
__inline__ void Timer_stop(void)
{
	TCCR1B = 0;// stop the timer
	TCNT1 = 0x0000; //reset timer
	TIFR1 |= (1 << TOV1); //clear overflow flag
}

/** @brief checks if the Timer has overflowed
 *	@retval - 0 not overflowed, 1 timer has overflowed
 */
__inline__ uint8_t Timer_Ovf(void)
{
	return (TIFR1 & (1 << TOV1)); //mask the timer overflow out
}


/** @brief checks if the GSM is on
 *	@retval - 0 off, 1 on
 *	Only checks the struct. For a hardware check, see GSM_CheckOn();
 */
__inline__ uint8_t GSM_On(void)
{
	return (( gsm.status & GSM_STATUS_POWER ) >> GSM_STATUS_POWER_Off );
}

#endif /* INTERFACE_H_ */
