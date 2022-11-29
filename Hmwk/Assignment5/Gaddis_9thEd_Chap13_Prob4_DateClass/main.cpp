/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: November 8, 2022 @ 8:32 PM
 * Purpose: Write a Car class.
 */

//System Libraries
#include "Car.h"
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
    Car c(2003,"Toyota");

    //Initial Variables

    //Map the Inputs to the Outputs
    cout<<"Car Information: "<<c.getYrMdl()<<" "<<c.getMake()<<endl;
    cout<<"Current Speed: "<<c.getSpeed()<<" MPH"<<endl;
    cout<<"Calling the accelerate function 5 times..."<<endl;
    c.accelerate();
    c.accelerate();
    c.accelerate();
    c.accelerate();
    c.accelerate();
    cout<<"Current Speed: "<<c.getSpeed()<<" MPH"<<endl;
    cout<<"Calling the break function 5 times..."<<endl;
    c.brake();
    c.brake();
    c.brake();
    c.brake();
    c.brake();
    cout<<"Current Speed: "<<c.getSpeed()<<" MPH"<<endl;

    //Display the Inputs and Outputs

    //Clean up the dynamic stuff

    //Exit the code
    return 0;
}

