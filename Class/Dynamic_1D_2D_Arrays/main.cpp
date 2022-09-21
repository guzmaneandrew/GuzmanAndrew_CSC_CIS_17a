/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created on September 20, 2022, 8:27 PM
 * Purpose:  
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
int *filArr(int);               //Create and return 1d array
int **filArr(int,int);          //Create and return 1d array
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
    a1D=filArr(rows*cols);  //Fill 1d arr same size as 2D array
    a2D=filArr(rows,cols);
    
    //Map the Inputs to the Outputs

    //Display the Inputs and Outputs
    prntArr(a1D,rows*cols,cols);    //Give size and number of elem per line
    prntArr(a2D,rows,cols);       
    
    //De-allocate memory
    destroy(a2D,a1D,rows);

    //Exit the code
    return 0;
}

void destroy(int **a2d,int *a1d,int rows) {
    delete []a1d;   //Destroy 1d array
    
    //For 2d array, delete in opposite order of what it was created
    //Delete all rows before we delete the pointer array
    for(int r=0; r<rows;r++) {
        delete []a2d[r];    //1 Destroy all row arrays
    }
    delete[]a2d;            //2 Destroy array of pointers
}

int *filArr(int n) {
    n = n>2&&n<1001?n:2;    //2<n<1001
    
    int *array = new int[n];    //Allocate the array
    
    for(int i=0;i<n;i++) {
        array[i]=rand()%90+10;   //0-89 -> 10-99
    }
    
    return array;
}               

int **filArr(int row,int col) {
    row = row>2&&row<1001?row:2;
    col = col>2&&col<1001?col:2;
    
    int **array=new int*[row];  //1 Create the array of pointers
    
    for(int r=0;r<row;r++) {
        array[r]=filArr(col);   //2 Create each row array with 1d array of pointers
        //same as
        //array[r]=new int[col];
    }  
    return array;
}    

void prntArr(int *a,int n,int perLine) {
    cout<<endl;
    for(int i=0;i<n;i++) {
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1)) cout << endl;
    }
    cout<<endl;
} 

void prntArr(int **a,int row,int col) {
    cout<<endl;
    for(int r=0; r<row;r++) {
        for(int c=0;c<col;c++) {
            cout<<a[r][c]<<" ";
            
        }
        cout<<endl;
    }
    cout<<endl;
} 

