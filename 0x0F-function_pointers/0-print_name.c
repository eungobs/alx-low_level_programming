#include "function_pointers.h"
#include <stdio.h>
/**
* print_name- functions that prints a name
* @name: string to print.
* @f: a function pointer, that recieves a string.
* Description: this function prints a name.
* Return: Nothing
*/
void print_name(char *name, void (*f)(char *))
{
if (name == 0 || f == 0)
	printf("name is %s\n", "0");
return;
(*f)(name);
}
