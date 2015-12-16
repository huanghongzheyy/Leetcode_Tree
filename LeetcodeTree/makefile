tree_main: main.o tree.o
	g++ tree.o main.o -o tree_main


tree.o: tree.cpp tree.h
	g++ -c tree.cpp

main.o: main.cpp tree.h
	g++ -c main.cpp 


clean:
	rm -rf main.o tree.o tree_main