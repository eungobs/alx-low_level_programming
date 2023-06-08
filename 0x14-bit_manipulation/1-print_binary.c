#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * print_binary -  prints the binary representation of a number.
 * Format: see example.
 * @n: binary.
 * Return: void
 */

void print_binary(unsigned long int n)
{
if (n > 1)
print_binary(n >> 1);
putchar((n & 1) + '0');
}
