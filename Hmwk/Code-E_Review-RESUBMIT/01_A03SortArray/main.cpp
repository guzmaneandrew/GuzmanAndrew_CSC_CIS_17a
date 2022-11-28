/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created on 9/10/22 20:53
 * Purpose:  Sorting an array of characters if specified correctly
 */

//System Libraries Here
#include <iostream>//cout,cin
#include <cstring> //strlen()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int  read(char []);
void sort(char [],int);
void swap(int &, int &);
void print(const char [],int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    
    //Declare all Variables Here
    const int SIZE = 80; //Larger than needed
    char array[SIZE]; //Character array larger than needed
    int sizeIn, sizeDet; //Number of characters to be read, check against length
    
    //Input the size of the array you are sorting
    cout << "Read in a 1 dimensional array of characters and sort" << endl;
    cout<<"Input the array size where size <= 20"<<endl;
    cin >> sizeIn;
    
    //Now read in the array of characters and determine it's size
    cout << "Now read the Array" << endl;
    cin >> array;
    sizeDet = read(array); //Determine it's size
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size to sort
    if(sizeDet == sizeIn) {
        sort(array, sizeIn); //Sort the array
        print(array, sizeIn);//Print the array
    } else {
        cout << (sizeDet < sizeIn ? "Input size less than specified.":
            "Input size greater than specified.") << endl;
    }
    
    //Exit
    return 0;
}

int read(char array[]) {
    int count;
    
    count = strlen(array);

    return count;
}

void sort(char array[], int size) {
    int maxElement, //subscr of last element to be compared to neighbor
        index;
        
    for(maxElement = size - 1; maxElement > 0; maxElement--) {
        for(index = 0; index < maxElement; index++) {
            if(array[index] > array[index+1]) swap(array[index], array[index+1]);
        }
    }
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void print(const char array[],int size) {
    for(int index = 0; index < size; index++) {
        cout << array[index];
    }
    cout << endl;
}