#include "shell.h"
/**
 * main - Entry point for the shell program.
 * Return: Always 0.
 */

int main(void)
{
	size_t buf_size = 0;
	char *buf;
	char **array;

	/*Main shell loop*/
	while (1)
	{
		buf = getline(&buf_size);
		array = tokenization(buf);

		execve(array);

		free_memory(buf, array);
	}
	return (0);
}
