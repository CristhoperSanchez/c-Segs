#ifndef WORKOUT_H
#define WORKOUT_H

#include <string>

using namespace std;

// Base class
class Workout{
    public:
        Workout(string name){
            this->name = name;
        };
        virtual string getWorkout(); 
        string getName() const {
            return this->name;
        }

    protected:
        string name;
};


#endif