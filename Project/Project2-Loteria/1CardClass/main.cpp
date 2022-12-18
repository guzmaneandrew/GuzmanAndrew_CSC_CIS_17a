/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: December 6, 2022 @ 1:07 PM
 * Purpose: v1. Card Class. Create names and cards array to be used for creating
 *  a Deck class.
 */

//System Libraries
#include <iostream>  //Input/output Library
#include <fstream>
using namespace std;

//User Libraries
#include "Card.h"

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only
const int NUMCRDS=54;

//Structure Definitions

//Function Prototypes
void crtArr(fstream &,string,string *);     //Create arrays from file input
bool openFil(fstream &,string);             //Opens a file for input
void filToAr(fstream &,string *);           //Saves file contents to memory

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Initialize the Random Number Seed

    //Declare Variables
    fstream file;                       //Input file
    string *names=new string[NUMCRDS];  //Array of name strings for images
    Card **cards;

    //Initial Variables
    //Get card names from file and save to array
    crtArr(file,"cardNames.txt",names);    
    
    //Initialize the deck
    int *indx=new int[NUMCRDS];
    cards=new Card*[NUMCRDS];   //An array of 52 Card Pointers
    for(int i=0;i<NUMCRDS;i++){
        cards[i]=new Card(i+1,*(names+i));  //Creation of each individual card
        indx[i]=i;
    }

    //Map the Inputs to the Outputs

    //Display the Inputs and Outputs
    for(int i=0;i<NUMCRDS;i++){
        cards[i]->display();
    }
    
    cout<<"Number of Cards: "<<cards[0]->getCnt()<<endl;

    //Clean up the dynamic stuff
    for(int i=0;i<NUMCRDS;i++){
        delete cards[i];       //Destroy each individual card
    }
    delete []cards;            //Destroy the array of pointers

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
