#include "main.h"
/**
* get_bit - the value of a bit at a given index.
* @n: input
* @index: index
* Return: 0
*/

int get_bit(unsigned long int n, unsigned int index)
{
unsigned long int j;

if (index > 63)
return (-1);
j = 1 << index;
return ((n & j) > 0);
}
