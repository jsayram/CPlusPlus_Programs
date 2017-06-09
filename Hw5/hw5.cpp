//******************************************************************
// Program #: 5
//
// Programmer: Jose Ramirez
//
// Due Date: October 31,2014
//
// EGRE 246, Fall 2013       Instructor: Robert Klenke
//
// Pledge: I have neither given nor received unauthorized aid on this program.
//
// Description: Main program, implementation of Matrix  methods
//
// Input: none
//
// Output: Matrix and its inverse , determinant, and if its singular
//
//******************************************************************
#include <fstream>
#include <iostream>
#include "hw5.h"

using namespace std;

int main(int argc, char *argv[])
{
	Matrix x;
	Matrix y(1.0, 2.0, 3.0, 4.0);
	Matrix z(y);

	cout << "\nx matrix is: \n";
	x.print();
	cout << "|x| = " << x.det() << "\n";
	if(x.isSingular())
		cout << "x is a singluar matrix\n";
	else
		cout << "x is not a singluar matrix\n";

	cout << "\ny matrix is: \n";
	y.print();
	cout << "|y| = " << y.det() << "\n";
	if(y.isSingular())
		cout << "y is a singluar matrix\n";
	else
		cout << "y is not a singluar matrix\n";

	cout << "\nz matrix is: \n";
	z.print();
	cout << "|z| = " << z.det() << "\n";
	if(z.isSingular())
		cout << "z is a singluar matrix\n";
	else
		cout << "z is not a singluar matrix\n";

	cout << "\nz matrix inverse is: \n";
	z.inverse();
	z.print();

	x.assign(0.0, 1.0, 0.0, 1.0);
	cout << "\nx matrix is: \n";
	x.print();
	cout << "\nx matrix inverse is: \n";
	x.inverse();
	x.print();

	y.assign(4.0, 3.0, 3.0, 2.0);
	cout << "\ny matrix is: \n";
	y.print();
	cout << "y matrix inverse is: \n";
	y.inverse();
	y.print();


}		/* end main */