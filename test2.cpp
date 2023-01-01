#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Business {
public:
    Business(string name, string year){
        this->name = name;
        this->yearBuilt = year;
    };
    void getInfo(){
        cout << "Infomration: " << name << endl;
    };

protected:
   string name;
   string yearBuilt;
};




class Restaurant : public Business {
public:

    Restaurant(string name, string year, int maxP):
        Business(name, year)
        {
            this->MaxPassengers = maxP;
        }

    private:
        int MaxPassengers;
};

int main() {
   vector<Business*> businessList;
   Business* businessPtr;
   Restaurant* restaurantPtr;

   businessPtr = new Business("Enola" ,"2012");


   businessList.push_back(businessPtr);
   businessList.push_back(restaurantPtr);

   businessList.at(0)->getInfo();



   return 0;
}


