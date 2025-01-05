OBJECTS = main.o
SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system


# Source Files
SRCS = $(wildcard *.cpp)

# Object Files
OBJS = $(SRCS:.cpp=.o)

# Executable Name
TARGET = paint

# Default Target
all: $(TARGET)

# Build the Executable
$(TARGET): $(OBJS)
	g++ -o $(TARGET) $(OBJS) $(SFMLFLAGS)

# Compile Object Files
%.o: %.cpp
	g++ -c $< -o $@

# Clean Up
clean:
	rm -f $(OBJS) $(TARGET)

# Run the Program
run: $(TARGET)
	./$(TARGET)
