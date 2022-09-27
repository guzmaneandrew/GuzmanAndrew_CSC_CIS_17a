/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: September 22, 2022 @ 12:58 PM
 * Purpose: Sort array in reverse order
 */

//System Libraries
#include <iostream>  //Input/output Library
using namespace std;

//User Libraries

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only

//Function Prototypes
int *getData(int &);            //Fill the array
int *sort(const int *,int);     //Sort smallest to largest
int *reverse(const int *,int);  //Sort in reverse order
void prntDat(const int *,int);  //Print the array

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Declare Variables
    int *array=nullptr, 
        *srtdArr=nullptr,   
        *revArr=nullptr,
        size;

    //Initial Variables
    cin>>size;
    
    //Map the Inputs to the Outputs
    //Fill the array 
    array=getData(size);             
    srtdArr=sort(array,size);   
    revArr=reverse(srtdArr,size);

    //Display the Inputs and Outputs
    prntDat(srtdArr,size);
    cout<<endl;
    prntDat(revArr,size);
    
    //Free memory
    delete [] array;
    array=nullptr;
    delete [] srtdArr;
    srtdArr=nullptr;
    delete [] revArr;
    revArr=nullptr;

    //Exit the code
    return 0;
}

int *getData(int &size) {
    int *arr=nullptr;
    
    //Dynamically allocate array large enough
    arr=new int[size];    
    for(int i=0;i<size;i++) {
        cin>>*(arr+i);
    }

    return arr; 
}

int *sort(const int *arr,int size) {
    int *srtdArr=nullptr,
        temp;
    
    //Create copy of array to sort (*arr points to const int)
    srtdArr=new int[size];        
    for(int i=0;i<size;i++) {
        *(srtdArr+i)=*(arr+i);
    }
   
    //Sort the array in ascending order
    for(int i=0;i<size;i++) {
        for(int j=i+1;j<size;j++) {
            if(*(srtdArr+i)>*(srtdArr+j)) {
                temp=*(srtdArr+i);
                *(srtdArr+i)=*(srtdArr+j);
                *(srtdArr+j)=temp;
            }
        }
    }
    
    return srtdArr;
}

int *reverse(const int * arr,int size) {
    int *revArr=nullptr,
        temp;
    
    //Create copy of array to sort (*arr points to const int)
    revArr=new int[size];       //
    for(int i=0;i<size;i++) {
        *(revArr+i)=*(arr+i);
    }
    
    //Sort the array in descending order
    for(int i=0;i<size;i++) {
        for(int j=i+1;j<size;j++) {
            if(*(revArr+i)<*(revArr+j)) {
                temp=*(revArr+i);
                *(revArr+i)=*(revArr+j);
                *(revArr+j)=temp;
            }
        }
    }
    
    return revArr;
}

void prntDat(const int *arr,int size) {
    for(int i=0;i<size;i++) {
        cout<<*(arr+i);
        if(i!=size-1) cout<<" ";
    }
}