#include <iostream>
#include <vector>
#include <array>
#include <string>



using namespace std;


// Base ship class, with protected Parametrers: Year Built, and name
class Ship {
    public:
        Ship(string name, string year);
        virtual void shipInfo();

    protected:
        string name;
        string yearBuilt;
};



// Cruise ship class. Inherits protected objects, and over-rides shipInfo() function
class CruiseShip : public Ship {
    public:
        CruiseShip(string name, string year, int maxP)  // 3 parameters, two are used to instanciate the base class method
            :Ship(name, year)
             {
                this->maxPassengers = maxP;
             };
        void shipInfo() override; // Overrides pervious method

    private: 
        int maxPassengers;
};

class CargoShip: public Ship{

    public: 
        CargoShip(string name, string yearBuilt, int tonnage): // Same method of calling base class constructors.
            Ship(name, yearBuilt){
               this->tonnage = tonnage; 
            };

    void shipInfo() override;

    private:
        int tonnage;
};



Ship::Ship(string name, string year){
    this->name = name;
    this->yearBuilt = year;
}


void Ship::shipInfo(){
    cout <<"Ship: " <<  name << endl <<  " Year Built: " <<  yearBuilt << endl;
    cout << endl;
};

void CruiseShip::shipInfo(){
    cout <<"Ship: " <<  name << endl;
    cout << "  Maximum Passengers: " << maxPassengers << endl;;
    cout << endl;
};

void CargoShip::shipInfo(){
    cout <<"Ship: " <<  name << endl;
    cout << "  Cargo Capacity: " <<  tonnage << " Ton(s)" <<  endl;
    cout << endl;
};





int main(){
    vector<Ship*> ShipList;  // Vector with a pointer to the Base class
    

                    // Three constrcutors to each class
    Ship* shipPtr; 

    CruiseShip* cruiseShipPtr; 

    CargoShip* cargoPtr;


                    // Creation of the three classes and stored within the pointers
    shipPtr = new Ship("Enola", "2012");
    cruiseShipPtr = new CruiseShip("Cruiser", "2014", 1200);
    cargoPtr = new CargoShip("FlightsRus", "2014" , 24003);



    ShipList.push_back(shipPtr);
    ShipList.push_back(cruiseShipPtr);
    ShipList.push_back(cargoPtr);


    // For loop of each item within the vector "ShipList".
    for(int i = 0; i<ShipList.size(); i++ ){
        ShipList.at(i)->shipInfo(); // Calls each objects personal method using its personal memory adress.
    }


    return 0;
}