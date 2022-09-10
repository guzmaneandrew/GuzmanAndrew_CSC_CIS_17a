/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created on September 7, 2022, 11:45 PM
 * Purpose: Predicts the size of a population of organisms.
 */

//System Libraries
#include <iostream>  //Input/output Library
#include <iomanip>  // I/0 Manipulators
using namespace std;

//User Libraries

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only

//Function Prototypes
bool validateInput(float, float, int);

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Set the Random Number Seed

    cout << "Organism Population Size Increase" << endl;
    
    //Declare Variables
    bool valInpt;   //flag for input validation
    int numDays;//number of days organisms to multiply
    
    float totalPop, //size of population
          incrPrcnt,//avg daily increase percentage
          popIncr;//daily pop increase
   
    //Initial Variables
    valInpt = false;
    
    do {
        cout << "Enter starting number of organisms "
                "(must be greater than or equal to 2): ";
        cin >> totalPop;
        cout << "Enter average daily population increase as a percentage "
                "(must be positive value): ";
        cin >> incrPrcnt;
        cout << "Enter number of days organisms will multiply "
                "(must be greater than or equal to 1): ";
        cin >> numDays;
    
        //validate input
        valInpt = validateInput(totalPop, incrPrcnt, numDays);
    }while(!valInpt);

    //Map the Inputs to the Outputs
    incrPrcnt = incrPrcnt * 1e-2f;  //convert percent to decimal for calculation
    popIncr = totalPop * incrPrcnt; //calculate population increase

    //Display the Inputs and Outputs
    for(int i = 1; i <= numDays; i++) {
        totalPop += popIncr;    //calculate total population
        cout << fixed << setprecision(1);
        //format table to display large values
        cout << "Day " << setw(7) << right << i << ": " <<
                setw(15) << right << totalPop << endl;
    }

    //Exit the code
    return 0;
}

bool validateInput(float totalPop, float incrPrcnt, int numDays) {
    
    if(totalPop < 2 || incrPrcnt < 0 || numDays < 1){
        cout << "Invalid input. Please try again." << endl << endl;
        return false;
    }
    
    return true;
}
