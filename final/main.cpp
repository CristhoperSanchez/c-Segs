// File Inclusion, for Headers and Methods
#include "Workout.h"
#include "Cardio.h"
#include "Weights.h"
#include "Stretching.h"
#include "Workout.cpp"
#include "Cardio.cpp"
#include "Weights.cpp"
#include "Stretching.cpp"

// Libraries being used.
#include <iostream>
#include <iomanip>
#include <vector>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <map>


using namespace std;

map <string, string>  MENU ={               // Global Menus in map
    {"main", "_______Main Menu_______\n\n"
            "1:             Add Item\n"
            "2:          Delete Item\n"
            "3:           Show Items\n\n"
            "4:                 Exit\n\n" 
            "(Enter Selection): "
            },

    {"add", "_____Add Workout____\n"
            "    WorkoutTypes:\n"
            "0:          Main Menu\n\n" 
            "1:            Weights\n"
            "2:             Cardio\n"
            "3:         Stretching\n\n"
            "(Enter Selection): "
     },

     {"delete",
            "____Delete Menu___\n"
            "0: Main Menu\n\n"
      },

    {
        "display",
            "__Display Items:__\n"
            "0: Main Menu\n\n"
    }
    
};


// Global Errors array
string ECODES[4] = {
    "  *Error: default",
    " *Error: Invalid Input",
    " *Error: Out of Range",
    " *No Workouts on file*",
};



// Sends command to operating system to clear the Screen.
void clearScreen(){
    #if _WIN32
        system("CLR");
        system("cls");
    
    #elif _WIN64
        system("CLR");
        system("cls");

    #elif defined(__linux__) // Or #if __linux__
        system("clear");

    #endif

}


// Funciton to outpput message and return string value
string returnLong(string* message){
    string user;
    
    cout << *message;
    getline(cin,user);

    return user;
}



// Funciton to validate Input is an interger, passes in min,max and a menu pointer.
int returnSelection(int min, int max, string *mptr, bool E=false, int Eindex=0){
    clearScreen();
    string display = *mptr;

    // If error parameter is passed, Displays the error code
    if(E){
        display = ECODES[Eindex] + '\n' + display;
    };

    int temp,input,status;
    cout << display;
    status = scanf("%d", &input);

    // While loop until input is correct. Then returned from the function.
    while(status!=1 || input > max || input < min){
        clearScreen();
        // Clears Screen only if there is no error code.
        while((temp=getchar()) != EOF && temp!='\n' );
        if((status == 1 && input < min)|| (status ==1 && input > max)){
            cout << ECODES[2] << endl;;
            cout << display;
        }
        else{
            cout << ECODES[1] << endl;
            cout << display;
        }
        status = scanf("%d", &input);
    }
    // Clears inputs "Precautionary"
    cin.get();
    cin.clear();
    return input;
};


string getItemList(vector<Workout*> *memory){
    string display; // Variable for Building menu

    // Indexes are appended to strings with names for user selection.
    for(int index = 0 ; index < memory->size(); index++){

        // For loop, gets the name of each Object
        display = display + to_string(index +1)+  ": " + (memory->at(index)->getName()) + "\n";

    };

    return display;
};





//============== CONSTRUCTOR FUNCTIONS FOR EACH OF THE DERIVED CLASSES=========TOP

void addWeights(vector<Workout*> *memory){
    clearScreen();
    // Message Objects for refrence.
    string messages[4] = {"Enter the name of the Exercise: ","Enter the amount of sets: ", "Enter the amount of reps: ", "Enter the resting time(seconds): "};   
    Weights* wptr;
    string name;
    int reps, sets, rest;


    name = returnLong(&messages[0]);
    sets = returnSelection(1,100,&messages[1]);
    reps = returnSelection(1,100,&messages[2]);
    rest = returnSelection(1,100,&messages[3]);

    // Values are put into pointer object and pushed into memory pointer.
    wptr = new Weights(name, reps,sets,rest);
    memory->push_back(wptr);

    return;
}

void addStretching(vector<Workout*> *memory){
    string name, bodypart, desc;
    int intervals, time;
    Stretching* sptr;
    clearScreen();
    // Message Objects for refrence.
    string messages[5] = {"Enter the name of the Stretch: ", "Enter What body part this stretches: ", "Enter the amount of intervals: ","How long should the intervals be(seconds)?: ", "Give a Breif description of how to perform the movement: \n"};


    // Function calls for each value required to create object.
    name = returnLong(&messages[0]);
    bodypart = returnLong(&messages[1]);
    intervals = returnSelection(1,100, &messages[2]);
    time = returnSelection(0,100, &messages[3]);
    desc = returnLong(&messages[4]);


    // Values are put into pointer object and pushed into memory pointer.
    sptr = new Stretching(name, bodypart, intervals, time, desc);
    memory->push_back(sptr);
    return;

}

