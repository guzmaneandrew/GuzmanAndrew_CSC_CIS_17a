/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on October 19, 2022 1:20 PM
 * Purpose:  1D Array Class Specification
 */

#ifndef CLASSARRAY1D_H
#define CLASSARRAY1D_H

class DynAry1{
    private:
        int size;
        int *array;
    public:
        void setSize(int);
        void setAry(int *);
        int getSize();
        int getData(int);
        ~DynAry1(){delete []array;}
};

#endif /* CLASS1DARRAY_H */

