# Objects
OBJS = main.o Game.o Chessboard.o AI.o

# Compiler
CC = g++ -std=c++11

TicTacToe: $(OBJS)
	$(CC) -o TicTacToe $(OBJS)

main.o: main.cpp Game.h
	$(CC) -c main.cpp

Game.o: Game.cpp Game.h Chessboard.h
	$(CC) -c Game.cpp

AI.o: AI.cpp AI.h
	$(CC) -c AI.cpp

Chessboard.o: Chessboard.cpp Chessboard.h
	$(CC) -c Chessboard.cpp

clean:
	rm TicTacToe ${OBJS}
