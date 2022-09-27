/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: September 22, 2022 @ 1:22 PM
 * Purpose: Create a 2-D array 1 row and 1 column larger than the array to copy
 */

//System Libraries
#include <iostream>  //Input/output Library
using namespace std;

//User Libraries

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only

//Function Prototypes
int **getData(int &,int &);//Get the Matrix Data
void prntDat(const int * const *,int,int);//Print the Matrix
int **augment(const int * const *,int,int);//Augment the original array
void destroy(int **,int);//Destroy the Matrix, i.e., reallocate memory

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Declare Variables
    int row,
        col,
        augRow,     
        augCol,
        **arr2D=nullptr,
        **augAr2D=nullptr;

    //Initial Variables
    cin>>row>>col;
    augRow=row+1;       //Augmented array is bigger by 1row and 1 col
    augCol=col+1;
    
    //Map the Inputs to the Outputs
    //Allocate arrays
    arr2D=getData(row,col);
    augAr2D=augment(arr2D,augRow,augCol);

    //Display the Inputs and Outputs
    prntDat(arr2D,row,col);
    cout<<endl;
    prntDat(augAr2D,augRow,augCol);
    
    //Free memory
    destroy(arr2D,row);
    destroy(augAr2D,row);

    //Exit the code
    return 0;
}

int **getData(int &rows,int &cols) {
    int **arr2D=nullptr;
    
    //Allocate the 2d array
    //Allocate array of pointers
    arr2D=new int*[rows];
    for(int r=0;r<rows;r++) {
        //Allocate row arrays that pointers point to
        for(int c=0;c<cols;c++) {
            *(arr2D+r)=new int[cols];
        }
    }
    
    //Fill the array
    for(int r=0;r<rows;r++) {
        for(int c=0;c<cols;c++) {
            cin>>arr2D[r][c];
        }
    }
    
    return arr2D;
} 

void prntDat(const int * const *arr,int rows,int cols) {
    for(int r=0;r<rows;r++) {
        for(int c=0;c<cols;c++) {
            cout<<arr[r][c];
            if(c!=cols-1&&r!=cols-1) cout<<" ";
            else if(c==cols-1&r!=rows-1) cout<<endl;
        }
    }
}

int **augment(const int * const *arr,int rows,int cols) {
    int **augArr=nullptr;
    
    //Allocate new augmented array
    //Create array of pointers
    augArr=new int*[rows];  
    for(int r=0;r<rows;r++) {
        //Create row array that pointers point to
        augArr[r]=new int[cols];
    }
    
    //Fill augmented array
    for(int r=0;r<rows;r++) {
        for(int c=0;c<cols;c++) {
            if(r==0||c==0) {
                augArr[r][c]=0; 
            }
            else augArr[r][c]=arr[r-1][c-1];
        }
    }
        
    //Return array
    return augArr;
}

void destroy(int **arr,int rows) {
    //Delete row arrays
    for(int r=0;r<rows;r++) {
        delete [] *(arr+r);
    }
    
    //Delete array of pointers
    delete [] arr;
    
    arr=nullptr;
}