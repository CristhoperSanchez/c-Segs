#include <iostream>
#include <string.h>
#include <vector>



using namespace std;





// Bunny class
class Bunny{
    public:
        Bunny(string name = "Unnamed");
        virtual void print();
        ~Bunny(){
            cout << "Exterminating bunny: " << this->name << endl;
        }
    
    private:
        string name; 
};


Bunny::Bunny(string name){
    cout << "Bunny created" << endl;
    this->name = name;
}

void Bunny::print(){
    cout << "Bunny name: " << this->name << endl;
}






int main(){

    vector <Bunny*> Bunnies;

    Bunny* bunnyPtr;

    for(int i=0;i<3;i++){
        string name;
        cout << "Enter bunny #" << i+1 << "'s name: ";
        cin >> name;
        bunnyPtr = new Bunny(name);
        Bunnies.push_back(bunnyPtr);
        cin.clear();
    }

    // Loop itteration through bunny vecor, using its pointer to call its independent print() funciton
    for(int i =0; i<Bunnies.size(); i++){
        cout << endl;
        Bunnies[i]->print();
    };

    // Itterating through each item in vector and deleting it.
    for(int i =0; i<Bunnies.size(); i++){
        cout << endl;
        delete Bunnies[i];
    };

    // Simple check to confirm the vector has been cleared
    if(Bunnies.size() > 1){
        cout << "The vector is now empty." <<endl;
    }


    return 0;
}