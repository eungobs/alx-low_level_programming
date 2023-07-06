#include "main.h"

/**
 * get_endianness -  function that checks the endianness.
 *
 * Returns: 0 if big endian, 1 if little endian.
 */

int get_endianness(void)
{
	int num = 1;
	char *endian  = (char *)&num;
	printf("%d\n", num);
	printf("%d", *endian);
	return 0;
}
