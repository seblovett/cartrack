/*
 * AT.h
 *
 * Created: 15/06/2014 14:04:13
 *  Author: seblovett
 */ 

#include <stdio.h>
#include "Interface.h"
#ifndef AT_H_
#define AT_H_



#define AT_SUCCESS	0	//! AT command was successful
#define AT_TIMEOUT	1	//! AT command has timed out
#define AT_ERROR	2	//! AT command returned error

uint8_t AT_OK(void);
uint8_t ATE(uint8_t Echo);
uint8_t ATV(uint8_t val);
uint8_t ATaF(void);
uint8_t ATCSQ(void);
uint8_t AT_CGATT(uint8_t val);
uint8_t AT_QIREGAPP(void);
uint8_t AT_QICSGP(void);
uint8_t AT_QISHOWRA(uint8_t val);
uint8_t AT_QIDNSIP(uint8_t val);
uint8_t AT_QIFGCNT(uint8_t val);
uint8_t AT_QILOCIP(void);
uint8_t AT_QIACT(void);
uint8_t AT_QISEND(void);
uint8_t AT_QIOPEN(void);
uint8_t ParseReceived(void);
#endif /* AT_H_ */
