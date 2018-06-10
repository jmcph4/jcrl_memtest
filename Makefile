SRC_DIR = src
INC_DIR = include
LIB_DIR = lib
BIN_DIR = bin

CC = gcc
CFLAGS = -Wall -Wextra -Wshadow -pedantic-errors -std=c11 -I$(INC_DIR) -L$(LIB_DIR) -ljcrl -g

.PHONY: all
all:
	make memtest_list;
	make memtest_stack;
	make memtest_queue;
	make memtest_multiset;
	make memtest_set;

memtest_list: $(SRC_DIR)/memtest_list.c
	$(CC) $^ $(CFLAGS) -o $(BIN_DIR)/$@

memtest_stack: $(SRC_DIR)/memtest_stack.c
	$(CC) $^ $(CFLAGS) -o $(BIN_DIR)/$@

memtest_queue: $(SRC_DIR)/memtest_queue.c
	$(CC) $^ $(CFLAGS) -o $(BIN_DIR)/$@

memtest_multiset: $(SRC_DIR)/memtest_multiset.c
	$(CC) $^ $(CFLAGS) -o $(BIN_DIR)/$@

memtest_set: $(SRC_DIR)/memtest_set.c
	$(CC) $^ $(CFLAGS) -o $(BIN_DIR)/$@

.PHONY: clean
clean:
	rm $(BIN_DIR)/*

