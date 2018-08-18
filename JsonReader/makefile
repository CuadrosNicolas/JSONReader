CC = g++
CFLAGS = -Wall
EXEC_NAME = bin/JsonReader.a
OBJECTS = bin/objects/
INSTALL_DIR = /usr/bin
OBJ_FILES = $(OBJECTS)JsonConvertable.o $(OBJECTS)JSONParser.o $(OBJECTS)JSONObject.o $(OBJECTS)JSONVariable.o $(OBJECTS)JSONArray.o $(OBJECTS)JSONEntity.o
all : $(EXEC_NAME)

clean :
	rm $(EXEC_NAME) $(OBJ_FILES)

$(EXEC_NAME) : $(OBJ_FILES)
	ar rvs $(EXEC_NAME) $(OBJ_FILES)

$(OBJECTS)%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<


install :
	cp $(EXEC_NAME) $(INSTALL_DIR)