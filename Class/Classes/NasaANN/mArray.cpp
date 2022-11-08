
/* 
 * File:   mArray.h
 * Author: andrewguzman
 * Created on November 7, 2022, 8:45 PM
 * Purpose: Mark Array Class Implementation (neural nets)
 */

//Things To Do
//  1) Read in the input file
//      time current
//  2) Add in reading the transformation matric
//  3) Add in reading start and stop times
//  4) Output the information as expected
//  5) Also send to the ftp file

#include <fstream>
#include <cmath>
using namespace std;

#include "mArray.h"

//Construct arrays from a file
mArray::mArray(char *fn) {
    ifstream in;
    in.open(fn);
    double rd,cd;
    in>>rd;
    in>>cd;
    Rows=static_cast<int>(rd);
    Cols=static_cast<int>(cd);
    Data=new double*[Rows];
    for(int r=0;r<Rows;r++) {
        Data[r]=new double[Cols];
    }
    for(int r=0;r<Rows;r++) {
        for(int c=0;c<Cols;c++) {
            in>>Data[r][c];
        }
    }
    in.close();
}

//Constructor given rows and cols
//and init to zero
mArray::mArray(int rd,int cd) {
    Rows=rd;
    Cols=cd;
    Data=new double*[Rows];
    for(int r=0;r<Rows;r++) {
        Data[r]=new double[Cols];
    }
    for(int r=0;r<Rows;r++) {
        for(int c=0;c<Cols;c++) {
            Data[r][c]=0;
        }
    }
}

//Copy constructor for entire array
mArray::mArray(const mArray &d) {
    Rows=d.Rows;
    Cols=d.Rows;
    Data=new double*[Rows];
    for(int r=0;r<Rows;r++) {
        Data[r]=new double[Cols];
    }
    for(int r=0;r<Rows;r++) {
        for(int c=0;c<Cols;c++) {
            Data[r][c]=d.Data[r][c];
        }
    }
}

//Copy constructor using array limits
//Also takes the transpose simultaneously 
//z==> false take the transpose
//[rc,re]==>Span for rows
//[cb,ce]==>Span for cols
mArray::mArray(bool z,const mArray &d,int rb,int re,int cb,int ce) {
    
    if(z) {
        Rows=re-rb+1;
        Cols=ce-cb+1;
        Data=new double*[Rows];
        for(int r=0;r<Rows;r++) {
            Data[r]=new double[Cols];
        }
        for(int r=0;r<Rows;r++) {
            for(int c=0;c<Cols;c++) {
                Data[r][c]=d.Data[rb+r][cb+c];  //partitioned arrays
            }
        }        
    } 
    //with transpose 
    else {
        Rows=re-rb+1;
        Cols=ce-cb+1;
        Data=new double*[Rows];
        for(int r=0;r<Rows;r++) {
            Data[r]=new double[Cols];
        }
        for(int r=0;r<Rows;r++) {
            for(int c=0;c<Cols;c++) {
                Data[r][c]=d.Data[rb+c][cb+r];
            }
        }  
    }
}

//Destructor
mArray::~mArray() {
    //Delete the columns in all the rows 
    //for the 2D array
    for(int i=0;i<Rows;i++) {
        delete []Data[i];
    }
    
    //Delete all the rows
    //in the array
    delete []Data;
}

//Note the +,- operators makes an assumption 
//of non-equal arrays. It does this by column
//such that the mod operation is utilized

//Overloaded binary + operator
//Used for Matrix+Vector additions
//Neural net specific
mArray mArray::operator+(const mArray &right) {
    mArray temp(Rows,Cols);
    int m=right.Cols;
    for(int r=0;r<Rows;r++) {
        for(int c=0;c<Cols;c++) {
            temp.Data[r][c]=Data[r][c]+right.Data[r][c%m];
        }
    }
    return temp;
}

//Overloaded binary - operator
//Used for Matrix+Vector subtractions
//Neural net specific
mArray mArray::operator-(const mArray &right) {
    mArray temp(Rows,Cols);
    int m=right.Cols;
    for(int r=0;r<Rows;r++) {
        for(int c=0;c<Cols;c++) {
            temp.Data[r][c]=Data[r][c]-right.Data[r][c%m];
        }
    }
    return temp;
}

//Overloaded binary * operator
//Typical matrix*matrix multiplication
mArray mArray::operator*(const mArray &right) {
    mArray temp(Rows,right.Cols);
    for(int r=0;r<Rows;r++) {
        for(int c=0;c<Cols;c++) {
            for(int k=0;k<Cols;k++) {
                temp.Data[r][c]+=Data[r][k]*right.Data[k][c];
            }
        }
    }
    return temp;
}

//Overloaded equality operator
mArray mArray::operator=(const mArray &right) {
    Rows=right.Rows;
    Cols=right.Cols;
    for(int r=0;r<Rows;r++) {
        for(int c=0;c<Cols;c++) {
            Data[r][c]=right.Data[r][c];
        }
    }
    return *this;
}

//Neural net activation function
//Note: This is a static function
mArray mArray::logsig(const mArray &a) {
    mArray temp(a.Rows,a.Cols);
    for(int r=0;r<a.Rows;r++) {
        for(int c=0;c<a.Cols;c++) {
            temp.Data[r][c]=1.0/(1.0+exp(-a.Data[r][c]));
        }
    }
    return temp;
}

//Sort using an index the content of an array
int *mArray::sort(int c) {
    int *indx=new int[Rows];
    for(int i=0;i<Rows;i++) {
        indx[i]=i;
    }
    for(int i=0;i<Rows-1;i++)
    {
        for(int j=i;j<Rows;j++) 
        {
            if(Data[indx[i]][c]>Data[indx[j]][c]) {
                int temp=indx[i];
                indx[i]=indx[j];
                indx[j]=temp;
            }
        }
    }
    return indx;
}

//Output the matrix/vector to a file
void mArray::mPrint(char *fn) {
    ofstream out;
    out.open(fn,ios::app);
    out<<Rows<<" ";
    out<<Cols<<endl;
    for(int r=0;r<Rows;r++) {
        for(int c=0;c<Cols;c++) {
            out<<Data[r][c]<<" ";
        }
        out<<endl;
    }
    out.close();
}