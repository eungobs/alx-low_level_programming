#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>
/**
* print_all - function that prints anything.
* @c: char.
* @i: integer.
* @f: float.
* @s: char *
* Return: 0
*/
void print_all(const char * const format, ...)
{
va_list valist;
int n = 0, w = 0;
char *sep = ", ";
char *str;
va_start(valist, format);
while (format && format[w])
w++;
while (format && format[n])
{
if (n  == (w - 1))
{
sep = "";
}
switch (format[n])
{
case 'c':
printf("%c%s", va_arg(valist, int), sep);
break;
case 'w':
printf("%d%s", va_arg(valist, int), sep);
break;
case 'f':
printf("%f%s", va_arg(valist, double), sep);
break;
case 's':
str = va_arg(valist, char *);
if (str == NULL)
str = "(nil)";
printf("%s%s", str, sep);
break;
}
n++;
}
printf("\n");
va_end(valist);
}
