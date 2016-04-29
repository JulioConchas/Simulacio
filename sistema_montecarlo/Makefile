CC = g++
all: sistema_montecarlo

sistema_montecarlo: main.o newton_Raphson.o #queue.o
	$(CC) main.o newton_Raphson.o # queue.o
main.o:main.cpp
	$(CC) -c main.cpp
newton_Raphson.o:newton_Raphson.cpp
	$(CC) -c newton_Raphson.cpp
#queue.o:queue.cpp
#	$(CC) -c queue.cpp
run:
	a.exe
clean:
	rm -Rf *.o
	rm -Rf *.exe
