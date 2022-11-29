/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: November 27, 2022 @ 8:30 PM
 * Purpose: Modify constructors. Create DayOfYear class to take an integer representing the day of 
 * the year and translates it to a string consisting of the month and day.
 */

//System Libraries
#include "DayOfYear.h"
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
    string month;
    int day;

    //Initial Variables
    cout<<"Enter a month: ";
    cin>>month;
    cout<<"Enter a day: ";
    cin>>day;

    //Map the Inputs to the Outputs
    //Testing overloaded ++ operators
    DayOfYear day1(month,day);
    cout<<"\nDay1 = "<<day1.getDayN()<<endl;
    
//    //Display the Inputs and Outputs
    cout<<"\nOverloaded ++ Operators"<<endl;
    cout<<"\nDay2 = ++Day1\n";
    DayOfYear day2=++day1;
    cout<<"Day1: "<< day1.getDayN()<<endl;
    cout<<"Day2: "<<day2.getDayN()<<endl;
    
    cout<<"\nDay3 = Day1++\n";
    DayOfYear day3=day2++;
    cout<<"Day2: "<<day2.getDayN()<<endl;
    cout<<"Day3: "<<day3.getDayN()<<endl;

    //Testing overloaded -- operators
    cout<<"\nOverloaded -- Operators"<<endl;
    cout<<"\nDay4=--Day3\n";
    DayOfYear day4=--day3;
    cout<<"Day3 = "<<day3.getDayN()<<endl;
    cout<<"Day4 = "<<day4.getDayN()<<endl;
    
    cout<<"\nDay6=Day5--\n";
    DayOfYear day5=day4--;
    cout<<"Day4 = "<<day4.getDayN()<<endl;
    cout<<"Day5= "<<day5.getDayN()<<endl;
    
    //Display the Inputs and Outputs
    
    //Clean up the dynamic stuff

    //Exit the code
    return 0;
}

