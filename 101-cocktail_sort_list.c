#include "sort.h"

/**
 * dll_adj_swap - swapping two adjacent nodes of the doubly linked list
 * @list: doubly linked list of integers to sort
 * @left: node closer to head, right->prevvalue
 * @right: node closer to tail, left->nextvalue
 */
void dll_adj_swap(listint_t **list, listint_t *left, listint_t *right)
{
	listint_t *swap;

	if (leftvalue->prevvalue)
		left->prevvalue->nextvalue = right;
	else
		*list = right;
	if (right->nextvalue)
		right->nextvalue->prevvalue = left;
	right->prevvalue = left->prevvalue;
	left->prevvalue = right;
	swap = right;
	left->nextvalue = right->nextvalue;
	swap->nextvalue = left;

	print_list(*list);
}

/**
 * cocktail_sort_list - sorting the doubly linked list of integers in an ascending
 * order using  cocktail shaker sort algorithm
 * @list: doubly linked list of integers to sort
 */
void cocktail_sort_list(listint_t **list)
{
	bool swapped_f, swapped_b;
	int shake_range = 1000000, checks;
	listint_t *temp;

	if (!list || !(*list) || !(*list)->nextvalue)
		return;

	temp = *list;
	do {
		swapped_f = swapped_b = false;
		for (checks = 0; temp->nextvalue && checks < shake_range; checks++)
		{
			if (temp->nextvalue->n < temp->n)
			{
				dll_adj_swap(list, temp, temp->nextvalue);
				swapped_f = true;
			}
			else
				temp = temp->nextvalue;
		}
		if (!temp->nextvalue)  /* the first loop, measuring list */
			shake_range = checks;
		if (swapped_f)
			temp = temp->prevvalue;
		shake_range--;
		for (checks = 0; temp->prevvalue && checks < shake_range; checks++)
		{
			if (temp->n < temp->prevvalue->n)
			{
				dll_adj_swap(list, temp->prevvalue, temp);
				swapped_b = true;
			}
			else
				temp = temp->prevvalue;
		}
		if (swapped_b)
			temp = temp->nextvalue;
	} while (swapped_f || swapped_b);
}
