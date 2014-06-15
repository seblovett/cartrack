/**
 *  @brief GSM.c
 *  Date Created: Sun 15 Jun 2014 12:15:12 BST by seblovett on seblovett-Ubuntu
 *  <+Last Edited: Sun 15 Jun 2014 12:16:17 BST by seblovett on seblovett-Ubuntu +>
 *  @author seblovett
 *  @brief ...
 */

#include "GSM.h"

/** @brief Initialise the GSM module
 */
uint8_t GSM_Init(void)
{
	//defaults in the config
	gsm.config = GSM_CONFIG_ECHO; //atv and echo are on by default
	Interface_Init();
	//maybe power cycle it to ensure it is reset?
	
	if (AT_TIMEOUT == ATaF()) //if it isn't on
	{
		printf("GSM Off, attempting to turn on...\n\r");
		//turn it on
		Pulse_Power();
		_delay_ms(1000);
		//try again
		if (AT_TIMEOUT == ATaF())
		{
			printf("Cannot turn GSM on");
			return AT_TIMEOUT;
		}
	}
	gsm.status |= GSM_STATUS_POWER; //remember that it is on.
	//set to not echo
	ATE(1);
	ATV(1);
	AT_OK();
	ATCSQ();
	AT_CGATT(1);
	printf("\n\rStatus = %x\n\r", gsm.status);
	return 0;
	
}

uint8_t GSM_Proc(void)
{
	//uint8_t c = Circ_Read_Char();
	Dump_Buf();
	return 0;
}

void GPRS_Setup()
{
	AT_QIREGAPP();
// 	Dump_Buf();
// 	printf("\n\r");
	_delay_ms(1000);
	AT_QIACT();
// 	Dump_Buf();
// 	printf("\n\r");
	_delay_ms(1000);
	AT_CGATT(1);
// 	Dump_Buf();
// 	printf("\n\r");
	_delay_ms(1000);
	//AT_QILOCIP();
	AT_QIFGCNT(0);
// 	Dump_Buf();
// 	printf("\n\r");
	_delay_ms(1000);
	//AT_QICSGP();
	AT_QIDNSIP(1);
// 	Dump_Buf();
// 	printf("\n\r");
	_delay_ms(1000);
	AT_QISHOWRA(1);
// 	Dump_Buf();
// 	printf("\n\r");
	_delay_ms(1000);
// 	for(uint8_t i = 0; i < CIRBUF_SIZE; i++)
// 		circBuf.Buffer[i] = 0;
// 	circBuf.ReadPtr = 0;
// 	circBuf.WritePtr = 0;
	
}

void GPRS_Send(void)
{
	AT_QIOPEN();
	
	//QISEND
	_delay_ms(4000);
	AT_QISEND();
	//QICLOSE

}