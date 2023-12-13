#include "lists.h"
#include <stdio.h>
/**
* add_nodeint_end - adds a node to the end.
* @head: pointer to the head.
* @n: number to be used.
* Return: address of the newly added node
*/
listint_t *add_nodeint_end(listint_t **head, const int n)
{
listint_t *new_node;
listint_t *temp;
new_node = malloc(sizeof(listint_t));
if (new_node == NULL)
return (NULL);
new_node->n = n;
new_node->next = NULL;
if (*head == NULL)
*head = new_node;
else
{
temp = *head;
while (temp->next != NULL)
temp = temp->next;
temp->next = new_node;
}
return (new_node);
}
