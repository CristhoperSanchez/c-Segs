
#include <iostream>
#include <vector>

using namespace std;




// There is a difference in the parameter one is a boolean
void patientReturn(bool patientType){


    // Declared Parameters

    int days = 0;
    double dailyRate = 0, medCharges = 0, services = 0, totalStay = 0;

    cout << "How many days did the patient stay in the hospital?" <<  endl;
    cin >> days;

    cout << "What was the daily rate?" << endl;
    cin >> dailyRate; 


    cout << "What were the charges for any services provided to the patient? " << endl;
    cin >> services;

    cout << "What about any Medications both perscribed and provided?" << endl;
    cin >> medCharges;

    totalStay = (days * dailyRate) + medCharges + services;

    cout << "The patients total charges was: " <<  totalStay << endl <<endl;

}


void patientReturn(string patientType){

    double medCharges, services;

    cout << "What were the charges for any services provided to the patient? " << endl;
    cin >> services;

    cout << "What about any Medications both perscribed and provided?" << endl;
    cin >> medCharges;

    cout << "The patients total charges was: " <<  medCharges + services << endl << endl;

}




int main(){
    string input;

    // Live to exit the loop or keep the continous program working
    bool live = true;

    while(live){
    
    cout << "Hello, Was your patient an inpatient or outpatient?  or type 'Exit' to exit"  << endl; 
    
    cin >> input;

        if(input == "inpatient" || input ==  "Inpatient"){
            patientReturn(true);
            
        }

    // If the input is oupatient a string is passed into the function instead
        if(input == "outpatient" || input == "Outpatient"){
            cout << "read Outpatient" << endl;

            patientReturn(input);
        }

        if(input == "Exit" || input ==  "exit"){
            cout << "Goodbye!"<< endl;
            live = false;
        }
        else{
            cout << "Try re-checking your spelling." << endl;
        }
        
    }

    return 0;
}