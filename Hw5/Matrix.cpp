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
// Description: Call matrix methods implementations 
//
// Input: none
//
// Output: none
//
//******************************************************************

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip> 



#include "hw5.h"

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

// Printing Matrix object
void Matrix::print()
{  
	if(a!=0 && b!=0 && c!=0 && d!=0)
	{
		cout<<fixed;
		cout<<setprecision(3);
		cout<<"        ---                     ---"<<endl;
		cout<<"\t|"<<right<<setw(13) <<a <<"  "<<left<<setw(10)<<b <<"|\n";
		cout<<"\t|"<<"                        "<<" |"<<endl;
		cout<<"\t|"<<right<<setw(13) <<c <<"  "<<left<<setw(10)<<d <<"|\n";
		cout<<"        ---                     ---"<<endl;
	}
	else if (b!=0 || d!=0)
	{
    cout<<fixed;
	cout<<"        ---                     ---"<<endl;
	cout<<"\t|"<<right<<setw(13) <<setprecision(4)<<a <<"  "<<left<<setw(10)<<setprecision(3)<<b <<"|\n";
	cout<<"\t|"<<"                        "<<" |"<<endl;
	cout<<"\t|"<<right<<setw(13) <<setprecision(4)<<c <<"  "<<left<<setw(10)<<setprecision(3)<<d <<"|\n";
	cout<<"        ---                     ---"<<endl;
	}
	else
	{
	    cout<<fixed;
		cout<<setprecision(4);
		cout<<"        ---                     ---"<<endl;
		cout<<"\t|"<<right<<setw(13) << a <<"  "<<left<<setw(10)<<b <<"|\n";
		cout<<"\t|"<<"                        "<<" |"<<endl;
		cout<<"\t|"<<right<<setw(13) <<c <<"  "<<left<<setw(10)<<d <<"|\n";
		cout<<"        ---                     ---"<<endl;
    }
	
}