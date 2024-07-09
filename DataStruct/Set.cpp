#include <stddef.h>

#define HASH_SIZE 100

struct set_item
{
	char key[50];
	struct set_item* next;
};

struct set
{
	struct set_item* table[HASH_SIZE];
};

//EXERCISE ---------------------------------------------------------------------------------------------------------------

struct set_item* set_search(struct set* s, const char* key)
{
    unsigned int index = hash_function(key);
    struct set_item* current = s->table[index];

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

void set_remove(struct set* s, const char* key)
{
    unsigned int index = hash_function(key);
    struct set_item* current = s->table[index];
    struct set_item* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->key, key) == 0)
        {
            if (prev == NULL)
            {
                s->table[index] = current->next;
            }
            else
            {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }

}

void set_insert_unique(struct set* s, const char* key)
{
    unsigned int index = hash_function(key);
    struct set_item* current = s->table[index];

    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
        {
            return;
        }
        current = current->next;
    }

    struct set_item* new_item = (struct set_item*)malloc(sizeof(struct set_item));
    if (new_item == NULL)
    {
        exit(EXIT_FAILURE);
    }

    strcpy(new_item->key, key);
    new_item->next = s->table[index];
    s->table[index] = new_item;
}