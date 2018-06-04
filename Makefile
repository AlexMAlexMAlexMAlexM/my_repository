# finished result(binary file)
all: executive
# goal <- source
executive: main.o
	g++ main.o -o executive
# goal <- source	
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
clean:
	rm *.o executive
