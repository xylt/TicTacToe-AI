# Objects
OBJS = main.o Game.o Chessboard.o AI.o

# Compiler
CC = g++ -std=c++11

TicTacToe: $(OBJS)
	$(CC) -o TicTacToe $(OBJS)

main.o: main.cpp
	$(CC) -c main.cpp

Game.o: Game.cpp
	$(CC) -c Game.cpp

AI.o: AI.cpp
	$(CC) -c AI.cpp

Chessboard.o: Chessboard.cpp
	$(CC) -c Chessboard.cpp

clean:
	rm TicTacToe ${OBJS}
