CC = g++
CFLAGS = -c
OBJECTS = main.o App.o Canvas.o Mouse.o Tools.o Utils.o Stamps.o Pallete.o Toolbar.o
DEP = -lsfml-graphics -lsfml-window -lsfml-system
OUTPUT = paint

all: $(OUTPUT)

$(OUTPUT): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(OUTPUT) $(DEP)

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(OUTPUT)

run: $(OUTPUT)
	./$(OUTPUT)
