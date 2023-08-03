#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
* print_binary - Prints the binary representation of a number.
*
* @n: The number to print.
*
* Return: None.
*/
void print_binary(unsigned long int n)
{
int shift = sizeof(unsigned long int) * 8 - 1;
int bit;

while (shift >= 0)
{
bit = (n >> shift) & 1;
putchar(bit ? '1' : '0');
shift--;
}
}
