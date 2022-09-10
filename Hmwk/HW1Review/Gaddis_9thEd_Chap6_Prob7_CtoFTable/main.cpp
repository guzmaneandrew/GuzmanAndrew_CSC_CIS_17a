/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created on September 7, 2022, 11:49 PM
 * Purpose: Displays a table of Fahrenheit temperatures 0 to 20 and Celsius equivalents.
 */

//System Libraries
#include <iostream>  //Input/output Library
#include <iomanip>  // I/O manipulators
using namespace std;

//User Libraries

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only

//Function Prototypes
float celsius(float);

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Set the Random Number Seed

    //Declare Variables

    //Initial Variables

    //Map the Inputs to the Outputs

    //Display the Inputs and Outputs
    cout << right << setw(10) << "Fahrenheit" << setw(9) << right<< "Celsius" << endl;
    
    for(int degF = 0; degF <= 20; degF++) { //loop through Fahrenheit degrees 1 to 20
        cout << fixed << setprecision(2);   //
        cout << right << setw(5)<< degF << "°F" << right << setw(10) << celsius(degF) << "°C" << endl;
    }

    //Exit the code
    return 0;
}

float celsius(float degF) {
    //Set the Random Number Seed

    //Declare Variables
    float celsius;

    //Initial Variables
    celsius = static_cast<float>(5)/9 * (degF - 32);

    //Map the Inputs to the Outputs

    //Display the Inputs and Outputs

    //Exit the code
    return celsius;
}

