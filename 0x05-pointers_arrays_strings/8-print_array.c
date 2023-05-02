#include "main.h"
#include <stdio.h>

/**
 *print_array - prints n elements of an array of integers
 *@a: Array of integers
 *@n: Number of elements of the array to be printed
 * Return: void
 */

void print_array(int *a, int n)

{
int a;

for (a = 0; a < n; a++)
{
printf("%d", a[n]);
if (a != (n - 1))
{
printf(",");
}
}
printf("\n");
}
