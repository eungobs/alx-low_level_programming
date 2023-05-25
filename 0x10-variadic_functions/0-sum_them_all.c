#include <stdarg.h>
#include "variadic_functions.h"
#include <stdio.h>
/**
* sum_them_all - sum of all its parameters.
* @n: number of arguments.
* Return: 0;
*/
int sum_them_all(const unsigned int n, ...)
{
va_list valist;
int sum = 0;
unsigned int s;
va_start(valist, n);
for (s = 0; s < n; s++)
{
sum += va_arg(valist, int);
}
va_end(valist);
return (sum);
}
