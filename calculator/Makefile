bin/main: bin/main.o bin/calculator.o bin/scientific.o
	mkdir -p bin
	g++ bin/main.o bin/calculator.o bin/scientific.o -o bin/main

bin/main.o: main.cpp calculator.h scientific.h
	mkdir -p bin
	g++ -c main.cpp -o bin/main.o

bin/calculator.o: calculator.cpp calculator.h
	mkdir -p bin
	g++ -c calculator.cpp -o bin/calculator.o

bin/scientific.o: scientific.cpp scientific.h
	mkdir -p bin
	g++ -c scientific.cpp -o bin/scientific.o
