/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: October 24, 2022 @ 1:15 PM
 * Purpose: Card Elements: Create class for card
 */

//System Libraries
#include <iostream>  //Input/output Library
#include <iomanip>
using namespace std;

//User Libraries
#include "Card.h"

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only

//Structure Definitions

//Function Prototypes

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Initialize the Random Number Seed

    //Declare Variables

    //Initial Variables
    for(int i=0;i<52;i++) {
        Card card;
        card.setNum(i);
        cout<<"Card "<<setw(2)<<i+1<<": "<<card.fVal()<<card.sVal()<<" ";
        cout<<"Card Count Value= "<<card.nVal()<<endl; 
    }

    //Map the Inputs to the Outputs

    //Display the Inputs and Outputs

    //Clean up the dynamic stuff

    //Exit the code
    return 0;
}