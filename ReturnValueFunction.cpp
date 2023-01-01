#include <iostream>
#include <vector>

using namespace std;

    // CRISTHOPER SANCHEZ


// Global Variable for insertion
const int MAXTEMPS = 4;


void printOut(double t1, double t2, double t3, double t4){


    // Declaration of a double average and a vector of temps;
    // I tried to declare this as a list of 4 values, temps.insert would return an array size of 7 and I could not understand
    double average;
    vector<double> temps;


// This is where I would argue that insertion at indexes using [VectorName].at(index)
// May be more functional, but I was attempting cleanliness and looping strategies.
//              Insertion would look like 

    // vector<double> tempsInsertion(MAXTEMPS);
    // vector.at(0) = t1;
    // vector.at(1) = t2;
    // vector.at(2) = t3;
    // vector.at(3) = t4;
    // __________________________________________________

    temps.insert(temps.begin(), {t1,t2,t3,t4});

//  Takes each item in temps, adds it to the average and then will be devided by 4 and returned to the user
    for( double v : temps){
        average += v;
    }

    average = average/4;

    cout << "The averages of the four temperatures:" << average << endl;

}



int main(){

    // Variables within the main function. The variable names overlap, it seemed simple in this case and
    // can definetly be renamed.
    double t1, t2, t3, t4;



    cout << "Average temperature amogst four." << endl;
    cout << "Insert four temperatures: " << endl;


    // Variable Insertion
    cin >> t1;
    cin >> t2;
    cin >> t3;
    cin >> t4;

    // Passed into the function
    printOut(t1,t2,t3,t4);
    return 0;

}