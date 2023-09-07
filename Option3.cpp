#include <iostream>
#include "input.h"
#include "Rational.h"

using namespace std;


char menuOption();
char caseThreeMenu();
void caseThree();


int main() {
	
	do {
		system("cls");
		switch (menuOption()) {
		case 'X': return EXIT_SUCCESS; break;
		case '3': caseThree(); break;
		default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
		}
		cout << "\n\n\t";
		system("pause");

	} while (true);

	return EXIT_SUCCESS;
}

char menuOption() {
	cout << "\n\tCMPR131 Chapter2 - ADT Assignments by Alexis Martinez (9/6/2023)";
	cout << "\n\t" << string(100, char(205));
	cout << "\n\t\t1> Quadratic Expression";
	cout << "\n\t\t2> Pseudorandom";
	cout << "\n\t\t3> Rational number";
	cout << "\n\t" << string(100, char(196));
	cout << "\n\t\tX. Exit";
	cout << "\n\t" << string(100, char(205));
	return inputChar("\n\t\tOption: ", static_cast<string>("123X"));
}

void caseThree() {
	Rational r1;
	Rational r2;
	bool optionAFlag = false;
	bool optionCFlag = false;

	do {
		system("cls");
		switch (caseThreeMenu()) {
		case '0': return; break;
		case 'A':
			try {
				optionAFlag = true;
				int numerator = inputInteger("\n\tEnter the value for the numerator: ");
				int denominator = inputInteger("\n\tEnter the value for the denominator: ");
				Rational tempR1(numerator, denominator); 
				r1 = tempR1; 
			}
			catch (Rational::ZeroDenominator& e)
			{
				cout << "\n\tEXCEPTION ERROR: Cannot push a Rational number, " << e.toString() << ", with a zero denominator value.";
				optionAFlag = false;
			}

			 break;
		case 'B':
			if (optionAFlag == false) {
				cout << "\n\tEnter in values for R1 first.";
				break;
			}
			cout << "\n\tRational Number R1: " << r1;

			 break;
		case 'C':
			try {
				optionCFlag = true;
				int numerator = inputInteger("\n\tEnter the value for the numerator: ");
				int denominator = inputInteger("\n\tEnter the value for the denominator: ");
				Rational tempR2(numerator, denominator);
				r2 = tempR2;
			}
			catch (Rational::ZeroDenominator& e)
			{
				cout << "\n\tEXCEPTION ERROR: Cannot push a Rational number, " << e.toString() << ", with a zero denominator value.";
				optionCFlag = false;
			}

			 break;
		case 'D':
			if (optionCFlag == false) {
				cout << "\n\tEnter in values for R2 first.";
				break;
			}
			cout << "\n\tRational Number R2: " << r2;
			break;

		case 'E':
			if (optionAFlag == false || optionCFlag == false) {
				cout << "\n\tMake sure that both R1 and R2 have been given values.";
				break;
			}
			cout << "\n\tR1 * R2: " << r1 * r2;
			break;
		case 'F':
			if (optionAFlag == false || optionCFlag == false) {
				cout << "\n\tMake sure that both R1 and R2 have been give values.";
				break;
			}
			cout << "\n\tR1 / R2: " << r1 / r2;
			break;
		case 'G': 
			if (optionAFlag == false || optionCFlag == false) {
				cout << "\n\tMake sure that both R1 and R2 have been given values.";
				break;
			}
			cout << "\n\tR1 + R2: " << r1 + r2;
			break;
		case 'H':
			if (optionAFlag == false || optionCFlag == false) {
				cout << "\n\tMake sure that both R1 and R2 have been given values.";
				break;
			}
			cout << "\n\tR1 - R2: " << r1 - r2;
			break;
		case 'I':
			if (optionAFlag == false || optionCFlag == false) {
				cout << "\n\tMake sure that both R1 and R2 have been given values.";
				break;
			}
			cout << (r1 == r2 ? "\n\tR1 == R2: true" : "\n\tR1 == R2: false");
			break;
		case 'J':
			if (optionAFlag == false || optionCFlag == false) {
				cout << "\n\tMake sure that both R1 and R2 have been given values.";
				break;
			}
			cout << (r1 < r2 ? "\n\tR1 < R2: true" : "\n\tR1 < R2: false");
			break;

		default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
		}
		cout << "\n\n\t";
		system("pause");
	} while (true);

}

char caseThreeMenu() {
	cout << "\n\t3> Rational Number menu";
	cout << "\n\t" << string(100, char(205));
	cout << "\n\t\tA. enter values of rational number R1";
	cout << "\n\t\tB. display R1";
	cout << "\n\t\tC. enter values for  rational number R2";
	cout << "\n\t\tD. display R2";
	cout << "\n\t\tE. multiplication of 2 rational numbers (R1 * R2)";
	cout << "\n\t\tF. division of 2 rational numbers (R1 / R2)";
	cout << "\n\t\tG. addition of 2 rational numbers (R1 + R2)";
	cout << "\n\t\tH. subtraction 2 rational numbers (R1 - R2)";
	cout << "\n\t\tI. (R1 == R2)";
	cout << "\n\t\tJ. (R1 < R2)";
	cout << "\n\t" << string(100, char(196));
	cout << "\n\t\t0. return";
	cout << "\n\t" << string(100, char(205));
	return inputChar("\n\t\tOption: ", static_cast<string>("ABCDEFGHIJ0"));
}
