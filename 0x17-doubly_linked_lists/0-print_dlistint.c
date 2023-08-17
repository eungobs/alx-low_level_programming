#include <stdio.h>
#include "lists.h"

/**
 * print_dlistint - function.
 * @h: string to print.
 *
 * Description: Function to print all elements in dlistint_t list.
 * Return: number of nodes.
 */

size_t print_dlistint(const dlistint_t *h)
{
    const dlistint_t *current = h;
    size_t node_count = 0;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
        node_count++;
    }

    return (node_count);
}
