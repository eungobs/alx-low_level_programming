#include <stddef.h>
#include "lists.h"

/**
* dlistint_len - Returns the number of elements in a doubly linked list.
* @h: Pointer to the head node of the list.
*
* Description: function to return number of elements in a linked list.
* Return: Number of elements in the list.
*/

size_t dlistint_len(const dlistint_t *h)
{
const dlistint_t *current = h;
size_t element_count = 0;

while (current != NULL)
{
current = current->next;
element_count++;
}

return (element_count);
}
