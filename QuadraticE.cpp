#include "QuadraticE.h"
#include "input.h"


// Precondition  : Class needs to be called
// Postcondition : Default Constructor
Quadratic::Quadratic() : aCoefficient(0.0),bCoefficient(0.0),cCoefficient(0.0) {}

//Coefficient for A get and set functions

// Precondition  : Function needs to be called
// Postcondition : Get the A coefficient
double Quadratic::getA() const
{
	return aCoefficient;
}
// Precondition  : Function needs to be called
// Postcondition : Set the A coefficient
void Quadratic::setA()
{
	aCoefficient = inputDouble("\n\t\tEnter a value and set coefficient (a): ");
}

//Coefficient for B get and set functions

// Precondition  : Function needs to be called
// Postcondition : Get the B coefficient
double Quadratic::getB() const
{
	return bCoefficient;
}
// Precondition  : Function needs to be called
// Postcondition : Set the B coefficient
void Quadratic::setB()
{
	bCoefficient = inputDouble("\n\t\tEnter a value and set coefficient (b): ");
}

//Coefficient for C get and set functions

// Precondition  : Function needs to be called
// Postcondition : Get the C coefficient
double Quadratic::getC() const
{
	return cCoefficient;
}
// Precondition  : Function needs to be called
// Postcondition : Set the C coefficient
void Quadratic::setC()
{
	cCoefficient = inputDouble("\n\t\tEnter a value and set coefficient (c): ");
}


//Calculates the Discriminant : b^2 - 4ac 
double Quadratic::calculateDiscriminant()
{
	return (bCoefficient * bCoefficient) - (4 * aCoefficient * cCoefficient);
}

//Displays the Formula of the Function with the coefficients 
void Quadratic::displayFormula()
{
	cout << aCoefficient << "x^2 + " << bCoefficient << "x + " << cCoefficient;
}

// This function displays the number of roots there is in the Quadratic Equation (num. possible are 0,1,2, where is imaginary)
int Quadratic::countRealRoots()
{
	double discriminant = calculateDiscriminant();

	if (aCoefficient == 0)
	{
		cout << "\nThis is not a Quadratic Equation, but a Linear Equation.\n";
	}
	else {
		if (discriminant > 0)
		{
			return 2;
		}
		else if (discriminant == 0)
		{
			return 1;
		}
		else {
			return 0;
			cout << "\nRoot(s) are complex and imaginary (There are 0 real roots)";
		}
	}
}

//This function will display the value of the real roots and imaginary roots
void Quadratic::displayRoots()
{
	double discriminat = calculateDiscriminant();

	if (discriminat > 0)
	{
		double root1 = (-bCoefficient + sqrt(discriminat)) / (2 * aCoefficient);
		double root2 = (-bCoefficient - sqrt(discriminat)) / (2 * aCoefficient);
		//outputing the largest number 1st
		if (root1 > root2)
		{
			cout << "\n\tThe two real roots are : " << root1 << " , " << root2;
		}
		else
			cout << "\n\tThe two real roots are : " << root2 << " , " << root1;
	}
	else if (discriminat == 0)
	{
		double root1 = -bCoefficient / (2 * aCoefficient);
		cout << "\n\tThe one real root is : " << root1;
	}
	else{
		cout << "\n\tRoot(s) are complex and imaginary (There are 0 real roots)";
		
		double imaginary = sqrt(discriminat) / (2 * aCoefficient);
		double real = -bCoefficient / (2 * aCoefficient);

		cout << "\n\tThe 1st complex root is : "
			<< real << " + " << imaginary << " i\n";
		cout << "\n\tThe 2nd complex root is : "
			<< real << " - " << imaginary << " i\n";
	}
}

//This Function will evaluate the user input of x (so, solving for y)
double Quadratic::solveForY(double x)
{
	return (aCoefficient * pow(x, 2)) + (bCoefficient * x) + cCoefficient;
}
