#include <iostream>

using namespace std;


int main() {

    const int MAX_HOURS_IN_WEEK = 168;

    const int MAX_WAGE = 100;

    const int LOWER_SALARY = 200;

    const int UPPER_SALARY = 800;


    int hourlyWage;

    int workHoursPerWeek;

    int weeklySalary;


    cout << "How many hours do you work per week?" << endl;

    cin >> workHoursPerWeek;


    // Changed to "Or" statement to check the range.
    if (workHoursPerWeek < 0 || workHoursPerWeek > MAX_HOURS_IN_WEEK) {

        cout << "Invalid number of hours per week." << endl;

        return -1;

    }


    cout << "What is your hourly wage?" << endl;

    cin >> hourlyWage;

    if (hourlyWage > MAX_WAGE) {

        cout << "An hourly wage greater than 100 requires executive approval." << endl;

    } else if (hourlyWage < 0) {

        cout << "Invalid hourly wage." << endl;

        return -1;

    }


    weeklySalary = hourlyWage * workHoursPerWeek;


    if (weeklySalary < LOWER_SALARY) {

        cout << "The weekly salary is less than 200." << endl;

    }
    // and statement added for the comparison to fall between 200 and 800
    if (weeklySalary < UPPER_SALARY && weeklySalary > LOWER_SALARY) {

        cout << "The weekly salary is between 200 and 800." << endl;

    } else {

        cout << "The weekly salary is greater than 800." << endl;

    }


    return 0;

};