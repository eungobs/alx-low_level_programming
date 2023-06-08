#include "main.h"

/**
 * get_endianness - return endianness of the machine.
 *
 * Return: 0 for big endian, 1 if little endian
 */

int get_endianness(void)
{
unsigned int j = 1;
char *c = (char *)&j;
if (*c)
return (1);
else
return (0);
}
