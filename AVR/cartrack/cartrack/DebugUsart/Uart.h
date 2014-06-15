/*
 * Uart.h
 *
 * Created: 15/06/2014 10:50:57
 *  Author: seblovett
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#ifndef UART_H_
#define UART_H_


void Uart_Init(void);
void Uart_SendChar(uint8_t c);
void Uart_SendString(char *s);
int Uart_putchar_printf(char var, FILE *stream);

static FILE mystdout = FDEV_SETUP_STREAM(Uart_putchar_printf, NULL, _FDEV_SETUP_WRITE);

#endif /* UART_H_ */