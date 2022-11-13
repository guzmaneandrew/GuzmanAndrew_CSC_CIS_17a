/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: November 9, 2022 @ 1:20 PM
 * Purpose: Example of Array of Objects With and Without Constructors
 * You can't create an array of objects of a class with a constructor because
 *  you don't call the constructor. 
 * To create an array of a class with a constructor use a double pointer
 *  -one to create the array of pointers
 *  -then create each instance of each individual element that pointer points to
 *  -call constructor for each instance to create the individual elements
 */

//System Libraries
#include <iostream>  //Input/output Library
using namespace std;

//User Libraries
//With Constructor
//You can't create an array of A... when you have a constructor, there's 
//no way to create dynamically (with new keyword)
class A {
    private:
        int n;
    public:
        A(int n){this->n=n;}
        int getN(){return n;}
};

//Without Constructor
//You can create an array of B... they don't construct with a constructor
class B {
    private:
        int n;
    public:
        void setB(int n){this->n=n;}
        int getN(){return n;}
};

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only

//Structure Definitions

//Function Prototypes

//Program Execution Begins Here!!!
int main(int argc, char** argv) {
    //Initialize the Random Number Seed

    //Declare Variables
    int size=5;
//    A *a=new A[size];//ERROR: No matching function call = no constructor
    A **a=new A*[size];     //Create array of pointers
    B *b=new B[size];       //B has no constructor, so you can create an array 
                            //because they don't construct with a constructor

    //Initial Variables
    //Fill arrays
    for(int i=0;i<size;i++) {
        a[i]=new A(i);      //An individual object is instantiated and initialized
        b[i].setB(i);    
    }

    //Map the Inputs to the Outputs

    //Display the Inputs and Outputs
    //Display contents of the arrays
    cout<<"Contents of A"<<endl;
    for(int i=0;i<size;i++) {
        cout<<a[i]->getN()<<endl;    //Use -> because a is pointer of pointers
    }
    
    //Display contents of the arrays
    cout<<"Contents of B"<<endl;
    for(int i=0;i<size;i++) {
        cout<<b[i].getN()<<endl;    
    }

    //Clean up the dynamic stuff
    delete []b;
    
    for(int i=0;i<size;i++) {
        delete a[i];    //1 Delete each individual a
    }
    delete []a;         //2 Delete array of pointers    
    
    //Exit the code
    return 0;
}

