//////////////////////////////////////////////////
//		President		        //
//		Logan Kopas			//
//		Copyright Dec 2013		//
//////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>
#include <algorithm>
#include <list>

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
	
	create_deck();
	shuffle();
	print_cards(52,current_deck->deck);	

    	return 0;
}

int shuffle()
{
	// Current implementation: 
	// 	A new deck is created every shuffle

	create_deck();	
	
	for( int i = 0; i < 200; i++ )
		swap_cards( (rand() % 52) +1, (rand() % 52) +1, current_deck->deck );
 
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

void print_cards(int num, int *cards)
{
	
	printf("|");
	for( int i=0; i<num; i++ )
	{
		switch(((*cards)-1)/13)
		{
			case 0:
				printf("D");
				break;
			case 1:
				printf("H");
				break;
			case 2:
				printf("C");
				break;
			case 3:
				printf("S");
				break;
		}

		printf("%d|",(((*cards)-1)%13)+1);
		cards++;
	}
	
	printf("\n");
}

int create_players(int num)
{
	if( players != NULL)
		return -1;

	num_players = num;	
	players = (player_t*) malloc(num * sizeof(player_t));	

	return 0;
}

void deal()
{
	int i,j;
	if(players == NULL)
		create_players(num_players);

	for( i=0; i<=DECK_SIZE; i++ );
	{
		for( j=0; j<num_players; j++ )
		{
			++i;
			if(i<=DECK_SIZE)
				players[j].hand.push_front(current_deck->deck[i]);	

		}
	}
	for( int j=0; j<num_players; j++ )
		players[j].hand.sort();

}

bool card_comp(int first, int second)
{
	if( (first-1)%13 < (second-1)%13 )
		return true;
	else
		return first<second;

}
