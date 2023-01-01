#include <iostream>
#include <vector>
#include <array>
#include <string>



using namespace std;
class Person {
    public: 
        Person();
        Person(string Fname, string Lname);
        void SetFirstName(string Fname);
        void SetLastName(string Lname);
        void GetInfo(){
            cout << "   First: " << Fname << endl;
            cout << "   Last: " << Lname << endl;
        };

    // Protected Object values, they are inherited 
    protected: 
        string Fname;
        string Lname;

};



// Derived class from Person. Getinfo() is updated, but still refrences the base class function
class Student: public Person{
    public:
        Student(string Fname, string Lname);
        void GetInfo(){
            cout << "Student: " << endl;
            Person::GetInfo();
            cout << "   StudentID: " << ID << endl;
       };

       // Replaces student id if nessesary, Specific to this class
       void NewStudentID();

    private:
        int ID;
        
};




// Default constructors if no values are given
Person::Person():Fname("Unknown"), Lname("Unknown") {}

Person::Person(string Fname, string Lname){
    this->Fname = Fname;
    this->Lname = Lname;
};

void Person::SetFirstName(string Fname){
    this->Fname = Fname;
};

void Person::SetLastName(string Lname){
    this->Lname = Lname;
};



// student constructor funciton. ID is a randomly assigned interger Range(3128 -> 4128)
Student::Student(string Fname, string Lname){
    this->Fname = Fname;
    this->Lname = Lname;
    this->ID = rand() % 1000 + 3128;
};



int main(){
    vector <Person> People;
    vector <Student> Students;

    string RandomPeopleValues[5][2] = {{"Cris", "Sanchez"}, {"Peter", "Velazques"}, {"Leroy", "Jankins"}, {"David", "Potter"}, {"Alexander", "Smith"}};

    string RandomPeopleValues2[5][2] = {{"Alex", "Lincoln"}, {"Steve", "Harvey"}, {"Vin", "Diesel"}, {"Henry", "Underwood"}, {"Chad", "Zmolek"}};


    // Creating Objects from calsses using pre existing 2D arrays.
    for(int i = 0; i < 5; i++){
        People.push_back(Person(RandomPeopleValues[i][0], RandomPeopleValues[i][1]));
        Students.push_back(Student(RandomPeopleValues2[i][0], RandomPeopleValues2[i][1]));

    }

    // Looping through calls
    for(int i = 0; i<People.size(); i++){
        People[i].GetInfo();
    };


    for(int i = 0; i<People.size(); i++){  // Students have a class-specific void "newID()"
        Students[i].GetInfo();
    };

    return 0;
}

