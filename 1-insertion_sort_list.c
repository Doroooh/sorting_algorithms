#include "custom_sort.h"

/**
 * custom_swap - swaps two nodes in a doubly linked list
 * @head: pointer to the head of the list
 * @node1: pointer to the first node
 * @node2: pointer to the second node
 *
 * Return: void
 */
void custom_swap(listint_t **head, listint_t *node1, listint_t *node2)
{
    listint_t *prev_node1, *next_node2;

    prev_node1 = node1->prev;
    next_node2 = node2->next;

    if (prev_node1 != NULL)
        prev_node1->next = node2;
    else
        *head = node2;

    node1->prev = node2;
    node1->next = next_node2;
    node2->prev = prev_node1;
    node2->next = node1;

    if (next_node2 != NULL)
        next_node2->prev = node1;
}

/**
 * custom_insertion_sort_list - sorts a doubly linked list using
 * the insertion sort algorithm
 *
 * @list: pointer to the head of the list
 *
 * Return: void
 */
void custom_insertion_sort_list(listint_t **list)
{
    listint_t *forward, *tmp;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    for (forward = (*list)->next; forward != NULL && forward->prev != NULL; forward = forward->next)
    {
        for (; forward != NULL && forward->prev != NULL && forward->n < forward->prev->n; forward = forward->prev)
        {
            tmp = forward->prev;
            custom_swap(list, tmp, forward);
            print_list(*list);
            forward = forward->next;
        }
    }
}
