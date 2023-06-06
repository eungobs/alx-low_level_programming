#include "lists.h"
#include <stdio.h>
/**
* add_nodeint - adds a node to the beginning.
* @head: pointer to the head.
* @n: integer to be used.
* Return: address of the newly added.
*/
listint_t *add_nodeint(listint_t **head, const int n)
{
listint_t *new_node;
new_node = malloc(sizeof(listint_t));
if (new_node == NULL)
return (NULL);
new_node->n = n;
new_node->next = *head;
*head = new_node;
return (new_node);
}
