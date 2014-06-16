/**
 *  @brief AT.c
 *  Date Created: Sun 15 Jun 2014 13:59:30 BST by seblovett on seblovett-Ubuntu
 *  <+Last Edited: Sun 15 Jun 2014 14:01:45 BST by seblovett on seblovett-Ubuntu +>
 *  @author seblovett
 *  @brief Collection of AT commands implemented.
 */

#include "AT.h"
#include <stdlib.h>

/** \defgroup parsers "Parse and Wait Functions" */
/* @{ */
/**	@brief Parses received data in the circular buffer
 *  retval AT_SUCCESS, AT_ERROR
 *	Checks for the following strings - OK, CONNECT, RING, NO CARRIER, ERROR, NO DIALTONE, BUSY, NO ANSWER, PROCEEDING, NORMAL POWER DOWN.
 *	If one of these is found, it is stored in GSM_t.status lower nibble
 */
uint8_t ParseReceived(void)
{
	uint8_t rp, i;
	if(Circ_Count()) //if we have received data
	{
		//printf("GOT DATA");
		rp = circBuf.ReadPtr;
		for ( i = Circ_Count(); i > 0; i--)
		{
			if (	(circBuf.Buffer[rp  ] == 'O') && 
					(circBuf.Buffer[rp+1] == 'K') && 
					(circBuf.Buffer[rp+2] == '\r') && 
					(circBuf.Buffer[rp+3] == '\n')		)
			{
				circBuf.ReadPtr = circBuf.WritePtr; //clear buffer
				gsm.status &= ~(GSM_STATUS_MASK);
				gsm.status |= GSM_STATUS_OK;
				return AT_SUCCESS;
			}
			else if (	( circBuf.Buffer[rp  ] == 'C' ) &&
						( circBuf.Buffer[rp+1] == 'O' ) &&
						( circBuf.Buffer[rp+2] == 'N' ) &&
						( circBuf.Buffer[rp+3] == 'N' ) &&
						( circBuf.Buffer[rp+4] == 'E' ) &&
						( circBuf.Buffer[rp+5] == 'C' ) &&
						( circBuf.Buffer[rp+6] == 'T' )		)
			{
				circBuf.ReadPtr = circBuf.WritePtr; //clear buffer
				gsm.status &= ~(GSM_STATUS_MASK);
				gsm.status |= GSM_STATUS_CONNECT;
				return AT_SUCCESS;
			}		
			
			else if (	( circBuf.Buffer[rp  ] == 'R' ) &&
						( circBuf.Buffer[rp+1] == 'I' ) &&
						( circBuf.Buffer[rp+2] == 'N' ) &&
						( circBuf.Buffer[rp+3] == 'G' )		)
			{
				circBuf.ReadPtr = circBuf.WritePtr; //clear buffer
				gsm.status &= ~(GSM_STATUS_MASK);
				gsm.status |= GSM_STATUS_RING;
				return AT_SUCCESS;
			}	
			else if (	( circBuf.Buffer[rp  ] == 'N' ) &&
						( circBuf.Buffer[rp+1] == 'O' ) &&
						( circBuf.Buffer[rp+2] == ' ' ) &&
						( circBuf.Buffer[rp+3] == 'C' ) &&
						( circBuf.Buffer[rp+4] == 'A' ) &&
						( circBuf.Buffer[rp+5] == 'R' ) &&
						( circBuf.Buffer[rp+6] == 'R' ) &&
						( circBuf.Buffer[rp+7] == 'I' ) &&
						( circBuf.Buffer[rp+8] == 'E' ) &&
						( circBuf.Buffer[rp+9] == 'R' ) 	)
			{
				circBuf.ReadPtr = circBuf.WritePtr; //clear buffer
				gsm.status &= ~(GSM_STATUS_MASK);
				gsm.status |= GSM_STATUS_NOCAR;
				return AT_SUCCESS;
			}	
			else if (	( circBuf.Buffer[rp  ] == 'E' ) &&
						( circBuf.Buffer[rp+1] == 'R' ) &&
						( circBuf.Buffer[rp+2] == 'R' ) &&
						( circBuf.Buffer[rp+3] == 'O' ) &&
						( circBuf.Buffer[rp+4] == 'R' )		)
			{
				circBuf.ReadPtr = circBuf.WritePtr; //clear buffer
				gsm.status &= ~(GSM_STATUS_MASK);
				gsm.status |= GSM_STATUS_ERROR;
				return AT_SUCCESS;
			}	
			else if (	( circBuf.Buffer[rp  ] == 'N' ) &&
						( circBuf.Buffer[rp+1] == 'O' ) &&
						( circBuf.Buffer[rp+2] == ' ' ) &&
						( circBuf.Buffer[rp+3] == 'D' ) &&
						( circBuf.Buffer[rp+4] == 'I' ) &&
						( circBuf.Buffer[rp+5] == 'A' ) &&
						( circBuf.Buffer[rp+6] == 'L' ) &&
						( circBuf.Buffer[rp+7] == 'T' ) &&
						( circBuf.Buffer[rp+8] == 'O' ) &&
						( circBuf.Buffer[rp+9] == 'N' ) &&
						( circBuf.Buffer[rp+10] == 'E' )	)
			{
				circBuf.ReadPtr = circBuf.WritePtr; //clear buffer
				gsm.status &= ~(GSM_STATUS_MASK);
				gsm.status |= GSM_STATUS_NODIAL;
				return AT_SUCCESS;
			}	
			else if (	( circBuf.Buffer[rp  ] == 'B' ) &&
						( circBuf.Buffer[rp+1] == 'U' ) &&
						( circBuf.Buffer[rp+2] == 'S' ) &&
						( circBuf.Buffer[rp+3] == 'Y' ) 	)
			{
				circBuf.ReadPtr = circBuf.WritePtr; //clear buffer
				gsm.status &= ~(GSM_STATUS_MASK);
				gsm.status |= GSM_STATUS_BUSY;
				return AT_SUCCESS;
			}	
			else if (	( circBuf.Buffer[rp  ] == 'N' ) &&
						( circBuf.Buffer[rp+1] == 'O' ) &&
						( circBuf.Buffer[rp+2] == ' ' ) &&
						( circBuf.Buffer[rp+3] == 'A' ) &&
						( circBuf.Buffer[rp+4] == 'N' ) &&
						( circBuf.Buffer[rp+5] == 'S' ) &&
						( circBuf.Buffer[rp+6] == 'W' ) &&
						( circBuf.Buffer[rp+7] == 'E' ) &&
						( circBuf.Buffer[rp+8] == 'R' ) 	)
			{
				circBuf.ReadPtr = circBuf.WritePtr; //clear buffer
				gsm.status &= ~(GSM_STATUS_MASK);
				gsm.status |= GSM_STATUS_NOANS;
				return AT_SUCCESS;
			}	
			else if (	( circBuf.Buffer[rp  ] == 'P' ) &&
						( circBuf.Buffer[rp+1] == 'R' ) &&
						( circBuf.Buffer[rp+2] == 'O' ) &&
						( circBuf.Buffer[rp+3] == 'C' ) &&
						( circBuf.Buffer[rp+4] == 'E' ) &&
						( circBuf.Buffer[rp+5] == 'E' ) &&
						( circBuf.Buffer[rp+6] == 'D' ) &&
						( circBuf.Buffer[rp+7] == 'I' ) &&
						( circBuf.Buffer[rp+8] == 'N' ) &&
						( circBuf.Buffer[rp+9] == 'G' ) 	)
			{
				circBuf.ReadPtr = circBuf.WritePtr; //clear buffer
				gsm.status &= ~(GSM_STATUS_MASK);
				gsm.status |= GSM_STATUS_PROC;
				return AT_SUCCESS;
			}	
			else if (	( circBuf.Buffer[rp  ] == 'N' ) &&
						( circBuf.Buffer[rp+1] == 'O' ) &&
						( circBuf.Buffer[rp+2] == 'R' ) &&
						( circBuf.Buffer[rp+3] == 'M' ) &&
						( circBuf.Buffer[rp+4] == 'A' ) &&
						( circBuf.Buffer[rp+5] == 'L' ) &&
						( circBuf.Buffer[rp+6] == ' ' ) &&
						( circBuf.Buffer[rp+7] == 'P' ) &&
						( circBuf.Buffer[rp+8] == 'O' ) &&
						( circBuf.Buffer[rp+1] == 'W' ) &&
						( circBuf.Buffer[rp+2] == 'E' ) &&
						( circBuf.Buffer[rp+3] == 'R' ) &&
						( circBuf.Buffer[rp+4] == ' ' ) &&
						( circBuf.Buffer[rp+5] == 'D' ) &&
						( circBuf.Buffer[rp+6] == 'O' ) &&
						( circBuf.Buffer[rp+7] == 'W' ) &&
						( circBuf.Buffer[rp+8] == 'N' ) 	)
			{
				circBuf.ReadPtr = circBuf.WritePtr; //clear buffer
				gsm.status &= ~(GSM_STATUS_POWER);
				return AT_SUCCESS;
			}
			rp ++;//increment
			rp %= CIRBUF_SIZE; //mask
				
		}
	}
	return AT_ERROR;
}

