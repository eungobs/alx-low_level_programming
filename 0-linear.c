#include "search_algos.h"
#include <stdio.h>

/**
 * linear_search - Searches for a value in an array of integers using Linear Search algorithm
 *
 * @array: Array to search
 * @size: Size of the array
 * @value: Value to search for
 *
 * Return: First index where value is located or -1 if value is not present or if array is NULL
 */
int linear_search(int *array, size_t size, int value)
{
    unsigned int index;

    for (index = 0; array && index < size; index++)
    {
        printf("Value checked array[%d] = [%d]\n", index, array[index]);

        if (array[index] == value)
        {
            return (index);
        }
    }

    return (-1);
}
