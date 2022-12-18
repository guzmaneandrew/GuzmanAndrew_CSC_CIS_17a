/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: November 22, 2022 @ 8:12 PM
 * Purpose: v6. Create a Player class
 */

//System Libraries
#include <iostream>  //Input/output Library
#include <fstream>
using namespace std;

//User Libraries
#include "Card.h"
#include "BrdCard.h"
#include "Deck.h"
#include "BrdDeck.h"
#include "Board.h"
#include "Player.h"

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only
const int NUMCRDS=54;   //# of cards to be generated for the game
const int MAXBRDS=20;   //# of boards to be generated for the game
const int MAXPLYRS=20;  //Max # players per game

//Structure Definitions

//Function Prototypes
void crtArr(fstream &,string,string *);     //Create arrays from file input
bool openFil(fstream &,string);             //Opens a file for input
void filToAr(fstream &,string *);           //Saves file contents to memory
string* filToAr(fstream &);                 //Saves file contents to memory
void freeMmr(Card **);                      //De-allocates memory
void freeMmr(Board **);                     //De-allocates memory

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    fstream file;                       //Input file
    string *names=new string[NUMCRDS];  //Array of name strings for images
    Card **cards=new Card*[NUMCRDS];    //Array of Card objects
    BrdCard **brdCrds=new BrdCard*[NUMCRDS]; //Array of cards used for creating boards
    Deck *deck=nullptr;                 //Pointer to deck of cards for game
    BrdDeck *brdDeck=nullptr;           //Pointer to deck of cards for creating boards
    Card *topCard=nullptr;              //Pointer to top card of the deck
    int topIndx=0,                      //Index of the card at the top
        nPlyrs;                         //Number of players
    Board **boards=new Board*[MAXBRDS]; //Array of board objects
    Player **playrs=new Player*[MAXPLYRS];  //Array of player objects
    
    //Initial Variables
    //Get card names from file and save to array
    crtArr(file,"cardNames.txt",names);

    //Map the Inputs to the Outputs  
    //1Fill array of Card objects
    for(int i=0;i<NUMCRDS;i++) {
        cards[i]=new Card(i+1,names[i]); //Instantiate and initialize each card
    }
   
    //1.5Fill brdCrds array to be used for creating boards
    for(int i=0;i<NUMCRDS;i++) {
        brdCrds[i]=new BrdCard(i+1,names[i]);
    }
    
    //2Create a deck of cards
    deck=new Deck(cards);
    cout<<"Original Deck\n";
//    deck->display();
    
//    //3 Create pointer to first card in deck and display it
//    topCard=deck->pick(topIndx);
//    cout<<"Top Card of Original Deck\n";
//    topCard->display();
//    
//    //4 Check if deck is empty
//    deck->check(topIndx);
//    
//    //5 Pick top card from the deck successfully until reach end of deck
//    for(int i=topIndx;i<NUMCRDS;i++) {
//        topCard=deck->pick(topIndx);
//    } 
//    
//    //6 Display last card in deck and check if deck is empty
//    cout<<"Last Card of Original Deck\n";
//    topCard->display();
//    deck->check(topIndx);
//    
//    //7 Shuffle the deck of cards and display it
//    cout<<"Shuffled Deck\n";
//    deck->shuffle();
//    deck->display();
//    
//    //8 Display first card in shuffled deck and check if deck is empty
//    topIndx=0;              //Reset topIndx=0
//    topCard=deck->pick(topIndx);
//    cout<<"Top Card of Shuffled Deck\n";
//    topCard->display();
//    deck->check(topIndx);
//    
//    //9 Pick top card from the deck successfully until reach end of deck
//    for(int i=topIndx;i<NUMCRDS;i++) {
//        topCard=deck->pick(topIndx);
//    } 
//    
//    //10 Display last card in shuffled deck and check if deck is empty
//    cout<<"Last Card of Shuffled Deck\n";
//    topCard->display();
//    deck->check(topIndx);
    
    //11 Create a deck of cards for boards
    brdDeck=new BrdDeck(brdCrds);    
    
    //12Fill array of board objects using brdDeck, shuffle each time
    for(int i=0;i<MAXBRDS;i++) {
        brdDeck->shuffle();
        boards[i]=new Board(i+1,brdDeck);
        boards[i]->brd2Fil(i+1);
    }
    
    //13 Create and print Player objects
    for(int i=0;i<MAXPLYRS;i++) {
        string plyrNam="Computer "+to_string(i+1);
        playrs[i]=new Player(plyrNam);
        playrs[i]->setBrd(boards[i]);
        cout<<playrs[i]->getName()<<"'s Board\n";
        playrs[i]->prntBrd();
    }
    
    //Display the Inputs and Outputs
    //Print out contents of arrays and static variables
//    cout<<endl<<"Contents of Cards Array"<<endl;
//    for(int i=0;i<NUMCRDS;i++) {
//        cards[i]->display();
//        cout<<endl;
//    }
//    
//    cout<<endl<<"Contents of Board Cards Array"<<endl;
//    for(int i=0;i<NUMCRDS;i++) {
//        brdCrds[i]->display();
//        cout<<endl;
//    }
    
    cout<<"Total Number of Cards: "<<cards[0]->getCnt()<<endl;
    cout<<"Total Number of Decks: "<<deck->getCnt()<<endl;
    cout<<"Total Number of Board Cards: "<<brdCrds[0]->getCnt()<<endl;
    cout<<"Total Number of Boards: "<<boards[0]->getCnt()<<endl;
    cout<<"Total Number of Players: "<<playrs[0]->getPCnt()<<endl;

    //Clean up the dynamic stuff
    delete []names;
    delete deck;
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