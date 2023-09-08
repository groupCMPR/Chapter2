//Name: Vivian Huynh
//Date: 9/6/2023
//Description: Header file for Chapter 2 Assignment Option 1 Quadratic Expression

#include <iostream>
using namespace std;

#pragma once
class QuadraticExpression
{
private:
	int aCoefficient; //-100 through 100
	int bCoefficient;
	int cCoefficient;
	int x;			  

public:
	//CONSTRUCTOR
	QuadraticExpression();

	//ACCESSORS
	int getACoefficient() const; 
	int getBCoefficient() const;
	int getCCoefficient() const;
	int getX() const;
	int getNumberRealNumbers() const;
	int getRealNumbers() const;

	//MUTATORS
	void setACoefficient(int newA);
	void setBCoefficient(int newB);
	void setCCoefficient(int newC);
	void setX(int newX);

	//OVERLOADING OPERATORS
	//QuadraticExpression operator + (const QuadraticExpression& number1, const QuadraticExpression& number2);
	//QuadraticExpression operator * (double r, const QuadraticExpression& number);
	QuadraticExpression operator + (const QuadraticExpression&);
	QuadraticExpression operator * (const QuadraticExpression&);

	//FRIENDS
	friend ostream& operator<<(ostream& out, const QuadraticExpression& obj);
};