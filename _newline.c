#include "main.h"
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
/**
 * newline - prints "$ ", waits for the user to enter a command
 * prints it on the next line.
 * Return: 0 on success
 */
int newline(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	printf("$ ");
	read = getline(&line, &len, stdin);
	if (read == -1)
	{
		printf("Error\n");
		return (1);
	}
	printf("%s", line);
	return (0);
}
/**
 * main - entry point
 * Return: 0 on success
*/
int main(void)
{
	newline();
}
