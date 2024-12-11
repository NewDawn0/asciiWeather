CC = gcc
CFLAGS = -O3 -Wall -Wpedantic -Wextra -lncurses

build:
	@echo "Building..."
	$(CC) $(CFLAGS) -o ascii-weather src/*.c

build-tests:
	@echo "Building tests..."
	$(CC) $(CFLAGS) -o test256cols  tests/test256cols.c
