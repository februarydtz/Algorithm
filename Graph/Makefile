main: Vertice.o Graph.o
	g++ -o main Vertice.o Graph.o

Vertice.o: Vertice.cpp Vertice.h
	g++ -c Vertice.cpp

Graph.o: Graph.cpp Graph.h
	g++ -c Graph.cpp

clear:
	rm *.o main