/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created on September 10, 2022, 8:47 PM
 * Purpose: Even, Odd Vectors and Array Columns Even, Odd
 * Note:  Check out content of Sample conditions in Hacker Rank
 * Input size of integer array, then array, output columns of Even, Odd
 * Vectors then Even, Odd 2-D Array
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <vector>  //vectors<>
#include <iomanip> //Format setw(),right
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX = 2;//Only 2 columns needed, even and odd

//Function Prototypes Here
void read(vector<int> &, vector<int> &);
void copy(vector<int>, vector<int>, int [][COLMAX]);
void prntVec(vector<int>, vector<int>, int);//int n is the format setw(n)
void prntAry(const int [][COLMAX], int, int, int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW = 80;           //No more than 80 rows
    int array[ROW][COLMAX];     //Really, just an 80x2 array, even vs. odd
    vector<int> even(0), odd(0); //Declare even,odd vectors
    
    //Input data and place even in one vector odd in the other
    read(even, odd);
    
    //Now output the content of the vectors
    //          setw(10)
    prntVec(even, odd, 10);//Input even, odd vectors with setw(10);
    
    //Copy the vectors into the 2 dimensional array
    copy(even, odd, array);
    
    //Now output the content of the array
    //                              setw(10)
    prntAry(array, even.size(), odd.size(), 10);//Same format as even/odd vectors
    
    //Exit
    return 0;
}

void read(vector<int> &even, vector<int> &odd) {
    int size, input;
    
    //Get value as input
    cout << "Input the number of integers to input." << endl;
    cin >> size;
    cout << "Input each number." << endl; 
    
    for(int i = 0; i < size; i++) {
        cin >> input;
        if(input%2 == 0) {
            even.push_back(input);
        }
        else {
            odd.push_back(input);
        }
    }
}

void prntVec(vector<int> even, vector<int> odd, int num) {
    vector<int> max, min;
    int maxSize, minSize;
    
    //Determine which vec is larger
    if(even.size() > odd.size()) {
        max = even;
        min = odd;
        minSize = min.size();
        maxSize = max.size();
        
        cout << setw(num) << "Vector" << setw(num) << "Even" << setw(num) << "Odd" << endl;
        for(int i=0; i<minSize; i++) {
            cout << setw(20) << even[i] << setw(10) << odd[i] << endl;
        }
        for(int i=minSize; i<maxSize; i++) {
            cout << setw(20) << even[i] << endl;
        }
    
    } else {
        max = odd;
        min = even;
        minSize = min.size();
        maxSize = max.size();   
        
        cout << setw(num) << "Vector" << setw(num) << "Even" << setw(num) << "Odd" << endl;
        for(int i=0; i<minSize; i++) {
            cout << setw(20) << even[i] << setw(10) << odd[i] << endl;
        }
        for(int i=minSize; i<maxSize; i++) {
            cout << setw(30) << odd[i] << endl;
    }
    }
}

void copy(vector<int> even, vector<int> odd, int array[][COLMAX]) {
    
    //Copy even numbers into col0 of array
    for(int i=0; i<even.size(); i++) {
        array[i][0] = even[i];
    }
    
    //Copy odd numbers into col2 of array
    for(int i=0; i<odd.size(); i++) {
        array[i][1] = odd[i];
    }
 

}

void prntAry(const int array[][COLMAX], int evnSize, int oddSize, int num) {
    int minSize, maxSize;
    
    if(evnSize>oddSize) {
        minSize = oddSize;
        maxSize = evnSize;
        
        cout << setw(num) << "Array" << setw(num) << "Even" << setw(num) << "Odd" << endl;
        for(int i=0; i<minSize; i++) {
            cout << setw(20) << array[i][0] << setw(10) << array[i][1]<< endl;
        }
        for(int i=minSize; i<maxSize; i++) {
            cout << setw(20) << array[i][0] << setw(10) << array[i][1]<< endl;
        }
    } else {
        minSize = evnSize;
        maxSize = oddSize;
        
        cout << setw(num) << "Array" << setw(num) << "Even" << setw(num) << "Odd" << endl;
        for(int i=0; i<minSize; i++) {
            cout << setw(20) << array[i][0] << setw(10) << array[i][1]<< endl;
        }
        for(int i=minSize; i<maxSize; i++) {
            cout << setw(30) << array[i][1]<< endl;
        }
    }
}

