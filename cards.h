//////////////////////////////////////////////////
//		President		        //
//		Logan Kopas			//
//		Copyright Dec 2013		//
//////////////////////////////////////////////////

#ifndef		_CARDS_H_
#define		_CARDS_H_

#include <list>
#include <iostream>

#define DECK_SIZE 52

enum suit 
{	HEARTS
,	DIAMONDS
,	CLUBS
,	SPADES
};

struct deck_t
{	
	int deck[DECK_SIZE + 1];
};

struct player_t
{
	char *name;
	int size;
	std::list<int> hand;
};

deck_t *current_deck;
player_t *players;
int num_players;

int shuffle(void);
int create_deck(void);
void swap_cards(int,int,int*);
void print_cards(int,int*);
int create_players(int);
void deal(void);
bool card_comp(int, int);

#endif
