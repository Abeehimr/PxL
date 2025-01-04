CC=g++
CFLAGS = -c
OBJECTS = main.o

all: prog

prog: $(OBJECTS)
	$(CC) $(OBJECTS) -o prog -lcurses

%.o: %.cpp
	$(CC) $(CFLAGS) $<

clean:
	rm -rf *.o prog