#include "Rational.h"
//PreConditon: Needs two integer values
//PostCondition: Finds the greatest commmon denominator
int Rational::gcd(int a, int b)
{
    if (a == 0 || b == 0)
        return 0;
    else if (a == b)
        return a;
    else if (a > b)
        return gcd(a - b, b);
    else
        return gcd(a, b - a);
}
//PreConditon: None
//PostCondition: Handles if both are negative or if the denom is negative it makes the numerator negative
void Rational::normalize()
{
    if (denominator < 0)
    {
        denominator *= -1;
        numerator *= -1;
    }

    if (numerator != 0)
    {
        int temp = gcd(abs(numerator), abs(denominator));
        numerator /= temp;
        denominator /= temp;
    }
}
//PreConditon: None
//PostCondition: Default constructor 
Rational::ZeroDenominator::ZeroDenominator()
{
}
//PreConditon:Rational Object
//PostCondition: Exception message
Rational::ZeroDenominator::ZeroDenominator(Rational r)
{
    rational = r.toString();
}
//PreConditon: None 
//PostCondition: converts to string
string Rational::ZeroDenominator::toString()
{
    return rational;
}
//PreConditon: None
//PostCondition: Default Constructor
Rational::Rational()
{
    numerator = 0;
    denominator = 1;
}
//PreConditon: None 
//PostCondition: converts to string
string Rational::toString()
{
    return to_string(numerator) + "/" + to_string(denominator);
}
//PreConditon: Accepts two integer values 
//PostCondition: will throw an exception if denominator is 0
Rational::Rational(int newN, int newD)
{
    numerator = newN;
    denominator = newD;
    if (denominator == 0)
        throw ZeroDenominator(*this);

    normalize();
}
//PreConditon: None
//PostCondition: returns numerator value
int Rational::getNumerator() const
{
    return numerator;
}
//PreConditon: An integer value is needed
//PostCondition: sets the value of numerator to the given integer value
void Rational::setNumerator(int newN)
{
    numerator = newN;
    normalize();
}
//PreConditon: None
//PostCondition: Returns the denominator 
int Rational::getDenominator() const
{
    return denominator;
}
//PreConditon: An integer value is needed
//PostCondition: Sets the value of the denominator to the given integer value
void Rational::setDenominator(int newD)
{
    denominator = newD;
    if (denominator == 0)
        throw ZeroDenominator(*this);

    normalize();
}
//PreConditon:Two rational objects are needed
//PostCondition: allows addition between two rational objects
Rational operator +(const Rational& obj1, const Rational& obj2)
{
    int newNumerator = (obj1.numerator * obj2.denominator) + (obj2.numerator * obj1.denominator);
    int newDenominator = obj1.denominator * obj2.denominator;
    return Rational(newNumerator, newDenominator);
}
//PreConditon:Two rational objects are needed
//PostCondition: allows subtraction between two rational objects
Rational operator -(const Rational& obj1, const Rational& obj2)
{
    int newNumerator = (obj1.numerator * obj2.denominator) - (obj2.numerator * obj1.denominator);
    int newDenominator = obj1.denominator * obj2.denominator;
    return Rational(newNumerator, newDenominator);
}
//PreConditon:Two rational objects are needed
//PostCondition: allows multiplication between two rational objects
Rational operator *(const Rational& obj1, const Rational& obj2)
{
    int newNumerator = obj1.numerator * obj2.numerator;
    int newDenominator = obj1.denominator * obj2.denominator;
    return Rational(newNumerator, newDenominator);
}
//PreConditon:Two rational objects are needed
//PostCondition: allows division between two rational objects
Rational operator /(const Rational& obj1, const Rational& obj2)
{
    int newNumerator = obj1.numerator * obj2.denominator;
    int newDenominator = obj1.denominator * obj2.numerator;
    return Rational(newNumerator, newDenominator);
}
//PreConditon:Two rational objects are needed
//PostCondition: allows the Rationals to be compared -- see if they are equal
bool operator ==(const Rational& obj1, const Rational& obj2)
{
    return (obj1.numerator * obj2.denominator) == (obj2.numerator * obj1.denominator);
}
//PreConditon:Two rational objects are needed
//PostCondition: allows the Rationals to be compared -- if one is less than the other
bool operator <(const Rational& obj1, const Rational& obj2)
{
    return (obj1.numerator * obj2.denominator) < (obj2.numerator * obj1.denominator);
}

// overloaded  cout << 
ostream& operator <<(ostream& out, Rational obj)
{
    out << obj.toString();
    return out;
}
