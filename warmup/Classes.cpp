#include <iostream>

using namespace std;

class Person{
    public:
        void SetName(string nameToSet);
        void SetAge(int newAge);
        string GetName() const;
        int GetAge() const;

    private:
        string name;
        int age;

};


void Person::SetName(string nameToSet){
    name = nameToSet;
}

string Person::GetName() const{
    return name;

}


void Person::SetAge(int newAge){
    age = newAge;
}

int Person::GetAge() const{
    return age;
}


int main(){
    string userName;
    Person person1;

    userName = "Bob";
    person1.SetName(userName);
    person1.SetAge(21);
    cout << "He is " << person1.GetName() << endl;
    cout << "and he is " << person1.GetAge() << " years old"; 

    return 0;
}