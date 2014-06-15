/**
 *  @brief Interface.c
 *  Date Created: Sun 15 Jun 2014 12:05:52 BST by seblovett on seblovett-Ubuntu
 *  <+Last Edited: Sun 15 Jun 2014 12:06:26 BST by seblovett on seblovett-Ubuntu +>
 *  @author seblovett
 *  @brief ...
 */

#include "Interface.h"

void Interface_Init()
{
	cli();
	//initialise the uart interface
	UBRR1H = 0;
	UBRR1L = 0x4d;
	UCSR1B = (1 << RXEN1) | (1 << TXEN1) | (1 << RXCIE1); //enable rx and tx, also rx interrupt
	UCSR1C = (1 << UCSZ11) | (1 << UCSZ10); // 8 data, 1 stop, 0 parity
	
	//init power pin
	PWR_PORT &= ~(1 << PWR_PIN);
	PWR_DDR |= (1 << PWR_PIN);
	
	//initialise the circular buffer
	circBuf.ReadPtr = 0;
	circBuf.WritePtr = 0;
	sei();

}

void Interface_SendChar(uint8_t c)
{
	while ( !(UCSR1A & (1<<UDRE1)) ) ; //wait until buffer is empty
	UDR1 = c; //send the data
}


ISR(USART1_RX_vect)
{
	uint8_t c = UDR1;
	Circ_Write_Char(c);
}

void Interface_SendString(char *s)
{
	while(*s)
		Interface_SendChar(*(s++));
}

void Dump_Buf(void)
{
	printf("\r                                                 \r");
	for (uint8_t i = 0; i < CIRBUF_SIZE; i++)
	{
// 		if ( circBuf.Buffer[i] == '\r')
// 			printf("\\r");
// 		else if ( circBuf.Buffer[i] == '\n')
// 			printf("\\n");
// 		else 
			printf("%c", circBuf.Buffer[i]);
	}
	printf("\tWP=%d\tRP=%d", circBuf.WritePtr, circBuf.ReadPtr);
}


uint8_t Circ_Count(void)
{
	uint8_t retval;
	if (circBuf.ReadPtr <= circBuf.WritePtr) //not wrapped
		retval = circBuf.WritePtr - circBuf.ReadPtr; //return the diff
	else
		retval = (circBuf.WritePtr + (CIRBUF_SIZE - circBuf.ReadPtr)); //if it is wrapped
	return retval;
}

void Pulse_Power(void)
{
	PWR_PORT |= (1 << PWR_PIN);
	_delay_ms(500);
	PWR_PORT &= ~(1 << PWR_PIN);
}