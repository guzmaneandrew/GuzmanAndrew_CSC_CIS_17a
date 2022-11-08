/* 
 * File:   mArray.h
 * Author: andrewguzman
 *
 * Created on November 7, 2022, 8:45 PM
 * Purpose: Mark Array Class Specification (neural nets)
 */
//Quick and Dirty Dynamic Array Class
//Built for speed, not error checking
//Know what you are doing or die using it
//The speed mentioned above was not speed
//of execution but speed to code

#ifndef MARRAY_H
#define MARRAY_H

class mArray {
    private:
        int     Rows;   //Rows of the array 
        int     Cols;   //Cols of the array
        double **Data;   //Dynamic 2D array
    public: 
        //Constructors
        mArray(char *);
        mArray(int,int);
        mArray(const mArray &);
        mArray(bool,const mArray &,int,int,int,int);
        //Destructors
        ~mArray();
        //Overloaded operators: to perform +-*= operations on matrices
        mArray operator+(const mArray &);
        mArray operator-(const mArray &);
        mArray operator*(const mArray &);
        mArray operator=(const mArray &);
        //Neural net activation function
        static mArray logsig(const mArray &);
        //Routines to use for calculations
        int *sort(int);
        void mPrint(char *);
        int getRows(){return Rows;}
        int getCols(){return Cols;}
        double getData(int r,int c){return Data[r][c];}
        void setData(double a,int r,int c){Data[r][c]=a;}
};

#endif /* MARRAY_H */

