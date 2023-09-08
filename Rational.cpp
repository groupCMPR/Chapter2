#include "Rational.h"

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

Rational::ZeroDenominator::ZeroDenominator()
{
}

Rational::ZeroDenominator::ZeroDenominator(Rational r)
{
    rational = r.toString();
}

string Rational::ZeroDenominator::toString()
{
    return rational;
}

Rational::Rational()
{
    numerator = 0;
    denominator = 1;
}

string Rational::toString()
{
    return to_string(numerator) + "/" + to_string(denominator);
}

Rational::Rational(int newN, int newD)
{
    numerator = newN;
    denominator = newD;
    if (denominator == 0)
        throw ZeroDenominator(*this);

    normalize();
}

int Rational::getNumerator() const
{
    return numerator;
}

void Rational::setNumerator(int newN)
{
    numerator = newN;
    normalize();
}

int Rational::getDenominator() const
{
    return denominator;
}

void Rational::setDenominator(int newD)
{
    denominator = newD;
    if (denominator == 0)
        throw ZeroDenominator(*this);

    normalize();
}

Rational operator +(const Rational& obj1, const Rational& obj2)
{
    int newNumerator = (obj1.numerator * obj2.denominator) + (obj2.numerator * obj1.denominator);
    int newDenominator = obj1.denominator * obj2.denominator;
    return Rational(newNumerator, newDenominator);
}

Rational operator -(const Rational& obj1, const Rational& obj2)
{
    int newNumerator = (obj1.numerator * obj2.denominator) - (obj2.numerator * obj1.denominator);
    int newDenominator = obj1.denominator * obj2.denominator;
    return Rational(newNumerator, newDenominator);
}

Rational operator *(const Rational& obj1, const Rational& obj2)
{
    int newNumerator = obj1.numerator * obj2.numerator;
    int newDenominator = obj1.denominator * obj2.denominator;
    return Rational(newNumerator, newDenominator);
}

Rational operator /(const Rational& obj1, const Rational& obj2)
{
    int newNumerator = obj1.numerator * obj2.denominator;
    int newDenominator = obj1.denominator * obj2.numerator;
    return Rational(newNumerator, newDenominator);
}

bool operator ==(const Rational& obj1, const Rational& obj2)
{
    return (obj1.numerator * obj2.denominator) == (obj2.numerator * obj1.denominator);
}

bool operator <(const Rational& obj1, const Rational& obj2)
{
    return (obj1.numerator * obj2.denominator) < (obj2.numerator * obj1.denominator);
}

ostream& operator <<(ostream& out, Rational obj)
{
    out << obj.toString();
    return out;
}
