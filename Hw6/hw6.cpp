//******************************************************************
// Program #: 6
//
// Programmer: Jose Ramirez
//
// Due Date: November 10, 2014
//
// EGRE 246, Fall 2013       Instructor: Robert Klenke
//
// Pledge: I have neither given nor received unauthorized aid on this program.
//
// Description: Main program, testing all method and overloaded operators 
//
// Input: text file with 2x2 matrix
//
// Output: Matrix and its inverse , determinant, and if its singular, 
// 				matrix addition,subtraction, multiplication ,division, output to file of 2x2 matrix
//
//******************************************************************

#include <iostream>
#include <fstream>
#include "hw6.h"

int main(int argc, char *argv[])
{
	ifstream infile;
	ofstream outfile;
	string infilename;

	Matrix w;
	Matrix x;
	Matrix y(1.0, 2.0, 3.0, 4.0);
	Matrix z(x);

if((argc < 3) || (strcmp(argv[1],"/?") == 0)) {
		cerr << "\nReads a list of numbers from a file\n\n";
		cerr << "Usage: Prog6 <input file name> <output file name>\n";
		return(0);
	}

	infile.open(argv[1]);
	if(!infile.is_open()) {
		cerr << "ERROR opening input file " << argv[1] << endl;
		cerr << "Usage: Prog6 <input file name> <output file name>\n";
		return(0);
		}

	outfile.open(argv[2]);
	if(!outfile.is_open()) {
		cerr << "ERROR opening output file " << argv[2] << endl;
		cerr << "Usage: Prog6 <input file name> <output file name>\n";
		return(0);
		}

	cout << "\nx matrix is: \n";
	cout << x;
	cout << "\ny matrix is: \n";
	cout << y;

	x = y;

	cout << "\nx = y\n";
	cout << "x matrix now is: \n";
	cout << x;

	x.assign(1.0, 2.0, 8.0, 7.0);
	y.assign(5.0, 4.0, 4.0, 5.0);

	z = x + y;

	cout << "\nx matrix is: \n";
	cout << x;
	cout << "\ny matrix is: \n";
	cout << y;
	cout << "\nz = x + y matrix is: \n";
	cout << z;

	x = z - y;

	cout << "\nz matrix is: \n";
	cout << z;
	cout << "\ny matrix is: \n";
	cout << y;
	cout << "\nx = z - y matrix is: \n";
	cout << x;

	x.assign(30.0, 50.0, 25.0, 40.0);
	y.assign(2.0, 3.0, 1.0, 1.0);

	z = x * y;

	cout << "\nx matrix is: \n";
	cout << x;
	cout << "\ny matrix is: \n";
	cout << y;
	cout << "\nz = x * y matrix is: \n";
	cout << z;

	x.assign(0.0, 0.0, 0.0, 0.0);
	x = z / y;

	cout << "\nz matrix is: \n";
	cout << z;
	cout << "\ny matrix is: \n";
	cout << y;
	cout << "\nx = z / y matrix is: \n";
	cout << x;

	double r = 2.0;

	x = r * y;

	cout << "\ny matrix is: \n";
	cout << y;
	cout << "\nx = 2.0 * y matrix is: \n";
	cout << x;
	
	infile >> w;
	cout << "\nRead w matrix from << argv[1] " << "\n";
	cout << "w matrix is: \n";
	cout << w;

	w = r * w;
	
	outfile << w;
}		/* end main */