#include "lists.h"
#include <stdio.h>
/**
* reverse_listint -  reverses a listint_t linked list.
* * @head: head of the list
* Return: the first node of the reversed node
*/
listint_t *reverse_listint(listint_t **head)
{
listint_t *prev = NULL;
listint_t *next = NULL;

if (head == NULL || *head == NULL)
return (NULL);
while (*head != NULL)
{
next = (*head)->next;
(*head)->next = prev;
prev = *head;
*head = next;
}
*head = prev;
return (*head);
}
