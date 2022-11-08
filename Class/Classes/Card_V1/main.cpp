/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: October 24, 2022 @ 1:15 PM
 * Purpose: Card Elements: Show basic way to get suit,face, and numerical values
 * All dependent on int i in for-loop
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

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Initialize the Random Number Seed

    //Declare Variables
    char suits[]={'S','D','C','H'};
    char faceVal[]={'A','2','3','4','5','6','7','8','9','10','J','Q','K'};

    //Initial Variables
    for(int i=0;i<52;i++) {
        int val=i%13+1;
        val=val>i?10:val;
        cout<<"Card "<<setw(2)<<i+1<<": "<<faceVal[i%13]<<suits[i/13]<<" ";
        cout<<"Card Count Value= "<<val<<endl; 
    }

    //Map the Inputs to the Outputs

    //Display the Inputs and Outputs

    //Clean up the dynamic stuff

    //Exit the code
    return 0;
}

