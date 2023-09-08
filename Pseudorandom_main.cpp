#include <iostream>
#include "input.h"
#include "Pseudorandom.h"
#include <chrono> //time (microseconds) used for random numbers
#include <thread> //to put to program to sleep (helps with randomization)
#include <cmath> //for pow(), and sqrt()
using namespace std;

//prototypes
void pseudorandom_function();
char menuOption2();
void display_seed(const Pseudorandom & p1); //get seed
void change_seed(Pseudorandom & p1); //set seed
void display_multiplier(const Pseudorandom & p1); //get multiplier
void change_multiplier(Pseudorandom & p1); //set multiplier
void display_mod(const Pseudorandom& p1); //set mod
void change_mod(Pseudorandom& p1); //get mod
void display_increment(const Pseudorandom& p1); //get increment
void change_increment(Pseudorandom& p1); //set increment
void display_next(Pseudorandom & p1); //get next number
void display_indirect(Pseudorandom & p1); //get indirect number
void experiment_range(Pseudorandom& p1); //display pseudocode with different values 
double median_func_calc(const Pseudorandom& p1, const int& MAX_SIZE, const double* numberArray); //to calculate median
double standard_deviation_func(const Pseudorandom& p1, const int& MAX_SIZE, const double * numberArray, const double & sum); //to calculate standard deviation



int main() {
    //code for other menus to be inserted later: switch() {case 2: pseudorandom_function() 
    pseudorandom_function();
}

void pseudorandom_function() {

    Pseudorandom p1; //calls on class pseudorandom to use in each function
    do {
        switch (menuOption2()) {
            case '0': return; break;
            case 'A': display_seed(p1); break; //get seed
            case 'B': change_seed(p1); break; //set seed
            case 'C': display_multiplier(p1); break; //get multiplier
            case 'D': change_multiplier(p1); break; //set multiplier
            case 'E': display_mod(p1); break; //set mod
            case 'F': change_mod(p1); break; //get mod
            case 'G': display_increment(p1); break; //get increment
            case 'H': change_increment(p1); break; //set increment
            case 'I': display_next(p1); break; //display next number
            case 'J': display_indirect(p1); break;//get indirect number
            case 'K': experiment_range(p1); break; //experiment with different values
            default: cout << "ERROR: Invalid option. Please re-enter."; break;
        }
    } while (true);
}

//will return a menu for pseudorandom 
char menuOption2() {
    cout << "\n\t2 > Pseudorandom menu";
    cout << "\n\t" << string(100, char(205));
    cout << "\n\tA.get seed";
    cout << "\n\tB.set seed";
    cout << "\n\tC.get multiplier";
    cout << "\n\tD.set multiplier";
    cout << "\n\tE.get modulus";
    cout << "\n\tF.set modulus";
    cout << "\n\tG.get increment";
    cout << "\n\tH.set increment";
    cout << "\n\tI.get next number";
    cout << "\n\tJ.get indirect next number";
    cout << "\n\tK.run experiment with different values(multiplier, increment, and modulus)";
    cout << "\n\t" << string(100, char(196));
    cout << "\n\t0. return";
    cout << "\n\t" << string(100, char(205));

	return toupper(inputChar("\n\tOption :"));
}

//lets user access seed
void display_seed(const Pseudorandom & p1) {
    cout << "\n\tseed: " << p1.get_Seed();
}

//lets user set seed
void change_seed(Pseudorandom & p1) {
    p1.set_Seed(inputInteger("\n\tEnter a value for seed: ", true));
}

//lets user access multiplier
void display_multiplier(const Pseudorandom & p1) {
    cout << "\n\tmultiplier: " << p1.get_Multiplier();
}

//lets user change multiplier
void change_multiplier(Pseudorandom & p1) {
    p1.set_Multiplier(inputInteger("\n\tEnter a value for multiplier: ", true));
}

//lets user access modulus
void display_mod(const Pseudorandom & p1) {
    cout << "\n\tmodulus:  " << p1.get_Mod();
}

//lets user change modulus
void change_mod(Pseudorandom & p1) {
    p1.set_Mod(inputInteger("\n\tEnter a value for modulus: ", true));
}

//lets user access increment
void display_increment(const Pseudorandom & p1) {
    cout << "\n\tincrement:  " << p1.get_Increment();
}

//lets user change increment
void change_increment(Pseudorandom & p1) {
    p1.set_Increment(inputInteger("\n\tEnter a value for increment: ", true));
}

//lets user chose next number 
void display_next(Pseudorandom & p1) {
    p1.set_Next_Num();
    cout << "\n\tnext Number: " << p1.get_Seed();
}

//lets user chose indirect number 
void display_indirect(Pseudorandom& p1) {
    p1.set_Next_Num(); //need to call next number before indirect number
    cout << "\n\tnext Indirect Number: " << p1.get_Indirect_Num();
}

