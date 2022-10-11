/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created on October 10, 2022, 11:30 PM
 * Purpose:  Compare 1 and 2 Dimensional vectors.
 */

//System Libraries Here
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions and Array Dimension


//Function Prototypes Here
void prntVec(const vector<int>&,int,int);
void prntVec(vector<vector<int>>&,int,int);
vector<int> fillVec(int,int,int);
vector<vector<int>> fillVec(int,int);
void fillVec(vector<vector<int>>&,vector<int>&,int,int);
void destroy(vector<vector<int>>&,int);
void mrkSort(vector<int>&,int);
void smlLst(vector<int>&,int,int);
void swap(int &,int &);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables Here
    int rowsize=4;//Row size for both 1 and 2 D vectors
    int colsize=3;//The column size for a 2 dimensional vector
    vector<int> aVec;
    vector<int> bVec;
    vector<int> cVec;
    vector<vector<int>> table;
    int lowRng=100,highRng=999;
    int perLine=4;
        
    //Fill each parallel vector
    aVec=fillVec(rowsize,highRng,lowRng);
    bVec=fillVec(rowsize,highRng/10,lowRng/10);
    cVec=fillVec(rowsize,highRng/100,lowRng/100);
    
    //Sort the vector the for all positions
    mrkSort(aVec,rowsize);
    mrkSort(bVec,rowsize);
    mrkSort(cVec,rowsize);
    
    //Fill the 2-D vector
    table=fillVec(rowsize,colsize);
    fillVec(table,aVec,rowsize,0);
    fillVec(table,bVec,rowsize,1);
    fillVec(table,cVec,rowsize,2);
    
    //Print the values in the vector
    prntVec(aVec,rowsize,perLine);
    prntVec(bVec,rowsize,perLine);
    prntVec(cVec,rowsize,perLine);
    prntVec(table,rowsize,colsize);
    
    //Cleanup
    aVec.clear();
    bVec.clear();
    cVec.clear();
    destroy(table,rowsize);

    //Exit
    return 0;
}

void prntVec(const vector<int>&v,int n,int perLine){
    //Print the values in the vector
    cout<<endl<<"The Vector Values"<<endl;
    for(int indx=0;indx<n;indx++){
        cout<<v[indx]<<" ";
        if(indx%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void prntVec(vector<vector<int>>&v,int rowsize,int colsize){
    cout<<endl<<"The Vector Values"<<endl;
    for(int row=0;row<rowsize;row++){
        for(int col=0;col<colsize;col++){
            cout<<setw(4)<<v[row][col];
        }
        cout<<endl;
    }
}

vector<int> fillVec(int n,int hr,int lr){
    n=n<2?2:n;
    vector<int> v(n);
    for(int indx=0;indx<n;indx++){
        v[indx]=rand()%(hr-lr+1)+lr;
    }
    return v;
}

vector<vector<int>> fillVec(int rows,int cols){
    //Allocate 2-D Vector
    rows=rows<2?2:rows;
    cols=cols<2?2:cols;

    //Initialize single row of vector
    vector<int> row(cols,0);
    
    //Initialize 2-D vector
    vector<vector<int>> v(rows,row);
    
    return v;
}

void fillVec(vector<vector<int>>&a,vector<int>&b,int rowSize,int wchCol){
    for(int row=0;row<rowSize;row++){
        a[row][wchCol]=b[row];
    }
}

void destroy(vector<vector<int>>&a,int rows){
    for(int row=0;row<rows;row++) {
        a[row].clear();
    }
}

void mrkSort(vector<int>&v,int n){
    for(int pos=0;pos<n-1;pos++){
        smlLst(v,n,pos);
    }
}

void smlLst(vector<int>&v,int n,int pos){
    for(int i=pos+1;i<n;i++){
        if(v[pos]>v[i]){
            swap(v[pos],v[i]);
        }
    }
}

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}