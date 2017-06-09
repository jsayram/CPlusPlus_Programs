prog7.exe : hw7.o parser.o
	g++ hw7.o parser.o -o prog7

hw7.o : hw7.cpp parser.h
	g++ -c hw7.cpp

parser.o : parser.cpp parser.h
	g++ -c parser.cpp
	
clean :
	rm *.o
	rm *.exe