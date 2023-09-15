all:
	g++ -c main.cpp sort.cpp pointer.cpp func.cpp
	g++ main.o sort.o pointer.o func.o
	mv main.o outputfiles/main.o
	mv sort.o outputfiles/sort.o
	mv pointer.o outputfiles/pointer.o
	mv func.o outputfiles/func.o
