#include <stddef.h>

#define HASH_SIZE 100

struct dictionary_item
{
    char key[50];
    int value;
    struct dictionary_item* next;
};

struct dictionary
{
    struct dictionary_item* table[HASH_SIZE];
};

//EXERCISE ---------------------------------------------------------------------------------------------------------------

void dictionary_insert(struct dictionary* d, const char* key, int value)
{
    unsigned int index = hash_function(key);
    struct dictionary_item* current = d->table[index];
    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
        {
            current->value = value;
            return;
        }
        current = current->next;
    }

    struct dictionary_item* new_item = (struct dictionary_item*)malloc(sizeof(struct dictionary_item));
    if (new_item == NULL)
    {
        exit(EXIT_FAILURE);
    }

    strcpy(new_item->key, key);
    new_item->value = value;
    new_item->next = d->table[index];
    d->table[index] = new_item;
}

void dictionary_remove(struct dictionary* d, const char* key)
{
    unsigned int index = hash_function(key);
    struct dictionary_item* current = d->table[index];
    struct dictionary_item* prev = NULL;
    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
        {
            if (prev == NULL)
            {
                d->table[index] = current->next;
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

int dictionary_search(struct dictionary* d, const char* key)
{
    unsigned int index = hash_function(key);
    struct dictionary_item* current = d->table[index];
    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
        {
            return current->value;
        }
        current = current->next;
    }

    return -1;
}