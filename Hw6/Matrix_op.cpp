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
// Description: Calls to matrix methods implementations , and overloaded operators 
//
// Input: none
//
// Output: none
//
//******************************************************************

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip> 

#include "hw6.h"

using namespace std;
// Implementations for the Matrix class
// Default constructor
Matrix::Matrix()
{
	this->a=0.0;	
	this->b=0.0;	
	this->c=0.0;	
	this->d=0.0;	

}
// Constructor function
Matrix::Matrix(double a, double b, double c, double d)
{
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
}
// Copy constructor function
Matrix::Matrix(const Matrix& m)
{
	this->a = m.a;
	this->b = m.b;
	this->c = m.c;
	this->d=m.d;
}


// Method for assigning values to an already existing Matrix object
void Matrix::assign(double a, double b, double c, double d)
{
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
}


// Singular the Matrix numbers 
bool Matrix::isSingular()
{
	bool singular;

	if(det()== true) 
	{								// Singular 
		return singular =true;
	}
	else
	{								// Non Singular 
	    return singular=false;
	}
}

//finds determinant of the matrix
double Matrix::det()
{
	double det=0.0;
    det=((a*d)-(b*c));
	return det; 
}

//finds inverse of the matrix
void Matrix::inverse()
{
     double deter=0.0;
	 double a1,b1,c1,d1;
	 deter=det();
	
    //temporary variables assigned values from elements in the matrix	
	a1=a;
	b1=b;
	c1=c;
	d1=d;
	
	this->a = d1/deter;
	this->b =-b1/deter;
	this->c = -c1/deter;
	this->d =a1/deter;
	//returns the original matrix if the determinant found is zero. 
	if(deter==0)
	 {
		cout<<"Error: matrix is singular - it does not have an inverse"<<endl;
		this->a = a1;
		this->b = b1;
		this->c =c1;
		this->d =d1;
	}
}
//assignment operator  assigns the value for the matrix passes to each element in the matrix 
Matrix& Matrix::operator=(const Matrix& m)
{
	this->a=m.a;
	this->b=m.b;
	this->c=m.c;
	this->d=m.d;
	return *this;
}
//addition operator adds two matrices  
Matrix Matrix::operator+(const Matrix& y)
{
	Matrix  answer,number;
	answer= *this;
	number=y;
	answer.a+=number.a;
	answer.b+=number.b;
	answer.c+=number.c;
	answer.d+=number.d;
	
	return answer;
}
//subtraction operator finds the difference of two matrices  
Matrix Matrix::operator-(const Matrix& y)
{
	Matrix  answer,number;
	answer= *this;
	number=y;
	answer.a-=number.a;
	answer.b-=number.b;
	answer.c-=number.c;
	answer.d-=number.d;
	
	return answer;
}
//multiplication operator finds the product of two matrices of same size 
Matrix Matrix::operator*(const Matrix& y)
{     
    double a1,a2,b1,b2,c1,c2,d1,d2;
    Matrix answer;
	answer =*this;
	
	//temporary variables to make the multiplication 
	//easier to handle 
	a1=(a*y.a);
	a2=(b*y.c);
	
	b1=(a*y.b);
	b2=(b*y.d);
	
	c1=(c*y.a);
	c2=(d*y.c);
	
	d1=(c*y.b);
	d2=(d*y.d);
	
	//final answer for the added multiplied variables
	answer.a=a1+a2;
	answer.b=b1+b2;
	answer.c=c1+c2;
	answer.d=d1+d2;
	
	return answer;
}
// division operator divides two matrices to together  
Matrix Matrix::operator/(const Matrix& y)
{
	double a1,a2,b1,b2,c1,c2,d1,d2;
	double ia1,ib1,ic1,id1;
	double ma,mb,mc,md;
	double deter=0.0;
	
    deter=((y.a*y.d)-(y.b*y.c)); //finds determinant 
	
    Matrix answer;
	answer =*this;
	
	//temporary variables assigned values from elements in the matrix	
	ia1=y.a;
	ib1=y.b;
	ic1=y.c;
	id1=y.d;
	
	//divide inverse matrix by determinant 
	ma = id1/deter;
	mb =-ib1/deter;
	mc = -ic1/deter;
	md =ia1/deter;
	
	//temporary variables to make the multiplication 
	//easier to handle 
	a1=(a*ma);
	a2=(b*mc);
	
	b1=(a*mb);
	b2=(b*md);
	
	c1=(c*ma);
	c2=(d*mc);
	
	d1=(c*mb);
	d2=(d*md);
	
	//adding the two multiplied variables.
	answer.a=a1+a2;
	answer.b=b1+b2;
	answer.c=c1+c2;
	answer.d=d1+d2;
	
	return answer;
}
//scalar multiplication operator takes in a scalar quantity and matrix and find the product
Matrix operator*(const double r, const Matrix& y)
{
    Matrix answer;
	
	answer.a=r*y.a;
	answer.b=r*y.b;
	answer.c=r*y.c;
	answer.d=r*y.d;
	
	return answer;
}
//insertion operator to output the screen 
ostream& operator<<(ostream& os, const Matrix& m)
{
 //picks the right amount of precision based on the values of each matrix , this is just for format purpose 
	if(m.a!=0 && m.b!=0 && m.c!=0 && m.d!=0)
	{
		os<<fixed;
		os<<setprecision(3);
		os<<"        ---                     ---"<<endl;
		os<<"\t|"<<right<<setw(13) <<m.a <<"  "<<left<<setw(10)<<m.b <<"|\n";
		os<<"\t|"<<"                        "<<" |"<<endl;
		os<<"\t|"<<right<<setw(13) <<m.c <<"  "<<left<<setw(10)<<m.d <<"|\n";
		os<<"        ---                     ---"<<endl;
	}
	else if (m.b!=0 || m.d!=0)
	{
		os<<fixed;
		os<<"        ---                     ---"<<endl;
		os<<"\t|"<<right<<setw(13) <<setprecision(4)<<m.a <<"  "<<left<<setw(10)<<setprecision(3)<<m.b <<"|\n";
		os<<"\t|"<<"                        "<<" |"<<endl;
		os<<"\t|"<<right<<setw(13) <<setprecision(4)<<m.c <<"  "<<left<<setw(10)<<setprecision(3)<<m.d <<"|\n";
		os<<"        ---                     ---"<<endl;
	}
	else 
	{
	    os<<fixed;
		os<<setprecision(4);
		os<<"        ---                     ---"<<endl;
		os<<"\t|"<<right<<setw(13) << m.a <<"  "<<left<<setw(10)<<m.b <<"|\n";
		os<<"\t|"<<"                        "<<" |"<<endl;
		os<<"\t|"<<right<<setw(13) <<m.c <<"  "<<left<<setw(10)<<m.d <<"|\n";
		os<<"        ---                     ---"<<endl;
    }
	
	return os;
}
//insertion operator to output to a FILE 
ofstream& operator<<(ofstream& os, const Matrix& m)
{       //outputs with a precision of one decimal space
		os<<fixed;
		os<<setprecision(1);
		os<<m.a <<"  "<<m.b <<endl;
		os<<m.c <<"  "<<m.d<<endl ;

		return os;
}
//extraction operator takes in four values from a file, and assigns to each 
//element of a 2x2 matrix 
 ifstream& operator>>(ifstream& in,  Matrix& m)
{  
  //assigns to each element of the 2x2 matrix 
	in >> m.a ;
	in >> m.b ;
	in >> m.c ;
	in >> m.d ;

	return in;
}