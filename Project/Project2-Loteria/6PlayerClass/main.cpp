/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: December 6, 2022 @ 1:07 PM
 * Purpose: v6. Player Class 
 */

//System Libraries
#include <iostream>  //Input/output Library
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

//User Libraries
#include "Card.h"
#include "Deck.h"
#include "BrdCard.h"
#include "BrdDeck.h"
#include "Board.h"
#include "Player.h"

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only
const int NUMCRDS=54;
const int MAXBRDS=20;
const int MAXPLYR=10;

//Structure Definitions

//Function Prototypes

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Initialize the Random Number Seed

    //Declare Variables
    fstream file;                       //Input file
    int topIndx=0,                  //Index of "top" card
        numPlyr,                    //Number of computer players
        rndBrd;                     //Random board number
    Board **boards=new Board*[MAXBRDS]; //Array of Board objects 
    Player **players=new Player*[MAXPLYR]; //Array of Player objects 
    vector<int> usedBrd;            //Vector to hold number of boards used

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
        boards[i]->brd2Fil(i+1);
    }
    
    //Create number of players and give each player a random board
    cout<<"How many players(up to 10): ";
    cin>>numPlyr;
    for(int i=0;i<numPlyr;i++) {      
        do{
            rndBrd=rand()%MAXBRDS;
        } while(count(usedBrd.begin(),usedBrd.end(),rndBrd));
        usedBrd.push_back(rndBrd);
        string plyrNam="Computer"+to_string(i+1);
        players[i]=new Player(plyrNam,boards[rndBrd]);
        players[i]->prntBrd();
    }
    
    //Map the Inputs to the Outputs

    //Display the Inputs and Outputs
    cout<<"Number of Decks: "<<deck.getCnt()<<endl;
    cout<<"Number of Boards: "<<boards[0]->getCnt()<<endl;
    cout<<"Number of Players: "<<players[0]->getCnt()<<endl;

    //Clean up the dynamic stuff

    //Exit the code
    return 0;
}