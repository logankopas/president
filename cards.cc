//////////////////////////////////////////////////
//              President                       //
//              Logan Kopas                     //
//              Copyright Dec 2013              //
//////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>
#include <algorithm>
#include <list>

#ifndef _CARDS_H_
#include "cards.h"
#endif 

using namespace std;

/* Declare External Globals */
int num_players=0;
player_t *players = NULL;
deck_t *current_deck = NULL;

/*
int main() // for testing
{
    
    create_deck();
    print_deck(current_deck->deck);
    shuffle();
    print_deck(current_deck->deck);
    num_players = 7;
    printf("Deal\n");
    deal();
    
    printf("Hands:\n");
    for(int i=0; i<num_players;i++)
    {
        print_hand(i);
    }

    return 0;
}*/


int shuffle()
{
    // Current implementation: 
    //      A new deck is created every shuffle

    create_deck();  
    
    for( int i = 0; i < 200; i++ )
        swap_cards( (rand() % 52) +1, (rand() % 52) +1, current_deck->deck );
    return 0;
}

int create_deck()
{
    /* Initialize rand sequence */
    
    #ifndef SEED
        time_t start_time;
        time( &start_time );
        srand( (unsigned int) start_time );
    #endif
    #ifdef SEED
        srand( SEED );
    #endif
    
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

void print_deck(int* cards)
{
    /* Deck starts from cards[1] */
    cards++;
    
    printf("|");
    for( int i=0; i<DECK_SIZE; i++ )
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

void print_hand(int number)
{
    list<int>::iterator cards;
    cards = players[number].hand->begin();
    
    printf("%d:\n|",players[number].count);
    for( int i=0; i<players[number].count; i++ )
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

    for( int i=0; i<num; i++ )
    {
        players[i].count=0;
        players[i].hand = new list<int>();
    }    

    return 0;
}

void deal()
{
    int i,j;
    if(players == NULL)
        create_players(num_players);

    for( i=0; i<=DECK_SIZE;  )
    {
        for( j=0; j<num_players; j++ )
        {
            i++;

            if(i<=DECK_SIZE)
            {
                players[j].hand->push_back(current_deck->deck[i]);          
                printf("%d,",i);
                players[j].count++;
            }
        }
    }
    for( int j=0; j<num_players; j++ )
        players[j].hand->sort(&card_comp);

}

bool card_comp(int first, int second)
{
    if( (first-1)%13 < (second-1)%13 )
        return true;
    else
        return first<second;
}
