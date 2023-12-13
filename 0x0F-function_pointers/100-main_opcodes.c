#include<stdio.h>
#include<stdlib.h>
/**
* main- Entry point.
* @argc: number of parameters.
* @argv: parameeters in the case the number of bytes.
* Return: 0 in succes
*/
int main(int argc, char *argv[])
{
int c, z;
if (argc != 2)
{
printf("Error\n");
return (1);
}
z = atoi(argv[1]);
if (z < 0)
{
printf("Error\n");
exit(2);
}
for (c = 0; c < z; c++)
{
printf("%02hhx", *((char *)main + c));
if (c < z - 1)
printf(" ");
else
printf("\n");
}
return (0);
}
