output: artchess.o
	g++ artchess.o -o output

main.o: artchess.cpp
	g++ -Wall -Werror -c artchess.cpp

clean:
	rm *.o output