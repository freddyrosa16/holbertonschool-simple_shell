#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main -elrfer
 * Return: ergergerg
*/
int main(void)
{
	size_t n = 10;
	char *buff = NULL;

	printf("Enter Name: ");
	getline(&buff, &n, stdin);

	printf("Name is %sBuffer size is %d\n", buff, n);

	free(buff);
	return (0);
}
