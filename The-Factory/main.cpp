/*  Cristhoper Sanchez */
#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Product {
    private:
        string name;

    public:
        Product(string name1) {name=name1;}
        string getName(){
            return name;
        };

};


class Factory {
    private:
        string location;
        int capacity;

    public:
        Factory(string location1, int capacity1) {location = location1; capacity = capacity1;}
        void makeProduct(Product product);
};



void Factory:: makeProduct(Product product) {
    if (capacity > 0){
        cout << "Factory: " << location << " is now making: " << product.getName() << endl;
    }
    else {
        cout << "Factory out of capacity." << endl;
    }
};





int main() {
    // Code goes here
    vector <Product> Products; // Arrays to store the created Objects;
    vector <Factory> Factories;

    unsigned int index, Findex, Pindex; // Indexes for Product&Factory creation (index), and for calling itteration (Findex; Factory, Pindex; Product)

    vector <string> myProducts = {"RubberDuckys", "Coffee Mugs", "Desks", "NoteBooks", "Water Bottles"}; // Vectors with values for the creation of Objects.
    vector <string> myFactoryLocation = {"Ames, IA", "Flint, MI", "Phoenix, AZ"};
    vector <int> myFactoryCapacity = {10, 22, 14};

    for(index = 0; index < myProducts.size(); index++) {                               // Creating Products from vector iteration
        Products.push_back(Product(myProducts[index]));
    };

    for(index = 0; index < myFactoryLocation.size(); index ++){                             // Creates Factories and passes two Variables one from each array 

        if(myFactoryCapacity.size() == myFactoryLocation.size()){  // Checks to make sure the two vectors have the same amount of values to prevent errors

            Factories.push_back(Factory(myFactoryLocation[index], myFactoryCapacity[index]));
        }
        else{ cout << "Unmached arguments within Vectors...." << endl;}
    };


    Pindex = 0;
    for(Findex = 0; Findex < Products.size(); Findex++){   // Iterates through each factory stored in the vector
        for(index = 0; index < 2; index++) { // Resets teh index for every 2 products
            if(Pindex < Products.size()){ // Only allows the call of makeProduct() if there is a product to make
                Factories[Findex].makeProduct(Products[Pindex]);
                Pindex++;
            }
        }
    }

    return 0;
}