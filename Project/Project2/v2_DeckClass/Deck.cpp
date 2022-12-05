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
    for(int i=0;i<MAX;i++) {
        Card card(i," ");
        deck[i]=card;
    }
}

Deck::Deck(Card **cards) {
    deckCnt++;
    for(int i=0;i<MAX;i++) {
        deck[i]=*(*(cards+i));
    }
}

void Deck::setDeck(Card **cards) {
    for(int i=0;i<MAX;i++) {
        deck[i]=*(*(cards+i));
    }
}

void Deck::display() {
    cout<<"Deck"<<endl;
    for(int i=0;i<MAX;i++) {
        deck[i].display();
    }
    cout<<endl;
}

Card* Deck::pick(int &index) {
    Card *crdPtr=&deck[index];
    
    index++;                        //Increment curIndx to pick next card 
    return crdPtr;
}

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
    
    cout<<"Shuffled ";
    for(int shffl=1;shffl<7;shffl++) {
        for(int index=0;index<MAX;index++) {
            do {        //Random index must not equal to current index
                rndIndx=rand()%MAX;
            }while(index==rndIndx);
            //Swap card at current index with card at random index
            Card temp=deck[index];
            deck[index]=deck[rndIndx];
            deck[rndIndx]=temp;
        }
    }
}