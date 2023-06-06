#include "lists.h"
#include <stdio.h>
/**
 * get_nodeint_at_index - returns the node at an index.
 * @head: first node.
 * @index: index of the node to return.
 * Return: pointer to the node.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
unsigned int p;
for (p = 0; head != NULL && p < index; p++)
head = head->next;
return (head == NULL ? NULL : head);
}
