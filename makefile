CC= g++
TARGET=matrix
INCLUDE=matrix.hpp
OBJ=main.o matrix.o

CFLAGS=-c -Wall

$(TARGET): $(OBJ)
	$(CC) -o $@ $(OBJ)
	
%.o: %.cpp $(INCLUDE)
	$(CC) $(CFLAGS) $< -o $@
