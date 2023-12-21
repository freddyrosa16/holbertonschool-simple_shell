#include "main.h"
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
/**
 * my_ppid - prints the pid and ppid
 * Return: 0 on success
 */

int my_ppid(void)
{
	pid_t my_pid, parent_pid;

	my_pid = getpid();
	parent_pid = getppid();
	printf("My pid is %u\n", my_pid);
	printf("My parent's pid is %u\n", parent_pid);
	return (0);
}
