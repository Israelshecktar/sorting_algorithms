#include <stdlib.h>
#include "deck.h"

/**
 * card_value - returns the value of a card
 * @card: card to evaluate
 *
 * Return: integer value of the card
 *         Order: Ace, 2-10, Jack, Queen, King, Spades, Hearts, Clubs,
 * Diamonds
 */
int card_value(const card_t *card)
{
	int card_num;
	int kind_val = 0;

	if (card->value[0] == 'A')
		card_num = 1;
	else if (card->value[0] == '1' && card->value[1] == '0')
		card_num = 10;
	else if (card->value[0] == 'J')
		card_num = 11;
	else if (card->value[0] == 'Q')
		card_num = 12;
	else if (card->value[0] == 'K')
		card_num = 13;
	else
		card_num = card->value[0] - '0';

	switch (card->kind)
	{
		case SPADE:
			kind_val = 0;
			break;
		case HEART:
			kind_val = 100;
			break;
		case CLUB:
			kind_val = 200;
			break;
		case DIAMOND:
			kind_val = 300;
			break;
	}

	return (card_num + kind_val);
}

/**
 * card_compare - compares two cards
 * @card1: first card to compare
 * @card2: second card to compare
 *
 * Return: difference between card1 and card2
 */
int card_compare(const void *card1, const void *card2)
{

	const card_t *c1;
	const card_t *c2;

	c1 = ((deck_node_t *)card1)->card;
	c2 = ((deck_node_t *)card2)->card;

	return (card_value(c1) - card_value(c2));
}

/**
 * sort_deck - sorts a deck of cards
 * @deck: deck to sort
 */
void sort_deck(deck_node_t **deck)
{
	size_t size;
	deck_node_t *tmp;
	deck_node_t *array[52];
	size_t i;

	if (deck == NULL || *deck == NULL)
		return;

	/* count number of elements */
	for (size = 0, tmp = *deck; tmp != NULL; size++, tmp = tmp->next)
		;

	/* copy linked list to array */
	tmp = *deck;
	i = 0;
	while (i < size)
	{
		array[i] = tmp;
		tmp = tmp->next;
		i++;
	}

	/* sort array */
	qsort((void *)array, size, sizeof(deck_node_t *), card_compare);

	/* rebuild linked list from sorted array */
	i = 0;
	while (i < size - 1)
	{
		array[i]->next = array[i + 1];
		i++;
	}

	array[size - 1]->next = NULL;
	*deck = array[0];
}
