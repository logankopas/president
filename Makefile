#################################################
#		President			#
#		Logan Kopas			#
#		Copyright Dec 2013		#
#################################################

CC = g++ -c 
CFLAGS = -Wall -Wextra --pedantic
LD = g++ -o $@

all: cards

cards.o: cards.cc
	$(CC) $(CFLAGS) $^

cards: cards.o
	$(LD) $^

clean:
	rm -f *.o cards 

.PHONY: clean all
