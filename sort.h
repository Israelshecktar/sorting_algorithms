#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/********************FUNCTION PROTEOTYPES******************/
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
int partition(int *array, int low, int high, size_t size);
void quick_sort_helper(int *array, int low, int high, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
/*void sort_deck(deck_node_t **deck);*/
void cocktail_sort_forward(listint_t **list, listint_t *current, int *swapped);
void swap_nodes(listint_t **list, listint_t *a, listint_t *b);
void cocktail_sort_backward(listint_t **list, listint_t *current, int *swapped);
void print_sub_array(const int *array, size_t size);
void merge(int *array, size_t size, size_t mid, int *temp);
void top_down_merge_sort(int *array, size_t size, int *temp);

#endif /* SORT_T*/
