#include "lists.h"
#include <stdio.h>
/**
 * insert_nodeint_at_index - inserts a new node.
 * @head: pointer to the first node in the list.
 * @idx:  new node is added
 * @n: data to insert 
 * Return: pointer to the new node, or NULL.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
unsigned int p;
listint_t *new_node, *temp;
if (head == NULL)
return (NULL);
new_node = malloc(sizeof(listint_t));
if (new_node == NULL)
return (NULL);
new_node->n = n;
if (idx == 0)
{
new_node->next = *head;
*head = new_node;
return (new_node);
}
temp = *head;
for (p = 0; temp != NULL && p < idx - 1; p++)
temp = temp->next;
if (temp == NULL)
{
free(new_node);
return (NULL);
}
new_node->next = temp->next;
temp->next = new_node;
return (new_node);
}
