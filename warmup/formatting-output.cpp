
#include <iostream>
#include <math.h>
using namespace std;



// Cristhoper Sanchez
int main() {

    float interest; 
    int cTimes, principal;
    double savingsA, power;



    cout << "Enter the principal: " << endl;
    cin >> principal;

    cout << "Enter the interest rate (as a percent):" << endl;
    cin >> interest;

    cout << "Enter the number of times compounded:" << endl;
    cin >> cTimes; 



    /* Variables get tinkered with:
        interest gets devided by 100 for a decimal 
        to work within the equation
        the pow function is used
        and then iserted into savings*/
    interest = interest/100;
    power = pow((1+interest/cTimes), cTimes );
    savingsA = principal * power;


    cout << "Amount in savings: $ " << savingsA << endl;


    return 0 ;
}