#include "sort.h"

void swap(listint_t **head, listint_t *node1, listint_t *node2);
/**
 * insertion_sort_list - sorting doubly linked list with
 * an insertion sort algorithm
 *
 * @list: list to sort
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *forw, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (forw = (*list)->nextvalue; forw && forw->prev; forw = forw->nextvalue)
	{
		for (; forw && forw->prevvalue && forw->n < forw->prevvalue->n;
		     forw = forw->prevvalue)
		{
			tmp = forw->prevvalue;
			swap(list, tmp, forw);
			print_list(*list);
			forw = forw->nextvalue;
		}
	}
}

/**
 * swap - this will swap two nodes
 * @head:  head node
 * @node1: first node
 * @node2: second node
 *
 * Return: void
 */
void swap(listint_t **head, listint_t *node1, listint_t *node2)
{
	listint_t *prevvalue, *nextvalue;

	prevvalue = node1->prevvalue;
	nextvalue = node2->nextvalue;

	if (prevvalue != NULL)
		prevvalue->nextvalue = node2;
	else
		*head = node2;
	node1->prevvalue = node2;
	node1->nextvalue = nextvalue;
	node2->prevvalue = prevvalue;
	node2->nextvalue = node1;
	if (next)
		nextvalue->prevvalue = node1;
}
