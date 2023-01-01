#include <vector>
#include <iostream>




using namespace std;




int main(){

    vector<int> main = {1,23,43,23};



    for(auto &index: main){
        cout << index << endl;
    };

    main.erase(2);
    cout << endl;
    
    for(auto &index: main){
        cout << index << endl;
    };


    return 0;
}