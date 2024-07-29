#include"uart.h"
 
void send_string(char *name)
{	
	while(*name)
	{
		UARTODR=*name++;
	}
}