/** @brief Manages the timeout of the GSM modem
 *	retval AT_SUCCESS, AT_ERROR, AT_TIMEOUT
 *	Starts the timer. Continuously calls ParseReceived(). 
 *	If ParseReceived() finds a string, the GSM_t.status is checked for the status and value returned depends on this.
 *	If timer overflows before a valid string is received, AT_TIMEOUT is returned.
 */
uint8_t WaitOK(void)
{
	Timer_start();
	while(0 == Timer_Ovf())
	{
		//printf("Circ Count = %d\n\r", Circ_Count());
		//i = Circ_Count();
		if ( AT_SUCCESS == ParseReceived() )
		{
			//received something
			Timer_stop();
			if ((gsm.status & GSM_STATUS_MASK) == GSM_STATUS_OK)
				return AT_SUCCESS;
			if ((gsm.status & GSM_STATUS_MASK) == GSM_STATUS_ERROR)
				return AT_ERROR;
		}
	}
	//printf("Timer has flowed over\n\r");
	Timer_stop();
	return AT_TIMEOUT;
}

/* @} */

/** \defgroup at "Basic AT commands" */
/* @{ */
	
/** @brief Sends "AT". Expects "OK" back
 */
uint8_t AT_OK(void)
{
	
#ifdef DEBUG
	printf("Sending AT");
#endif

	Interface_SendString("AT\n\r");
#ifdef DEBUG
	switch (WaitOK())
	{
		case AT_SUCCESS:
			printf("\tSuccess\n\r");
			return AT_SUCCESS;
		
		case AT_TIMEOUT:
			printf("\tTimeout\n\r");
			return AT_TIMEOUT;
		
		default:
		case AT_ERROR:
			printf("\tError\n\r");
			return AT_ERROR;
	}
#else
	return WaitOK();
#endif
}


