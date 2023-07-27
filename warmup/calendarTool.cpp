#include<iostream>
#include<typeinfo>

using namespace std;

/* 
                Cristhoper Sanchez
 */

// Checking Leap Year for the month of February, takes in intergrer
// These functions should not allow for negative numbers based on program structure.
int checkleap(int year){
    if(year <= 0){
        return 0;
    }
// if, and, or. 
// To meet the qualifications
    if((((year % 4) == 0) && ((year % 100) != 0)) || ((year %4) == 0) && ((year%400) == 0)){
        return 29;
    }


    return 28;
}

// Takes in two parameters, the month for a quick return 
// Year in case it is February that needs to be checked for its leap year.
// These functions should not allow for negative numbers based on program structure.
int month_days(int month, int year){
    int solution; 
    switch (month){
        case 1: 
            solution = 31;
            break;
        case 2: 
            solution = checkleap(year);
            break;
        case 3: 
            solution = 31;
            break;
        case 4: 
            solution = 30;
            break;
        case 5: 
            solution = 31;
            break;
        case 6: 
            solution = 30;
            break;
        case 7: 
            solution = 31;
            break;
        case 8: 
            solution = 31;
            break;
        case 9: 
            solution = 30;
            break;
        case 10: 
            solution = 31;
            break;
        case 11: 
            solution = 30;
            break;
        case 12: 
            solution = 31;
            break;
    }

    return solution;
}



// Valid Month function. That displays repeated message until criteria is met
int validMonth(){
    double month;
    while(true){
        cout << "Enter a Month (1-12): ";
        cin >> month;
        if(month >0 && month < 13){
        break;
        }
        else{
            month = 0;
            cout << "Invalid Month" << endl;
        }
        month = 0;
    }
    return month;
}

// Valid Year function. That displays repeated message until criteria is met
int validYear(){
    int validValue;

    while(true){
        double year;
        cout << "Enter a year:";
        cin >> year;
        if(year > 0){
            validValue = year;
            break;
        }
        else{
            cout << "Invalid Year" << endl;
        }
    }

    return validValue;
}



/* Main function */
int main(){
    int days, month, year;
    string exit;


// True loop for repettition.
    while(true){
        cout << "Enter a month and Year in number format to get the amount of days that month will have." << endl << endl;


    // Functions are called to store the variables, as well as filter for correct input
        month = validMonth();
        year = validYear();
        days = month_days(month, year);



    // Prompt that will display the amount of days on given input
        cout << "There will be " << days << " days on "  << month << "/" << year << "." << endl << endl;
        
        cout << "Would you like to exit? type 'yes' to exit or 'no' to continue." << endl;

        cin >> exit;

// Prompt for exiting program.
        if(exit == "yes"){
            cout << "Goodbye..." <<endl;
            break;
        }
    }

    return 0;

}

#include <QtTest>

class calendarTest : public QObject {

    Q_OBJECT

public:

    calendarTest();

    ~calendarTest();

private slots:

    void test_month();
    
    void leap_year();


};

calendarTest::calendarTest() {

}

calendarTest::~calendarTest() {

}

void calendarTest::test_month() {


    month_days(6, 2022);

    QCOMPARE(30, 30);

}

void calendarTest::leap_year() {

    checkleap(2022)

    QCOMPARE(checkleap(2022), 22);

}

QTEST_APPLESS_MAIN(calendarTest)

#include "tst_calendarTool.moc"