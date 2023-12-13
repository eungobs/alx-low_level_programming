#include "lists.h"
#include <stdio.h>

/**
 * print_listint_safe - prints a listint_t linked list.
 * @h: head 
 * Returns: the number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
    const listint_t *current;
    size_t count;

    current = head;
    count = 0;
    while (current != NULL)
    {
        printf("[%p] %d\n", (void *)current, current->n);
        current = current->next;
        count++;
    }

    return (count);
}
