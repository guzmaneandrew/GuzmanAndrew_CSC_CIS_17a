/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created on September 10, 2022, 8:48 PM
 * Purpose: Sum Rows, Sum Columns, Grand Sum of an integer array
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <iomanip> //setw(10)
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX = 80;  //Max Columns much larger than needed.

//Function Prototypes Here
void read(int [][COLMAX], int &, int &);//Prompt for size then table
void sum(const int [][COLMAX], int, int, int[][COLMAX]);//Sum rows,col,grand total
void print(const int [][COLMAX], int, int, int);//Either table can be printed

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW = 80;           //Max Rows much larger than needed
    int array[ROW][COLMAX]={};  //Declare original array
    int augAry[ROW][COLMAX]={}; //Actual augmented table row+1, col+1
    int row, col;                
    
    //Input the original table
    read(array, row, col);
    
    //Augment the original table by the sums
    sum(array, row, col, augAry);
    
    //Output the original array
    cout << endl << "The Original Array" << endl;
    print(array, row, col, 10);//setw(10)
    
    //Output the augmented array
    cout << endl << "The Augmented Array" << endl;
    print(augAry, row+1, col+1, 10);//setw(10)
    
    //Exit
    return 0;
}

void read(int array[][COLMAX], int &row, int &col) {
    cout << "Input a table and output the Augment ";
    cout << "row,col and total sums." << endl;
    
    cout << "First input the number of rows and cols. <20 for each";
    cin >> row >> col;
    cout << endl;
    
    cout << "Now input the table.";
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            cin>>array[i][j];
        }
    }
    
    cout<<endl;
}

void sum(const int array[][COLMAX], int row, int col, int augArr[][COLMAX]) {
    int rowSum, colSum, grndSum;
    
    grndSum=0;
    
    //Copy array to aug array
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            augArr[i][j]=array[i][j];
        }
    }
    
    //Calculate row sum
    for(int i=0; i<row; i++) {
        rowSum=0;
        for(int j=0; j<col; j++) {
            rowSum+=array[i][j];
        }
        augArr[i][col]=rowSum;
    }
    
    //Calculate col sum
    for(int j=0; j<col; j++) {
        colSum=0;
        for(int i=0; i<row;i++) {
            colSum+=array[i][j];
        }
        augArr[row][j]=colSum;
    }
    
    //Calculate grandsum
    for(int i=0; i<row; i++) {
        grndSum+=augArr[i][col];
        augArr[row][col]=grndSum;
    }
}

void print(const int array[][COLMAX], int row, int col, int num) {
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            cout << setw(num) << array[i][j];
        }
        cout << endl;
    }
}