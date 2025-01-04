CC=g++
CFLAGS = -c
OBJECTS = main.o
SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

all: prog

prog: $(OBJECTS)
	$(CC) $(OBJECTS) -o prog $(SFMLFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) $<

clean:
	rm -rf *.o prog