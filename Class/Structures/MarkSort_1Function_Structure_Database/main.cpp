/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on September 26, 2022
 * Purpose:  Implementation structure database sort by index ->
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
Array *fillAry(int);
void prntAry(const Array *,int);
void markSrt(Array *);

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables here
    int size=100;               //
    Array *array;               //Create pointer reference
    
    //Initialize variables here
    array=fillAry(size);        //Fill the array structure
    
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
    delete []array->data;    //Delete the data elements INSIDE the Array structure
    delete array;           //Delete the Array structure itself

    //Exit stage left
    return 0;
}

void markSrt(Array *a){
    for(int pos=0;pos<a->size-1;pos++){//Works on each position in the list
        for(int i=pos+1;i<a->size;i++){//Compare and swap with lower elements in the list
            if(a->data[a->index[pos]]>a->data[a->index[i]]){//Swap
                a->index[pos]=a->index[pos]^a->index[i];
                //same as: 
                //a->index[pos]=a->index[pos]^a->index[i];
                (*a).index[i]=*(a->index+pos)^a->index[i];
                //same as:
                //a->index[i]=a->index[pos]^a->index[i];
                //same as: to use dot op, need parens around *a
                //(*a).index[pos]=a->index[pos]^a->index[i];
                //same as: to use pointer notation, need parens around *a.data+pos
                *((*a).index+pos)=a->index[pos]^a->index[i];
            }
        }
    }
}

void prntAry(const Array *a,int perLine){
    cout<<endl;
    for(int i=0;i<a->size;i++){
        cout<<a->data[a->index[i]]<<" ";      //Print out w respect to the index
        if(i%perLine==perLine-1)cout<<endl;
    }
    cout<<endl;
}

Array *fillAry(int size){
    Array *a=new Array;       //Dynamically create the structure
    
    a->data=new int[size];    //Dynamically point the data to that element inside struct
    a->index=new int[size];
    a->size=size;             //Set the size
    
    for(int i=0;i<a->size;i++){              //Fill data inside structure one by one
        a->data[i]=rand()%90+10;//[10,99]    
        a->index[i]=i;
    }
    
    return a;               //Return structure
}