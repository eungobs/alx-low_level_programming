#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

#include <stdio.h>
#include <stddef.h>

/* Function prototypes */
int recursive_binary_search(int *array, int left, int right, int value);
int binary_search(int *array, size_t size, int value);
void print_search(int *array, int first, int last);

#endif /* SEARCH_ALGOS_H */

#include "search_algos.h"

/**
 * binary_search - Searches for a value in a sorted array using Binary Search
 *
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index where value is located or -1 if not found
 */
int binary_search(int *array, size_t size, int value) {
    if (array && size) {
        return recursive_binary_search(array, 0, size - 1, value);
    }
    return -1;
}

/**
 * recursive_binary_search - Recursively performs Binary Search
 *
 * @array: Array to search
 * @left: Left index of the sub-array
 * @right: Right index of the sub-array
 * @value: Value to search for
 *
 * Return: Index where value is located or -1 if not found
 */
int recursive_binary_search(int *array, int left, int right, int value) {
    int middle;

    if (right >= left) {
        middle = left + (right - left) / 2;
        print_search(array, left, right);

        if (array[middle] == value) {
            return middle;
        } else if (array[middle] > value) {
            return recursive_binary_search(array, left, middle - 1, value);
        } else {
            return recursive_binary_search(array, middle + 1, right, value);
        }
    }
    return -1; /* Element not found */
}

/**
 * print_search - Prints the elements being searched in the array
 *
 * @array: Array being searched
 * @first: Index of the first element in the current sub-array
 * @last: Index of the last element in the current sub-array
 */
void print_search(int *array, int first, int last) {
    printf("Searching in array: ");
    for (; first <= last; ++first) {
        printf("%d", array[first]);
        if (first < last) {
            printf(", ");
        }
    }
    printf("\n");
}
