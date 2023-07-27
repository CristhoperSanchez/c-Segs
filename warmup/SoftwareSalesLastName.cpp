
#include <iostream>
#include <string>



using namespace std;



int main(){
    // Message Variable
    string message = "Enter the Quantity of Units sold:";

    // temp will catch junk, input is users value, satus calls a function that makes sure input is valid
    int temp,input,status;
    
    cout << message;
    status = scanf("%d", &input);

    // While loop until criteria is met: Interger Values, Anything < 1 is not allowed
    while(status!=1 || input < 0){
        cout << message << endl;
        while((temp=getchar()) != EOF && temp!='\n' );
        if(status == 1 && input < 0){
            cout << "Athing less than 1 is not a sale." << endl;
        }
        else{
            cout << "Use numbers: ";
        }
        status = scanf("%d", &input);
    }





    // Decending statements to return the appropriate discount.
        if(input>=100){
            cout << "The sale gets 50% Discount" << endl;
        }
        else if(input>=50){
            cout << "The sale gets 40% Discount" << endl;
        }
        else if(input>=20){
            cout << "The sale gets 30% Discount" << endl;
        }
        else if(input>10){
            cout << "The sale gets 20% Discount" << endl;
        }
        else{
            cout << "There is no discount for that amount of sales." << endl;
        }

    return 0;
}