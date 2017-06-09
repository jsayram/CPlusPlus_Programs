prog5.exe : hw5.o Matrix.o
	g++ hw5.o Matrix.o -o prog5

hw5.o : hw5.cpp hw5.h
	g++ -c hw5.cpp 

Matrix.o : Matrix.cpp hw5.h
	g++ -c Matrix.cpp
	
	
clean :
	rm *.o
	rm *.exe