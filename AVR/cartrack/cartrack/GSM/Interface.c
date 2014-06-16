/**
 *  @brief Interface.c
 *  Date Created: Sun 15 Jun 2014 12:05:52 BST by seblovett on seblovett-Ubuntu
 *  <+Last Edited: Sun 15 Jun 2014 12:06:26 BST by seblovett on seblovett-Ubuntu +>
 *  @author seblovett
 *  @brief All hardware specifics are done in this file
 */

#include "Interface.h"


/** @brief initialises the peripherals and variables needed
 *	USART is configured
 *	Power pin in set to output,
 *	Circular Buffer is cleared
 */
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

/** @brief Sends a single uint8_t to the GSM modem 
 *	@param c - the data to send
 */
void Interface_SendChar(uint8_t c)
{
	while ( !(UCSR1A & (1<<UDRE1)) ) ; //wait until buffer is empty
	UDR1 = c; //send the data
}

/** @brief ISR for the receipt of data from modem.
 *	Data received is stored in the circular buffer using Circ_Write_Char()
 */
ISR(USART1_RX_vect)
{
	uint8_t c = UDR1;
	Circ_Write_Char(c);
}

/** @brief Sends a string of chars to the GSM modem 
 *	@param s - a pointer to the null terminated string to send
 */
void Interface_SendString(char *s)
{
	while(*s)
		Interface_SendChar(*(s++));
}

/** @brief Debug method for dumping the contents and pointers of the circular buffer 
 */
void Dump_Buf(void)
{
	printf("\r                                                 \r");
	for (uint8_t i = 0; i < CIRBUF_SIZE; i++)
	{
			printf("%c", circBuf.Buffer[i]);
	}
	printf("\tWP=%d\tRP=%d", circBuf.WritePtr, circBuf.ReadPtr);
}

/** @brief Calculates how much data is in the buffer (if any)
 *	@retval number of bytes of valid, unread data in the circular buffer
 */
uint8_t Circ_Count(void)
{
	uint8_t retval;
	if (circBuf.ReadPtr <= circBuf.WritePtr) //not wrapped
		retval = circBuf.WritePtr - circBuf.ReadPtr; //return the diff
	else
		retval = (circBuf.WritePtr + (CIRBUF_SIZE - circBuf.ReadPtr)); //if it is wrapped
	return retval;
}

/** @brief pulses the power pin to turn the GSM modem on.
 */
void Pulse_Power(void)
{
	PWR_PORT |= (1 << PWR_PIN);
	_delay_ms(500);
	PWR_PORT &= ~(1 << PWR_PIN);
}