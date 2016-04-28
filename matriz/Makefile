CC = g++
all: matriz

matriz: main.o matriz.o 
	$(CC) main.o matriz.o
main.o:main.cpp
	$(CC) -c main.cpp
matriz.o:matriz.cpp
	$(CC) -c matriz.cpp
run:
	a.exe
clean:
	del *.o
