#include <iostream>
#include <fstream>

using namespace std;


int main(){
    // String where user input will be stored to locate the fiel
    string filename;
    ifstream inFS;

    int filenums;
    string studentName;
    cout << "Enter file name:" <<endl;
    cin >> filename;

    cout << "Opening file:  " << filename << endl;

    inFS.open(filename);

    // catch in case the file does not open/doesn't exist
    if (!inFS.is_open()) {
        cout << "Could not read the file" << filename <<endl;
        return 1;
    }

    while (!inFS.fail()) {
        inFS >> studentName;
        inFS >> filenums;
        // Takes in the sutdent name and exports the average
        cout << studentName << (filenums / filenums.length);
        
        // Clears the variables
        inFS.clear();
        
    }


    inFS.close();
    cout << "End of file, closing..." << endl;
}
