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
    //Finds GCD for numerator and denominator
    int gcd(int, int);
    //Handles if both are negative or if the denom is negative it makes the numerator negative
    void normalize();

public:
    class ZeroDenominator
    {
    private:
        string rational;

    public:
        //Default
        ZeroDenominator();
        //Exception message
        ZeroDenominator(Rational);
        //converts to string
        string toString();
    };
    //Default Constructor
    Rational();
    //converts to string
    string toString();
    // will throw an exception
    Rational(int, int);

    //getter for numerator
    int getNumerator() const;
    //setter for numerator
    void setNumerator(int);
    //getter for denominator
    int getDenominator() const;
    //setter for denominator throws exception if 0
    void setDenominator(int);
    //allows addition between two rational objects
    friend Rational operator +(const Rational&, const Rational&);
    //allows subtraction between two rational objects
    friend Rational operator -(const Rational&, const Rational&);
    //allows multiplication between two rational objects
    friend Rational operator *(const Rational&, const Rational&);
    //allows division between two rational objects
    friend Rational operator /(const Rational&, const Rational&);
    //allows the Rationals to be compared -- see if they are equal
    friend bool operator ==(const Rational&, const Rational&);
    //allows the Rationals to be compared -- if one is less than the other
    friend bool operator <(const Rational&, const Rational&);
    // overloaded  cout << 
    friend ostream& operator <<(ostream&, Rational);
};
