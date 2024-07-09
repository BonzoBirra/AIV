#include <stddef.h>

#define AIV_LIST(x) &(x.list_item)

struct aiv_list_item
{
	struct aiv_list_item *next;
	unsigned int count;
};

struct aiv_list
{
	struct aiv_list_item *head;
	unsigned int counter;
};

struct aiv_int_item
{
	struct aiv_list_item list_item;
	int value;
};

struct aiv_list_item* aiv_list_get_tail(struct aiv_list_item *head)
{
	if (!head)
	{
		return NULL;
	}

	struct aiv_list_item* current_item = head;
	struct aiv_list_item* last_item = head;
	while (current_item)
	{
		last_item = current_item;
		current_item = current_item->next;
	}

	return last_item;
}

struct aiv_list_item* aiv_list_append(struct aiv_list_item *head, struct aiv_list_item *item)
{
	struct aiv_list_item* tail = aiv_list_get_tail(*head);
	if (!tail)
	{
		*head = item;
		(*head)->count = 1;
	}
	else
	{
		tail->next = item;
		(*head)->count++;

	}
}

struct aiv_list_item* aiv_list_pop(struct aiv_list_item** head)
{
	if (!head)
	{
		return NULL;
	}

	struct aiv_list_item* current_head = *head;
	const unsigned int current_count = current_head->count;
	*head = (*head)->next;
	if (*head)
	{
		(*head)->count = current_count - 1;
	}

	current_head->next = NULL;
	return current_head;
}

unsigned int aiv_list_length(struct aiv_list_item* head)
{
	return head->count;
}

int main(int argc, char** argv)
{
	struct aiv_list_item* head = NULL;

	struct aiv_inv_item int_item;
	int_item.value = 100;
	aiv_list_append(&head, AIV_LIST(& int_item));

	struct aiv_inv_item int_item2;
	int_item.value = 101;
	aiv_list_append(&head, AIV_LIST(&int_item));
	return 0;
}





//EXERCISE 1 ---------------------------------------------------------------------------------------------------------------

struct aiv_list_item* aiv_list_remove(struct aiv_list_item* head, struct aiv_list_item* item)
{
	if (!head || !item)
	{
		return head;
	}

	struct aiv_list_item* current = head;
	struct aiv_list_item* prev = NULL;
	while (current != NULL && current != item)
	{
		prev = current;
		current = current->next;
	}

	if (current == NULL=
	{
		return head;
	}

	if (prev == NULL)
	{
		head = current->next;
	}
	else
	{
		prev->next = current->next;
	}

	head->count--;
	return head;
}

void reverse_list(struct aiv_list* list) {
	struct aiv_list_item* prev = NULL;
	struct aiv_list_item* current = list->head;
	struct aiv_list_item* next = NULL;

	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;      
		current = next;     
	}

	list->head = prev;
}
