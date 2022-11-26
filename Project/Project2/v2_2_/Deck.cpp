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
    numCards=0;
}

Deck::Deck(int num,Card **cards) {
    deckCnt++;
    numCards=num;
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

void Deck::setNum(int num) {
    numCards=num;
}

void Deck::setDeck(Card **cards) {
    for(int i=0;i<MAX;i++) {
        deck[i]=*(*(cards+i));
    }
}

//Card Deck::getCrd() {
//    
//}
//
//bool Deck::isEmpty() {
//    
//}
//void Deck::shuffle() {
//    
//}