#include <stdio.h>
#include "lists.h"

/**
  * print_listint - prints all elements.
  * @h: singly linked list to print
  * Return: number of nodes
 */
size_t print_list(const list_t *h)
{

size_t count = 0;
list_t *current = (list_t *)h;
while (current != NULL)
{
if (current->str == NULL)
printf("[0] (nil)\n");
else
printf("[%d] %s\n", current->len, current->str);
current = current->next;
count++;
}
return (count);
}
