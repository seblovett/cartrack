/**
 *  @brief Uart.c
 *  Date Created: Sun 15 Jun 2014 10:51:54 BST by seblovett on seblovett-Ubuntu
 *  <+Last Edited: Sun 15 Jun 2014 11:23:46 BST by seblovett on seblovett-Ubuntu +>
 *  @author seblovett
 *  @brief ...
 */

#include "Uart.h"
#include "../GSM/Interface.h"
///@todo - make this more generic
void Uart_Init(void)
{
	cli();
	stdout = &mystdout;
	UBRR0H = 0;
	UBRR0L = 0x4d;
	UCSR0B = (1 << RXEN0) | (1 << TXEN0) | (1 << RXCIE0); //enable rx and tx, also rx interrupt
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); // 8 data, 1 stop, 0 parity
	sei();
}


void Uart_SendChar(uint8_t c)
{
	while ( !(UCSR0A & (1<<UDRE0)) ) ; //wait until buffer is empty
	UDR0 = c; //send the data
}


ISR(USART0_RX_vect)
{
	uint8_t c = UDR0;
	Interface_SendChar(c);//echo to GSM
	//if (c == '\r')
	//	Interface_SendChar('\n');
	if (c == 2)
	{
		circBuf.WritePtr = 0; //reset ptr
		circBuf.ReadPtr = 0;
		for (c = 0; c < CIRBUF_SIZE; c++)
			circBuf.Buffer[c] = 0;
	}
}

void Uart_SendString(char *s)
{
	while(*s)
		Uart_SendChar(*(s++));
}

int Uart_putchar_printf(char var, FILE *stream) {
    if (var == '\n') 
		Uart_SendChar('\r');
    Uart_SendChar(var);
    return 0;
}