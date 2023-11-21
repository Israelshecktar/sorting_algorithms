#ifndef DECK_H
#define DECK_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * enum kind_e - Enum for the kind of card
 * @SPADE: Spade card
 * @HEART: Heart card
 * @CLUB: Club card
 * @DIAMOND: Diamond card
 *
 * Description: This enum represents the kind of card.
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Card structure
 * @value: Value of the card
 * @kind: Kind of the card
 *
 * Description: This struct represents a card. Each card
 * contains a value and a kind.
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Node of a deck
 * @card: Card in the deck
 * @prev: Pointer to the previous node in the deck
 * @next: Pointer to the next node in the deck
 *
 * Description: This struct represents a node in a deck. Each node
 * contains a card and pointers to the previous and next nodes in the deck.
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);
int card_compare(const void *card1, const void *card2);
int card_value(const card_t *card);

#endif /* DECK_H */
