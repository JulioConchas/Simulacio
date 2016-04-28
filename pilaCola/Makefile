CC = g++
all: proces

proces: main.o stack.o queue.o
	$(CC) main.o stack.o queue.o
main.o:main.cpp
	$(CC) -c main.cpp
stack.o:stack.cpp
	$(CC) -c stack.cpp
queue.o:queue.cpp
	$(CC) -c queue.cpp
run:
	a.exe
clean:
	del *.o
