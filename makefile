all: onegin

main.o: main.cpp
	g++ -c -o main.o main.cpp

core.o: core.cpp
	g++ -c -o core.o core.cpp

onegin: main.o core.o
	g++ main.o core.o -o Onegin.exe

