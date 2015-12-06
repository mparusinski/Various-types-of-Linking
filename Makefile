clean:
	rm -f *.o *.so main_* *.a

top.o:
	g++ -c top.cpp -o top.o
	
top_pic.o:
	g++ -Wall -fPIC -c top.cpp -o top_pic.o
	
left_pic.o:
	g++ -Wall -fPIC -c left.cpp -o left_pic.o
	
right_pic.o:
	g++ -Wall -fPIC -c right.cpp -o right_pic.o

left.o:
	g++ -c left.cpp -o left.o

right.o:
	g++ -c right.cpp -o right.o

libleft_static.a: left.o
	ar rcs libleft_static.a left.o

libright_static.a: right.o
	ar rcs libright_static.a right.o

libtop.so: top_pic.o
	g++ -shared -o libtop.so top_pic.o
	
libleft.so: left_pic.o
	g++ -shared -o libleft.so left_pic.o
	
libright.so: right_pic.o
	g++ -shared -o libright.so right_pic.o

main_classic:
	g++ main.cpp right.cpp left.cpp top.cpp -o main_classic

main_static: libleft_static.a libright_static.a
	g++ -o main_static main.cpp libleft_static.a libright_static.a

main_dynamic: libtop.so libleft.so libright.so
	g++ -Wall -L`pwd` main.cpp -lleft -lright -ltop -o main_dynamic
