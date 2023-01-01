
#include <iostream>
#include <vector>
#include <cmath>

// Cristhoper Sanchez

using namespace std; 




// Array Size was declared larger than most users will need since array declarations need a constant variable.
const int SIZE = 100;


int main(){

    // Variable declaration for numbers that will be complete intergers.
    int index, displayMessageVar, counter, evenDays;

    // Numbers that Wil be doubles.
    double userInput,averageTemps;
    bool active = true;

    // Variables to display exit in case user forgets, and also so it 
    // Does not print every single line. Starts at 5 to display once at the beginning
    displayMessageVar = 5;
    averageTemps = 0;
    counter = 0;           // Counter will keep track of how many variables are inputed for iteration.
    index = 0;
    evenDays = 0;


    // Static String message to be displayed every few itterations
    string message = "**** Enter a Letter Character at any point to Exit ****";
    vector <double> temperatures = {}; 

// If the input is not an interger it will break the loop.
    while(active){
        if(displayMessageVar == 5){
            displayMessageVar = 0;
            cout << endl << message << endl << endl;
        }

    // Displays the day for the information being entered. Added one here because the refrence 
    // Index is one digit behind of the array.
        cout <<"Day " << index +1 << ": ";

        cin >> userInput;
    // Constant array pushback
        temperatures.push_back(userInput);
        cout <<userInput << endl;


// If the user inputs a Character the active boolean gets flipped and the 
// loop is broken. I could have just used a break stement but this was more thurough
    if(userInput == 0 ){
        active = false;
    }

    // Clears cin to prevent input buildup.
        cin.clear();


        index++;displayMessageVar++;
    }




    // Iteration to only accocunt for even days. 
    // When the Criteria is met evenDays counter incriments by 1
    // averageTemps takes the temperature of the even day and adds it to a total.
    // counter%2 == 0 checks to see if the day is even.
    for (int value : temperatures){
        if((counter+1) %2 == 0){
            evenDays ++;
            averageTemps = averageTemps + temperatures[value];
        }
        counter++;

    }

// cMath for using floor method to allow up to two decimals.
// Devides the total temperatures taken from the Even days that were stored
// On the previous for loop as well as the Even days length.
    cout << "The average Temperatures of the Even days entered was: " << floor(averageTemps/evenDays*100)/100. << endl;

    return 0;
}
