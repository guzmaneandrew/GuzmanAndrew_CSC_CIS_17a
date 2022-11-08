/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on September 29th, 2021, 12:55 PM
 * Purpose:  Class 1D Dynamic Array
 */

//System Libraries Here
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

//User Libraries Here
#include "ClassArray1D.h"

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions and Array Dimension


//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables Here
    int size=100;
    DynAry1 *array1D=new DynAry1;
    array1D->setSize(size);
        
    //Print the values in the array
    array1D->prntAry(10);
    array1D->setAry(500,50);
    array1D->prntAry(10);
    
    //Cleanup
    delete array1D; 
    
    //Exit
    return 0;
}
