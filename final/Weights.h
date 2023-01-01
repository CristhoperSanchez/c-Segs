#ifndef WEIGHTS_H
#define  WEIGHTS_H

#include <string>
#include "Workout.h"

using namespace std;
// Derived class
class Weights: public Workout{
    public:
        Weights(string name, int reps, int sets, int rest)
            :Workout(name){
            this->reps = reps;
            this->sets = sets;
            this->rest = rest;
        }
        
        string getWorkout() override;
        private:
            string name;
            int reps;
            int sets;
            int rest;


};

#endif