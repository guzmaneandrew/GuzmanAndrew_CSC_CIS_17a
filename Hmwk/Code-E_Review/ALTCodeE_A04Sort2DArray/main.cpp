/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created on 9/10/22 22:21
 * Purpose: Sorting a 2-D array of characters if row and columns match
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <cstring> //strlen(),strcmp(),strcpy()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX = 80;//Only 20 required, and 1 for null terminator

//Function Prototypes Here
int  read(char [][COLMAX], int &);//Outputs row and columns detected from input
void sort(char [][COLMAX], int,int);//Sort by row
void print(const char [][COLMAX], int,int);//Print the sorted 2-D array
void swap(const char[][COLMAX],char [],char [],int); //swap for sort

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW = 30;             //Only 20 required
    char array[ROW][COLMAX];      //Bigger than necessary 
    int colIn, colDet, rowIn, rowDet;//Row, Col input and detected
    
    //Input the size of the array you are sorting
    cout << "Read in a 2 dimensional array of characters and sort by Row" << endl;
    cout << "Input the number of rows <= 20" << endl;
    cin >> rowIn;
    cout << "Input the maximum number of columns <= 20" << endl;
    cin >> colIn;
    
    //Now read in the array of characters and determine it's size
    rowDet = rowIn;
    cout << "Now input the array." << endl;
    
    //Receive inputs for 2d array, one character array at a time
    for(int i = 0; i < rowDet; i++) {
        cin >> array[i];
    }
    
    //Receive inputs for 2d array, one character at a time
//    for(int i = 0; i < rowDet; i++) {
//        for(int j = 0; j < colIn; j++) {
//            cin >> array[i][j];
//        }
//    }
  
    colDet = read(array, rowDet);
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size
    if(rowDet==rowIn && colDet==colIn){
        sort(array, rowIn, colIn);
        cout << "The Sorted Array" << endl;
        print(array, rowIn, colIn);
    } else {
        if(rowDet != rowIn)
        cout << (rowDet < rowIn ? "Row Input size less than specified.":
            "Row Input size greater than specified.") << endl;
        if(colDet != colIn)
        cout << (colDet < colIn ? "Column Input size less than specified.":
            "Column Input size greater than specified.") << endl;
    }
    
    //Exit
    return 0;
}

int  read(char array[][COLMAX], int &rowSize) {
    int colSize,                            //Loop counter
        maxCol;                             //Max col size
    
    maxCol = 1;
    
    for(int i = 0; i < rowSize; i++) {
        colSize = 0;                        //# col = 0 at beginning of each new row
        while(array[i][colSize] != '\0') { //Increment colSize until we reach '\0'
            colSize++; 
        }   
    }
    
    return colSize;
}

void sort(char array[][COLMAX],int rowSize, int colSize) {

}

void swap(const char array[][COLMAX],char rowA[],char rowB[],int colSize) {

}

void print(const char array[][COLMAX], int rowSize, int colSize) {
    //Display array    
    for(int i = 0; i < rowSize; i++) {
        for(int j = 0; j < colSize; j++) {
            cout << array[i][j];
        }
        cout << endl;
    }
}