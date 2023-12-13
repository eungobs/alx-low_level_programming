#include "function_pointers.h"
#include <stdio.h>
/**
* int_index - this functions find the index of an integer.
*@array: to find the index
*@size: size of the array
*@cmp: a function pointer.
* Description: this function find the index of an int
* Return: 0;
*/
int int_index(int *array, int size, int (*cmp)(int))
{
int z;
if (size <= 0 || array == 0 || cmp == 0)
return (-1);
for (z = 0; z < size; z++)
if (cmp(*(array + z)))
return (z);
return (-1);
}
