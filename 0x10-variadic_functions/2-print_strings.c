#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>
/**
* print_strings - function that prints strings.
* @separator: the string to be printed between the strings.
* @n: the number of strings passed to the function.
* Return: void
*/
void print_strings(const char *separator, const unsigned int n, ...)
{
char *sep, *ptr;
unsigned int t;
va_list list;
if (separator == NULL || *separator == 0)
sep = "";
else
sep = (char *) separator;
va_start(list, n);
if (n > 0)
printf("%s", va_arg(list, char *));
for (t = 1; t < n; t++)
{
ptr = va_arg(list, char*);
if (ptr == NULL)
ptr = "(null)";
printf("%s%s", sep, ptr);
}
printf("\n");
va_end(list);
}
