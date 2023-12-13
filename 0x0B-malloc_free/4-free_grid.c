#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
* free_grid - Entry point
*@grid: rows of matrix
*@height: columns of string
* Return: a pointer to a 2 dimensional array of integers or null
*/
void free_grid(int **grid, int height)
{
int i;
int *h;

for (i = 0; i < height; i++)
{
h = grid[i];
free(h);
}
free(grid);
}
