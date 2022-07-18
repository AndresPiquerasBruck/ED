BIN = bin
CPPFLAGS = -Wall -Wpedantic -Werror -g -c -I$(INC)
CXX = g++
INC = include
LIB = lib
OBJ = obj
SRC = src

# ******* Compilación ******

all: $(BIN)/ProgramaImagen

$(BIN)/ProgramaImagen: $(OBJ)/main.o $(LIB)/libimage.a
	$(CXX) $(OBJ)/main.o -l imagen -o $(BIN)/ProgramaImagen -Llib

$(OBJ)/main.o: $(SRC)/main.cpp $(INC)/image.h $(INC)/imagenES.h $(INC)/tools.h
	$(CXX) $(CPPFLAGS) $(SRC)/main.cpp -o $(OBJ)/main.o

$(OBJ)/tools.o: $(SRC)/tools.cpp $(INC)/tools.h $(INC)/image.h $(INC)/imagenES.h
	$(CXX) $(CPPFLAGS) $(SRC)/tools.cpp -o $(OBJ)/tools.o

$(OBJ)/image.o: $(SRC)/image.cpp $(INC)/image.h $(INC)/imagenES.h
	$(CXX) $(CPPFLAGS) $(SRC)/image.cpp -o $(OBJ)/imagen.o

$(OBJ)/imagenES.o: $(INC)/imagenES.h $(SRC)/imagenES.cpp
	$(CXX) $(CPPFLAGS) -c $(SRC)/imagenES.cpp -o $(OBJ)/imagenES.o

# ****** Biblioteca ******

$(LIB)/libimage.a: $(OBJ)/tools.o $(OBJ)/image.o $(OBJ)/imagenES.o
	ar rvs $(LIB)/libimagen.a $(OBJ)/tools.o $(OBJ)/imagen.o $(OBJ)/imagenES.o

# ****** Clean ******

clean:
	rm $(BIN)/* $(OBJ)/* $(LIB)/*