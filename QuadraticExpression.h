//Names: Angie Campos & Vivian Huynh
//Date: 9/6/2023
//Description: //Header File for the class of Quadratic Expressions: The class will get values of the coefficients
//		       	 and it will calculate the discriminant of the equation, as to count the number of roots
//				 and display its root(s) values. 

#include <iostream> //For cout and cin
#include <iomanip>  //For setprecision
#include <string>   //For string
using namespace std;

#pragma once
class QuadraticExpression
{
private:
	double aCoefficient; //For varible a to contain values -100.0 through 100.0
	double bCoefficient; //For varible b to contain values -100.0 through 100.0
	double cCoefficient; //For varible c to contain values -100.0 through 100.0

public:
	//CONSTRUCTOR
	QuadraticExpression(); //Default

	//ACCESSORS
	double getACoefficient() const;
	double getBCoefficient() const;
	double getCCoefficient() const;
	double solveForY(double) const; 
	double calculateDiscriminant() const;
	string countRealRoots() const;

	//MUTATORS
	void setACoefficient(double);
	void setBCoefficient(double);
	void setCCoefficient(double);
	void displayRoots();

	//FRIEND
	friend ostream& operator<<(ostream&, const QuadraticExpression&);
};
