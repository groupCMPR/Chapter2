//Names: Angie Campos & Vivian Huynh
//Date: 9/6/2023
//Description: //Header File for the class of Quadratic Expressions: The class will get values of the coefficients
//		       	 and it will calculate the discriminant of the equation, as to count the number of roots
//				 and display its root(s) values. 

#include "QuadraticExpression.h"

//Precondition : Class needs to be called
//Postcondition: Default Constructor; initializes the private members
QuadraticExpression::QuadraticExpression() : aCoefficient(0), bCoefficient(0), cCoefficient(0)
{};

//==============================================================================
//Accessors Section
//==============================================================================
//Precondition : Function needs to be called
//Postcondition: Returns the private member aCoefficient
double QuadraticExpression::getACoefficient() const
{
	return aCoefficient;
}
//Precondition : Function needs to be called
//Postcondition: Returns the private member bCoefficient
double QuadraticExpression::getBCoefficient() const
{
	return bCoefficient;
}
//Precondition : Function needs to be called
//Postcondition: Returns the private member cCoefficient
double QuadraticExpression::getCCoefficient() const
{
	return cCoefficient;
}
//Precondition : Function needs to be called; input is between -100.0 and 100.0
//Postcondition: Returns the y answer after substituting x into the quadratic equation
double QuadraticExpression::solveForY(double x) const
{
	return (aCoefficient * pow(x, 2)) + (bCoefficient * x) + cCoefficient;
}
//Precondition : Private members aCoefficient, bCoefficient, or cCoefficient values are between -100.0 and 100.0
//Postcondition: Returns the discriminant
double QuadraticExpression::calculateDiscriminant() const
{
	return (pow(bCoefficient, 2)) - (4 * aCoefficient * cCoefficient);
}
//Precondition : Private members aCoefficient, bCoefficient, or cCoefficient values are between -100.0 and 100.0
//Postcondition: Returns the number of roots (num. possible are 0,1,2, & infinity)
string QuadraticExpression::countRealRoots() const
{
	double discriminant = calculateDiscriminant();

	if (aCoefficient == 0 && bCoefficient == 0 && cCoefficient == 0)
	{
		return "infinity";
	}
	else if (aCoefficient == 0 && (bCoefficient != 0 || cCoefficient != 0))
	{
		cout << "\n\tThis is not a Quadratic Equation, but a Linear Equation.\n";
		return to_string(1);
	}
	else 
	{
		if (discriminant > 0)
		{
			return to_string(2);
		}
		else if (discriminant == 0)
		{
			return to_string(1);
		}
		else if (discriminant < 0)
		{
			//cout << "\n\tRoot(s) are complex and imaginary (There are 0 real roots).";
			return to_string(0);
		}
	}
	return 0;
}

//==============================================================================
//Mutators Section
//==============================================================================
//Precondition : Function needs to be called; private member aCoefficient values are between -100.0 and 100.0
//Postcondition: Set the private member aCoefficient
void QuadraticExpression::setACoefficient(double newA)
{
	aCoefficient = newA;
}
//Precondition : Function needs to be called; private member bCoefficient values are between -100.0 and 100.0
//Postcondition: Set the private member bCoefficient
void QuadraticExpression::setBCoefficient(double newB)
{
	bCoefficient = newB;
}
//Precondition : Function needs to be called; private member bCoefficient values are between -100.0 and 100.0
//Postcondition: Set the private member cCoefficient
void QuadraticExpression::setCCoefficient(double newC)
{
	cCoefficient = newC;
}
//Precondition : Private members aCoefficient, bCoefficient, or cCoefficient values are between -100.0 and 100.0
//Postcondition: Display the value of the real roots and imaginary roots
void QuadraticExpression::displayRoots()
{
	double root1 = 0;							   //To contain the first or only root number
	double root2 = 0;							   //To contain the second root number
	double real = 0;							   //The real number in the complex number
	double imaginary = 0;                          //The imaginary number in the complex number
	double discriminant = calculateDiscriminant(); //To contain the discriminant (b^2 - 4ac)

	if (aCoefficient == 0 && bCoefficient == 0 && cCoefficient == 0)
	{
		cout << "\n\tEvery value of x is a real root.\n";
	}
	else if (aCoefficient == 0 && (bCoefficient != 0 || cCoefficient != 0))
	{
		cout << "\n\tThis is a Linear Equation.";
		cout << "\n\t" << bCoefficient << "x + " << cCoefficient << '\n';
	}
	else if (discriminant > 0)
	{
		root1 = (-bCoefficient + sqrt(discriminant)) / (2 * aCoefficient);
		root2 = (-bCoefficient - sqrt(discriminant)) / (2 * aCoefficient);

		//Outputting the largest number first
		if (root1 > root2)
		{
			cout << fixed << setprecision(4) << "\n\tThe two real roots are: " << root1 << " , " << root2 << '\n';
		}
		else
		{
			cout << fixed << setprecision(4) << "\n\tThe two real roots are: " << root2 << " , " << root1 << '\n';
		}
	}
	else if (discriminant == 0)
	{
		root1 = -bCoefficient / (2 * aCoefficient);

		cout << "\n\tThe one real root is : " << root1 << '\n';
	}
	else if (discriminant < 0)
	{
		cout << "\n\tRoot(s) are complex and imaginary (There are 0 real roots)";

		imaginary = sqrt(-discriminant) / (2 * aCoefficient);
		real = -bCoefficient / (2 * aCoefficient);

		cout << fixed << setprecision(4) << "\n\tThe 1st complex root is: " << real << " + " << imaginary << "i";
		cout << fixed << setprecision(4) << "\n\tThe 2nd complex root is: " << real << " - " << imaginary << "i\n";
	}
}

//==============================================================================
//Friend Section
//==============================================================================
//Precondition : Function needs to be called
//Postcondition: Display the quadratic equation
ostream& operator<<(ostream& out, const QuadraticExpression& obj)
{
	//Quadratic equation format - 0x^2 + 0x + 2
	out << "\n\t" << obj.getACoefficient() << "x^2 + " << obj.getBCoefficient() << "x + " << obj.getCCoefficient() << '\n';
	return out;
}
