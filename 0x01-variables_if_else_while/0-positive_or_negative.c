#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/*more headers goes ther */

/**
 * main - Entry point
 * Description - prints if random generated number is +tive,zero -tive
 * Return: Always 0 (Success)
 */
int main(void)
{
int n;
srand(time(0));
n = rand() - RAND_MAX / 2;
if (n < 0)
	printf("%d is negative\n", n);
else if (n == 0)
printf("%d is zero\n", n);
else
printf("%d is positive\n", n);
retun (0);
}
