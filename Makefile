CFLAGS = -O3 -Wall -Wpedantic -Wextra -lncurses

build:
	@echo "Building..."
	cc $(CFLAGS) -o ascii-weather src/*.c

build-tests:
	@echo "Building tests..."
	cc $(CFLAGS) -o test256cols  tests/test256cols.c
