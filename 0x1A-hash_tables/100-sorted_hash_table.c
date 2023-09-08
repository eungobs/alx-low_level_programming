#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* struct shash_node_s - Node of a sorted hash table
* @key: The key, string
* The key is unique in the HashTable
* @value: The value corresponding to a key
* @next: A pointer to the next node of the List
* @sprev: A pointer to the previous element of the sorted linked list
* @snext: A pointer to the next element of the sorted linked list
*/
typedef struct shash_node_s
{
char *key;
char *value;
struct shash_node_s *next;
struct shash_node_s *sprev;
struct shash_node_s *snext;
} shash_node_t;

/**
* struct shash_table_s - Sorted hash table data structure
* @size: The size of the array
* @array: An array of size @size
* Each cell of this array is a pointer to the first node of a linked list,
* because we want our HashTable to use a Chaining collision handling
* @shead: A pointer to the first element of the sorted linked list
* @stail: A pointer to the last element of the sorted linked list
*/
typedef struct shash_table_s
{
unsigned long int size;
shash_node_t **array;
shash_node_t *shead;
shash_node_t *stail;
} shash_table_t;

unsigned long int hash_djb2(const unsigned char *str)
{
unsigned long int hash = 5381;
int c;

while ((c = *str++))
hash = ((hash << 5) + hash) + c;

return hash;
}

shash_table_t *shash_table_create(unsigned long int size)
{
shash_table_t *ht;
unsigned long int i;

ht = malloc(sizeof(shash_table_t));
if (ht == NULL)
return (NULL);

ht->size = size;
ht->array = malloc(sizeof(shash_node_t *) * size);
if (ht->array == NULL)
{
free(ht);
return (NULL);
}

for (i = 0; i < size; i++)
ht->array[i] = NULL;

ht->shead = NULL;
ht->stail = NULL;

return (ht);
}

int insert_sorted_node(shash_table_t *ht, shash_node_t *node)
{
shash_node_t *current, *prev;

if (ht == NULL || node == NULL)
return (0);

current = ht->shead;
prev = NULL;

while (current)
{
if (strcmp(node->key, current->key) < 0)
{
node->sprev = current->sprev;
node->snext = current;
if (prev)
prev->snext = node;
else
ht->shead = node;
current->sprev = node;

if (!node->sprev)
ht->shead = node;
if (!node->snext)
ht->stail = node;

return (1);
}

prev = current;
current = current->snext;
}

if (!prev)
{
ht->shead = node;
ht->stail = node;
}
else
{
prev->snext = node;
node->sprev = prev;
ht->stail = node;
}

return (1);
}

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
shash_node_t *new_node, *current;
unsigned long int index;

if (ht == NULL || key == NULL || value == NULL)
return (0);

index = hash_djb2((unsigned char *)key) % ht->size;

current = ht->array[index];
while (current)
{
if (strcmp(current->key, key) == 0)
{
free(current->value);
current->value = strdup(value);
if (current->value == NULL)
return (0);
return (1);
}
current = current->next;
}

new_node = malloc(sizeof(shash_node_t));
if (new_node == NULL)
return (0);

new_node->key = strdup(key);
if (new_node->key == NULL)
{
free(new_node);
return (0);
}
new_node->value = strdup(value);
if (new_node->value == NULL)
{
free(new_node->key);
free(new_node);
return (0);
}

new_node->next = ht->array[index];
ht->array[index] = new_node;

if (insert_sorted_node(ht, new_node) == 0)
{
free(new_node->key);
free(new_node->value);
free(new_node);
return (0);
}

return (1);
}

char *shash_table_get(const shash_table_t *ht, const char *key)
{
shash_node_t *node;
unsigned long int index;

if (ht == NULL || key == NULL)
return (NULL);

index = hash_djb2((unsigned char *)key) % ht->size;
node = ht->array[index];

while (node)
{
if (strcmp(node->key, key) == 0)
return (node->value);
node = node->next;
}

return (NULL);
}

void shash_table_print(const shash_table_t *ht)
{
shash_node_t *node;
char *separator = "";

if (ht == NULL)
return;

printf("{");
for (node = ht->shead; node != NULL; node = node->snext)
{
printf("%s'%s': '%s'", separator, node->key, node->value);
separator = ", ";
}
printf("}\n");
}

void shash_table_print_rev(const shash_table_t *ht)
{
shash_node_t *node;
char *separator = "";

if (ht == NULL)
return;

printf("{");
for (node = ht->stail; node != NULL; node = node->sprev)
{
printf("%s'%s': '%s'", separator, node->key, node->value);
separator = ", ";
}
printf("}\n");
}

void shash_table_delete(shash_table_t *ht)
{
shash_node_t *node, *temp;

if (ht == NULL)
return;

for (node = ht->shead; node != NULL;)
{
temp = node;
node = node->snext;
free(temp->key);
free(temp->value);
free(temp);
}

free(ht->array);
free(ht);
}

int main(void)
{
shash_table_t *ht;

ht = shash_table_create(10);
shash_table_set(ht, "key1", "value1");
shash_table_set(ht, "key3", "value3");
shash_table_set(ht, "key2", "value2");
shash_table_set(ht, "key4", "value4");

printf("Original Sorted Hash Table:\n");
shash_table_print(ht);

printf("Reverse Sorted Hash Table:\n");
shash_table_print_rev(ht);

shash_table_delete(ht);

return (0);
}
