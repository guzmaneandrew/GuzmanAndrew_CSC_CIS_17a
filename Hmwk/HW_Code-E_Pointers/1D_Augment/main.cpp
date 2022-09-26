/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: September 22, 2022 @ 1:20 PM
 * Purpose: Augment a 1-D array by 1 element
 */

//System Libraries
#include <iostream>  //Input/output Library
using namespace std;

//User Libraries

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only

//Function Prototypes

int *getData(int &);//Read the array
int *augment(const int *,int);//Augment and copy the original array
void prntAry(const int *,int);//Print the array

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Declare Variables
    int *array=nullptr,
        *augArr=nullptr,
        size,
        augSize;
    
    
    //Initial Variables
    cin>>size;
    augSize=size+1;
    
    //Map the Inputs to the Outputs
    array=getData(size);
    augArr=augment(array,augSize);

    //Display the Inputs and Outputs
    prntAry(array,size);
    cout<<endl;
    prntAry(augArr,size+1);

    //Free memory
    delete [] array;
    array=nullptr;
    delete [] augArr;
    augArr=nullptr;

    //Exit the code
    return 0;
}

int *getData(int &size) {
    int *arr=nullptr;
    
    //Dynamically allocate array 
    arr=new int[size];  
    //Fill array
    for(int i=0;i<size;i++) {
        cin>>arr[i];
    }

    return arr; 
}

int *augment(const int *arr,int size) {
    int *augArr=nullptr; 
    
    //Dynamically allocate array
    augArr=new int[size];
    //Fill the array
    *(augArr)=0;
    for(int i=0;i<size;i++) {
        *(augArr+i+1)=*(arr+i);
    }
    
    return augArr;
}

void prntAry(const int *arr,int size) {
    for(int i=0;i<size;i++) {
        cout<<*(arr+i);
        if(i!=size-1) cout<<" ";
    }
}

