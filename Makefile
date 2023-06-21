CC = g++
CFLAGS = -std=c++11

all: main experiments

main: main.cpp a_star.cpp bfs.cpp gbfs.cpp heuristic_calculator.cpp idastar.cpp idfs.cpp puzzle.cpp solution.cpp state.cpp
	$(CC) $(CFLAGS) -o main main.cpp a_star.cpp bfs.cpp gbfs.cpp heuristic_calculator.cpp idastar.cpp idfs.cpp puzzle.cpp solution.cpp state.cpp

experiments: experiments.cpp a_star.cpp bfs.cpp gbfs.cpp heuristic_calculator.cpp idastar.cpp idfs.cpp puzzle.cpp solution.cpp state.cpp
	$(CC) $(CFLAGS) -o experiments experiments.cpp a_star.cpp bfs.cpp gbfs.cpp heuristic_calculator.cpp idastar.cpp idfs.cpp puzzle.cpp solution.cpp state.cpp

clean:
	rm -f main experiments