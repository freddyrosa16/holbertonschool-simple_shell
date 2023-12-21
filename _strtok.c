#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * main - entry point
 * Return: 0 on success
*/
int main(void)
{
	char *src = "These are tokens";
	char *str = malloc(sizeof(char) * strlen(src));
	char *delim = " ";
	char *token;

	strcpy(str, src);
	token = strtok(str, delim);

	while (token)
	{
		printf("%s\n", token);
		token = strtok(NULL, delim);
	}

	return (0);
}
