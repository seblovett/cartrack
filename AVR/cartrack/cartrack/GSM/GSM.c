/**
 *  @brief GSM.c
 *  Date Created: Sun 15 Jun 2014 12:15:12 BST by seblovett on seblovett-Ubuntu
 *  <+Last Edited: Sun 15 Jun 2014 12:16:17 BST by seblovett on seblovett-Ubuntu +>
 *  @author seblovett
 *  @brief Encompassing functions to run the higher level aspects of the GSM modem.
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

/** @brief Checks if the GSM modem is on or off
 *	Result is stored in the GSM_t.status
 */
void GSM_CheckOn()
{
	switch (AT_OK())
	{
		case AT_SUCCESS:
			//set the bit
			gsm.status |= GSM_STATUS_POWER;
			break;
		default:
			//clear the bit
			gsm.status &= ~(GSM_STATUS_POWER);
			break;
	}
}

/** @brief Runs regular functions needed.
 *  retval - 0 okay, > 0 error
 *  Runs the ParseReceived() function.
 *  Also sends an AT command to ensure the GSM is still working error free. 
 *	Any errors found here are stored in the GSM_t struct.
 */
uint8_t GSM_Proc(void)
{
	//uint8_t c = Circ_Read_Char();
	return ParseReceived();
	//Dump_Buf();
	//return 0;
}


/** @brief Calls all AT commands to set up the GPRS functionality
  */
void GPRS_Setup()
{
	AT_QIREGAPP();
	_delay_ms(1000);
	AT_QIACT();
	_delay_ms(1000);
	AT_CGATT(1);
	_delay_ms(1000);
	//AT_QILOCIP();
	AT_QIFGCNT(0);
	_delay_ms(1000);
	AT_QIDNSIP(1);
	_delay_ms(1000);
	AT_QISHOWRA(1);
	_delay_ms(1000);
}


/** @brief Calls functions needed to submit data to the website
 *	@todo - need to put actual data sending in here
 */
void GPRS_Send(void)
{
	AT_QIOPEN();
	
	//QISEND
	_delay_ms(4000);
	AT_QISEND();
	//QICLOSE

}