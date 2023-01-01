
#include "Weights.h"
#include <iostream>

using namespace std;

string Weights::getWorkout(){
    return "Workout Type: Weights \n   Exercise: " +  this->getName() +"\n   " + to_string(this->sets) + " sets of "+ to_string(this->reps) 
    + "\n   Make sure to rest for " + to_string(this->rest) + "second(s) at a time!";
};

