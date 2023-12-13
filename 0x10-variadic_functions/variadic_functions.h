#ifndef _variadic_functions_h_
#define _variadic_functions_h_
#include <stddef.h>
#include <stdlib.h>

int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);
#endif /* _variadic_functions_h_ */
