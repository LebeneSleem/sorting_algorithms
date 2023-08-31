#include "sort.h"

void insertion_sort_list(listint_t **list)
{
	int value;
	listint_t *curr, *temp;
	
	if (*list == NULL || (*list)->next == NULL)
	{
		return;
	}

	*curr = (*list)->next;
	while (curr != NULL)
	{
		*temp = curr->prev;
		value = curr->n;
		while (temp != NULL && temp->n > value)
		{
			temp->next->n = temp->n;
			temp = temp->prev;
        }
		if (temp == NULL)
		{
			(*list)->n = value;
		}
		else
		{
			temp->next->n = value;
		}
		print_list(*list);
		curr = curr->next;
	}
}
