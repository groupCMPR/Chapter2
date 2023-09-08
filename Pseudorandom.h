#pragma once
class Pseudorandom {
private:
	int seed;
	int multiplier;
	int modulus;
	int increment;

public:
	Pseudorandom(); //constuctor

	//MUTATORS:
	
	//changes seed
	void set_Seed(int number);

	//changes multiplier
	void set_Multiplier(int number);

	//changes modulos
	void set_Mod(int number);

	//changes increment
	void set_Increment(int number);

	//changes seed to next number
	void set_Next_Num();

	//ACCESSORS:

	//displays seed
	int get_Seed() const;

	//displays multiplier
	int get_Multiplier() const;

	//displays modulus
	int get_Mod() const;

	//displays increment
	int get_Increment() const;

	//displays indirect number
	double get_Indirect_Num() const;
};