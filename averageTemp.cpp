#include <iostream>
#include <array>
#include <cmath>

// Cristhoper Sanchez

using namespace std; 




// Array Size was declared larger than most users will need since array declarations need a constant variable.
const int SIZE = 100;


int main(){

    // Variable declaration for numbers that will be complete intergers.
    int displayMessageVar, counter, evenDays;

    // Numbers that Wil be doubles.
    double userInput,averageTemps;

    // Variables to display exit in case user forgets, and also so it 
    // Does not print every single line. Starts at 5 to display once at the beginning
    displayMessageVar = 5;
    averageTemps = 0;
    counter = 0;            // Counter will keep track of how many variables are inputed for iteration.
    evenDays = 0;


    // Static String message to be displayed every few itterations
    string message = "**** Enter a Letter Character at any point to Exit ****";
    array <double, SIZE> temperatures = {}; 


// Itteration that pushes users input into temperatures
    for(int index = 0; index < SIZE; index ++){
        
        if(displayMessageVar == 5){
            displayMessageVar = 0;
            cout << endl << message << endl << endl;
        }

    // Displays the day for the information being entered. Added one here because the refrence 
    // Index is one digit behind of the array.
        cout <<"Day " << index +1 << ": ";
        if(std::cin >> temperatures[index]){
            displayMessageVar++; counter++;




    // Clears cin to prevent input buildup.
        cin.clear();

        }

    // In case cin recieves a non double the if loop breaks.
        else{
            break;
            }

    }

// Iteration to only accocunt for even days. 
    for(int iterator = 0; iterator < counter; iterator++){
    // When the Criteria is met evenDays counter incriments by 1
    // averageTemps takes the temperature of the even day and adds it to a total.
    // iterator%2 == 0 checks to see if the day is even.
        if((iterator+1) %2 == 0){
            evenDays ++;
            averageTemps = averageTemps + temperatures[iterator];
        }
    }

// cMath for using floor method to allow up to two decimals.
// Devides the total temperatures taken from the Even days that were stored
// On the previous for loop as well as the Even days length.
    cout << "The average Temperatures of the Even days entered was: " << floor(averageTemps/evenDays*100)/100. << endl;

    return 0;
}
