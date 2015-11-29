clean:
	rm -f *.o main_* *.a

top.o:
	g++ -c top.cpp -o top.o

left.o:
	g++ -c left.cpp -o left.o

right.o:
	g++ -c right.cpp -o right.o

main_classic:
	g++ main.cpp right.cpp left.cpp top.cpp -o main_classic

libleft_static.a: left.o
	ar rcs libleft_static.a left.o

libright_static.a: right.o
	ar rcs libright_static.a right.o