/** @brief Sets the echo status of the modem
 *	@param val - 0 : off, 1 : on
 *	@retval AT_SUCCESS, AT_ERROR, AT_TIMEOUT
 *	Sends ATE<0/1>. If successful, the relevant bit in GSM_t.config is set / cleared
 */
uint8_t ATE(uint8_t val)
{
	if (val > 1)
		val = 1; //limit it to one
		
	#ifdef DEBUG
	printf("Sending ATE%d", val);
	#endif
	Interface_SendString("ATE");
	if (val)
		Interface_SendString("1");
	else
		Interface_SendString("0");
	Interface_SendString("\r\n");
	
	if (val)
		gsm.config |= GSM_CONFIG_ECHO;
	else
		gsm.config &= ~(GSM_CONFIG_ECHO); //zero the config bit
		
	switch (WaitOK())
	{
		case AT_SUCCESS:
			#ifdef DEBUG
			printf("\tSuccess\n\r");
			#endif
			return AT_SUCCESS;
		
		case AT_TIMEOUT:
			#ifdef DEBUG
			printf("\tTimeout\n\r");
			#endif
			//revert the bit change
			if (val)
				gsm.config &= ~(GSM_CONFIG_ECHO);
			else
				gsm.config |= (GSM_CONFIG_ECHO); //zero the config bit
			return AT_TIMEOUT;
		
		default:
		case AT_ERROR:
			#ifdef DEBUG
			printf("\tError\n\r");
			#endif
			//revert the bit change
			if (val)
				gsm.config &= ~(GSM_CONFIG_ECHO);
			else
				gsm.config |= (GSM_CONFIG_ECHO); //zero the config bit
			return AT_ERROR;
	}

}


