
#ifndef STRETCHING_H
#define STRETCHING_H

#include <string>
#include "Workout.h"

using namespace std;

// Derived class
class Stretching: public Workout{
    public:
        Stretching(string name, string bodyPart, int intervals, int time,  string desc):
            Workout(name){
                this->bodyPart = bodyPart;
                this->intervals = intervals;
                this->desc = desc;
                this->time = time;
            };

        string getWorkout() override;
    private:
        string name;
        string bodyPart;
        string desc;
        int time;
        int intervals;
};






#endif