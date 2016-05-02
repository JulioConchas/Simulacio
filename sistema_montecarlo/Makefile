CC = g++
all: sistema_montecarlo

sistema_montecarlo: main.o newton_Raphson.o #simpson.o
	$(CC) main.o newton_Raphson.o #simpson.o
main.o:main.cpp
	$(CC) -c main.cpp
newton_Raphson.o:newton_Raphson.cpp
	$(CC) -c newton_Raphson.cpp
#simpson.o:simpson.cpp
#	$(CC) -c simpson.cpp
run:
	a.exe
clean:
	rm -Rf *.o
	rm -Rf *.exe
