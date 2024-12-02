CC = gcc
CFLAGS = -Wall -Wpedantic -Wextra -lncurses
# TODO: Add -O3 flag

build:
	$(CC) $(CFLAGS) -o ascii-weather src/*.c
