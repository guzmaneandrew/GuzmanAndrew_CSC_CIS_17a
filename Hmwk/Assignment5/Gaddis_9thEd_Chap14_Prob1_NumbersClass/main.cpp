/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: November 11, 2022 @ 10:51 PM
 * Purpose: Create Numbers class to translate whole dollar amounts in the range
 * 0 to 9999 into an English description of the number.
 */

//System Libraries
#include <iostream>  //Input/output Library
#include "Numbers.h"
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
    int num2wrd;
   
    //Initial Variables
    cout<<"Enter a number 0 to 9999: ";
    cin>>num2wrd;
    //Define a Numbers object
    Numbers number(num2wrd);

    //Map the Inputs to the Outputs

    //Display the Inputs and Outputs
    number.print();

    //Clean up the dynamic stuff

    //Exit the code
    return 0;
}

