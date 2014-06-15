/*
 * GSM.h
 *
 * Created: 15/06/2014 12:05:36
 *  Author: seblovett
 */ 

#include "Interface.h"
#include "AT.h"
#include <util/delay.h>
#ifndef GSM_H_
#define GSM_H_

uint8_t GSM_Init(void);

uint8_t GSM_Proc(void);


#endif /* GSM_H_ */
