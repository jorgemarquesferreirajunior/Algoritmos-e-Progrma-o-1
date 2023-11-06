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
	$(OBJ)/linked_list.o
	ar -rcs $(LIB)/libed.a $(OBJ)/*.o


myapps: clean_apps \
	$(BIN)/listas_encadeadas \
	$(BIN)/tarefa_01_linked_list

$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	gcc $(FLAGS) -c $< -I $(INCLUDE) -o $@

$(BIN)/%: $(APPS)/%.c
	gcc $(FLAGS) $< $(LIBS) -I $(INCLUDE) -o $@

run:
	$(BIN)/listas_encadeadas

clean:
	rm -rf $(BIN)/* $(LIB)/* $(OBJ)/*

clean_apps:
	rm -rf $(BIN)/*
