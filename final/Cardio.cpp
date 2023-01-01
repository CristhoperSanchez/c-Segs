#include "Cardio.h"
#include <iostream>

using namespace std;

string Cardio::getWorkout(){
    return "Workout type: Cardio\n   Activity: " + this->exercise + "\n   Time: " + to_string(this->time); 
};


