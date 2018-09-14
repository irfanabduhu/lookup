CXX=clang++
CXXFLAGS=-g -std=c++17 -Wall -pedantic
BIN=prog

SRC=$(wildcard *.cpp)
0BJ=$(SRC:%.cpp=%.o)

all: $(OBJ)
	$(CXX) -o $(BIN) $^

%.o: %.c
	$(CXX) $@ -c $<

clean:
	rm -f *.o
	rm $(BIN)
