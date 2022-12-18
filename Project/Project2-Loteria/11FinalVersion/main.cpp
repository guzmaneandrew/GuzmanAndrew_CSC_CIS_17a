/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: December 8, 2022 @ 11:07 AM
 * Purpose: v11. Implement game logic.
 */

//System Libraries
#include <iostream>  //Input/output Library
#include <fstream>   //File stream
#include <vector>    //Vector
#include <algorithm> //count()
using namespace std;

//User Libraries
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
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    fstream file;                   //Input file
    int topIndx=0,                  //Index of card at top of deck
        numPlyr,                    //Number of computer players
        rndBrd,                     //Random board number
        input,                      //Read input from caller
        nWinnrs=0,                  //Number of winners for the game
        nRounds=0;                  //Number of rounds in game
    vector<int> usedBrd;            //Vector to hold number of boards used
    Card* topCrd;                   //Pointer to card at the top of the deck
    string crdName;                 //Name of card
    bool tryAgain=true;             //Flag to reread input
    
    //Initial Variables
    Board **boards=new Board*[MAXBRDS];     //Array of Board objects 
    Player **players=new Player*[MAXPLYR]; //Array of Player objects 
    //Create Caller for the game - creates deck for game, caller doesn't need a board
    Caller caller("Caller",nullptr,file,"cardNames.txt");
    //Create board deck - deck to be used for creating boards
    Deck<BrdCard> bDeck(file,"cardNames.txt");

    //Map the Inputs to the Outputs
    for(int i=0;i<MAXBRDS;i++) {      //Initialize random boards in boards array
        bDeck.shuffle();
        boards[i]=new Board(i+1,&bDeck);
        boards[i]->brd2Fil(i+1);
    }
    
    cout<<"LOTERÍA"<<endl;
    while(tryAgain) {
        try {
            cout<<"How Many Players(2 to 20): ";
            cin>>numPlyr;
            if(numPlyr<2||numPlyr>20) {
                throw 1;
            }
            tryAgain=false;
        }
        catch(int e) {
            cout<<"Invalid Number Of Players"<<endl;
        }        
    }
    
    //Create number of players and give each player a board at random
    for(int i=0;i<numPlyr;i++) {      
        do{         //Pick random index to assign a random board
            rndBrd=rand()%MAXBRDS;
        } while(count(usedBrd.begin(),usedBrd.end(),rndBrd));
        usedBrd.push_back(rndBrd);      //Add index to vector to avoid double assignment
        string plyrNam="Computer "+to_string(i+1);
        players[i]=new Player(plyrNam,boards[rndBrd]);
    }
    players[numPlyr]=&caller;       //Polymorphism - Add caller to the array of players   
    

    //Display the Inputs and Outputs
    cout<<"This Is A Game Of Lotería With "<<players[0]->getCnt()<<" Players: "
          <<numPlyr<<" Computer Players Plus You As The Caller.\n\n"
          "The Caller Shuffles The Deck And Picks Cards From The Deck.\n"
          "Players Will Search For Matching Cards On Their Boards.\n"
          "In Order To Win, A Player's Board Must Be Full.\n"
          "All Boards Generated For This Game Have Been Saved To Files.\n";
    
    do {   
        cout<<"Press 1 to Preview Each Player's Board: ";
        cin>>input;
    } while(input!=1);
    
    for(int i=0;i<=numPlyr;i++) { //Display Player's Full Boards
        players[i]->display();
    }
    
    do {
        cout<<"Press 1 to Shuffle The Deck: ";
        cin>>input;
    }while(input!=1);
    caller.shuffle();
    cout<<"Deck Shuffled!"<<endl;
    
    //Play game while deck is not empty and no winners
    while(topIndx<54&&nWinnrs==0) {
        nRounds++;
        cout<<"------------------------------------------------------------"<<endl;
        cout<<"ROUND "<<nRounds<<": "<<endl;

        do {
            cout<<"Press 0 to Pull A Card From The Shuffled Deck: ";
            cin>>input;
        }while(input!=0);
        
        if(input==0) {
            //Pick card and name of card that caller picks from the deck    
            topCrd=caller.pick(topIndx);
            crdName=topCrd->getName();
            topIndx++;      //Increment top index to pick next card in deck

            //Send the card info to the computer players to check their boards
            for(int i=0;i<numPlyr;i++) {
                players[i]->chkBrd(crdName);
            }
            
            //Display mini board pattern on screen
            for(int i=0;i<numPlyr;i++) {
                players[i]->dispMBrd();
            }
            
            topCrd->display();  //Display the card the was just picked

            //Check if any of the players have indicated that their board is filled
            //Increment number of winners if needed
            for(int i=0;i<numPlyr;i++) {
                if(players[i]->chkWin()){ 
                    nWinnrs++;
                }
            }
            
            if(nWinnrs!=0) {
                cout<<"------------------------Game Over---------------------------"<<endl;    
            }

        }
    }
    
    cout<<"Number of Boards: "<<boards[0]->getCnt()<<endl;
    cout<<"Number of Boards Assigned: "<<usedBrd.size()<<endl;
    cout<<"Number of Players(Including The Caller): "<<players[0]->getCnt()<<endl;
    cout<<"Number of Rounds Played: "<<nRounds<<endl;
    cout<<"Number of Winners For This Round: "<<nWinnrs<<endl;

    //Clean up the dynamic stuff
    //Delete players
    for(int i=0;i<numPlyr;i++) {
        delete players[i];
    }
    delete []players;

    //Exit the code
    return 0;
}