# Compiler used. 
CC = gcc 

# Directory containing header files. 
INCLUDE = './include'

# Object complation flags.
CFLAGS = -c -iquote './include'

# Object files compiled from source.
Objects = main.o InEnd.o 

# Main Headers. 
Mainh = include/InEnd.h


all: hello

 
hello:  $(Objects)
	$(CC) $(Objects) -lSDL2 -o hello 

main.o: main.cpp $(Mainh) 
	$(CC) $(CFLAGS) main.cpp 

InEnd.o: InEnd.cpp $(Mainh)
	$(CC) $(CFLAGS) InEnd.cpp 

.PHONY: clean
clean: 
	rm *.o hello
	


