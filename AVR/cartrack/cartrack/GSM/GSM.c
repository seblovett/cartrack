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
	Interface_Init();
	Interface_SendString("AT\r");
	return 0;
}

uint8_t GSM_Proc(void)
{
	//uint8_t c = Circ_Read_Char();
	Dump_Buf();
	return 0;
}


