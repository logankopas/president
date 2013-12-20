//////////////////////////////////////////////////
//		President		        //
//		Logan Kopas			//
//		Copyright Dec 2013		//
//////////////////////////////////////////////////

#ifndef		_CARDS_H_
#define		_CARDS_H_

enum suit 
{	HEARTS
,	DIAMONDS
,	CLUBS
,	SPADES
};

struct deck_t
{	
	int deck[53];
};

struct hand_t
{
	int count;
	// Some sort of list
};

deck_t *current_deck;

int shuffle(void);
int create_deck(void);
void swap(int,int,void*);

#endif
