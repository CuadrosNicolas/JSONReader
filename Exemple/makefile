CC = g++
CFLAGS = -Wall
EXEC_NAME = bin/exemple
LIBNAME = lib/JsonReader.a
OBJECTS = bin/objects/
OBJ_FILES = $(OBJECTS)main.o $(OBJECTS)JData.o $(OBJECTS)JPage.o $(OBJECTS)JLocation.o

all : $(EXEC_NAME)

clean :
	rm $(EXEC_NAME) $(OBJ_FILES)

$(EXEC_NAME) : $(OBJ_FILES)
	g++ -o $(EXEC_NAME) $(OBJ_FILES) $(LIBNAME)

$(OBJECTS)%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<