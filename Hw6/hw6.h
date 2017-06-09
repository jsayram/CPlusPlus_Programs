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
// Description: Class Header
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
	private:  //variables for different elements in matrix
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
		void print(); // print matrix to cout
		
		Matrix& operator=(const Matrix& m); // overloaded assignment operator 
		Matrix operator+(const Matrix& y); //overloaded addition operator 
		Matrix operator-(const Matrix&y); //overloaded subtraction operator 
		Matrix operator*(const Matrix&y);//overloaded multiplication operator 
		Matrix operator/(const Matrix&y);//overloaded division operator 
		
		friend Matrix operator*(const double r, const Matrix& x); //friend overloaded multiplication, taking in a scalar double.
	   
		
		friend ostream& operator<<(ostream& os, const Matrix& m); //overloaded insertion operator 
		friend  ifstream& operator>>(ifstream& in, Matrix& m); //overloaded extraction operator to print to the screen
		friend ofstream& operator<<(ofstream& os, const Matrix& m); //overloaded insertion operator to output to a file
	
		
};