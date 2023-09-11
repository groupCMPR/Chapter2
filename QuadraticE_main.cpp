#include <iostream>
#include <math.h>
#include "input.h"
#include "QuadraticE.h"

using namespace std;

char caseOneMenu();		// Quadratic Expressions Menu
void caseOne();
//----------------------------------------------------
//Functions for menu 1 : (Only for the last 3 parts)
void rootCount(Quadratic& equation);
void ValueofRoots(Quadratic& equation);
void evaluationOfx(Quadratic& equation);

char caseOneMenu()
{
	cout << "\n\t1: Quadratic Expression";
	cout << "\n\t" << string(100, char(205));
	cout << "\n\t\t A: set coefficient (a)";
	cout << "\n\t\t B: set coefficient (b)";
	cout << "\n\t\t C: set coefficient (c)";
	cout << "\n\t\t D: display the expression";
	cout << "\n\t\t E: get evaluation (x)";
	cout << "\n\t\t F: get the number of real roots";
	cout << "\n\t\t G: get real root(s)";
	cout << "\n\t" << string(100, char(196));
	cout << "\n\t\t 0: Return";
	cout << "\n\t" << string(100, char(205));
	return inputChar("\n\t\tOption: ", static_cast<string>("ABCDEFG0"));
}
void caseOne()
{
	Quadratic equation; //calls all the functions

	do
	{
		system("cls");
		switch (caseOneMenu()) {
		case '0': return; break;
		case 'A':
			equation.setA();
			break;
		case 'B':
			equation.setB();
			break;
		case 'C':
			equation.setC();
			break;
		case 'D':
			
			cout << "Quadratic Equation:\t";
			equation.displayFormula();

			break;
		case 'E':
			evaluationOfx(equation);
			break;
		case 'F':
			rootCount(equation);
			break;
		case 'G':
			ValueofRoots(equation);
			break;

		default: cout << "\t\tERROR: - Invalid option. Please re-enter"; break;
		}
		cout << "\n\n";
		system("pause");

	} while (true);
}

//Functions for case One - Quadratic Equations
void rootCount(Quadratic & equation)
{
	int rootCount = equation.countRealRoots();
	cout << "Number of real roots:\t" << rootCount;
}
void ValueofRoots(Quadratic & equation)
{
	int rootCount = equation.countRealRoots();

	if (rootCount >= 0 && rootCount <= 2)
	{
		cout << "Root(s):\n";
		equation.displayRoots();
	}
	else {
		cout << "Invalid Number of Roots.";
	}
}
void evaluationOfx(Quadratic & equation)
{
	double x = inputDouble("Enter the value of x = ");
	double result = equation.solveForY(x);
	cout << "Evaluation Result = " << result;
}
