#include "shell.h"
/**
 * getline - Read a line of input from the user.
 * @buf: Pointer to the buffer.
 * @buf_size: Pointer to the size of the buffer.
 * Return: A pointer to the input buffer.
 */

char _getline(size_t *buf_size)
{
	char *buf = NULL;

	if (isatty(STDIN_FILENO))
	{
		write(1, "#cisfun$ ", 9);
	}
	getline(&buf, buf_size, stdin);
	int len = strlen(buf);

	if (len > 0 && buf[len - 1] == '\n')
	{
		buf[len - 1] = '\0';
	}
	return (buf);
}
