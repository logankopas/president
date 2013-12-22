#################################################
#		    President			                #
#		    Logan Kopas			                #
#		    Copyright Dec 2013		            #
#################################################

CC = g++ -c 
CFLAGS = -Wall -Wextra --pedantic -g
LD = g++ -o $@

all: cards-online cards

cards.o: cards.cc
	$(CC) $(CFLAGS) $^
	
cards: driver.o cards.o
	$(LD) $^
    
cards-online: online-driver.o cards.o
	$(LD) $^

online-driver.o: online-driver.cc
	$(CC) $(CFLAGS) $^

driver.o: driver.cc
	$(CC) $(CFLAGS) $^

clean:
	rm -f *.o cards 

.PHONY: clean all
