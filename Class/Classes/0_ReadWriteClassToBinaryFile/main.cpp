/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on April 6th, 2021, 1:30 PM
 * Purpose:  Create a simple class to read and write to 
 * binary file.
 */

//System Libraries Here
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

//User Libraries Here
#include "Test.h"

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void wrtTxt(fstream &,Test *,int);  //Write structure info to a text file
void wrtBin(fstream &,Test *);      //Write structure info to a binary file
Test *readBin(fstream &,int);       //Extract a record from binary file and 
                                        //compare to text file
void prntTxt(Test *);                 //Print out structure info

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Open the Text and binary files
    fstream txtFile,binFile;
    txtFile.open("data.txt",ios::in|ios::out);      
    binFile.open("data.bin",ios::in|ios::out|ios::binary);  
    
    //Declare all Variables Here and Loop
    //Create 100 records
    int nRecords=100;//Number of records 
    
    //Fill a binary and text file with a bunch of regular size structures
    for(int record=0;record<nRecords;record++){
        //Allocate the Structure
        Test *test=new Test;    //Create simple structure dynamically
        //Fill the structure
        test->c=rand()%26+65;
        test->s=rand()%900+100;
        test->i=rand()%900+1000;
        //Write to binary and text files
        wrtTxt(txtFile,test,record);
        wrtBin(binFile,test);
        //Delete dynamic memory
        delete test;         
    }
    
    //Read back in the array, randomly choose one record, then print out
    int randRec=rand()%nRecords;
    cout<<"Random record to find = "<<randRec<<endl;
    //Read random record from binary file and return the pointer to the structure
    //that was filled up to see whether they match
    Test *test=readBin(binFile,randRec);
    prntTxt(test);
    cout<<"The size of the test structure = "<<sizeof(Test)<<" bytes"<<endl;
    
    //Delete the array
    delete test;
    
    //Close the files
    txtFile.close();
    binFile.close();
    
    //Exit
    return 0;
}

Test *readBin(fstream &in,int record){
    //Declare and initialize variables
    long cursor=0L;    //Where to place the cursor
    Test *a=new Test;//The array to return
    
    //Find the record
    cursor=record*sizeof(Test);
    
    //Fill the structure
    in.seekg(cursor,ios::beg);  //Set cursor to byte from the beginning of the file
    in.read(reinterpret_cast<char *>(a),sizeof(Test));  //Read structure from cursor
    return a;   //Return what was read in
}

void wrtBin(fstream &out,Test *a){
    out.write(reinterpret_cast<char *>(a),sizeof(Test));
}

void wrtTxt(fstream &out,Test *a,int record){
    out<<endl;
    out<<"Structure Contents Record = "<<record<<endl;
    out<<setw(6)<<a->c<<endl;
    out<<setw(6)<<a->s<<endl;
    out<<setw(6)<<a->i<<endl;
    out<<endl;
}

void prntTxt(Test *a){
    cout<<endl;
    cout<<"Structure Contents "<<endl;
    cout<<setw(6)<<a->c<<endl;
    cout<<setw(6)<<a->s<<endl;
    cout<<setw(6)<<a->i<<endl;
    cout<<endl;
}