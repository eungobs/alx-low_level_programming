#include "lists.h"
#include <stddef.h>
/**
* list_len - returns the lenth of a list.
* @h: pointer to the head of a list.
*
* Return: Length (INT) of a list.
*/
size_t list_len(const list_t *h)
{
size_t n_nodes = 0;
if (!h)
return (0);
while (h)
{
n_nodes++;
h = h->next;
}
return (n_nodes);
}
