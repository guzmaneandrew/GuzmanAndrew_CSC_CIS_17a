/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: October 24, 2022 @ 1:15 PM
 * Purpose: Card Elements: Create functions to get face value, suit value, and 
 * numerical value
 */

//System Libraries
#include <iostream>  //Input/output Library
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only

//Structure Definitions

//Function Prototypes
char fVal(int); //Face value
char sVal(int); //Suit value
int nVal(int); //Numerical value

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Initialize the Random Number Seed

    //Declare Variables

    //Initial Variables
    for(int i=0;i<52;i++) {
        cout<<"Card "<<setw(2)<<i+1<<": "<<fVal(i)<<sVal(i)<<" ";
        cout<<"Card Count Value= "<<nVal(i)<<endl; 
    }

    //Map the Inputs to the Outputs

    //Display the Inputs and Outputs

    //Clean up the dynamic stuff

    //Exit the code
    return 0;
}

char fVal(int i) {
    char faceVal[]={'A','2','3','4','5','6','7','8','9','10','J','Q','K'};
    return faceVal[i%13];
}

char sVal(int i) {
    char suits[]={'S','D','C','H'};
    return suits[i/13];
}

int nVal(int i) {
    int val=i%13+1;
    return val>10?10:val;
}