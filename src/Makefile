OBJS = main.o Game.o Chessboard.o AI.o

CC = g++ -std=c++11

APP_NAME = TicTacToe

$(APP_NAME): $(OBJS)
	$(CC) -o $(APP_NAME) $(OBJS)

$(OBJS): %.o: %.cpp
	$(CC) -c $< -o $@

clean:
	rm $(APP_NAME) ${OBJS}

run:
	@./$(APP_NAME)
