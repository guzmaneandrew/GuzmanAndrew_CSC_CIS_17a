/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: December 6, 2022 @ 1:07 PM
 * Purpose: v8. Caller Class - deriver from Player
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
#include "Caller.h"

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only
const int NUMCRDS=54;
const int MAXBRDS=20;
const int MAXPLYR=21;

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
    vector<int> usedBrd;            //Vector to hold number of boards used
    
    //Initial Variables
    Board **boards=new Board*[MAXBRDS]; //Array of Board objects 
    Player **players=new Player*[MAXPLYR]; //Array of Player objects 
    //Create Caller for the game - creates deck for game, caller doesn't need a board
    Caller caller("Caller",nullptr,file,"cardNames.txt");
    caller.display();
    //Shuffle and display the deck, first and last cards
    cout<<"Caller will Shuffle and Display the Deck For This Game."<<endl;
    caller.shuffle();
    caller.dispDck();
    
    cout<<"First Card"<<endl;
    caller.pick(topIndx)->display();
    caller.check(topIndx);
    for(int i=topIndx;i<NUMCRDS-1;i++) {
        caller.pick(topIndx);
    }
    cout<<"Last Card"<<endl;
    caller.pick(topIndx)->display();
    caller.check(topIndx);
    
    //Create deck
//    Deck deck(file,"cardNames.txt");
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
        do{         //Pick random index to assign a random board
            rndBrd=rand()%MAXBRDS;
        } while(count(usedBrd.begin(),usedBrd.end(),rndBrd));
        usedBrd.push_back(rndBrd);      //Add index to vector to avoid double assignment
        string plyrNam="Computer "+to_string(i+1);
        players[i]=new Player(plyrNam,boards[rndBrd]);
        players[i]->display();
    }
    players[numPlyr]=&caller;       //Polymorphism - Add caller to the array of players
    players[numPlyr]->display();
    
    //Map the Inputs to the Outputs

    //Display the Inputs and Outputs
    cout<<"Number of Boards: "<<boards[0]->getCnt()<<endl;
    cout<<"Number of Boards Assigned: "<<usedBrd.size()<<endl;
    cout<<"Number of Players(includes Caller): "<<players[0]->getCnt()<<endl;

    //Clean up the dynamic stuff
    //Delete players
    for(int i=0;i<numPlyr;i++) {
        delete players[i];
    }
    delete []players;

    //Exit the code
    return 0;
}