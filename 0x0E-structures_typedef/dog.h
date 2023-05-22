#ifndef _dog_h_
#define _dog_h_

/**
* struct dog - such structure, huu
* @name: dog's name
* @age: dog's age
* @owner: dog's owner
*/
typedef struct dog
{
char *name;
float age;
char *owner;
}
dog_h;
void init_dog(struct dog *f, char *name, float age, char *owner);
void print_dog(struct dog *f);
dog_h *new_dog(char *name, float age, char *owner);
void free_dog(dog_h *f);
#endif /* _dog_h_ */
