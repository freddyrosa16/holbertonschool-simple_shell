#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * main - main
 * @argc: arg count
 * @argv:arguments
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	int i;

	printf("argc:%d\n", argc);

	for (i = 0; argv[i]; i++)
	{
		printf("argv[%d]: %s\n", i, argv[i]);
	}

	return (0);
}