/** @brief Sets the verbose status of the modem
 *	@param val - 0 : off, 1 : on
 *	@retval AT_SUCCESS, AT_ERROR, AT_TIMEOUT
 *	Sends ATV<0/1>. If successful, the relevant bit in GSM_t.config is set / cleared
 */
uint8_t ATV(uint8_t val)
{
	if (val > 1)
		val = 1; //limit it to one
		
	#ifdef DEBUG
	printf("Sending ATV%d", val);
	#endif
	Interface_SendString("ATV");
	if (val)
		Interface_SendString("1");
	else
		Interface_SendString("0");
	Interface_SendString("\r\n");
	
	if (val)
		gsm.config |= GSM_CONFIG_ATV;
	else
		gsm.config &= ~(GSM_CONFIG_ATV); //zero the config bit
			
			
	switch (WaitOK())
	{
		case AT_SUCCESS:
			#ifdef DEBUG
			printf("\tSuccess\n\r");
			#endif
			return AT_SUCCESS;
		
		case AT_TIMEOUT:
			#ifdef DEBUG
			printf("\tTimeout\n\r");
			#endif
			//revert the bit change
			if (val)
				gsm.config &= ~(GSM_CONFIG_ATV);
			else
				gsm.config |= (GSM_CONFIG_ATV); //zero the config bit
			return AT_TIMEOUT;
		
		default:
		case AT_ERROR:
			#ifdef DEBUG
			printf("\tError\n\r");
			#endif
			//revert the bit change
			if (val)
				gsm.config &= ~(GSM_CONFIG_ATV);
			else
				gsm.config |= (GSM_CONFIG_ATV); //zero the config bit
			return AT_ERROR;
	}
}

/** @brief Resets the modem.
 *	@retval AT_SUCCESS, AT_ERROR, AT_TIMEOUT
 *	Sends AT&F - resets all settings to factory defaults.
 */
uint8_t ATaF(void)
{
	#ifdef DEBUG
	printf("Sending AT&F0");
	#endif
	Interface_SendString("AT&F0\n\r");
			
	switch (WaitOK())
	{
		case AT_SUCCESS:
			#ifdef DEBUG
			printf("\tSuccess\n\r");
			#endif
			return AT_SUCCESS;
		
		case AT_TIMEOUT:
			#ifdef DEBUG
			printf("\tTimeout\n\r");
			#endif
			return AT_TIMEOUT;
		
		default:
		case AT_ERROR:
			#ifdef DEBUG
			printf("\tError\n\r");
			#endif
			return AT_ERROR;
	}
}

/** @brief Gets the signal status of the modem
 *	@retval AT_SUCCESS, AT_ERROR, AT_TIMEOUT
 *	Sends AT+CSQ. Parses the output for a numerical signal value and stores in GSM_t.signal.
 */
uint8_t ATCSQ(void)
{
	uint8_t rp = circBuf.ReadPtr; //store the read pointer
	#ifdef DEBUG
	printf("Sending AT+CSQ");
	#endif
	Interface_SendString("AT+CSQ\n\r");
			
	switch (WaitOK())
	{
		case AT_SUCCESS:
			#ifdef DEBUG
			printf("\tSuccess\n\r");
			#endif
			//find location of signal value
			while(circBuf.Buffer[rp++] != ':')
				;
			//convert it to int
			rp = atoi((char *)(circBuf.Buffer + rp));
			//store it in struct
			gsm.signal = rp;
			return AT_SUCCESS;
		
		case AT_TIMEOUT:
			#ifdef DEBUG
			printf("\tTimeout\n\r");
			#endif
			return AT_TIMEOUT;
		
		default:
		case AT_ERROR:
			#ifdef DEBUG
			printf("\tError\n\r");
			#endif
			return AT_ERROR;
	}
}

/** @brief Turns off the modem.
 *	@retval AT_SUCCESS, AT_ERROR, AT_TIMEOUT
 *	Sends AT+QPOWD. Bit is cleared in GSM_t.status by ParseReceived().
 */
