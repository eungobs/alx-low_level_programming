#include "lists.h"
#include <stdio.h>

/**
* print_listint_safe -  prints a listint_t linked list.
* @head: head of the list.
* Return: the number of nodes
*/

size_t print_listint_safe(const listint_t *head)
{
  size_t count = 0;
    const listint_t *temp;

    while (head != NULL)
    {
        printf("[%p] %d\n", (void *)head, head->n);
        count++;
        temp = head;
        head = head->next;
        if (temp <= head)
        {
            printf("-> [%p] %d\n", (void *)head, head->n);
            break;
        }
    }

    return (count);
}
