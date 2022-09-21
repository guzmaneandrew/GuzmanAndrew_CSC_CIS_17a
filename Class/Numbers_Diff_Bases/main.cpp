/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created on September 20, 2022, 8:13 PM
 * Purpose: Shows numbers in different bases in a program
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

    //Declare Variables
    unsigned char b10,b16,b8,b2;

    //Initial Variables
    b10=159;
    b16=0x9F;
    b8=0237;
    b2=0b10011111;

    //Map the Inputs to the Outputs

    //Display the Inputs and Outputs
    cout<<"Base 10 = "<<static_cast<int>(b10)<<endl;
    cout<<"Base 16 = "<<static_cast<int>(b16)<<endl;
    cout<<"Base  8 = "<<static_cast<int>(b8)<<endl;
    cout<<"Base  2 = "<<static_cast<int>(b2)<<endl;
    
    //Exit the code
    return 0;
}

