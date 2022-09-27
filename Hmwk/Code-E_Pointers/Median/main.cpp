/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: September 21, 2022 @ 12:46 PM
 * Purpose: Calculate the median
 */

#include <iostream>
#include <iomanip>

using namespace std;

int *getData(int &);         //Return the array size and the array
void prntDat(int *,int);    //Print the integer array
float *median(int *,int);  //Fill the median Array with the Float array size, the median, and the integer array data
void prntMed(float *);     //Print the median Array
void mrkSort(int *,int);    //Mark Sort
void minPos(int *,int,int); //Find min Position
void swap(int *,int *);     //Swap

int main(){
    //Declare Variables
    int *intArr=nullptr, 
        size;
    float *medArr=nullptr;

    //Initial Variables
    cin>>size;
    
    //Map the Inputs to the Outputs
    //Fill integer array   
    intArr=getData(size);       
    //Fill median array
    medArr=median(intArr,size);     

    //Display the Inputs and Outputs
    prntDat(intArr,size);
    prntMed(medArr);
    
    //Free the memory
    delete [] intArr;
    intArr=nullptr;
    delete [] medArr;
    medArr=nullptr;

    //Exit the code
    return 0;
}

int *getData(int &size) {
    int *arr=nullptr;
    //Dynamically allocate array large enough
    arr=new int[size];   
    for(int i=0;i<size;i++) {
        cin>>*(arr+i);
    }

    return arr; 
}

void prntDat(int *array,int size) {
    for(int i=0;i<size;i++) {
        cout<<*(array+i);
        if(i!=size-1) cout<<" ";
    }
    cout<<endl;
}

float *median(int *intArr,int size) {
    int *srtdArr=nullptr,
        arrSize,            //Float array 2 bigger than int array
        high;              //Highest position in array
    float medVal,
          *arr=nullptr;
    
    arrSize=size+2;         //Median array is 2 larger than int array
    
    //Create sorted copy of int array
    srtdArr=new int[size];
    for(int i=0;i<size;i++) {
        *(srtdArr+i)=*(intArr+i);
    }
    
    //Array must be sorted to calculate median
    mrkSort(srtdArr,size); 
 
    //Calculate the median     
    high=size-1;
    if(size%2!=0) {                 
        for(int i=0;i<size;i++) {
            if(i!=high) high--;     //Decrement high until i==high
            else medVal=*(srtdArr+i);
        }
    } else {
        for(int i=0;i<size;i++) {
            if(i!=high-1) high--;   //Decrement high until it is elem after i
            else medVal=((float)(srtdArr[i]+srtdArr[high]))/2;
        }
    }
    
    //Allocate dynamic memory for float array
    arr=new float[arrSize];
    //Fill float array
    arr[0]=arrSize;
    arr[1]=medVal;
    for(int i=0;i<arrSize;i++) {
        *(arr+i+2)=static_cast<float>(*(intArr+i));
    }
    
    return arr;
}

void prntMed(float *medArr) {
    int arrSize;     
    
    arrSize=medArr[0];      //Arr size is first element of float array
    
    for(int i=0;i<arrSize;i++) {
        if(i==0) cout<<*(medArr)<< " ";
        else {
            cout<<fixed<<setprecision(2);
            cout<<*(medArr+i);
            if(i!=arrSize-1) cout<<" ";
        }
    }
}

void mrkSort(int *array,int n){
    for(int i=0;i<n-1;i++){
        minPos(array,n,i);
    }
}

void minPos(int *array,int n,int pos){
    for(int i=pos+1;i<n;i++){
        if(*(array+pos)>*(array+i))
            swap(array+pos,array+i);
    }
}

void swap(int *a,int *b){
    //Swap in place
    *a=*a^*b;
    *b=*a^*b;
    *a=*a^*b;
}