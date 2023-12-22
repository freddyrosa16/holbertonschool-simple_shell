#include "main.h"
#include <stdio.h>
#include <signal.h>
/**
 * handle_sigint - handles the SIGINT signal
 * @sig: signal number
*/
void handle_sigint(int sig)
{
	if (sig == 2)
	{
		printf("\r⛅ Have a nice day\n");
	}
	printf("☾  Goodbye  \n");
	exit(0);
}