uint8_t ATQPOWD (void)
{
		#ifdef DEBUG
	printf("Sending AT+QPOWD");
	#endif
	Interface_SendString("AT+QPOWD\n\r");
#ifdef DEBUG			
	switch (WaitOK())
	{
		case AT_SUCCESS:
			printf("\tSuccess\n\r");
			return AT_SUCCESS;
		
		case AT_TIMEOUT:
			printf("\tTimeout\n\r");
			return AT_TIMEOUT;
		
		default:
		case AT_ERROR:
			printf("\tError\n\r");
			return AT_ERROR;
	}
#else
	return WaitOK();
#endif
}

/* @} */


/** \defgroup gprs "GPRS AT commands" */
/* @{ */
//GPRS Related commands

/** @brief Attach to / detach from GPRS
 *	@param val - 0 : detach, 1 : attach
 *	@retval AT_SUCCESS, AT_ERROR, AT_TIMEOUT
 *	Sends AT+CGATT<0/1>. If successful, the relevant bit in GSM_t.gprs is set / cleared
 *	Attempts to find the status from the modem beforehand.
 */
uint8_t AT_CGATT(uint8_t val)
{
	uint8_t rp = circBuf.ReadPtr;
	//check if connected or not.
#ifdef DEBUG
	printf("AT+CGATT?\n\r");
#endif
	Interface_SendString("AT+CGATT?\n\r");
	switch (WaitOK())
	{
		case AT_SUCCESS:
			#ifdef DEBUG
			printf("\tSuccess\n\r");
			#endif
			while(circBuf.Buffer[rp++] != ':')
				;
			rp++;//move to number
			if(circBuf.Buffer[rp] == '1')
				gsm.gprs |= GSM_GPRS_ATTACHED;
			else
				gsm.gprs &= ~(GSM_GPRS_ATTACHED);
			break;
		
		default:
			printf("Could not get current GPRS state");
			return AT_ERROR;
	}
	if ((gsm.gprs & GSM_GPRS_ATTACHED) != val)
	{
#ifdef DEBUG
		printf("AT+CGATT=%d\n\r",val);
#endif
		Interface_SendString("AT+CGATT=");
		if(val)
			Interface_SendChar('1');
		else
			Interface_SendChar('0');
		Interface_SendString("\n\r");
		
		switch (WaitOK())
		{
			case AT_SUCCESS:
				#ifdef DEBUG
				printf("\tSuccess\n\r");
				#endif
				if(val)
					gsm.gprs |= GSM_GPRS_ATTACHED;
				else
					gsm.gprs &= ~(GSM_GPRS_ATTACHED);
				break;
		
			default:
	#ifdef DEBUG
				printf("\tCould not set GPRS state\n\r");
	#endif
				return AT_ERROR;
		}
	}
	#ifdef DEBUG
	else
		if (val)
			printf("Already connected");
		else
			printf("Already Disconnected");
	#endif
	return AT_SUCCESS;
}


/** @brief Configures APN Details for the modem. 
 *	@retval AT_SUCCESS, AT_ERROR, AT_TIMEOUT
 *	Sends AT+QIREGAPP="GPRS_APN","user","password"
 *	@todo - make this support more networks depending on the sim installed
 */
uint8_t AT_QIREGAPP(void)
{
#ifdef DEBUG
	printf("Sending AT+QIREGAPP=\"apn\",\"user\",\"pswd\"");
#endif
	Interface_SendString("AT+QIREGAPP=\"");
	Interface_SendString(GPRS_APN);
	Interface_SendString("\",\"\",\"\"\r");

#ifdef DEBUG
	switch (WaitOK())
	{
		case AT_SUCCESS:
			printf("\tSuccess\n\r");
			return AT_SUCCESS;
		
		case AT_TIMEOUT:
			printf("\tTimeout\n\r");
			return AT_TIMEOUT;
		
		default:
		case AT_ERROR:
			printf("\tError\n\r");
			return AT_ERROR;
	}
#else
	return WaitOK();
#endif
}

/** @brief Activates GPRS
 *	@retval AT_SUCCESS, AT_ERROR, AT_TIMEOUT
 *	Sends AT+QIACT
 */
