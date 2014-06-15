/**
 *  @brief AT.c
 *  Date Created: Sun 15 Jun 2014 13:59:30 BST by seblovett on seblovett-Ubuntu
 *  <+Last Edited: Sun 15 Jun 2014 14:01:45 BST by seblovett on seblovett-Ubuntu +>
 *  @author seblovett
 *  @brief ...
 */

#include "AT.h"


uint8_t WaitOK(void)
{
	uint8_t rp, i;
	//start timer
	Timer_start();
	while(0 == Timer_Ovf())
	{
		//printf("Circ Count = %d\n\r", Circ_Count());
		//i = Circ_Count();
		if(Circ_Count()) //if we have received data
		{
			//printf("GOT DATA");
			rp = circBuf.ReadPtr;
			for ( i = Circ_Count(); i > 0; i--)
			{
				if (( circBuf.Buffer[rp] == 'O') && (circBuf.Buffer[rp+1] == 'K') && (circBuf.Buffer[rp+2] == '\r') && (circBuf.Buffer[rp+3] == '\n'))
				{
					circBuf.ReadPtr = circBuf.WritePtr; //clear buffer
					Timer_stop();
					return AT_SUCCESS;
				}
				rp ++;//increment
				rp %= CIRBUF_SIZE; //mask
			}
		}
	}
	//printf("Timer has flowed over\n\r");
	Timer_stop();
	return AT_TIMEOUT;
}
/** @brief ATOK
 */
uint8_t AT_OK(void)
{
	Interface_SendString("AT\n\r");
	if (AT_SUCCESS == WaitOK())
	{
		printf("Success\n\r");
		return AT_SUCCESS;
	}
	else
	{
		printf("Failure\r\n");
		return AT_TIMEOUT;
	}
}

