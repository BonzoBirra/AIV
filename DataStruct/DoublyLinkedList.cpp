#include <stddef.h>

struct aiv_list_item {
	struct aiv_list_item* next;
	struct aiv_list_item* prev;
	unsigned int count;
};

struct aiv_list {
	struct aiv_list_item* head;
	struct aiv_list_item* tail;
	unsigned int counter;
};

struct aiv_int_item {
	struct aiv_list_item list_item;
	int value;
};

//EXERCISE ---------------------------------------------------------------------------------------------------------------

void aiv_list_remove(struct aiv_list* list, struct aiv_list_item* item)
{
	if (list->head == NULL || item == NULL) return;

	if (list->head == item)
	{
		list->head = item->next;
	}

	if (list->tail == item)
	{
		list->tail = item->prev;
	}

	if (item->next != NULL)
	{
		item->next->prev = item->prev;
	}
}

void aiv_list_insert_after(struct aiv_list* list, struct aiv_list_item* after, struct aiv_int_item* new_item)
{
	if (after == NULL || new_item == NULL) return;

	new_item->list_item.prev = after;
	new_item->list_item.next = after->next;
	if (after->next != NULL)
	{
		after->next->prev = &new_item->list_item;
	}
	else
	{
		list->tail = &new_item->list_item;
	}

	after->next = &new_item->list_item;
	if (list->head != NULL) {
		list->head->count++;
	}
	list->counter++;
}

void aiv_list_insert_before(struct aiv_list* list, struct aiv_list_item* before, struct aiv_int_item* new_item)
{
	if (before == NULL || new_item == NULL) return;

	if (list->head == before) {
		new_item->list_item.next = list->head;
		new_item->list_item.prev = NULL;
		list->head->prev = &new_item->list_item;
		list->head = &new_item->list_item;
	}
	else
	{
		new_item->list_item.next = before;
		new_item->list_item.prev = before->prev;
		if (before->prev != NULL) {
			before->prev->next = &new_item->list_item;
		}
		before->prev = &new_item->list_item;
	}

	list->head->count++;
	list->counter++;
}

void shuffle(struct aiv_list* list) {
	if (list->head == NULL) return;

	int count = 0;
	struct aiv_list_item* current = list->head;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}

	struct aiv_list_item** items = malloc(count * sizeof(struct aiv_list_item*));
	current = list->head;
	for (int i = 0; i < count; i++)
	{
		items[i] = current;
		current = current->next;
	}

	srand(time(NULL));
	for (int i = count - 1; i > 0; i--)
	{
		int j = rand() % (i + 1);
		struct aiv_list_item* temp = items[i];
		items[i] = items[j];
		items[j] = temp;
	}

	list->head = items[0];
	list->head->prev = NULL;
	current = list->head;
	for (int i = 1; i < count; i++)
	{
		current->next = items[i];
		items[i]->prev = current;
		current = current->next;
	}

	list->tail = current;
	list->tail->next = NULL;
}