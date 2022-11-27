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
    //deck in Deck class of type Card, default constructor for Card creates
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
}

void Deck::display() {
    cout<<"Deck"<<endl;
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