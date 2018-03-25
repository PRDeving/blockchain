CC = g++
FLAGS = -std=c++11 -std=gnu++11 -Wall
INCLUDES = -Iincludes
LIBRARIES = -Llib -lcrypto
NAME = bcNode

FILES = src/utils.cpp src/block.cpp src/chain.cpp src/main.cpp

compile:
	$(CC) $(FLAGS) $(INCLUDES) $(FILES) $(TESTS) $(LIBRARIES) -o $(NAME)

clean:
	rm $(NAME)

test:
	make -C tests
