//////////////////////////////////////////////////
//              President                       //
//              Logan Kopas                     //
//              Copyright Dec 2013              //
//////////////////////////////////////////////////

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "cards.h"

int take_turn(int);
void clear(void);

using namespace std;

int main(int argc, char** argv)
{
	bool gameon = true;
	(void) argc;
	(void) argv;
    num_players = 2;
	played_cards.num = 0;

	shuffle();
	deal();

	while(gameon)
	{
		int num_played;
		for( int i=0; i<num_players; i++)
		{
			clear();
			num_played = take_turn(i);
		}

	}

    return 0;
}

int take_turn(int id)
{
	int response;
	if( played_cards.num > 0 )
	{
		if(execlp("echo","balls",(char*) NULL)!=0)
				printf("clear failed\n");
		print_card( played_cards.cards, played_cards.num );
	}
	print_hand(id);
	printf("Pick a card\n");
	scanf("%d",&response);
	printf("Response: %d\n",response);
	return response;
}

void clear()
{
	for( int i=0; i<50; i++ )
		printf("\n");
}
