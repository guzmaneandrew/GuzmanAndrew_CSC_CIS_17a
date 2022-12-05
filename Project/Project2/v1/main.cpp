/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: November 22, 2022 @ 8:12 PM
 * Purpose: v1: Read from file and create arrays of Card objects
 */

//System Libraries
#include <iostream>  //Input/output Library
#include <fstream>
using namespace std;

//User Libraries
#include "Card.h"

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only
const int NUMCRDS=54;   //# of elements(lines in files,names,cards/deck)

//Structure Definitions

//Function Prototypes
void crtArr(fstream &,string,string *);     //Create arrays from file input
bool openFil(fstream &,string);             //Opens a file for input
void filToAr(fstream &,string *);           //Saves file contents to memory
string* filToAr(fstream &);                 //Saves file contents to memory
void freeMmr(Card **);                      //De-allocates memory

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    fstream file;                       //Input file
    string *names=new string[NUMCRDS];  //Array of name strings for images
    Card **cards=new Card*[NUMCRDS];    //Array of Card objects
    
    //Initial Variables
    //Get card names from file and save to array
    crtArr(file,"cardNames.txt",names);

    //Map the Inputs to the Outputs  
    //Fill array of Card objects
    for(int i=0;i<NUMCRDS;i++) {
        cards[i]=new Card(i+1,names[i]); //Instantiate and initialize each card
    }

    //Display the Inputs and Outputs
    //Print out contents of arrays and static variables
    cout<<endl<<"Contents of Cards Array"<<endl;
    for(int i=0;i<NUMCRDS;i++) {
        cards[i]->display();
        cout<<endl;
    }
    cout<<"Total Number of Cards: "<<cards[0]->getCnt()<<endl;

    //Clean up the dynamic stuff
    delete []names;
    freeMmr(cards);

    //Exit the code
    return 0;
}

void crtArr(fstream &file,string filName,string *array) {
    if(openFil(file,filName)) {
        filToAr(file,array);
        file.close();
    } else {
        cout<<"File open error!"<<endl;
    } 
}

bool openFil(fstream &file,string name) {
    file.open(name,ios::in);    //Open file for input
    
    if(file.fail()) {
        return false;
    } else
        return true;
}

void filToAr(fstream &file,string *array) {
    string line;
    for(int i=0;i<NUMCRDS;i++) {
        getline(file,line,'\n');    //Get a line from text file
        *(array+i)=line;            //Add line to array of strings
    }
}

void freeMmr(Card **cards) {
    for(int i=0;i<NUMCRDS;i++) {
        delete cards[i];    //1 Delete each individual Card object
    }
    delete []cards;         //2 Delete array of pointers 
}