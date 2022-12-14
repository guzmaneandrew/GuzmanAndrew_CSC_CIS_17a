/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: November 22, 2022 @ 8:12 PM
 * Purpose: v4: Create Board Card class and objects. Create Board class and objects.
 */

//System Libraries
#include <iostream>  //Input/output Library
#include <fstream>
using namespace std;

//User Libraries
#include "Image.h"
#include "Card.h"
#include "Deck.h"
//#include "BrdDeck.h"
#include "BrdCard.h"
#include "Board.h"

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only

//Structure Definitions

//Function Prototypes
void crtArr(fstream &,string,string *);     //Create arrays from file input
bool openFil(fstream &,string);             //Opens a file for input
void filToAr(fstream &,string *);           //Saves file contents to memory
void freeMmr(Image **);                     //De-allocates memory
void freeMmr(Card **);                      //De-allocates memory

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //0Declare Variables
    fstream file;                       //Input file
    string *names=new string[NUMELMS],  //Array of name strings for images
           *riddles=new string[NUMELMS];//Array of riddle strings for images
    Image **imgs=new Image*[NUMELMS];   //Array of Image objects
    Card **cards=new Card*[NUMELMS];    //Array of Card objects used for creating deck and boards
    BrdCard **brdCrds=new BrdCard*[NUMELMS]; //Array of cards used for creating boards
    Deck *deck=nullptr,              //Pointer to deck of cards for game
         *brdDeck=nullptr;              //Pointer to deck of cards used to create boards
    Card *topCard=nullptr;               //Pointer to top card of the deck   
    int cardIdx=0;                      //Index of card at the "top"
    Board *gameBrd=nullptr;               //Pointer to a board
    Board **boards=new Board*[MAXBRDS]; //Array of Image objects
    
    //Initial Variables
    //Get card names and riddles from files and save to arrays 
    crtArr(file,"cardNames.txt",names);
    crtArr(file,"cardRiddles.txt",riddles);

    //Map the Inputs to the Outputs
    //1Fill array of Image objects
    for(int i=0;i<NUMELMS;i++) {
        imgs[i]=new Image(riddles[i],names[i]); //Instantiate and initialize each image
    }
    
    //2Fill array of cards to be used for game deck
    for(int i=0;i<NUMELMS;i++) {
        Image img=*(*(imgs+i));         //Don't need to create a new image
        Image *imgPtr=&img;             //Need pointer to an Image for card
        cards[i]=new Card(i+1,imgPtr); //Instantiate and initialize each card
//        cards[i]=new Card(i+1,imgs[i]);//Don't use - makes copy of image, need pointer
    }
    
    //3Fill brdCrds array to be used for creating boards
    for(int i=0;i<NUMELMS;i++) {
          brdCrds[i]=new BrdCard(i+1,imgs[i]);//Use this to make copy of images
//        Image img=*(*(imgs+i));         //Dont use- this skips creating a new image
//        Image *imgPtr=&img;             //and gets pointer to an Image for card
//        brdCrds[i]=new BrdCard(i+1,imgPtr); //Instantiates and initializes each card
    }
    
    //4Create a deck of cards for game and display it
    deck=new Deck(cards);    
    deck->shuffle();
    cout<<"Shuffled Game Cards Deck\n";
    deck->display();
    
    //5Create a deck of cards for boards and display it
    brdDeck=new Deck(brdCrds);    
    brdDeck->shuffle();
    cout<<"Shuffled Board Cards Deck\n";
    brdDeck->display();
    
//    //6 Display first card in deck and check if deck is empty
//    topCard=deck->pick(cardIdx);
//    cout<<"Top Card\n";
//    topCard->display();
//    deck->check(cardIdx);
//    
//    //9 Create an empty board
//    gameBrd=new Board();
//    gameBrd->display();
    
    //10 Create a board using brdDeck
    
    //Fill array of BOARD objects
//    for(int i=0;i<MAXBRDS;i++) {
//        boards[i]=new Board();
//    }
    
    //Display the Inputs and Outputs
    //Print out contents of arrays and static variables
//    cout<<"Contents of Images Array"<<endl;
//    for(int i=0;i<3;i++) {
//        imgs[i]->display();
//        cout<<endl;
//    }
//    cout<<endl<<"Contents of Cards Array"<<endl;
//    for(int i=0;i<3;i++) {
//        cards[i]->display();
//        cout<<endl;
//    }
    cout<<"Total Number of Images: "<<imgs[0]->getCnt()<<endl;
    cout<<"Total Number of Cards: "<<cards[0]->getCnt()<<endl;
    cout<<"Total Number of Board Cards: "<<brdCrds[0]->getCnt()<<endl;
    cout<<"Total Number of Decks: "<<deck->getCnt()<<endl;
    cout<<"Total Number of Boards: "<<gameBrd->getCnt()<<endl;

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