/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created on September 7, 2022, 11:42 PM
 * Purpose: Converts U.S. dollar amounts to Japanese yen and to euros
 */

//System Libraries
#include <iostream>  //Input/output Library
#include <iomanip>  
using namespace std;

//User Libraries

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only

//Function Prototypes

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Set the Random Number Seed

    cout << "Currency Conversion" << endl;
    
    //Declare Variables
    const float YEN_PER_DOLLAR = 144.01;
    const float EUROS_PER_DOLLAR = 1.00;
    float dollar, yen, euro;
    
    //Initial Variables
    cout << "Enter a dollar amount: $";
    cin >> dollar;
    
    //Map the Inputs to the Outputs
    yen = YEN_PER_DOLLAR * dollar;
    euro = EUROS_PER_DOLLAR * dollar;

    //Display the Inputs and Outputs
    cout << setprecision(2) << fixed;
    cout << dollar << " US Dollars = " << yen << " Japanese Yen" << endl;
    cout << dollar << " US Dollars = " << euro << " Euros" << endl;
    //Exit the code
    return 0;
}

