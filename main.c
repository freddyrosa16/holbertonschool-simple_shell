#include "main.h"
#include <stdio.h>
/**
 * main - entry point
 * @argc: arg count
 * @argv: args
 * Return: 0 on success
*/
int main(int argc, int *argv)
{
	int x;
	int y;

	printf("Enter Numbers to add: ");
	scanf("%d %d", &x, &y);

	add(x, y);

	return (0);
}
