/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: November 8, 2022 @ 8:33 PM
 * Purpose: Design an Inventory class that can hold information and calculate data
 * for items in a retail store's inventory
 */

//System Libraries
#include "Inventory.h"
#include <string>
#include <iomanip>
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
    int num,qty;
    float cost;

    //Initial Variables
    cout<<"Enter Item Information"<<endl;
    cout<<"Enter Item Number: ";
    cin>>num;
    cout<<"Enter Item Quantity: ";
    cin>>qty;
    cout<<"Enter Item Per-Unit Cost: $";
    cin>>cost;
    Inventory item(num,qty,cost);
    
    //Map the Inputs to the Outputs
//
//    //Display the Inputs and Outputs
    cout<<fixed<<setprecision(2);
    cout<<"Item Total Cost: $"<<item.getTotalCost()<<endl;

    //Clean up the dynamic stuff

    //Exit the code
    return 0;
}

