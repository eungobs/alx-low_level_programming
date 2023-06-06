#include "lists.h"
#include <stdio.h>
/**
* print_listint_safe -  that frees a listint_t list.
* @head: head of the list
* Return:  the size of the list that was free’d
*/
void free_listint(listint_t *head)
{
    listint_t *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}
