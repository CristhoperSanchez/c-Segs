#include <iostream>
#include <string>


using namespace std;





// Function, takes in pointers to the memory location. 
void returnToPointers(string* firstName, string* lastName){

    // function string variable declarations.
    string first, last;

    cout << "Enter a first and last name: " << endl;

    cin >> first >> last;

        //  Derefrencing to memory location
    *firstName = first;
    *lastName = last;

}


int main(){
    string localFirst, localLast;



    returnToPointers(&localFirst, &localLast);



    // Local Variables that were updated from the function call are now outputed
    cout << "First name: " << localFirst << endl <<  "Last name: " << localLast << endl;
    return 0;
}