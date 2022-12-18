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

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only
const int NUMCRDS=54;

//Structure Definitions

//Function Prototypes

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Initialize the Random Number Seed

    //Declare Variables
    fstream file;                       //Input file
    int topIndx=0;

    //Initial Variables
    Deck deck(file,"cardNames.txt");
    BrdDeck bDeck(file,"cardNames.txt");

    //Map the Inputs to the Outputs

    //Display the Inputs and Outputs
//    deck.display();
    deck.shuffle();
    for(int i=0;i<NUMCRDS;i++) {
        deck.pick(topIndx)->display();
    }
    deck.check(topIndx);
    
    topIndx=0;
    bDeck.shuffle();
    for(int i=0;i<NUMCRDS;i++) {
        bDeck.pick(topIndx)->display();
    }
    bDeck.check(topIndx);

    cout<<"Number of Decks: "<<deck.getCnt()<<endl;

    //Clean up the dynamic stuff

    //Exit the code
    return 0;
}