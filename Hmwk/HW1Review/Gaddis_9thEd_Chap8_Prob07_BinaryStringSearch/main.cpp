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
void selectionSort(string[], int);
void swap(string &, string &);
int binarySearch(const string [], int, string);
void prntArr(string[], int);

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Set the Random Number Seed

    //Declare Variables
    const int NUM_NAMES = 20;
    string name;    //name to search for
    int position; //position name found at

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
    
    selectionSort(names, NUM_NAMES);    //Sort array for binary search
    cout << "SORTED LIST OF NAMES" << endl;
    prntArr(names, NUM_NAMES);
    
    //Map the Inputs to the Outputs
    cout << "Enter a name to search: ";
    getline(cin, name);
    //Determine position name is in array
    position = binarySearch(names, NUM_NAMES, name);

    //Display the Inputs and Outputs
    if(position == -1) {
        cout << name << " was not found." << endl;
    } else {
        cout << names[position] << " was found at position " << position << "." << endl;
    }

    //Exit the code
    return 0;
}

void selectionSort(string array[], int size) {
    int minIndex;   //Index of minimum string
    string minStr;  //String with smallest value
    
    for(int i = 0; i < size; i++) {
        minIndex = i;   //Start with index 0 as min index
        minStr = array[minIndex];
        for(int j = i + 1; j < size; j++) {
            if(minStr > array[j]) { //Compare strings
                minIndex = j;
                minStr = array[minIndex];       
            }
        }
        swap(array[minIndex], array[i]);//swap current min string with new min string
    }
}

void swap(string &str1, string &str2) {
    string temp;
    
    temp = str1; 
    str1 = str2;
    str2 = temp;
}

int binarySearch(const string array[], int size, string name) {
    int first = 0,          //First array element
        last = size - 1,    //Last array element
        middle,             //Mid point
        position = -1;      //Position of string to search
    bool found = false;     //Flag
    
    while(found==false && first<=last) {
        middle = (first + last) / 2; //calculate mid point
        if(array[middle] == name) {         //If string found at mid point
            found = true;
            position = middle;
        } else if(array[middle] > name) {   //If string is in lower half
            last = middle - 1;
        } else {
            first = middle + 1;             //If string is in upper half
        }
    }
    return position;
}

void prntArr(string array[], int size) {
    for(int i = 0; i < size; i++) {
        cout << array[i] << endl;
    }
    cout << "----------"<< endl;
}