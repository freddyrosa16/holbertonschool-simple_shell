#include "shell.h"
/**
 * execute_external_command - Execute an external command using fork and execvp
 * @command_array: Array of command and its arguments.
 */

void _excecve(char **array)
{
	int status;

	pid_t child_pid = fork();

	if (child_pid == 0)
	{
		execvp(array[0], array);
		perror("ERROR");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
	}
}
