main: Tree.o Node.o
	g++ -o main Tree.o Node.o

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

Tree.o: Tree.cpp Tree.h
	g++ -c Tree.cpp

clean:
	rm -r *.o main*