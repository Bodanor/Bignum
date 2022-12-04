CC = gcc
CFLAGS = -Wall -Wextra -D DEBUG -g

C_SOURCES := $(wildcard *.c)
C_HEADERS := $(wildcard *.h)
C_OBJECTS := $(C_SOURCES:.c=.o)

bignum: $(C_OBJECTS) $(C_SOURCES) $(C_HEADERS)
	$(info Building target : $<)
	$(CC) $(CFLAGS) -o $@ $(C_OBJECTS)

%.o: %.c
	$(info Building : $<)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf *.o
	rm -rf bignum
