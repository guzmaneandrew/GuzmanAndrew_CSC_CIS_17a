/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: September 21, 2022 @ 12:34 AM
 * Purpose:
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
    float fract,sum;
    int nSums;

    //Initial Variables
    sum=0;
    fract=0.5f;
    //fract=0.1f;
    nSums=10000000;

    //Map the Inputs to the Outputs
    for(int i=0;i<nSums;i++) {
        sum+=fract;
    }

    //Display the Inputs and Outputs
    cout<<"Sum "<<fract<<" nTimes "<<nSums<<" = "<<sum<<endl;
    cout<<"Sum using multiplication = " <<fract*nSums<<endl;

    //Exit the code
    return 0;
}

