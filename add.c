#include "main.h"
#include <stdio.h>
#include <unistd.h>

/**
 * add - adds and prints the pid and ppid
 * @a: first number
 * @b: second number
 */

void add(int a, int b)
{
	int my_pid = getpid();
	int my_ppid = getppid();
	int sum = a + b;

	printf("The sum of %d and %d is %d.\n", a, b, sum);
	printf("My pid is:%d\nMy ppid is:%d\n", my_pid, my_ppid);

}
