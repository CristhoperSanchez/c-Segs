#include <iostream>
#include <string>
#include <array>

using namespace std;




int main(){

string myArray[3] = {"test", "Testing", "Leaving"};


for(auto &index: myArray){
    cout << index << endl;
}



 return 0;
}