# Hunter Long
# CS-3424
# May 2nd, 2021
# Assignment 6

CC = gcc
CFLAGS = -Wall -g 
PROGRAM = assign6
all: $(PROGRAM)

assing6.o: assign6.c
	$(CC) $(CFLAGS) -c assign6.c

assign6: assign6.o
	$(CC) $(CFLAGS) -o assign6 assign6.o

clean: 
	rm -f *.o
	rm $(PROGRAM)
