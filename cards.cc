//////////////////////////////////////////////////
//		President		        //
//		Logan Kopas			//
//		Copyright Dec 2013		//
//////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "cards.h"

using namespace std;

int main()
{
	/* initialize the random number sequence */

	#ifndef SEED
		time_t start_time;
		time( &start_time );
		srand( (unsigned int) start_time );
	#endif
	#ifdef SEED
		srand( SEED );
	#endif


    	return 0;
}

int shuffle()
{
	// Current implementation: 
	// 	A new deck is created every shuffle

	create_deck();	
	
	for( int i = 0; i < 200; i++ )
		swap( (rand() % 52) +1, (rand() % 52) +1,(void*) current_deck->deck );
 
	return 0;
}

int create_deck()
{
	if( current_deck == NULL )
		current_deck = (deck_t*) malloc( sizeof(deck_t) );

	for( int i=1; i <= 52; i++ )
	{
		current_deck->deck[i] = i;
	}		
	
	return 0;
}

void swap_cards(int a, int b, int *cards)
{

	int temp;
	
	if( a == b )
		return;

	temp = cards[a];
	cards[a] = cards[b];
	cards[b] = temp;
	return;
}
