prog4: hw4.o hw4_functions.o
	g++ hw4.o hw4_functions.o -o prog4

hw4.o: hw4.cpp hw4.h
	g++ -c hw4.cpp 
	
hw4_functions.o: hw4_functions.cpp 
	g++ -c hw4_functions.cpp

clean:
	rm *.o prog*
