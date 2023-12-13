#include "lists.h"
#include <stdio.h>

/**
* listint_len - counts the number of nodes.
* @h: head of the list.
* Return: the number of element.
*/
size_t listint_len(const listint_t *h)
{
size_t count = 0;
const listint_t *current = h;
while (current != NULL)
{
current = current->next;
count++;
}
return (count);
}
