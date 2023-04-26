#include "main.h"

/**
 * print_alphabet_x10 - print all alphabets in lowercase 10 times.
 * Reyurn: On success 1.
 */
void print_alphabet_x10(void)
{
 char i, k;

 for (k = 0; k < 10; k++)
 {
	 
  for (i = 'a'; i <= 'z'; i++)
  {

    _putchar(i);
   }
   _putchar('\n');
  }
}
