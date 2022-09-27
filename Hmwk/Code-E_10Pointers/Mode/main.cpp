/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on March 6th, 2019, 7:45 PM
 */

//Libraries
#include <cstdlib>//Random number seed
#include <iostream>//I/O Library
#include <cmath>   //Math Library
using namespace std;

//No Global Constants

//Function Prototypes
int *fillAry(int,int);      //Fill the Array
void prntAry(int *,int,int);//Print the Array
void prntMod(int *);        //Print the mode set
void swap(int *,int *);     //Swap
void minPos(int *,int,int); //Find min Position
void mrkSort(int *,int);    //Mark Sort
int *copy(const int *,int); //Copy the Array
void shuffle(int *,int,int);//Shuffle the Array
unsigned int GRB();         //Generate Random Bit
void GR(unsigned int&);     //Generate Random Number
int *mode(const int *,int); //Find the mode set

//Execution begins here
int main(int argc, char*argv[]) {
    //Declare variables and fill
    int arySize,//The array/set size
         modNum,//Unique numbers in the array
           *ary;//Pointer to the array
    
    //Input the number of unique numbers
    //and size of the array
    cout<<"The program finds the mode of a set"<<endl;
    cout<<"Input the size of the array and ";
    cout<<"quantity of unique numbers"<<endl;
    cin>>arySize>>modNum;
    ary=fillAry(arySize,modNum);
    
    //Print the initial array
    cout<<"The Array before shuffling"<<endl;
    prntAry(ary,arySize,modNum);
    
    //Shuffle the Array 7 times
    shuffle(ary,arySize,7);
    
    //Calculate the mode array
    int *modeAry=mode(ary,arySize);
    
    //Print the initial array
    cout<<"The Array after shuffling"<<endl;
    prntAry(ary,arySize,modNum);
    
    //Print the modal information of the array
    cout<<"The Modal Information"<<endl;
    prntMod(modeAry);
    
    //Delete allocated memory
    delete []ary;
    delete []modeAry;
    
    //Exit stage right
    return 0;
}

//This just a stub.  You are to fill in the correct solution
int *mode(const int *array,int arySize){
    int maxFreq=1,freq=1,currNum,nextNum,nmodes=0;
    
    //Copy the array
    int *ary=copy(array,arySize);
    
    //Sort the copy
    mrkSort(ary,arySize);
    
    //Find the max Frequency
    for(int i=0;i<=arySize;i++) {
        currNum=*(ary+i);
        nextNum=*(ary+i+1);
        if(currNum==nextNum) {  //Increment freq if same number
            freq++;
        }
        else {                  //Compare freq to maxFreq
            if(freq>maxFreq) {
                maxFreq=freq;  
            }
            freq=1;             //Reset freq to 1 for next number
        }
    }
        
    //Find the number of modes
    freq=1;                     //Reset freq to 1 to find the number of modes
    for(int i=0;i<=arySize;i++) {
        currNum=*(ary+i);
        nextNum=*(ary+i+1);
        if(currNum==nextNum) {  //Increment freq if same as next number
            freq++;
        }
        else {                  //Determine if number has max frequency
            if(freq==maxFreq && freq>1) {
                nmodes++;       //If this number is a mode, increment nmodes
            }
            freq=1;             //Reset freq to 1 for next number
        }
    }
    
    //Allocate the mode array
    int *modeAry=new int[nmodes+2];
    
    //Fill the mode array
    modeAry[0]=nmodes;
    modeAry[1]=maxFreq;
    
    freq=1;                     //Reset freq to 1 to fill the mode array
    int modeIndx=2;             //mode array is offset by 2
    //Find the number of modes
    for(int i=0;i<=arySize;i++) {
        currNum=*(ary+i);
        nextNum=*(ary+i+1);
        if(currNum==nextNum) {  //Increment freq if same number
            freq++;
        }
        else {                  //Determine if number has max frequency
            if(freq==maxFreq && freq>1) {
                *(modeAry+modeIndx)=currNum;    //Update value in mode array
                modeIndx++;                     //Next index in mode array
            }
            freq=1;             //Reset freq to 1 for next number
        }
    }

    //Delete the allocated copy and return
    delete []ary;
    return modeAry;
}

int *copy(const int *a,int n){
    //Declare and allocate an array
    int *b=new int[n];
    //Fill with passed array
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    //Return the copy
    return b;
}

void prntMod(int *ary){
    cout<<"The number of modes = "<<
            ary[0]<<endl;
    cout<<"The max Frequency = "<<
            ary[1]<<endl;
    if(ary[0]==0){
        cout<<"The mode set = {null}"<<endl;
        return;
    }
    cout<<"The mode set = {";
    for(int i=2;i<ary[0]+1;i++){
        cout<<*(ary+i)<<",";
    }
    cout<<ary[ary[0]+1]<<"}"<<endl;
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

void prntAry(int *array,int n,int perLine){
    //Output the array
    for(int i=0;i<n;i++){
        cout<<*(array+i)<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

int *fillAry(int n, int modNum){
    //Allocate memory
    int *array=new int[n];
    
    //Fill the array with 2 digit numbers
    for(int i=0;i<n;i++){
        *(array+i)=i%modNum;
        //*(array+i)=rand()%modNum;
    }
    
    //Exit function
    return array;
}

void shuffle(int *a,int n,int nShuf){
    unsigned int temp;
    for(int shuf=1;shuf<=nShuf;shuf++){
        for(int i=0;i<n;i++){
            GR(temp);
            temp%=n;
            if(i!=temp)swap(a[i],a[temp]);
        }
    }
}

unsigned int GRB(){
    static unsigned int seed=0;
    seed += (seed * seed) | 5;
    return seed & 0x80000000;
}
 
void GR(unsigned int& value){
    value=0;
    const unsigned int numBits = sizeof(int) * 8;
    unsigned int* dataPointer = (unsigned int *)&value;
    for (unsigned int index = 0; index < numBits; ++index)
    {
        if(GRB()) {
            unsigned int pointerIndex = index / 32;
            unsigned int mask = 1 << index % 32;
            dataPointer[pointerIndex] |= mask;
        }
    }
}