#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

/**
 * main - fork
 * Return: pid of child
*/
int main(void)
{
	pid_t pid;
	pid_t ppid;

	pid = fork();

	if (pid == -1)
	{
		perror("unsuccessful\n");
		return (1);
	}

	if (pid == 0)
	{
		sleep(5);
	} else
	{
		ppid = getpid();
	}
	return (0);
}
