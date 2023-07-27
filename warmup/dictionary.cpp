#include <iostream>
#include <map>
#include <string>

using namespace std;


int main(){

    map <string,string> dictionary ={
        { "One", "menu"},
        { "Two", "list"},
        {"Three", "Mexico"}
    };


    cout << dictionary.find("Two")->second;


    return 0;
}