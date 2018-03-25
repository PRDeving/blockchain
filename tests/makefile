CC = g++
FLAGS = -std=c++11 -std=gnu++11 -Wall
INCLUDES = -I../src -I../includes
LIBRARIES = -L../lib -lcrypto -lgtest
NAME = runTests

FILES = ../src/utils.cpp ../src/block.cpp ../src/chain.cpp
TESTS = utilsTest.cpp run.cpp blockTest.cpp chainTest.cpp

compile:
	$(CC) $(FLAGS) $(INCLUDES) $(FILES) $(TESTS) $(LIBRARIES) -o $(NAME)

clean:
	rm $(NAME)

