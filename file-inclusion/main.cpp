#include <iostream>
using namespace std;



#include "StoreItem.cpp"


int main(){

    StoreItem item1;

    item1.SetWeightOunces(16);
    item1.Print();
    cout << "Finishing Program..." << endl;

    return 0;
}
