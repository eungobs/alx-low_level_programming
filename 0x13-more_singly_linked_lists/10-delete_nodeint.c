#include "lists.h"
/**
* delete_nodeint_at_index - deletes a node in a linked list at a certain index
* @head: pointer to the first element in the list
* @index: index of the node to delete
* Return: 1 (Success)
*/
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
unsigned int p;
listint_t *temp, *prev;
if (*head == NULL)
return (-1);
temp = *head;
if (index == 0)
{
*head = (*head)->next;
free(temp);
return (1);
}
for (p = 0; temp != NULL && p < index; p++)
{
prev = temp;
temp = temp->next;
}
if (temp == NULL)
return (-1);
prev->next = temp->next;
free(temp);
return (1);
}
