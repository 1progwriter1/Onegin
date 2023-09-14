all:
	g++ -c main.cpp sort.cpp pointer.cpp func.cpp
	g++ main.o sort.o pointer.o func.o
