#include "Pseudorandom.h"

//constructor with defualt values
Pseudorandom::Pseudorandom() {
	seed = 1;
	multiplier = 40;
	modulus = 729;
	increment = 725;
}

//MUTATORS:

//int number: number inserted by player to change seed
void Pseudorandom::set_Seed(int number) {
	//precondition: No negative numbers 
	//postcondition: changes private member seed

	seed = number;
}

//int number: number inserted by player to change multiplier
void Pseudorandom::set_Multiplier(int number) {
	//precondition: No negative numbers 
	//postcondition: changes private member multiplier

	multiplier = number;
}

//int number: number inserted by player to change modulus
void Pseudorandom::set_Mod(int number) {
	//precondition: No negative numbers 
	//postcondition: changes private member modulus

	modulus = number;
}

//int number: number inserted by player to change increment
void Pseudorandom::set_Increment(int number) {
	//precondition: No negative numbers 
	//postcondition: changes private member increment

	increment = number;

}


void Pseudorandom::set_Next_Num() {
	//postcondition: changes private member seed

	seed = (multiplier * seed + increment) % modulus;
}

//ACCESSORS:
int Pseudorandom::get_Seed() const {
	//postcondition: returns private member seed
	return seed;
}

int Pseudorandom::get_Multiplier() const {
	//postcondition: returns private member multiplier
	return multiplier;
}

int Pseudorandom::get_Mod() const {
	//postcondition: returns private member modulus
	return modulus;
}

int Pseudorandom::get_Increment() const {
	//postcondition: returns private member increment
	return increment;
}

double Pseudorandom::get_Indirect_Num() const{
	//precondition: use set_Next_Num() before calling for correct calculations
	//postcondition: returns double (answer for indirect number)
	return seed / (modulus * 1.0);
}