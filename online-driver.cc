//////////////////////////////////////////////////
//              President                       //
//              Logan Kopas                     //
//              Copyright Dec 2013              //
//////////////////////////////////////////////////

#include <stdlib.h>
#include <stdio.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/fcntl.h>
#include <ifaddrs.h>
#include <string.h>

#include "cards.h"
#include "online.h"

using namespace std;

int main(int argc, char** argv)
{
    (void) argc;
    (void) argv;
    (void) players;
    (void) current_deck;
    num_players = 0;
    
    gethost();
    
    return 0;
}

/*int gethost()
{
    ifaddrs *ifAddrStruct=NULL,*ifa=NULL;
    void *tmpAddrPtr=NULL;
    
    getifaddrs(&ifAddrStruct);
    
    for( ifa = ifAddrStruct; ifa != NULL; ifa=ifa->ifa_next)
    {
        if( ifa->ifa_addr->sa_family==AF_INET )
        {   // IP4 address
            tmpAddrPtr=&((sockaddr_in*)ifa->ifa_addr)->sin_addr;
            char addressBuffer[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, tmpAddrPtr, addressBuffer, INET_ADDRSTRLEN);
            printf("4:'%s': %s\n", ifa->ifa_name, addressBuffer);
        }else if(ifa->ifa_addr->sa_family==AF_INET6)
        {   // IP6 address
            tmpAddrPtr=&((sockaddr_in6*)ifa->ifa_addr)->sin6_addr;
            char addressBuffer[INET6_ADDRSTRLEN];
            inet_ntop(AF_INET6, tmpAddrPtr, addressBuffer, INET6_ADDRSTRLEN);
            printf("6:'%s': %s\n",ifa->ifa_name, addressBuffer);
        }
    }
    
    return 0;
}*/

int gethost()
{
    // create UDP socket, biind to wildcard,
    //      connect to 1.2.3.4, getsockname
}
