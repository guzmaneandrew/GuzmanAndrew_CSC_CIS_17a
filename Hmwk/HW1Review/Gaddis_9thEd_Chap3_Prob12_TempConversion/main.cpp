/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created on September 7, 2022, 11:40 PM
 * Purpose: Converts Celsius temperatures to Fahrenheit temperatures
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

    cout << "Celsius to Fahrenheit Conversion" << endl;
    
    //Declare Variables
    float degC, degF; //degrees Celsius, degrees Fahrenheit
    
    //Initial Variables
    cout << "Enter temperature in degrees Celsius: ";
    cin >> degC;

    //Map the Inputs to the Outputs
    degF = static_cast<float>(9) / 5 * degC + 32; 

    //Display the Inputs and Outputs
    cout << degC << "°C = " << degF << "°F" << endl;

    //Exit the code
    return 0;
}

