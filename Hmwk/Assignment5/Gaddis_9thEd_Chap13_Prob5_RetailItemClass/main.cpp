/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: November 8, 2022 @ 8:33 PM
 * Purpose: Write a class RetailItem that holds data about an item in a retail store
 */

//System Libraries
#include "RetailItem.h"
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
    RetailItem item1("Jacket",12,59.95);
    RetailItem item2("Designed Jeans",40,34.95);
    RetailItem item3("Shirt",20,24.95);
    
    cout<<"Creating New Item for Database..."<<endl;
    RetailItem item4;
    item4.setDesc();
    item4.setUnits();
    item4.setPrice();

    //Initial Variables

    //Map the Inputs to the Outputs

    //Display the Inputs and Outputs
    cout<<fixed<<setprecision(2);
    cout<<setw(20)<<"Description"<<
          setw(15)<<"Units On Hand"<<
          setw(10)<<"Price"<<endl;
    cout<<setw(20)<<item1.getDesc()<<
          setw(15)<<item1.getUnits()<<" "<<
          setw(10)<<item1.getPrice()<<endl;
    cout<<setw(20)<<item2.getDesc()<<
          setw(15)<<item2.getUnits()<<" "<<
          setw(10)<<item2.getPrice()<<endl;
    cout<<setw(20)<<item3.getDesc()<<
          setw(15)<<item3.getUnits()<<" "<<
          setw(10)<<fixed<<setprecision(2)<<item3.getPrice()<<endl;
    cout<<setw(20)<<item4.getDesc()<<
          setw(15)<<item4.getUnits()<<" "<<
          setw(10)<<fixed<<setprecision(2)<<item4.getPrice()<<endl;
    

    //Clean up the dynamic stuff

    //Exit the code
    return 0;
}

