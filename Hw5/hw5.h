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
// Description: Class file 
//
// Input: none
//
// Output: none
//
//******************************************************************


using namespace std;

// Class matrix  method prototypes
class Matrix 
{ 
	private:  //variables for different elements in the list
		double a;		
		double b;		
		double c;
		double d;    

	public:
		Matrix ();   // Default constructor function
		Matrix (double, double, double, double); // Constructor function
		Matrix (const Matrix&); // Copy constructor
		void assign(double,double,double, double); // assign values to the matrix variables
		bool isSingular(); //return if the matrix is singular or non singular
		double det(); 	// find determinant
		void inverse(); //calculates its inverse			
		void print(); // print matrix 
};