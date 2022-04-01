CC = g++
CFLAGS = -c -Wall

all: run

run: sort
	./sort.exe

sort: main.o sortingAlgorithms.hh sortingAlgorithms.o arrayGenerator.hh arrayGenerator.o
	$(CC) -g3 -DDEBUG main.o sortingAlgorithms.o arrayGenerator.o -o sort.exe

main.o: main.cpp sortingAlgorithms.hh arrayGenerator.hh
	$(CC) $(CFLAGS) main.cpp

sortingAlgorithms.o: sortingAlgorithms.cpp sortingAlgorithms.hh
	$(CC) $(CFLAGS) sortingAlgorithms.cpp

arrayGenerator.o: arrayGenerator.cpp arrayGenerator.hh
	$(CC) $(CFLAGS) arrayGenerator.cpp