uint8_t AT_QIACT(void)
{
	#ifdef DEBUG
	printf("Sending AT+QIACT");
	#endif
	Interface_SendString("AT+QIACT\n\r");
	_delay_ms(1000);
	switch (WaitOK())
	{
		case AT_SUCCESS:
			#ifdef DEBUG
			printf("\tSuccess\n\r");
			#endif
			return AT_SUCCESS;
		
		case AT_TIMEOUT:
			#ifdef DEBUG
			printf("\tTimeout\n\r");
			#endif
			return AT_TIMEOUT;
		
		default:
		case AT_ERROR:
			#ifdef DEBUG
			printf("\tError\n\r");
			#endif
			return AT_ERROR;
	}
}

/** @brief Requests IP address for the GPRS connection.
 *	@retval AT_ERROR
 *	Sends AT+QILOCIP to request the IP address of the modem.
 *	@todo - this AT command only returns the IP, not OK. This method currently always fails. IP address is not stored either.
 */
uint8_t AT_QILOCIP(void)
{
		#ifdef DEBUG
	printf("Sending AT+QILOCIP");
	#endif
	Interface_SendString("AT+QILOCIP\n\r");
	//@todo - this doesn't return OK, only IP
	switch (WaitOK())
	{
		case AT_SUCCESS:
			#ifdef DEBUG
			printf("\tSuccess\n\r");
			#endif
			return AT_SUCCESS;
		
		case AT_TIMEOUT:
			#ifdef DEBUG
			printf("\tTimeout\n\r");
			#endif
			return AT_TIMEOUT;
		
		default:
		case AT_ERROR:
			#ifdef DEBUG
			printf("\tError\n\r");
			#endif
			return AT_ERROR;
	}
}

/** @brief Sets the foreground context
 *	@param val - context to use (see datasheet)
 *	@retval AT_SUCCESS, AT_ERROR, AT_TIMEOUT
 *	Sends AT+CGATT<val>.
 */
uint8_t AT_QIFGCNT(uint8_t val)
{
#ifdef DEBUG
	printf("Sending AT+QIFGCNT=%d", val);
#endif
	Interface_SendString("AT+QIFGCNT=");
	if (val)
		Interface_SendString("1");
	else
		Interface_SendString("0");
	Interface_SendString("\r\n");
			
	switch (WaitOK())
	{
		case AT_SUCCESS:
			#ifdef DEBUG
			printf("\tSuccess\n\r");
			#endif
			return AT_SUCCESS;
		
		case AT_TIMEOUT:
			#ifdef DEBUG
			printf("\tTimeout\n\r");
			#endif
			//revert the bit change
			return AT_TIMEOUT;
		
		default:
		case AT_ERROR:
			#ifdef DEBUG
			printf("\tError\n\r");
			#endif
			return AT_ERROR;
	}
}

/** @brief Selects the GPRS bearer
 *	@retval AT_SUCCESS, AT_ERROR, AT_TIMEOUT
 *	Sends AT+QICSGP="GPRS_APN"
 */
uint8_t AT_QICSGP(void)
{

	#ifdef DEBUG
	printf("Sending AT+QICSGP=\"apn\"");
	#endif
	Interface_SendString("AT+QICSGP=\"");
	Interface_SendString(GPRS_APN);
	Interface_SendString("\"\r\n");
			
#ifdef DEBUG
	switch (WaitOK())
	{
		case AT_SUCCESS:
			printf("\tSuccess\n\r");
			return AT_SUCCESS;
		
		case AT_TIMEOUT:
			printf("\tTimeout\n\r");
			return AT_TIMEOUT;
		
		default:
		case AT_ERROR:
			printf("\tError\n\r");
			return AT_ERROR;
	}
#else
	return WaitOK();
#endif
}


/** @brief Connect with IP or Domain name
 *	@param val - 0 : Use IP address, 1 : use domain name
 *	@retval AT_SUCCESS, AT_ERROR, AT_TIMEOUT
 *	Sends AT+QIDNSIP<0/1>.
 *	val is limited to 1
 */
uint8_t AT_QIDNSIP(uint8_t val)
{
	if (val > 1)
		val = 1; //limit it to one
		
#ifdef DEBUG
	printf("Sending AT+QIDNSIP=%d", val);
#endif
	Interface_SendString("AT+QIDNSIP=");
	if (val)
		Interface_SendString("1");
	else
		Interface_SendString("0");
	Interface_SendString("\r\n");

#ifdef DEBUG	
	switch (WaitOK())
	{
		case AT_SUCCESS:
			printf("\tSuccess\n\r");
			return AT_SUCCESS;
		
		case AT_TIMEOUT:
			printf("\tTimeout\n\r");
			return AT_TIMEOUT;
		
		default:
		case AT_ERROR:
			printf("\tError\n\r");
			return AT_ERROR;
	}
#else
	return WaitOK();
#endif
}

