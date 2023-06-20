CC = g++
CFLAGS = -std=c++11

all: main

main: main.cpp a_star.cpp bfs.cpp gbfs.cpp heuristic_calculator.cpp idastar.cpp idfs.cpp puzzle.cpp solution.cpp state.cpp
	$(CC) $(CFLAGS) -o main main.cpp a_star.cpp bfs.cpp gbfs.cpp heuristic_calculator.cpp idastar.cpp idfs.cpp puzzle.cpp solution.cpp state.cpp

clean:
	rm -f main