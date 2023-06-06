#include "lists.h"
#include <stdio.h>
/**
* print_listint_safe -  that frees a listint_t list.
* @head: head of the list
* Return:  the size of the list that was free’d
*/
size_t free_listint_safe(listint_t **h)
{
    size_t count;
    listint_t *current, *tmp;

    if (h == NULL || *h == NULL)
        return (0);

    current = *h;
    *h = NULL;
    count = 0;
    while (current != NULL)
    {
        tmp = current;
        current = current->next;
        free(tmp);
        count++;
    }

    return (count);
}
