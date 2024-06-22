CC=gcc
CFLAGS=-I./include -DLSH_USE_STD_GETLINE

SRC=src
INC=include
BIN=bin
OBJ=obj

SOURCES=$(wildcard $(SRC)/*.c)
OBJECTS=$(patsubst $(SRC)/%.c,$(OBJ)/%.o,$(SOURCES))
HEADERS=$(wildcard $(INC)/*.h)

$(BIN)/lsh: $(OBJECTS) | $(BIN)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ)/%.o: $(SRC)/%.c $(HEADERS) | $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN) $(OBJ):
	mkdir -p $@

.PHONY: build run clean

clean:
	rm -rf $(OBJ) $(BIN)

build: $(BIN)/lsh

run: build
	$(BIN)/lsh
