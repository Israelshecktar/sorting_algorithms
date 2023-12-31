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
void cocktail_sort_backward(listint_t **list,
		listint_t *current, int *swapped);
void merge(int *array, size_t size, int *left, int *right, size_t middle);
void swap_elements(int *array, int i, int j, size_t size);
void sift_down(int *array, int start, int end, size_t size);
void heapify(int *array, size_t size);
int get_max(int *array, size_t size);
void count_sort(int *array, size_t size, int exp);
void bitonic_split(int *array, size_t low, size_t size, int dir);
void bitonic_merge(int *array, size_t low, size_t size, int dir);
void swap(int *a, int *b);
int partition(int *array, int start, int end, size_t size);
void quicksort(int *array, int start, int end, size_t size);



#endif /* SORT_T*/

