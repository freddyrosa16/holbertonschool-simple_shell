#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - Basic Shell
 * @argc: number of arguments
 * @argv: arguments
 * Return: 0 on success
*/
int main(int argc, char **argv)
{
	char *cmd = NULL, *cmd_cpy = NULL, *token = NULL;
	char *delim = " \n";
	size_t n = 0;
	pid_t pid;
	int i = 0;

	if (isatty(STDIN_FILENO)) /*Checks if shell is in interactive mode*/
	{
		char cwd[1024]; /*buffer*/

		getcwd(cwd, sizeof(cwd));
		char *username = getlogin();
		char hostname[1024];

		gethostname(hostname, sizeof(hostname));
		while(1)
		{
		printf("%s@%s:%s☀", username, hostname, cwd); /*Accept input*/

		if (getline(&cmd, &n, stdin) == -1)
		{
			perror("ERROR: getline() Failed");
			return (-1);
		}
		cmd_cpy = strdup(cmd);
		token = strtok(cmd, delim);
		while (token)
		{
			token = strtok(NULL, delim);
			argc++;
		}
		token = strtok(cmd_cpy, delim);
		while (token)
		{
			token = strtok(NULL, delim);
			argv[i] = token;
			i++;
		}
		argv[i] = NULL;

		pid = fork();

		if (pid == -1)
		{
			perror("ERROR:Fork Failed\n");
			return (-1);
		} 
		if (pid == 0)
		{
			int val = execve(argv[0], argv, NULL);
			if (val == -1)
			{
				perror("ERROR: Execve Failed\n");
				exit(EXIT_FAILURE); // or return -1, depending on your error handling strategy
			}

			if (val == -1)
			{
				perror("ERROR: Execve Failed\n");
			}
		} else
		{
			wait(NULL);
		}
		}
		free(cmd_cpy);
		free(cmd);
	}
}
