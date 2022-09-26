/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created on September 20, 2022, 8:27 PM
 * Purpose: 1D and 2D arrays
 */

//System Libraries
#include <iostream>     //Input/output Library
#include <cstdlib>      //Random number
#include <ctime>        //Time to set random seed
using namespace std;

//User Libraries

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only

//Function Prototypes
int *fillArr(int);               //Create and return 1d array
int **fillArr(int,int);          //Create and return 2d array
void prntArr(int *,int,int);    //Print 1d array
void prntArr(int **,int,int);  //Print 2d array
void destroy(int **,int *,int);  //Cleans up/De-allocate dynamic memory

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Set the Random Number Seed
    srand(static_cast<unsigned int>(time(0))); 

    //Declare Variables
    int *a1D,**a2D,rows,cols;   //1D,2D array, rows, columns
    
    //Initial Variables
    rows=5;
    cols=20;
    a1D=fillArr(rows*cols);      //Fill 1d arr same size as 2D array
    a2D=fillArr(rows,cols);
    
    //Map the Inputs to the Outputs

    //Display the Inputs and Outputs
    prntArr(a1D,rows*cols,cols);    //Give size and number of elem per line
    prntArr(a2D,rows,cols);
    
    //De-allocate memory
    destroy(a2D,a1D,rows);

    //Exit the code
    return 0;
}

int *fillArr(int n) {
    n = n>2&&n<1001?n:2;
    
    //Allocate the array
    int *array=new int[n];    
    
    //Fill the array
    for(int i=0;i<n;i++) {
        array[i]=rand()%90+10;  //0-89 -> 10-99
    }
    
    return array;
}               

int **fillArr(int row,int col) {
    row = row>2&&row<1001?row:2;
    col = col>2&&col<1001?col:2;
    
    //1 Create the array of pointers
    int **array=new int*[row];
    //2 Create each row array with 1d array of pointers
    for(int r=0;r<row;r++) {
        //array[r]=fillArr(col);
        //same as
        *(array+r)=new int[col];
        for(int c=0;c<col;c++) {
            array[r][c]=rand()%90+10;
        }
    }
    return array;
}    

void prntArr(int *a,int n,int perLine) {
    for(int i=0;i<n;i++) {
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1)) cout<<endl;
    }
    cout<<endl;
} 

void prntArr(int **a,int row,int col) {
    for(int r=0;r<row;r++) {
        for(int c=0;c<col;c++) {
            cout<<a[r][c]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
} 

void destroy(int **a2d,int *a1d,int rows) {
    //Destroy 1d array
    delete [] a1d;
    
    //Destroy 2d array
    //1 Delete all row arrays before deleting pointer array
    for(int r=0;r<rows;r++) {
        delete [] a2d[r];
    }
    //2 Delete the array of pointers
    delete [] a2d;
}