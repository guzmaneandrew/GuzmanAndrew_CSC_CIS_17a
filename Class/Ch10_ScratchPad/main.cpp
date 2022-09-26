/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: September 25, 2022 @ 6:08 PM
 * Purpose: Ch 10 Scratch pad
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
    //Initialize the Random Number Seed

    //Declare Variables 

    //Initial Variables

    //Map the Inputs to the Outputs

    //Display the Inputs and Outputs
    for(int i=0;i<26;i++) {
        char letter='a'+i;
        cout<<"lower case "<<static_cast<char>(letter)<<" vs. upper case "
                <<static_cast<char>(letter-32)<<endl;
    }
    
    for(int i=0;i<=127;i++) {
        cout<<static_cast<char>(i);
        if(i%32==31) cout<<endl;
    }

    //Exit the code
    return 0;
}

