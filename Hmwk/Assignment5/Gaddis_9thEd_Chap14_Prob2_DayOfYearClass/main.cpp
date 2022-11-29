/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: November 11, 2022 @ 10:53 PM
 * Purpose: Create DayOfYear class to take an integer representing the day of 
 * the year and translates it to a string consisting of the month and day.
 */

//System Libraries
#include "DayOfYear.h"
#include <iostream>  //Input/output Library
using namespace std;

//User Libraries

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only

//Structure Definitions

//Function Prototypes

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Initialize the Random Number Seed

    //Declare Variables
    int input;

    //Initial Variables
    cout<<"Enter a number 1 to 365: ";
    cin>>input;
    DayOfYear day(input);

    //Map the Inputs to the Outputs

    //Display the Inputs and Outputs
    day.print();

    //Clean up the dynamic stuff

    //Exit the code
    return 0;
}

