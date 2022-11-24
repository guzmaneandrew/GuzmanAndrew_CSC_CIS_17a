/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: November 23, 2022 @ 10:15 PM
 * Purpose: v2: Implement functions to shuffle and pick top card from deck
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
void crtArr(fstream &,string,string *);     //Create arrays from file input
bool openFil(fstream &,string);             //Opens a file for input
void filToAr(fstream &,string *);           //Saves file contents to memory
string* filToAr(fstream &);                 //Saves file contents to memory
void shuffle(Card **);                      //Shuffle deck of cards
Card pick(Card **,int &);                   //Pick card from deck of cards
void freeMmr(Image **);                     //De-allocates memory
void freeMmr(Card **);                      //De-allocates memory

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    fstream file;                       //Input file
    string *names=new string[NUMELMS],  //Array of name strings for images
           *riddles=new string[NUMELMS];//Array of riddle strings for images
    Image **imgs=new Image*[NUMELMS];   //Array of Image objects
    Card **cards=new Card*[NUMELMS];    //Array of Card objects/deck of cards
    int topIndx=0;                      //Index of card at "top" of the deck
    
    //Initial Variables
    //Get card names and riddles from files and save to arrays 
    crtArr(file,"cardNames.txt",names);
    crtArr(file,"cardRiddles.txt",riddles);

    //Map the Inputs to the Outputs
    //Fill array of Image objects
    for(int i=0;i<NUMELMS;i++) {
        imgs[i]=new Image(riddles[i],names[i]); //Instantiate and initialize each image
    }
    
    //Fill array of Card objects
    for(int i=0;i<NUMELMS;i++) {
        cards[i]=new Card(i+1,imgs[i]); //Instantiate and initialize each card
    }
    
    //Shuffle deck of cards
    shuffle(cards);
    
    //Pick card from top of deck
    Card topCard=pick(cards,topIndx);
    topCard.display();
    
    //Display the Inputs and Outputs
    //Print out contents of arrays and static variables
//    cout<<"Contents of Images Array"<<endl;
//    for(int i=0;i<NUMELMS;i++) {
//        imgs[i]->display();
//        cout<<endl;
//    }
    cout<<endl<<"Contents of Cards Array"<<endl;
    for(int i=0;i<NUMELMS;i++) {
        cards[i]->display();
        cout<<endl;
    }
    cout<<"Total Number of Images: "<<imgs[0]->getCnt()<<endl;
    cout<<"Total Number of Cards: "<<cards[0]->getCnt()<<endl;

    //Clean up the dynamic stuff
    delete []riddles;
    delete []names;
    freeMmr(imgs);
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
    for(int i=0;i<NUMELMS;i++) {
        getline(file,line,'\n');    //Get a line from text file
        *(array+i)=line;            //Add line to array of strings
    }
}

void shuffle(Card **cards) {
    int rndIndx;        //Random card index
    
    for(int shffl=1;shffl<7;shffl++) {
        for(int index=0;index<NUMELMS;index++) {
            do {        //Random index must not equal to current index
                rndIndx=rand()%NUMELMS;
            }while(index==rndIndx);
            //Swap card at current index with card at random index
            Card temp=*(*(cards+index));
            *(*(cards+index))=*(*(cards+rndIndx));
            *(*(cards+rndIndx))=temp;
        }
    }
}

Card pick(Card **cards,int &curIndx) {
    cout<<"TOP CARD"<<endl;
    Card topCard=*(*(cards+curIndx)); //Card at curIndx is on "top" of the deck
    curIndx++;                        //Increment curIndx to pick next card 
    return topCard;
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