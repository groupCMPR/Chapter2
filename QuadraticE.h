#include <iostream>
#include "input.h"

//Header File for the class of Quadratic Expressions : The class will get values of the Coeficients
//			and it will calculate the discriminant of the equation, as to count the number of roots
//			and display its root(s) values. 

class Quadratic
{
private:
	double aCoefficient, bCoefficient, cCoefficient; 

public:

	//Constructor 
	Quadratic();
	
	//The accessor and mutator of Coefficient of A
	double getA() const;
	void setA();
	
	//The accessor and mutator of Coefficient of A
	double getB() const;
	void setB();
	
	//The accessor and mutator of Coefficient of A
	double getC() const;
	void setC();

	//Accessors and mutators
	double calculateDiscriminant();
	void displayFormula();
	int countRealRoots();
	void displayRoots();
	double solveForY(double x);
	
};
