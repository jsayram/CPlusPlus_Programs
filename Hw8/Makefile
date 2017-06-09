prog8.exe : hw8.o parser.o
	g++ hw8.o parser.o -o prog8

hw8.o : hw8.cpp parser.h
	g++ -c hw8.cpp

parser.o : parser.cpp parser.h
	g++ -c parser.cpp
	
clean :
	rm *.o
	rm *.exe