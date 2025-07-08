CC = g++
CFLAGS = -O3
TARGET = brainfuck
OBJECTS = compiler.o machine.o runner.o main.o

all: $(TARGET)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET) *.o