//experiments with randomized multiplier, increment, and modulus
void experiment_range(Pseudorandom & p1) {
    const int MAX_SIZE = 10, RAND_SIZE = 3, GAUSSIAN_SIZE = 12; //used for array count_Occur, rand_Spawn, and gaussianNumber
    int count_Occur[MAX_SIZE] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }; //used to count amount of occurences
    int rand_Spawn[RAND_SIZE]; //used to hold chrono number
    double gaussianNumbers[12]; //used to hold indirect numbers
    double sum = 0; //sum for gaussian numbers
    int order = 0; //is used for count_Occur, determines the array number 
    
    cout << "\n\texperiment of pseudorandom with random multiplier, increment and modulus:";
    cout << "\n\t" << string(100, char(196));


    //NOTICE: SINCE WE WAIT 3 SECONDS IT MAY SEEM LIKE IT IS BUFFERING
    //we use microseconds to create a random number (if negative we turn positive)
    //we use sleep to stop the computer, the added seconds allow for more randomized numbers from chrono
    for (int i = 0; i < RAND_SIZE; i++) {
        rand_Spawn[i] = static_cast<int>(chrono::duration_cast<chrono::microseconds>(chrono::system_clock::now().time_since_epoch()).count());

        if (rand_Spawn[i] < 0)
            rand_Spawn[i] = rand_Spawn[i] * -1;

       this_thread::sleep_for(chrono::seconds(1));
    }

    //sets up random number (gets original value + random value % Max amount they can be)
    p1.set_Multiplier(((p1.get_Multiplier() + rand_Spawn[0]) % 40000));
    p1.set_Mod(((p1.get_Mod() + rand_Spawn[1]) % 40000));
    p1.set_Increment(((p1.get_Increment() + rand_Spawn[2]) % 40000));


    cout << "\n\tmultiplier = " << p1.get_Multiplier() << ", increment = " << p1.get_Increment() << ", modulus = " << p1.get_Mod();
 
    //generates 1 million indirect numbers, the way it counts is by using order
    //example: lets say we have number 0.1, when we multiply by 10 we get 1, and that is the order of the array
    //example: 0.873 * 10 = 8.73, int truncates .73, order = 8, count_Occur[8] = adds one more (occurance)
    for (int i = 0; i < 1000000; i++) {
        p1.set_Next_Num();
        order = static_cast<int>(p1.get_Indirect_Num() * 10);
        count_Occur[order]++;
    }

    cout << "\n\tRange\tNumber of Occurrences";

    //displays, note that I used (i+1)/10.0 bc i needed to display 1.00 well 
    //simply displays table 
    for (int i = 0; i < MAX_SIZE; i++) {

        cout << "\n\t[0." << i << " ... " << ((i + 1) / 10.0) << ") " << count_Occur[i];
    }
    
    // Calculate the approximate Gaussian distribution
    //calls on 12 more indirect numbers, adds all these numbers up and stores individual numbers
    //we store numbers so that we can access their individual numbers in median and standard deviation array
    for (int i = 0; i < GAUSSIAN_SIZE; i++) {
        p1.set_Next_Num();
        gaussianNumbers[i] = p1.get_Indirect_Num();
        sum += p1.get_Indirect_Num();
    }

    //gets median, standard deviation, then uses equation from project 14 in textbook
    double median = median_func_calc(p1, GAUSSIAN_SIZE, gaussianNumbers); 
    double standardDev = standard_deviation_func(p1, GAUSSIAN_SIZE, gaussianNumbers, sum);
    double result = (median + (sum - 6) * standardDev);

    //displays
   cout << "\n\t  With 10 uniformly distributed rand number in the range[0...1.0), \n\tthe approximate Gaussian distribution is" << result;
}

//calculates Median, used in other following functions
double median_func_calc(const Pseudorandom & p1, const int & MAX_SIZE, const double * numberArray) {
    double middle = 0;
    int middle_length = (MAX_SIZE / 2); //gets half length, if odd truncates decimal (should still be correct number bc arrays start from 0)

    //if even array adds the two numbers together, if odd simply takes it
    if (MAX_SIZE % 2 == 0)
        middle = (numberArray[middle_length - 1] + numberArray[middle_length]) / 2.0;
    else
        middle = numberArray[middle_length];

    return middle;
}


//calculates standard dev, used in other following functions
double standard_deviation_func(const Pseudorandom & p1, const int & MAX_SIZE, const double * numberArray, const double & sum) {

    double mean = (sum / MAX_SIZE) * 1.0; //gets mean

    double total_sqr_diff = 0, result = 0;

    //subtracts every value by mean = ans
    //squares it ()^2, adds all od them after
    //then divides by the amount of numbers and square roots
    for (int i = 0; i < MAX_SIZE; i++)
        total_sqr_diff += pow(numberArray[i] - mean, 2);

    return sqrt(total_sqr_diff / MAX_SIZE);

}

