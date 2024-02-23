.PHONY: lsh
lsh: bin/lsh
	@./bin/lsh

bin/lsh: main.c
	@mkdir -p bin
	@$(CC) -DLSH_USE_STD_GETLINE main.c -o bin/lsh
