/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: November 8, 2022 @ 8:31 PM
 * Purpose: Design Date Class. Print the date in multiple forms.
 */

//System Libraries
#include <iostream>  //Input/output Library
#include "Date.h"
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
    Date date;
    
    //Initial Variables
    date.setMonth();
    date.setDay();
    date.setYear();

    //Map the Inputs to the Outputs

    //Display the Inputs and Outputs
    date.printv1();
    date.printv2();
    date.printv3();

    //Clean up the dynamic stuff

    //Exit the code
    return 0;
}

