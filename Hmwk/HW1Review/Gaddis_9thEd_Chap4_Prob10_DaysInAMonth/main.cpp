/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created on September 7, 2022, 11:44 PM
 * Purpose: Displays number of days in a given month.
 */

//System Libraries
#include <iostream>  //Input/output Library
using namespace std;

//User Libraries

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only

//Function Prototypes

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Set the Random Number Seed

    cout << "Days in Month" << endl;
    
    //Declare Variables
    int numDays,    //number of days
        month,
        year;
    bool leapYr;    //flag to determine whether a year is a leapYear

    //Initial Variables
    cout << "Enter a month (1-12): ";
    cin >> month;
    cout << "Enter a year:  ";
    cin >> year;

    //Map the Inputs to the Outputs
    
    //Determine whether input year is a leap year
    // (year divisible by 100 AND 400) OR (year not divisible by 100 AND divisible by 4)
    if((year%100 == 0 && year%400 == 0) || (year%100 != 0 && year%4 == 0)) {
        leapYr = true;
    }else leapYr = false;
    
    //Determine number of days for a given month in a given year
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || 
            month == 10 || month == 12) {
        numDays = 31;
    } else if(month == 4 || month == 6 || month == 9 || month == 11) {
        numDays = 30;
    } else if(month == 2 && !leapYr) {   //Leap year
        numDays = 28;
    } else if(month == 2 && leapYr) {  //Non-leap year
        numDays = 29;
    }

    //Display the Inputs and Outputs
    cout << numDays << " days";

    //Exit the code
    return 0;
}

