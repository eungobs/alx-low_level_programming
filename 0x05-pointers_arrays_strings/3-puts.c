#include "main.h"

/**
 * _puts - prints a string
 *@str: The string to print
 * Return: void
 */
void _puts(char *str)
{
	int i;

	for (i = 0; str[i]; ! = '\0'; i++)
		putchar(str[i]);
	putchar('\n');
}
