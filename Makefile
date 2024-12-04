CC = gcc
CFLAGS = -Wall -Wpedantic -Wextra -lncurses
# TODO: Add -O3 flag

build:
	@echo "Building..."
	$(CC) $(CFLAGS) -o ascii-weather src/*.c

build-tests:
	@echo "Building tests..."
	$(CC) $(CFLAGS) -o test256cols  tests/test256cols.c
