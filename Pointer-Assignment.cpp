#include <iostream>
using namespace std;

int main() {
    float price1;
    float price2;

    // input prices from the user
    cout << "Enter id 1: ";
    cin >> price1;
    cout << "Enter id 2: ";
    cin >> price2;

    float* pricePtr;

    /* TODO: Your solution goes here.
    
       Update pricePtr so the output is correct.
       Do not change anything else. */
    
    if(price1>price2){
        pricePtr = &price1;
    }
    else if(price2>price1){
        pricePtr = &price2;
    }
    else{
        pricePtr = nullptr;
    };

    // output message to the user
    if (pricePtr == nullptr) {
        cout << "The prices are the same." << endl;
    } else {
        cout << "The largest price is " << *pricePtr << "." << endl;
    }
}