/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on September 26, 2022
 * Purpose:  Implementation of static structures(with dynamic elements inside
 *           of the structure) using references and the dot operator.
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <cstdlib>    //Random function location
#include <ctime>      //Time Library
using namespace std;  //STD Name-space where Library is compiled

//User Libraries
#include "Array.h"

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
void fillAry(Array &);
void prntAry(const Array &,int);
void markSrt(Array &);

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables here
    int size=100;               //Statically declare Array structure
    Array array;               
    array.size=size;            //Set size
    array.data=new int[size];   //Created elements dynamically(data is a pointer)
    
    //Initialize variables here
    fillAry(array);
    
    //Map inputs to outputs here, i.e. the process
    
    //Display the results
    cout<<"Display the Original Random Array"<<endl;
    prntAry(array,10);
    
    //Testing the memory swap function
    markSrt(array);
    
    //Display the results
    cout<<"Apply a loop on smallest in the list n times = Mark Sort"<<endl;
    prntAry(array,10);
    
    //Free memory
    delete []array.data;        //Delete dynamically allocated memory

    //Exit stage left
    return 0;
}

void markSrt(Array &a){
    for(int pos=0;pos<a.size-1;pos++){//Works on each position in the list
        for(int i=pos+1;i<a.size;i++){//Compare and swap with lower elements in the list
            if(a.data[pos]>a.data[i]){//Swap
                a.data[pos]=a.data[pos]^a.data[i];
                a.data[i]=a.data[pos]^a.data[i];
                a.data[pos]=a.data[pos]^a.data[i];
            }
        }
    }
}

void prntAry(const Array &a,int perLine){
    cout<<endl;
    for(int i=0;i<a.size;i++){
        cout<<a.data[i]<<" ";
        if(i%perLine==perLine-1)cout<<endl;
    }
    cout<<endl;
}

void fillAry(Array &a){
    for(int i=0;i<a.size;i++){              //Bring in size 
        a.data[i]=rand()%90+10;//[10,99]    //Set the data
    }
}