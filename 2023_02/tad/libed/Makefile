APPS = ./apps
BIN = ./bin
INCLUDE = ./include
LIB = ./lib
OBJ = ./obj
SRC = ./src

FLAGS = -O3 -Wall
LIBS = -lm -led -L $(LIB)



all: libed myapps

libed: \
	$(OBJ)/cubo.o \
	$(OBJ)/cilindro.o \
	$(OBJ)/esfera.o \
	$(OBJ)/n_complex.o
	ar -rcs $(LIB)/libed.a $(OBJ)/*.o


myapps: clean_apps \
	$(BIN)/test_cubo \
	$(BIN)/test_cilindro \
	$(BIN)/test_esfera \
	$(BIN)/test_n_complex

$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	gcc $(FLAGS) -c $< -I $(INCLUDE) -o $@

$(BIN)/%: $(APPS)/%.c
	gcc $(FLAGS) $< $(LIBS) -I $(INCLUDE) -o $@

run:
	$(BIN)/test_cubo

clean:
	rm -rf $(BIN)/* $(LIB)/* $(OBJ)/*

clean_apps:
	rm -rf $(BIN)/*
