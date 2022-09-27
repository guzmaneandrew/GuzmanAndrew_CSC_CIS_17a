/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: September 22, 2022 @ 1:19 PM
 * Purpose: Total elements in 2D array
 */

//System Libraries
#include <iostream>  //Input/output Library
using namespace std;

//User Libraries

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only

//Function Prototypes
int **getData(int &,int &);        //Return the 2-D array and its size.
void prntDat(int **,int,int);//Print the 2-D Array
void destroy(int **,int,int);       //De-allocate memory
int sum(int **,int,int);    //Return the Sum
//Program Execution Begins Here!!!

int main(int argc, char** argv) {
     //Declare Variables
     int **array=nullptr,
         row,
         col,
         arrSum;

    //Initial Variables
    cin>>row>>col;

    //Map the Inputs to the Outputs
    array=getData(row,col);
    arrSum=sum(array,row,col);

    //Display the Inputs and Outputs
    prntDat(array,row,col);
    cout<<arrSum;
    
    //Free memory
    destroy(array,row,col);

    //Exit the code
    return 0;
}

int **getData(int &row,int &col) {
    int **arr=nullptr;
    
    //Dynamically allocate 2d array
    arr=new int*[row];          //Array of pointers
    for(int r=0;r<row;r++) {
        *(arr+r)=new int[col];    //Array that pointers point to
    }
    
    //Take in values for 2d array
    for(int r=0;r<row;r++) {
        for(int c=0;c<col;c++) {
            cin>>arr[r][c];
        }
    }
 
    return arr;
}

void prntDat(int **arr,int row,int col) {
    for(int r=0;r<row;r++) {
        for(int c=0;c<col;c++) {
            cout<<arr[r][c];
            if(c!=col-1) cout<<" ";
        }
        cout<<endl;
    }
}

void destroy(int **arr,int row,int col) {
    //1 Delete row arrays
    for(int r=0;r<row;r++) {
        delete [] *(arr+r);
    }
    //2 Delete array of pointers
    delete [] arr;
}

int sum(int **arr,int row,int col) {
    int arrSum,
        input;
    
    //Init sum to 0
    arrSum=0;
    
    for(int r=0;r<row;r++) {
        for(int c=0;c<col;c++) {
            arrSum+=arr[r][c];
        }
    }
    
    return arrSum;
}