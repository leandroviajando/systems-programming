SHELL := /usr/bin/env bash
MAKEFLAGS += --silent

-include .env
export

LANG := c
CCFLAGS :=
CXXFLAGS := -std=c++20 -Wall -Wextra -pedantic -pthread

## Example usage: make LANG=c/c++/cpp/rs/rust [CCFLAGS/CXXFLAGS=...]

PKG   = fibonacci
BIN   = bin
LIB   = lib
SRC   = src
TESTS = tests

TARGET = $(shell if [ $(LANG) = rust ] || [ $(LANG) = rs ]; then echo target/debug/$(PKG); else echo $(BIN)/main; fi)

$(TARGET):
	$(call build_target)

.PHONY: all
all: help

.PHONY: help
help: ## Display the available commands
	echo "Available commands:"
	grep -h -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'

.PHONY: build
build: $(TARGET) ## Build target

define build_target
	echo LANG = $(LANG)
	mkdir -p bin
	if [ $(LANG) = c ]; then \
		$(CC) $(SRC)/main.c $(LIB)/fib/$(SRC)/fib.c -o $(BIN)/main; \
	elif [ $(LANG) = c++ ] || [ $(LANG) = cpp ]; then \
		echo CXXFLAGS = $(CXXFLAGS); \
		$(CC) -c $(CCFLAGS) $(LIB)/fib/$(SRC)/fib.c -o $(BIN)/fib.o; \
		$(CXX) $(CXXFLAGS) $(SRC)/main.cpp $(BIN)/fib.o -o $(BIN)/main; \
	elif [ $(LANG) = rust ] || [ $(LANG) = rs ]; then \
		cargo build; \
	else \
		echo Invalid LANG; \
		exit 1; \
	fi

	echo
	echo Successfully built $(TARGET).
	exit 0
endef

.PHONY: clean
clean: ## Clean target
	rm -f $(TARGET)

.PHONY: run
run: $(TARGET) ## Run compiled program
	if [ $(LANG) = c ] || [ $(LANG) = c++ ] || [ $(LANG) = cpp ]; then \
		$(BIN)/main; \
	elif [ $(LANG) = rust ] || [ $(LANG) = rs ]; then \
		cargo run; \
	else \
		echo Invalid LANG; \
		exit 1; \
	fi

.PHONY: check
check: format lint test ## Run code quality checks

.PHONY: format
format: ## Format code
	find $(LIB) $(SRC) $(TESTS) -type f \( -name '*.c' -o -name '*.cpp' \) -exec clang-format -i {} -style=Google \;
	cargo fmt

.PHONY: lint
lint: ## Lint code
	cppcheck $(LIB) $(SRC) $(TESTS)

.PHONY: test
test: ## Run tests
	if [ $(LANG) = c ]; then \
		$(CC) $(TESTS)/test.c $(LIB)/fib/$(SRC)/fib.c -o $(BIN)/test; \
		$(BIN)/test; \
	elif [ $(LANG) = c++ ] || [ $(LANG) = cpp ]; then \
		$(CC) -c $(CCFLAGS) $(LIB)/fib/$(SRC)/fib.c -o $(BIN)/fib.o; \
		$(CXX) $(CXXFLAGS) $(TESTS)/test.cpp $(BIN)/fib.o -o $(BIN)/test; \
		$(BIN)/test; \
	elif [ $(LANG) = rust ] || [ $(LANG) = rs ]; then \
		cargo test; \
	else \
		echo Invalid LANG; \
		exit 1; \
	fi
