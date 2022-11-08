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
int *fill1D(int);
void prntAry(DynAry1 *,int);
void destroy(DynAry1 *);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables Here
    int size=100;
    int *dynAry=fill1D(size);      //Dynamically allocate array
    DynAry1 *array1D=new DynAry1;
    array1D->setSize(size);
    array1D->setAry(dynAry);
        
    //Print the values in the array
    prntAry(array1D,10);
    
    //Cleanup
    destroy(array1D);
    
    //Exit
    return 0;
}

int *fill1D(int n){
    int *a=new int[n];
    //Filling the data in the array
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;
    }
    return a;
}

void prntAry(DynAry1 *d1,int perLine) {
    cout<<endl;
    for(int i=0;i<d1->getSize();i++) {
        cout<<d1->getData(i)<<" ";
        if(i%perLine==(perLine-1)) cout<<endl;
    }
}

void destroy(DynAry1 *d1){
    delete d1;        //Reallocate the structure
}
