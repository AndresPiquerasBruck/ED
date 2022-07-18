SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c

all: $(BIN)/usopilas $(BIN)/usocolas_max

$(BIN)/usopilas: $(OBJ)/usopilas.o
	$(CXX) -o $(BIN)/usopilas $(OBJ)/usopilas.o 
$(OBJ)/usopilas.o: $(INC)/pila.h $(SRC)/usopilas.cpp
	$(CXX) $(CPPFLAGS)  $(SRC)/usopilas.cpp  -o $(OBJ)/usopilas.o -I$(INC)

$(BIN)/usocolas_max: $(OBJ)/usocolas_max.o 
	$(CXX) -o $(BIN)/usocolas_max $(OBJ)/usocolas_max.o 
$(OBJ)/usocolas_max.o: $(SRC)/usocolas_max.cpp $(INC)/cola_max.h $(INC)/pila.h
	$(CXX) $(CPPFLAGS)  $(SRC)/usocolas_max.cpp  -o $(OBJ)/usocolas_max.o -I$(INC)

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
