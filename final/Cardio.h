
#ifndef CARDIO_H
#define  CARDIO_H

#include <string>
#include "Workout.h"

using namespace std;




// Derived class
class Cardio: public Workout{

    public:
        Cardio(string name, string exercise, int time):
        Workout(name){
            this->exercise = exercise;
            this->time = time;
        };

        string getWorkout() override;

    private:
        string name;
        string exercise;
        int time;

};




#endif