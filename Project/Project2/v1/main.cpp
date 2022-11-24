/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: November 22, 2022 @ 8:12 PM
 * Purpose: v1: Read from file and create arrays of Image and Card objects
 */

//System Libraries
#include <iostream>  //Input/output Library
#include <fstream>
using namespace std;

//User Libraries
#include "Image.h"
#include "Card.h"

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only
const int NUMELMS=54;   //# of elements(lines in files,names,riddles,images,cards/deck)

//Structure Definitions

//Function Prototypes
bool openFil(fstream &,string);             //Opens a file for input
string* filToAr(fstream &);                 //Saves file contents to memory
void freeMmr(Image **);                     //De-allocates memory
void freeMmr(Card **);                      //De-allocates memory


//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    fstream dataFile;                   //Input files
    string *riddles=nullptr,            //Array of riddle strings for images
           *names=nullptr;              //Array of names for images
    
    //Initial Variables
    //Get card names from cardNames.txt file and save to names array   
    if(openFil(dataFile,"cardNames.txt")) {
        names=filToAr(dataFile);    
        dataFile.close();
    } else {
        cout<<"File open error!"<<endl;
    }

    //Get card riddles from cardRiddles.txt file and save to riddles array
    if(openFil(dataFile,"cardRiddles.txt")) {
        riddles=filToAr(dataFile);  
        dataFile.close();
    } else {
        cout<<"File open error!"<<endl;
    }

    //Map the Inputs to the Outputs
    //Create array of Image objects
    Image **imgs=new Image*[NUMELMS];
    for(int i=0;i<NUMELMS;i++) {
        imgs[i]=new Image(riddles[i],names[i]); //Instantiate and initialize image
    }
    
    //Create array of Card objects
    Card **cards=new Card*[NUMELMS];
    for(int i=0;i<NUMELMS;i++) {
        cards[i]=new Card(i+1,imgs[i]); //Instantiate and initialize image
    }

    //Display the Inputs and Outputs
    cout<<"Contents of Images Array"<<endl;
    for(int i=0;i<NUMELMS;i++) {
        imgs[i]->display();
        cout<<endl;
    }
    
    cout<<endl<<"Contents of Cards Array"<<endl;
    for(int i=0;i<NUMELMS;i++) {
        cards[i]->display();
        cout<<endl;
    }

    //Clean up the dynamic stuff
    freeMmr(imgs);
    freeMmr(cards);

    //Exit the code
    return 0;
}

bool openFil(fstream &file,string name) {
    file.open(name,ios::in);    //Open file for input
    
    if(file.fail()) {
        return false;
    } else
        return true;
}

string* filToAr(fstream &file) {
    string *items=new string[NUMELMS];
    string line;
    for(int i=0;i<NUMELMS;i++) {
        getline(file,line,'\n');    //Get a line from text file
        *(items+i)=line;            //Add line to array of strings
    }
    return items;
}

void freeMmr(Image **imgs) {
    for(int i=0;i<NUMELMS;i++) {
        delete imgs[i];    //1 Delete each individual Image object
    }
    delete []imgs;         //2 Delete array of pointers    
}

void freeMmr(Card **cards) {
    for(int i=0;i<NUMELMS;i++) {
        delete cards[i];    //1 Delete each individual Card object
    }
    delete []cards;         //2 Delete array of pointers 
}