/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: December 6, 2022 @ 1:07 PM
 * Purpose: v4. BrdDeck Class - derived from Deck class
 */

//System Libraries
#include <iostream>  //Input/output Library
#include <fstream>
using namespace std;

//User Libraries
#include "Card.h"
#include "Deck.h"
#include "BrdCard.h"
#include "BrdDeck.h"
#include "Board.h"

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only
const int NUMCRDS=54;
const int MAXBRDS=20;

//Structure Definitions

//Function Prototypes

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Initialize the Random Number Seed

    //Declare Variables
    fstream file;                       //Input file
    int topIndx=0;
    Board **boards=new Board*[MAXBRDS]; //Array of board objects 

    //Initial Variables
    //Create deck
    Deck deck(file,"cardNames.txt");
    //    deck.display();
//    deck.shuffle();
//    for(int i=0;i<NUMCRDS;i++) {
//        deck.pick(topIndx)->display();
//    }
//    deck.check(topIndx);
    
    //Create board deck - deck to be used for creating boards
    BrdDeck bDeck(file,"cardNames.txt");
//    topIndx=0;
//    bDeck.shuffle();
//    for(int i=0;i<NUMCRDS;i++) {
//        bDeck.pick(topIndx)->display();
//    }
//    bDeck.check(topIndx);    
    
    //Initialize boards in boards array
    for(int i=0;i<MAXBRDS;i++) {
        bDeck.shuffle();
        boards[i]=new Board(i+1,&bDeck);  
        boards[i]->dispBrd();
        boards[i]->brd2Fil(i+1);
    }
    
    //Map the Inputs to the Outputs

    //Display the Inputs and Outputs
    cout<<"Number of Decks: "<<deck.getCnt()<<endl;
    cout<<"Number of Boards: "<<boards[0]->getCnt()<<endl;

    //Clean up the dynamic stuff

    //Exit the code
    return 0;
}