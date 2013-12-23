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
#include <errno.h>

#include "cards.h"
#include "online.h"

using namespace std;

int main(int argc, char** argv)
{
    (void) argc;
    (void) argv;
    (void) players;
    (void) current_deck;
    (void) hostname;
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

/* 
 * gethost() prints current host
 * More for practice, probably won't ever call this
 */
int gethost()
{
   
    struct addrinfo hints, *res, *p, *out, out_hints;
    int status;
    char ipstr[INET6_ADDRSTRLEN];
    int s;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC; // AF_INET or AF_INET6 to force version
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_flags = AI_PASSIVE;

    if ((status = getaddrinfo(NULL, "45555", &hints, &res)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        return 2;
    }

    printf("IP address:\n\n");

    for(p = res;p != NULL; p = p->ai_next) {
        void *addr;
        char *ipver;

        // get the pointer to the address itself,
        // different fields in IPv4 and IPv6:
        if (p->ai_family == AF_INET) { // IPv4
            struct sockaddr_in *ipv4 = (struct sockaddr_in *)p->ai_addr;
            addr = &(ipv4->sin_addr);
            ipver = (char*)"IPv4";
        } else { // IPv6
            struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)p->ai_addr;
            addr = &(ipv6->sin6_addr);
            ipver = (char*)"IPv6";
        }

        // convert the IP to a string and print it:
        inet_ntop(p->ai_family, addr, ipstr, sizeof ipstr);
        printf("  %s: %s\n", ipver, ipstr);
    }

    s=socket(res->ai_family,SOCK_DGRAM,0);
    if(s==-1)
    {
        fprintf(stderr,"socket failed\n");
    }
    
    /* Set port to re-usable */
    int yes=1;

    // lose the pesky "Address already in use" error message
   /* if (setsockopt(listener,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(int)) == -1) {
        perror("setsockopt");
        exit(1);
    } */
    
    bind(s,res->ai_addr,res->ai_addrlen);
    if(s==-1)
    {
        fprintf(stderr,"bind failed\n");
    }
    
    // now connect to 1.2.3.4
     memset(&out_hints, 0, sizeof out_hints);
    out_hints.ai_family = AF_UNSPEC; // AF_INET or AF_INET6 to force version
    out_hints.ai_socktype = SOCK_DGRAM;

    if ((status = getaddrinfo("1.2.3.4", NULL, &out_hints, &out)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        return 2;
    }

    if(connect(s,out->ai_addr,out->ai_addrlen)!=0)
    {
        fprintf(stderr, "connect failed\n");
    }

    char ip4[INET_ADDRSTRLEN];
    sockaddr address;
    socklen_t address_len;
    address_len = sizeof address;
    if(getsockname(s, &address, &address_len)!=0)
    {
        fprintf(stderr,"Error getting sock name\n");
    }
    if(address.sa_family == AF_INET)
    {
        inet_ntop(AF_INET,&address.sa_data,ip4,INET_ADDRSTRLEN);
        printf("Address: %s\n",ip4);
    }

    
    
    freeaddrinfo(res); // free the linked list
    freeaddrinfo(out);
    
    return 0;
}
