#include <stdio.h>
#include <main.h>

/**
 * main - prints the largest prime factor of the number 612852475143
 * Return: Always 0 (Success)
 */

int main(void)

{

	long x, maxf;
	long number = 612852475143;
	double squre = sqrt(number);

	for (x = 1; x <= squre; x++)
	{
	maxf = number / x;
	}
}
printf("%ld\n", maxf);
	return (0);
}

