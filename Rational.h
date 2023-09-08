#pragma once
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Rational
{
private:
    int numerator;
    int denominator;

    int gcd(int, int);
    void normalize();

public:
    class ZeroDenominator
    {
    private:
        string rational;

    public:
        ZeroDenominator();
        ZeroDenominator(Rational);
        string toString();
    };

    Rational();
    string toString();
    Rational(int, int);

    int getNumerator() const;
    void setNumerator(int);

    int getDenominator() const;
    void setDenominator(int);

    friend Rational operator +(const Rational&, const Rational&);
    friend Rational operator -(const Rational&, const Rational&);
    friend Rational operator *(const Rational&, const Rational&);
    friend Rational operator /(const Rational&, const Rational&);

    friend bool operator ==(const Rational&, const Rational&);
    friend bool operator <(const Rational&, const Rational&);

    friend ostream& operator <<(ostream&, Rational);
};
