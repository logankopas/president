//////////////////////////////////////////////////
//              President                       //
//              Logan Kopas                     //
//              Copyright Dec 2013              //
//////////////////////////////////////////////////

#ifndef     _CARDS_H_
#define     _CARDS_H_

#include <list>
#include <iostream>

#define DECK_SIZE 52

enum suit 
{       HEARTS
,       DIAMONDS
,       CLUBS
,       SPADES
};

struct deck_t
{       
    int deck[DECK_SIZE + 1];
};

struct player_t
{
    char *name;
    int count;
    std::list<int> *hand;
	bool pass;
};

struct cards
{
	int num;
	int cards[4];
};

extern deck_t *current_deck;
extern player_t *players;
extern int num_players;
extern cards played_cards;

int shuffle(void);
int create_deck(void);
void swap_cards(int,int,int*);
void print_deck(int*);
void print_hand(int);
int create_players(int);
void deal(void);
bool card_comp(int, int);
void print_card(int*,int);

#endif
