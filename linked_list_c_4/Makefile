FILES = main.c linkedlist.c
BIN_LOCATION = bin/main

valgrind:
	@gcc $(FILES) -o $(BIN_LOCATION)
	valgrind --leak-check=full  $(BIN_LOCATION)

default:
	@gcc $(FILES) -o $(BIN_LOCATION)
	@./$(BIN_LOCATION)
