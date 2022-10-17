/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: October 13, 2022, 10:45 AM
 * Purpose: Reads data from file into an array and display array's contents.
 */

//System Libraries
#include <iostream>  //Input/output Library
#include <fstream>  //File stream Library
using namespace std;

//User Libraries

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only

//Structure Definitions

//Function Prototypes
void arrayToFile(string,int *,int);
void fileToArray(string,int *,int);

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    const int SIZE=10;
    int array[SIZE]={1,2,3,4,5,6,7,8,9,10};
   
    //Map the Inputs to the Outputs
    //Write array to binary file
    cout<<"Writing array from memory to binary file..."<<endl;
    arrayToFile("file.dat",array,SIZE);
    
//    Fill array with 0s to confirm the new array printed is from the file
//    for(int i=0;i<SIZE;i++) {
//        *(array+i)=0;
//    }
//    
//    for(int i=0;i<SIZE;i++) {
//        cout<<*(array+i)<<" ";
//    }
//    cout<<endl;

    //Read array from file
    cout<<"Reading array from binary file back into memory..."<<endl;
    fileToArray("file.dat",array,SIZE);

    //Display the Inputs and Outputs
    //Display contents of array after it's read from file
    for(int i=0;i<SIZE;i++) {
        cout<<*(array+i)<<" ";
    }

    //Exit the code
    return 0;
}

void arrayToFile(string filName,int *arr,int size) {
    //Open file for binary output
    fstream file(filName,ios::out|ios::binary);

    //Write contents of array to the binary file
    file.write(reinterpret_cast<char *>(arr),sizeof(arr)*size);
        
    //Close file
    file.close();

}

void fileToArray(string filName,int *arr,int size) {
    //Open file for binary input
    fstream file(filName,ios::in|ios::binary);
    
    //Read contents of file into the array
    file.read(reinterpret_cast<char *>(arr),sizeof(arr)*size);
    
    //Close file
    file.close();
} 