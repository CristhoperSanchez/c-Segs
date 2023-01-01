#include <iostream>
using namespace std;

#include "StoreItem.h"

void StoreItem::SetWeightOunces(int ounces) {
    weightOunces = ounces;
}

void StoreItem::Print() const {
    cout << "Weight in ounces: " << weightOunces << endl;
}