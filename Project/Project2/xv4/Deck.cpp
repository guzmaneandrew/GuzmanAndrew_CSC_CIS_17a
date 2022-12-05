/* 
 * File:   Deck.h
 * Author: andrewguzman
 * Deck Class Implementation
 * Created on November 25, 2022, 3:24 PM
 */

#include <string>
#include <iostream>
#include "Card.h"
#include "Deck.h"

int Deck::deckCnt=0;        //Define static variables outside of the class

Deck::Deck() {
    deckCnt++;
    isEmpty=true;
    //deck in Deck class of type Card
    //Declaring the deck uses the default constructor for Card which creates
    //deck of empty cards pointing to nullptr
    //code below creates bugs with making more cards and images than we need
//    for(int i=0;i<MAX;i++) {
//        Image img=new Image();
//        Image *imgPtr=&img;
//        Card card=new Card(i+1,imgPtr);
//        Card card=new Card();
//        deck[i]=card;
//    }
}

Deck::Deck(Card **cards) {
    deckCnt++;
    for(int i=0;i<MAX;i++) {
        deck[i]=*(*(cards+i));
    }
    isEmpty=false;
}

Deck::Deck(BrdCard **cards) {
    deckCnt++;
    for(int i=0;i<MAX;i++) {
        BrdCard card(*(cards+i));
        deck[i]=card;
    }
    isEmpty=false;
}

void Deck::display() {
    for(int i=0;i<MAX;i++) {
        deck[i].display();
    }
    cout<<endl;
}

void Deck::setDeck(Card **cards) {
    for(int i=0;i<MAX;i++) {
        deck[i]=*(*(cards+i));
    }
}
//* DONT DELETE
Card* Deck::pick(int &index) {
    Card *crdPtr=&deck[index];
    
    index++;                        //Increment curIndx to pick next card 
    return crdPtr;
}
//* DONT DELETE

//Card Deck::getCrd(int index) {
//    Card card=deck[index];
//    return card;
//}

void Deck::check(int &index) {
    if(index==MAX) {
        cout<<"The deck is empty.\n\n";
        isEmpty=true;
    } else {
        cout<<"The deck is not empty.\n\n";
    }
}

void Deck::shuffle() {
    int rndIndx;        //Random card index
    
    for(int shffl=1;shffl<7;shffl++) {
        for(int index=0;index<NUMELMS;index++) {
            do {        //Random index must not equal to current index
                rndIndx=rand()%NUMELMS;
            }while(index==rndIndx);
            //Swap card at current index with card at random index
            Card temp=deck[index];
            deck[index]=deck[rndIndx];
            deck[rndIndx]=temp;
        }
    }
}