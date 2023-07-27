#include <iostream>

// Including strings for storage in arrays and variables
#include <string>



using namespace std;



// Enumerations for the Weekdays. 
// Modified Sunday to have the array begin at 1 instead of 0;
enum DayOFWeek {
    Sunday = 1, 
    Monday,
    Teusday,
    Wednesday,
    Thursday,
    Friday,
    Saturday
};



// Function to check for valid input that will all be 
// refrenced using intergers
int returnValid(int user, int min, int max){

    // While loop that checks until input is valid
    while(true){
        if(user > min && user < max){
            break;
        }
        if(user < min){
            cout <<  "That input was to low, \n try something between: " << min << " and " << max << endl;
            cin >> user;
        }
        if(user > max){
            cout <<  "That input was to high, \n try something between: " << min << " and " << max << endl;
            cin >> user;
        }
    }
    return user;
}


// Structure that will store the data
struct Date {
    int DayOfWeek;
    string Day;
    int Month;
    int MonthDay; 
    int Year;
};



// Declarations of the dataDisplay function, as well as
// The creation function
void displayData(Date);
Date getData(Date);


int main(){

    // Declaring the structure the user will fill
    Date userDate;

    // Calling the creation function within the variable;
    userDate = getData(userDate);

    // Calling the display of the data.
    displayData(userDate);
    return 0;
};



// Creation Function
Date getData(Date userDate){
    // iniitalizing temp variable that will be used to check input 
    int temp;

    // Array with refrence days using idnexes
    string DaysOfWeek[7] =
    {"Sunday", "Monday", "Tuesday", "Wednesday","Thursday","Friday","Saturday"};

// This section includes 4 cycles that ask for the users input --> Call the checking function --> Then store the variables

    cout << "Enter a day of the week using Numbers(1 Representing Sunday):" << endl << endl;
    cin >> temp;

// Example one where the users input is stored within the temp variable and then 
// passed to the returnValid funciton with parameters specific to the 
// prompt being asked
    userDate.DayOfWeek = returnValid(temp, 1, 7);
    userDate.Day = DaysOfWeek[userDate.DayOfWeek];
    cin.clear();

    cout << "Enter a Month using a Number (1-12). Starting with January:" << endl << endl;
    cin >> temp;
    userDate.Month = returnValid(temp, 1,12);
    cin.clear();

    cout << "Enter the Day of the month (1-30 or 31):" << endl << endl;
    cin >> temp;
    userDate.MonthDay = returnValid(temp, 1, 32);
    cin.clear();

    cout << "Enter a Year anything after(0 ADE): " << endl << endl;
    cin >> temp;
    userDate.Year = returnValid(temp,1,200000);

    return userDate;
   
};

// Display Data Funciton
void displayData(Date userDate){
    cout << "Displaying Date: " << endl;
// Pulls the structures data in the approprate format
    cout << userDate.Day << ", " << userDate.Month << "/" << userDate.MonthDay << "/" << userDate.Year << endl;
};