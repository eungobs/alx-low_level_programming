#include "lists.h"
#include <stdio.h>
/**
*pop_listint - deletes the head.
*@head: head of the list.
*Return: the deleted node data.
*/
int pop_listint(listint_t **head)
{
listint_t *temp;
int n;
if (*head == NULL)
return (0);
temp = *head;
n = (*head)->n;
*head = (*head)->next;
free(temp);
return (n);
}
