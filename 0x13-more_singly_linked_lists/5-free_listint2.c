#include "lists.h"
#include <stdio.h>
/**
*free_listint2 - frees a linked list
*@head: pointer to the head.
*Return: void
*/
void free_listint2(listint_t **head)
{
listint_t *temp;
if (head == NULL)
return;
while (*head != NULL)
{
temp = *head;
*head = (*head)->next;
free(temp);
}
*head = NULL;
}
