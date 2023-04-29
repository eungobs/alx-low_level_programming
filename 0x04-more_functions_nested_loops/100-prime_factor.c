#include <stdio.h>
#include "main.h>

/**
 * main - prints the largest prime factor of the number 612852475143
 * Return: Always 0 (Success)
 */

int main(void)

{
	long x, maxf;
	long number = 612852475143;
	double squre = sqrt(number);

	for (x = 1; x <= square; x++)
	{
	if (number % x == 0)
	{
	maxf = number / x;
	}
	}
	print("%ld\n", maxf);
	return (0);
}