void addCardio(vector<Workout*> *memory){
    clearScreen();
    
    // Message Objects for refrence.
    string messages[3] = {"Enter the name of the name of Cardio Exercise: ", "Enter the type of Cardio Exercise: ", "Enter the duration(minutes): "};
    string name, exercise;
    int time;
    Cardio* cptr;

    name = returnLong(&messages[0]);
    exercise = returnLong(&messages[1]);
    time = returnSelection(0,100,&messages[2]);


    // Values are put into pointer object and pushed into memory pointer.
    cptr = new Cardio(name, exercise, time);
    memory->push_back(cptr);
    return;

}

//============== CONSTRUCTOR FUNCTIONS FOR EACH OF THE DERIVED CLASSES=========BOTTOM



// Add item menu
void addItem(vector<Workout*> *memory){
    clearScreen(); // Clears screen

    // pulls global menu and attaches it to local variable.
    string addmenu = MENU.find("add")->second;
    int user;

    user = returnSelection(0,4, &addmenu);

    // User Selection. Calls itself again to add another item
    switch(user){
        case 1:
            addWeights(memory);
            addItem(memory);
            return;
        case 2:
            addCardio(memory); 
            addItem(memory);
            return;
        case 3:
            addStretching(memory); 
            addItem(memory);
            return;
    }
    return;
}

bool showItems(vector<Workout*> *memory){
    clearScreen();
    if(memory->size() <= 0)return true;  // If no items are in memory the function returns.
    int user; 

    string options[2] = {"Main Menu", "Show All"};
    string menu = (MENU.find("display")->second) + (getItemList(memory)) + to_string(memory->size() +1) + ": Show All\n\n"; // Clean menu to modify depending on selection.
    string shortmenu =  menu + "(Enter Selection):"; // Menu for first selection

    user = returnSelection(0, (memory->size()+2), &shortmenu);

    if(user == 0) return false;

    while(user!= 0){ // While loop for continous itterations.
        if (user == (memory->size() +1)){ 
            string dAmenu =  menu; // Display All Menu: creates a separate menu to be displayed, 
                                  // This is important in case the user alters between displaying all & just a specific workout.
            for(auto &item : *memory){
                dAmenu = dAmenu + item->getWorkout() + "\n\n";
            };
            dAmenu = dAmenu + "(Enter Selection):";
            user = returnSelection(0, (memory->size()+2), &dAmenu);
        }              
        else{
            string oMenu = menu + memory->at(user-1)->getWorkout() + "\n\n(Enter Selection):"; // One Item Menu: Dispays one object.
            user = returnSelection(0, (memory->size()+2), &oMenu);
        }
    };
    return false;

}

bool deleteItems(vector<Workout*> *memory){
    clearScreen();
    if(memory->size() <= 0) return true;
    string menu = (MENU.find("delete")->second) + (getItemList(memory)) + '\n' +"(Select # to delete): ";
    int user;
    user = returnSelection(0,(memory->size()), &menu);

    // If users selection is approprate and not return to main menu, Tha item is deleted. 

    while(user-1 < memory->size() && user != 0 && memory->size() > 0){
        string name = memory->at(user-1)->getName() + "\n";
        memory->erase(memory->begin()+(user-1)); // Deletes memory from pointer locaiton.
        menu = "Deleted: " + name + (MENU.find("delete")->second) + (getItemList(memory)) + '\n' +"(Select # to delete): ";
        if(memory->size() <= 0) return true;
        user = returnSelection(0,(memory->size()), &menu);
    };

    return false;
};


void mainMenu(vector<Workout*> *memory, bool E=false){
    clearScreen();
    string main = MENU.find("main")->second;
    int user;
    if(E) user = returnSelection(1,4,&main, true, 3); // Recursive call in the scenaro selection from below returns error.
    else  user = returnSelection(1,4, &main);

    // Cases are called with each menu option. Recursion happens with each case
    // So that the menu will return to main Menu.
    switch(user){
        case 1:
            addItem(memory);
            mainMenu(memory);
            break;
        case 2:
            mainMenu(memory, deleteItems(memory));// Callback Function uses Boolean to determine whether to run & allows return of error  
            break;                                
        case 3:
            mainMenu(memory,showItems(memory)); // Same method as above.
            break;
        case 4:
            break;

    }

    return;
};



// Main function
int main(){

    vector<Workout*> memory;  // Memory Allocation Pointer
    mainMenu(&memory); // Main Function.
    return 0;
}