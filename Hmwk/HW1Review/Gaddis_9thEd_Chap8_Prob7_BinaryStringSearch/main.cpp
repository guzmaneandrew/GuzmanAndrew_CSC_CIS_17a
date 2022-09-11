/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created on September 7, 2022, 11:53 PM
 * Purpose: Binary search an array of strings.
 */

//System Libraries
#include <iostream>  //Input/output Library
#include <string>
using namespace std;

//User Libraries

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only

//Function Prototypes
int binarySearch(const int[], int, int);

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Set the Random Number Seed

    //Declare Variables
    const int NUM_NAMES = 20;

    //Initial Variables
    string names[NUM_NAMES] = {
        "Collins, Bill", "Smith, Bart", "Allen, Jim",
        "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
        "Taylor, Terri", "Johnson, Jill", "Allison, Jeff",
        "Looney, Joe", "Wolfe, Bill", "James, Jean",
        "Weaver, Jim", "Pore, Bob", "Rutherford, Greg",
        "Javens, Renee", "Harrison, Rose", "Setzer, Cathy",
        "Pike, Gordon", "Holland, Beth"
    };

    //Map the Inputs to the Outputs

    //Display the Inputs and Outputs


    //Exit the code
    return 0;
}

int binarySearch(const int array[], int numElems, int value) {
    int first = 0,            //first array element
        last = numElems - 1, //last array element
        middle,              //midpoint of search
        position = -1;      //position of search value
    bool found = false;     //flag
    
    while(!found && first <= last) {
        middle = (first + last) / 2; //calculate midpoint
        if(array[middle] == value) {  //if value is found at mid
            found = true;
            position = middle;
        } else if(array[middle] > value) { //if value is in lower half
            last = middle - 1;
        } else {
            first = middle + 1;
        }
        return position;
    }
}
