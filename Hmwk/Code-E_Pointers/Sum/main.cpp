/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: September 22, 2022 @ 1:17 PM
 * Purpose: Create a parallel array that represents the successive 
 * sum of preceding members in the array
 */

//System Libraries
#include <iostream>  //Input/output Library
using namespace std;

//User Libraries

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only

//Function Prototypes
int *getData(int &);             //Return the array size and the array from the inputs
int *sumAry(const int *,int);   //Return the array with successive sums
void prntAry(const int *,int);  //Print the array

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Declare Variables
    int *array=nullptr,
        *sumArr=nullptr,
        size;
    
    //Initial Variables
    cin>>size;
    
    //Map the Inputs to the Outputs
    //Fill the array 
    array=getData(size);    
    
    //Create parallel array w successive sums
    sumArr=sumAry(array,size);

    //Display the Inputs and Outputs
    prntAry(array,size);
    cout<<endl;
    prntAry(sumArr,size);
    
    //Free memory
    delete [] array;
    array=nullptr;
    delete [] sumArr;
    sumArr=nullptr;

    //Exit the code
    return 0;
}

int *getData(int &size) {
    int *arr=nullptr;
    
    //Dynamically allocate array large enough
    arr=new int[size];    
    //Take in values for array
    for(int i=0;i<size;i++) {
        cin>>*(arr+i);
    }

    return arr; 
}

int *sumAry(const int *arr,int size) {
    int sum, *sumArr=nullptr;
    
    sum=0; 
    
    //Dynamically allocate array
    sumArr=new int[size];
    for(int i=0;i<size;i++) {
        sum+=*(arr+i);
        *(sumArr+i)=sum;
    }
    
    return sumArr;
}

void prntAry(const int *arr,int size) {
    for(int i=0;i<size;i++) {
        cout<<*(arr+i);
        if(i!=size-1) cout<<" ";
    }
}