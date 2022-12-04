CC = gcc
CFLAGS = -Wall -Wextra -D DEBUG -g

C_SOURCES := $(filter-out seatest.c tests.c, $(wildcard *.c))
C_HEADERS := $(filter-out seatest.h, $(wildcard *.h))
C_OBJECTS := $(C_SOURCES:.c=.o)

bignum: $(C_OBJECTS) $(C_SOURCES) $(C_HEADERS)
	$(info Building target : $<)
	$(CC) $(CFLAGS) -o $@ $(C_OBJECTS)

tests: $(filter-out main.c, $(C_SOURCES)) $(filter-out main.o, $(C_OBJECTS)) seatest.c seatest.h tests.c
	$(info Making tests...)
	$(CC) $(CFLAGS) -o $@ seatest.c $(filter-out main.o, $(C_OBJECTS)) tests.c

%.o: %.c
	$(info Building : $<)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf *.o
	rm -rf bignum
	rm -rf tests
