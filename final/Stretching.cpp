#include <iostream>
#include "Stretching.h"

using namespace std;


string Stretching::getWorkout(){

    return "Workout type: Stretching\n   " + this->getName() + "\n   Stretch will target: " + this->bodyPart +"\n   Description: "
     + this->desc + "\n   Hold for: " + to_string(this->time) + "(seconds), " +  to_string(this->intervals) + " time(s).";

};