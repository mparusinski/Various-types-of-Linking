clean:
	rm *.o main_*

top.o:
	g++ -c top.cpp -o top.o

left.o:
	g++ -c left.cpp -o left.o

right.o:
	g++ -c right.ccp -o right.o

main_classic:
	g++ main.cpp right.cpp left.cpp top.cpp -o main_classic
