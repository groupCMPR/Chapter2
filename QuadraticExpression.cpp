//Name: Vivian Huynh
//Date: 9/6/2023
//Description: cpp file for Chapter 2 Assignment Option 1 Quadratic Expression

#include "QuadraticExpression.h"

QuadraticExpression::QuadraticExpression() : aCoefficient(0), bCoefficient(0), cCoefficient(0), x(0)
{};

//==============================================================================
//Accessors Section
//==============================================================================
int QuadraticExpression::getACoefficient() const
{
	return aCoefficient;
}
int QuadraticExpression::getBCoefficient() const
{
	return bCoefficient;
}
int QuadraticExpression::getCCoefficient() const
{
	return cCoefficient;
}
int QuadraticExpression::getX() const
{
	return x;
}
int QuadraticExpression::getNumberRealNumbers() const
{

}
int QuadraticExpression::getRealNumbers() const
{

}

//==============================================================================
//Mutators Section
//==============================================================================
void QuadraticExpression::setACoefficient(int newA)
{
	aCoefficient = newA;
}
void QuadraticExpression::setBCoefficient(int newB)
{
	bCoefficient = newB;
}
void QuadraticExpression::setCCoefficient(int newC)
{
	cCoefficient = newC;
}
void QuadraticExpression::setX(int newX)
{
	newX = (aCoefficient * (pow(newX, 2))) + (bCoefficient * newX) + cCoefficient;
	x = newX;
}

//==============================================================================
//Overloading Operators Section
//==============================================================================
QuadraticExpression QuadraticExpression::operator + (const QuadraticExpression&)
{

}
QuadraticExpression QuadraticExpression::operator * (const QuadraticExpression&)
{

}

//==============================================================================
//Friends Section
//==============================================================================
ostream& operator<<(ostream& out, const QuadraticExpression& obj)
{
	//Quadratic equation format - 0x^2 + 0x + 2
	out << "\n\t" << obj.getACoefficient() << "x^2 + " << obj.getBCoefficient() << "x + " << obj.getCCoefficient();
}