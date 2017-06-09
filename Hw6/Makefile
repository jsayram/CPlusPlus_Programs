prog6.exe : hw6.o Matrix_op.o
	g++ hw6.o Matrix_op.o -o prog6

hw6.o : hw6.cpp hw6.h
	g++ -c hw6.cpp 

Matrix_op.o : Matrix_op.cpp hw6.h
	g++ -c Matrix_op.cpp
	
clean :
	rm *.o
	rm *.exe