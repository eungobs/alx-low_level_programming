#include "main.h"
/**
* get_bit - Entry Point
* @n: input
* @index: index
* Return: 0
*/

int get_bit(unsigned long int n, unsigned int index)
{
unsigned long int j;

if (index > 8)
return (-1);
j = 1 << index;
return ((n & j) > 0);
}
