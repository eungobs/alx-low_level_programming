#include "lists.h"
#include <stdlib.h>

unsigned int len_node(dlistint_t *node);

/**
* delete_dnodeint_at_index - delete node at given index
* @head: pointer to the pointer to the head node
* @index: given index
* Return: 1 on success, -1 on failure
*/
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
dlistint_t *start;
unsigned int i;
unsigned int len;

len = len_node(*head);

if (*head == NULL || index >= len)
return (-1);

start = *head;

if (index == 0)
{
*head = start->next;
if (*head != NULL)
(*head)->prev = NULL;
free(start);
return (1);
}

for (i = 0; i < index; i++)
{
start = start->next;
if (!start)
return (-1);
}

if (start->next != NULL)
start->next->prev = start->prev;

if (start->prev != NULL)
start->prev->next = start->next;

free(start);
return (1);
}

/**
* len_node - calculate list length
* @node: list head
* Return: unsigned int
*/
unsigned int len_node(dlistint_t *node)
{
unsigned int len = 0;
dlistint_t *start = node;

while (start != NULL)
{
len += 1;
start = start->next;
}
return (len);
}
