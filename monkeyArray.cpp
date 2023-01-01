#include <iostream>
#include <array>
#include <cmath>


// Cristhoper Sanchez

using namespace std;

const int Days = 5;
const int Monkeys = 3;


int main(){

// UserInput can be a double.
    double userInput; 

    array < array<double,Monkeys>,Days> foodcount = {};
    array <double, Monkeys> monkeyAverages = {};

// Iterates through each row and column filling in the monkey indexes
    for(int monkey = 0;monkey < Monkeys; monkey++){
        for(int day = 0; day < Days; day++){
            cout << "Monkey ["<< monkey+1 << "] Day [" << day + 1 << "]: ";
            cin >> userInput;
            foodcount[monkey][day] = userInput;
            cin.clear();
        }

        // This is setting the average at 0 for futre calculation
        monkeyAverages[monkey] = 0;
    };



// Iterates through each monkey input ands adds the total to a second array.
   for (size_t monkey_index = 0;monkey_index < Monkeys; monkey_index++) {
        for (size_t day_index = 0; day_index < Days; day_index++) {
            monkeyAverages[monkey_index] = monkeyAverages[monkey_index] + foodcount[monkey_index][day_index];
        };
    };



// Devides all the toals by 5 (days) and returns the average.
    for(size_t monkey_index = 0; monkey_index < Monkeys; monkey_index++){
    
    // cmath for a 2 decimal int
        monkeyAverages[monkey_index] = floor(monkeyAverages[monkey_index] / 5 * 100)/100;

        cout << "Average for Monkey " << monkey_index + 1 << ": " << monkeyAverages[monkey_index] << endl; 
    }

    return 0;
}