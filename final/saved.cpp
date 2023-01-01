#include <iostream>
#include <iomanip>
#include <vector>
#include <array>
#include <stdlib.h>
#include <cstdlib>
#include <string>

#include "Workout.h"
#include "Cardio.h"
#include "Weights.h"
#include "Stretching.h"

using namespace std;




// Error code function to reduce repitition code.
void getError(int type){
    switch(type){
        case 1:
            cout << "**ERROR: Invalid Input" << endl;
            break;
        case 2:
            cout << "**ERROR: Out of Range" << endl;
            break;
        case 3:
            cout << "What??" << endl;
            break;
    }
}



// Sends command to operating system to clear the Screen.
void clearScreen(){
    #if _WIN32
        system("CLR");
    
    #elif _WIN64
        system("CLR");

    #elif defined(__linux__) // Or #if __linux__
        system("clear");

    #endif

}




// Funciton to outpput message and return string value
string returnString(string* message){
    string user;
    cout << *message;
    cin.ignore();
    getline(cin,user);
    cin.clear();
    return user;
}



// Interger Filter function
int returnSelection(int min, int max, string *menu){
    clearScreen();
    int temp,input,status;
    cout << *menu;
    status = scanf("%d", &input);
    while(status!=1 || input > max || input < min){
        clearScreen();
        while((temp=getchar()) != EOF && temp!='\n' );
        if((status == 1 && input < min)|| (status ==1 && input > max)){
            getError(2);
            cout << *menu;
        }
        else{
            getError(1);
            cout << *menu;
        }
        status = scanf("%d", &input);
    }


    cin.clear();

    return input;
};


//============== CONSTRUCTOR FUNCTIONS FOR EACH OF THE DERIVED CLASSES==============================================================================
void addWeights(vector<Workout*> *memory){
    clearScreen();
    string messages[4] = {"Enter the name of the Exercise: ","Enter the amount of sets: ", "Enter the amount of reps: ", "Enter the resting time(seconds): "};   
    string name;
    Weights* wptr;
    int reps, sets, rest;
    cout << messages[0];
    cin >> name;
    sets = returnSelection(0,100,&messages[1]);
    reps = returnSelection(0,100,&messages[2]);
    rest = returnSelection(0,100,&messages[3]);

    wptr = new Weights(name, reps,sets,rest);
    memory->push_back(wptr);

    return;
}

void addStretching(vector<Workout*> *memory){
    string name, bodypart, desc;
    int intervals, time;
    Stretching* sptr;
    clearScreen();
    string messages[5] = {"Enter the name of the Stretch: ", "Enter What body part this stretches: ", "Enter the amount of intervals: ","How long should the intervals be(seconds)?: ", "Give a Breif description of how to perform the movement: \n"};

    name = returnString(&messages[0]);
    bodypart = returnString(&messages[1]);
    intervals = returnSelection(0,100, &messages[2]);
    time = returnSelection(0,100, &messages[3]);
    desc = returnString(&messages[4]);

    sptr = new Stretching(name, bodypart, intervals, time, desc);

    memory->push_back(sptr);
    return;

}

void addCardio(vector<Workout*> *memory){
    clearScreen();
    string messages[3] = {"Enter the name of the name of Cardio Exercise: ", "Enter the type of Cardio Exercise: ", "Enter the duration(minutes): "};
    string name, exercise;
    int time;
    Cardio* cptr;

    name = returnString(&messages[0]);
    exercise = returnString(&messages[1]);
    time = returnSelection(0,100,&messages[2]);

    cptr = new Cardio(name, exercise, time);

    memory->push_back(cptr);
    return;

}
//===============================================================================================================================================================================


void addItem(vector<Workout*> *memory){
    clearScreen();
    string menu = 
    "_____Add Workout____\n"
    "    WorkoutTypes:\n"
    "1:            Weights\n"
    "2:             Cardio\n"
    "3:         Stretching\n"
    "4:             Return\n" 
    "Enter Selection: ";

    int user = returnSelection(1,4, &menu);

    switch(user){
        case 1:
            addWeights(memory);
            break;

        case 2:
            addCardio(memory); 
            break;

        case 3:
            addStretching(memory); 
            break;
    }

}

void showItems(vector<Workout*> *memory){
    cout << "In add show" << endl;
    return;

}
void deleteItems(vector<Workout*> *memory){
    string message = "Enter a number do delete that workout.";
    int user;
    int mSize = memory->size();
    if(mSize <= 0){
        cout << "Nothing to Delete" << endl;
        return;
    };
    vector<string> workouts;

    cout << "Memory Size: " << mSize << endl;
    cout << "Workout Vector Size:" << workouts.size() << endl;

    for(int index = 0; index < mSize; index++) {
        workouts.push_back(memory->at(index)->getName());
    }; 


    string menu =
    "____Delete Menu___\n"
    "0:    Pevious Menu\n";

    for(int item = 0 ; item < workouts.size(); item++){
        menu.append(to_string(item+1) + ":  " + workouts[item] + "\n");
        if(item+1 == workouts.size()){
            menu.append("Enter Item to delete: ");
        }
    };

    user = returnSelection(0,workouts.size(), &menu);

    
    if(user == 0){
        return;
    }
    else if(user >=1 || user < mSize){
        memory->erase(memory->begin()+(user-1));
    };


    return;

}


void mainMenu(vector<Workout*> *memory){
    clearScreen();
    string menu = 
    "_______Main Menu_______\n"
    "1:             Add Item\n"
    "2:          Delete Item\n"
    "3:           Show Items\n"
    "4:                 Exit\n\n" 
    "Enter Selection: ";

    int user = returnSelection(1,4, &menu);

    // Cases are called with each menu option. Recursion happens with each case
    // So that the menu will return to main Menu.
    switch(user){
        case 1:
            addItem(memory);
            mainMenu(memory);
            break;
        case 2:
            deleteItems(memory);
            mainMenu(memory);
            break;
        case 3:
            showItems(memory);
            mainMenu(memory);
            break;
        case 4:
            break;

    }

    return;
};



int main(){

/*     vector<Workout*> memory; 

    mainMenu(&memory); */

    return 0;
}