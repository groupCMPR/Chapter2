//Names: Alexis Martinez, Angie Campos, Neidy Malaga, & Vivian Huynh
//Date: 9/5/2023
//Description: Chapter 2 Assignment: Abstract Data Types and C++ Classes

#include <iostream>
#include <iomanip>
#include <algorithm>
#include "input.h"
#include "QuadraticExpression.h"
using namespace std;

//PROTOTYPES
int menuOption();

//Option 1 - Quadratic Expression
char quadraticMenuOption();
//Option 2 - Pseudorandom
//char pseudorandomMenuOption();
//Option 3 - Rational Number
//char rationalNumberMenuOption();

int main()
{
	do
	{
		system("cls");
		switch (menuOption())
		{
		case 'X': exit(1); break;
		case '1': system("cls"); quadraticMenuOption(); break;
		//case '2': system("cls"); pseudorandomMenuOption(); break;
		//case '3': system("cls"); rationalNumberMenuOption(); break;
		default: cout << "\n\tERROR: Invalid input.\n"; break;
		}
		cout << "\n";
		system("pause");
	} while (true);

	return 0;
}

//Precondition: N/A
//Postcondition: Output the main menu
int menuOption()
{
	cout << "\n\tCMPR131 Chapter2 - ADT Assignments by Alexis Martinez, Angie Campos, Neidy Malaga, & Vivian Huynh (9/5/23)";
	cout << "\n\t" << string(100, char(205));
	cout << "\n\t\t1> Quadratic Expression"; //TODO
	cout << "\n\t\t2> Pseudorandom";         //TODO
	cout << "\n\t\t3> Rational number";      //TODO
	cout << "\n\t" << string(100, char(196));
	cout << "\n\t\tX> Exit";
	cout << "\n\t" << string(100, char(205));

	return toupper(inputChar("\n\t\tOption: ", static_cast<string>("123X")));
}

//Precondition: N/A
//Postcondition: Output option 1 quadratic expression menu
char quadraticMenuOption()
{
	QuadraticExpression equation; //QuadraticExpression object to call the member functions
	int x = 0;					  //To contain the x value 
	do
	{
		system("cls");
		cout << "\n\t1> Quadratic Menu";
		cout << "\n\t" << string(100, char(205));
		cout << "\n\t\tD. display the expression";		   //DONE
		cout << "\n\t\tA. set coefficient (a)";		       //DONE
		cout << "\n\t\tB. set coefficient (b)";			     //DONE
		cout << "\n\t\tC. set coefficient (c)";			     //DONE
		cout << "\n\t\tE. get evaluation (x)";           //DONE
		cout << "\n\t\tN. get the number of real roots"; //DONE
		cout << "\n\t\tR. get real root(s)";			       //DONE
		cout << "\n\t" << string(100, char(196));
		cout << "\n\t\t0. return";
		cout << "\n\t" << string(100, char(205));

		switch (toupper(inputChar("\n\t\tOption: ", static_cast<string>("DABCENR0"))))
		{
		case '0': return 0;
		case 'A': equation.setACoefficient(inputDouble("\n\tEnter a value and set coefficient (a): ", -100.0, 100.0)); break;
		case 'B': equation.setBCoefficient(inputDouble("\n\tEnter a value and set coefficient (b): ", -100.0, 100.0)); break;
		case 'C': equation.setCCoefficient(inputDouble("\n\tEnter a value and set coefficient (c): ", -100.0, 100.0)); break;
		case 'D': cout << equation; break;
		case 'E': 
		{
			x = inputInteger("\n\tEnter a value of x: ", -100, 100);
			cout << "\n\tEvaluation result: " << equation.solveForY(x) << '\n';
		}break;
		case 'N': cout << "\n\tNumber of roots are: " << equation.countRealRoots(); break;
		case 'R': equation.displayRoots(); break;

		default: cout << "\t\tERROR: - Invalid option. Please re-enter"; break;
		}
		cout << "\n\n";
		system("pause");

	} while (true);
}
