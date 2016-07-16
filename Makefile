CC=g++
LIB=./lib
INCLUDE=./include
SRC=./src
OBJ=./obj
FLAGS = -Wall

main:	bst_lib
	$(CC) $(SRC)/main.cpp $(OBJ)/bst_lib.o $(FLAGS) -I$(INCLUDE) -L$(LIB) -o mybst

bst_lib:
	$(CC) -c $(SRC)/bst_lib.cpp $(FLAGS) -I$(INCLUDE) -o $(OBJ)/bst_lib.o
	ar -cru $(LIB)/bst_lib.a $(OBJ)/bst_lib.o

clean:
	rm mybst $(SRC)/*~ $(OBJ)/*o $(LIB)/*a
