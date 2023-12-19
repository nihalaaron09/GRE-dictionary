CC = gcc
TARGET = GREdict

all: $(TARGET)

$(TARGET): GREdict.o
	$(CC) -o $(TARGET) GREdict.o

GREdict.o: GREdict.c
	$(CC) -c GREdict.c

help:
	@echo "Usage: make [all|clean|help]"
	@echo "all: Build the program."
	@echo "clean: Remove the program and object files."
	@echo "help: Display this help message."

clean:
	rm -f $(TARGET) *.o
