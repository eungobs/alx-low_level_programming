#include "main.h"

/**
 * flip_bits - bits you would need to flip to get from one number to another.
 * @n: inputs.
 * @m: bits.
 * Return: 0
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
unsigned long int x = n ^ m;
unsigned int count = 0;
while (x > 0)
{
count += x & 1;
x >>= 1;
}
return (count);
}
