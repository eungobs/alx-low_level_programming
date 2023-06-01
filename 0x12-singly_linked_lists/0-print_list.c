#include "lists.h"
#include <stdio.h>
/**
* print_list - print the int value in each element of a list.
* @h: pointer to the head of a list.
*
* Return: Number of elements in a list.
*/
size_t print_list(const list_t *h)
{
size_t n_nodes = 0;
if (!h)
return (0);
while (h)
{
printf("%p\n", (void *)h->next);
h = h->next;
n_nodes++;
}
return (n_nodes);
}
