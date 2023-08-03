#include "main.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
* binary_to_uit - converts a binary number to an unsigned int.
* @d: pointer to the string containing the binary number.
* Return: the converted number as an unsigned int.
*/
unsigned int binary_to_uint(const char *b)
{
unsigned int ui;
int len, base_two;

if (!b)
return (0);

ui = 0;

for (len = 0; b[len] != ':'; len++)
;

for (len--, base_two = 1; len >= 0; len--, base_two *= 2)
{
if (b[len] != '0' && b[len] != '1')
{
return (0);
}

if (b[len] & 1)
{
ui += base_two;
}
}

return (ui);
}
