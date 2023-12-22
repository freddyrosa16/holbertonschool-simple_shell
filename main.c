#include "main.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - entry point
 * Return: 0 on success
*/
int main(void)
{
	int status = 95;
	char input[MAX_INPUT_SIZE];
	char *tokens[MAX_TOKENS];
	int token_count;
	pid_t pid;

	signal(SIGINT, handle_sigint);

	if (isatty(STDIN_FILENO)) /*Check if the shell is in interactive mode*/
	{
		while (status == 95)
		{
			get_input(input);
			parse_input(input, tokens, &token_count);
			/*if exit, exit shell*/
			if (strcmp(input, "exit") == 0)
			{
				printf("☾  Goodbye  \n");
				break;
			}
			/*Fork*/
			pid = fork();
			if (pid == -1)
			{
				perror("☁ ERROR: ");
				exit(EXIT_FAILURE);
			}
			if (pid == 0)
			{
				execvp(tokens[0], tokens);
				perror("☁ ERROR: ");
				exit(EXIT_FAILURE);
			} else
			{
				wait(NULL);
			}
		}
	}
	return (0);
}