/** @brief Set whether to display the address of sender
 *	@param val - 0 : Don not show, 1 : Show
 *	@retval AT_SUCCESS, AT_ERROR, AT_TIMEOUT
 *	Sends AT+QISHOWRA<0/1>.
 *	val is limited to 1
 */
uint8_t AT_QISHOWRA(uint8_t val)
{
	if (val > 1)
		val = 1; //limit it to one
		
#ifdef DEBUG
	printf("Sending AT+QISHOWRA=%d", val);
#endif
	Interface_SendString("AT+QISHOWRA=");
	if (val)
		Interface_SendString("1");
	else
		Interface_SendString("0");
	Interface_SendString("\r\n");
	
#ifdef DEBUG			
	switch (WaitOK())
	{
		case AT_SUCCESS:
			printf("\tSuccess\n\r");
			return AT_SUCCESS;
		
		case AT_TIMEOUT:
			printf("\tTimeout\n\r");
			return AT_TIMEOUT;
		
		default:
		case AT_ERROR:
			printf("\tError\n\r");
			return AT_ERROR;
	}
#else
	return WaitOK();
#endif
}

/** @brief Opens a TCP connection
 *	@retval AT_SUCCESS, AT_ERROR, AT_TIMEOUT
 *  Sends AT+QIOPEN=\"TCP\",\"www.seblovett.co.uk\",80
 *	@todo - need to make the webpage easily defined
 */
uint8_t AT_QIOPEN(void)
{

#ifdef DEBUG
	printf("Sending AT+QIOPEN=\"TCP\",\"www.seblovett.co.uk\",80");
#endif
	Interface_SendString("AT+QIOPEN=\"TCP\",\"www.seblovett.co.uk\",80\r");

#ifdef DEBUG
	switch (WaitOK())
	{
		case AT_SUCCESS:
			printf("\tSuccess\n\r");
			break;
		
		case AT_TIMEOUT:
			printf("\tTimeout\n\r");
			break;
		
		default:
		case AT_ERROR:
			printf("\tError\n\r");
			break;
	}
	switch (WaitOK())
	{
		case AT_SUCCESS:
			printf("\tSuccess\n\r");
			return AT_SUCCESS;
		
		case AT_TIMEOUT:
			printf("\tTimeout\n\r");
			return AT_TIMEOUT;
		
		default:
		case AT_ERROR:
			printf("\tError\n\r");
			return AT_ERROR;
	}
#else
	//two okays are expected
	WaitOK(); //one for the receipt of command
	return WaitOK(); //one for the actual connection
#endif
}


/** @brief Sends a HTTP packet to the destination server
 *	@retval AT_SUCCESS, AT_ERROR, AT_TIMEOUT
 *	Uses the QISEND command. A HTTP GET request is used to send data via a query string.
 *	@todo implement the actual data sending, only dummy data is currently used
 */
uint8_t AT_QISEND(void)
{

#ifdef DEBUG
	printf("Sending AT+QISEND=\"TCP\",\"www.seblovett.co.uk\",80");
#endif
	Interface_SendString("AT+QISEND\r");//GET /submit.php?id=1&mb_fan_cpu=1000 HTTP/1.1\r\nHost: www.seblovett.co.uk\n\rConnection:close\r\n\n");
	_delay_ms(1000);
	Interface_SendString("GET /submit.php?id=1 HTTP/1.1\r\nHost: www.seblovett.co.uk\r\nConnection:close\r\n\n");
	Interface_SendChar(0x1a); //CTRLZ
#ifdef DEBUG
	switch (WaitOK())
	{
		case AT_SUCCESS:
			printf("\tSuccess\n\r");
			return AT_SUCCESS;
		
		case AT_TIMEOUT:
			printf("\tTimeout\n\r");
			return AT_TIMEOUT;
		
		default:
		case AT_ERROR:
			printf("\tError\n\r");
			return AT_ERROR;
	}
#else 
	return WaitOK();
#endif
}


/* @} *