/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on October 19, 2022 1:20 PM
 * Purpose:  1D Array Class Implementation
 */

#include "ClassArray1D.h"
#include <cstdlib>
#include <iostream>
using namespace std;

void DynAry1::setSize(int n) {
    size=n<2?2:
         n>1000?1000:n;
    
    //Dynamically allocate and fill array
    array=new int[size];
    for(int i=0;i<size;i++){
        array[i]=rand()%50+10;
    }
}

void DynAry1::setAry(int val,int indx) {
    if(indx>=0&&indx<=size-1) array[indx]=val;
}

int DynAry1::getSize() {
    return size;
}

int DynAry1::getData(int indx) {
    int value=-999;
    if(indx>=0&&indx<=size-1) {
        return array[indx]; 
    } else 
        return value;
}

void DynAry1::prntAry(int perLine) {
    cout<<endl;
    for(int i=0;i<size;i++) {
        cout<<array[i]<<" ";
        if(i%perLine==(perLine-1)) cout<<endl;
    }
}