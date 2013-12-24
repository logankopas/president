//////////////////////////////////////////////////
//              President                       //
//              Logan Kopas                     //
//              Copyright Dec 2013              //
//////////////////////////////////////////////////

#ifndef _ONLINE_H_
#define _ONLINE_H_

const int BACKLOG = 5;
static char hostname[80];

int gethost();
int send_deck(char*, char*);
int receive_deck();

#endif
