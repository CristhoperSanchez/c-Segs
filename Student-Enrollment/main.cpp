/* CRISTHOPER SANCHEZ  */

#include<iostream>
#include<iomanip>
#include<vector>
#include<string>


using namespace std;



bool valid(string userI){  // User input check for exiting using strings
    if(userI == "0"){ // Comparitor for strings
        cout << "Exiting..." << endl;
        return true;
    }
    return false;
};

bool valid(double userI){  // User input checks for exiting using doubles
    if(userI == 0){ // Comparitor for doubles
        cout << "Exiting..." << endl;
        return true;
    }
    return false;
};



class Student {
    public:
        Student();   // Default Constructor
        Student(string First, string Last, double Grade); // Cunstrocter wtih parameters
        void setFirst(string First);
        void setLast(string Last);
        void setGrade(double Grade);
        void GetInfo();

    // Private variables, not modifyable without public methods
    private: 
        string First;
        string Last;
        double Grade;

}; 

// Display of student info in a cleaner layout
void Student::GetInfo(){
    cout << "Student:" << setw(14) << right << Last;
    cout << ", " << setw(10) << left  << First;
    cout << "  Grade: " << setw(4) << Grade << endl;
};


// Public Methods for updating specific variables with pointers.
void Student::setFirst(string First){
    this->First = First;    
};

void Student::setLast(string Last){
    this->Last = Last;    
};

void Student::setGrade(double Grade){
    this->Grade = Grade;
};


// Default constructor with Default Parameters

Student::Student():First("Unkown") , Last("Unknown"), Grade(0.0) {}


// Custom Constructor with users Parameters

Student::Student(string First, string Last, double Grade){
    this->First = First;
    this->Last = Last;
    this->Grade = Grade;
    cout << "Added: " << First << " " << Last << " as a student!" << endl << endl;
}


int main() {
    vector <Student> EnrolledStudents;          // Vector for storage of Student Objects
    unsigned int index;

    while(true){ // While Loop for user inputs

        cout << "***Enter '0' at any point to Exit.*** \nEnter Students to add to Enrollment: " << endl << endl;   

        string currFirst, currLast; 
        double currGrade;

        cout << "Student's First name: ";
        cin >> currFirst; 
        if(valid(currFirst))break;  // Function calling for immediate Loop exiting

        cout << "Student's last name: ";
        cin >> currLast;
        if(valid(currLast))break;

        cout << "Student (" << currFirst << " " << currLast << ") Grade: ";
        cin >> currGrade;
        if(valid(currGrade))break;

        cout << endl;

        EnrolledStudents.push_back(Student(currFirst, currLast,currGrade));        // Vector push_back of created student
    }


    cout <<  endl << "Displaying Enrolled Students information: " << endl;

    for(index = 0;index < EnrolledStudents.size(); index++){        // Displayment of Each students information Using itteration from vector.
        EnrolledStudents[index].GetInfo();
    }

    return 0;
}


