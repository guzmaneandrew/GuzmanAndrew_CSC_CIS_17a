/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: October 24, 2022 @ 1:15 PM
 * Purpose: Card Elements: Implement function to shuffle deck of cards and deal
 */

//System Libraries
#include <iostream>  //Input/output Library
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries
#include "Card.h"

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only

//Structure Definitions

//Function Prototypes
void shuffle(Card *,int);   //Shuffle a deck of cards
void deal(Card *,int,Card *,int,int &);      //Deal cards

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    srand(static_cast<unsigned int>(time(0)));

    //Declare Variables
    const int numCrds=52;
    Card cards[numCrds];    //Created an array of card elements
    const int nHand=5;      //number of cards in a hand
    Card hand[nHand];       //Created an array of cards in hand

    //Initial Variables
    //Set each of the card elements in original array/deck and print
    cout<<"The Original Deck of Cards"<<endl<<endl;
    for(int i=0;i<52;i++) {
        cards[i].setNum(i+1);
        cout<<"Card "<<setw(2)<<i+1<<": "<<cards[i].fVal()<<cards[i].sVal()<<" ";
        cout<<"Card Count Value= "<<cards[i].nVal()<<endl; 
    }
    
    //Shuffle the deck/array of card elements
    shuffle(cards,numCrds);
    //Print shuffled cards
    cout<<"The Shuffled Deck of Cards"<<endl<<endl;
    for(int i=0;i<52;i++) {
        cout<<"Card "<<setw(2)<<i+1<<": "<<cards[i].fVal()<<cards[i].sVal()<<" ";
        cout<<"Card Count Value= "<<cards[i].nVal()<<endl; 
    }
    
    //Deal cards twice
    int nDealt=0;
    deal(cards,numCrds,hand,nHand,nDealt);
    //Print dealt cards
    cout<<"The Hand Dealt from Shuffled Deck "<<nDealt<<endl;
    cout<<"Number Dealt = "<<nDealt<<endl;
    for(int i=0;i<nHand;i++) {
        cout<<"Card "<<setw(2)<<i+1<<": "<<hand[i].fVal()<<hand[i].sVal()<<" ";
        cout<<"Card Count Value= "<<hand[i].nVal()<<endl; 
    }
    
    deal(cards,numCrds,hand,nHand,nDealt);
    //Print dealt cards
    cout<<"The Hand Dealt from Shuffled Deck "<<nDealt<<endl;
    cout<<"Number Dealt = "<<nDealt<<endl;
    for(int i=0;i<nHand;i++) {
        cout<<"Card "<<setw(2)<<i+1<<": "<<hand[i].fVal()<<hand[i].sVal()<<" ";
        cout<<"Card Count Value= "<<hand[i].nVal()<<endl; 
    }

    //Map the Inputs to the Outputs

    //Display the Inputs and Outputs

    //Clean up the dynamic stuff

    //Exit the code
    return 0;
}

void shuffle(Card *cards,int nc) {
    for(int shfl=1;shfl<=7;shfl++)
    {  //7 times to make it look pretty random
        for(int crd=0;crd<nc;crd++) {
            int choice;   //randomly choose a random card to swap with
            do{
                choice=rand()%nc;
            }while(choice==crd);
            
            Card temp=cards[crd];   //Swap
            cards[crd]=cards[choice];
            cards[choice]=temp;
        }
    }
}

void deal(Card *cards,int nc,Card *hand,int nh,int &nDlt) {
    for(int crd=nDlt,indxH=0;crd<nDlt+nh;crd++,indxH++) {   //multiple counters [0-nh][0-52]
        hand[indxH]=cards[crd];
    }
    nDlt+=nh;
}