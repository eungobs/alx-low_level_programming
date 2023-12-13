#include "function_pointers.h"
/**
* array_iterator - it iterates an array
* @array: the array to iterate.
* @size: the size of the array.
* @action: this a function pointer.
* Description: this function iterate an array.
* Return: 0;
*/
void array_iterator(int *array, size_t size, void (*action)(int))
{
size_t e;

if (array && size && action)
for (e = 0; e < size; e++)
action(*(array + e));
}
