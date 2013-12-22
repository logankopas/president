//////////////////////////////////////////////////
//              President                       //
//              Logan Kopas                     //
//              Copyright Dec 2013              //
//////////////////////////////////////////////////

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "cards.h"

using namespace std;

int main(int argc, char** argv)
{
    num_players = 0;
    
    while(1)
    {
        num_players++;
        printf("%d\n",num_players);
        sleep(2);
    }   

    return 0;
}
