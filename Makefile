
CC=gcc 
CFLAGS=-c 

all: hello

hello: hello.o InEnd.o  
	$(CC) hello.o InEnd.o -lSDL2 -o hello 

hello.o: hello.cpp 
	$(CC) $(CFLAGS) hello.cpp

InEnd.o: InEnd.cpp 
	$(CC) $(CFLAGS) InEnd.cpp 


rm: 
	rm *.o hello
	


