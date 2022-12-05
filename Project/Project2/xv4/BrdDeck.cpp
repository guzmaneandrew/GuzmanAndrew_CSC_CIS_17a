/* 
 * File:   BrdDeck.h
 * Author: andrewguzman
 * BrdDeck Class Implementation
 * Created on November 29, 2022, 1:44 PM
 */
#include <string>
#include <iostream>
#include "BrdCard.h"
#include "BrdDeck.h"

int BrdDeck::deckCnt=0;        //Define static variables outside of the class

BrdDeck::BrdDeck():Deck() {
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

//BrdDeck::BrdDeck(BrdCard **cards):Deck() {
//    deckCnt++;
//    for(int i=0;i<NUMELMS;i++) {
////        BrdCard card(*(cards+i));
//        bDeck[i]=*(cards+i);
//    }
//    isEmpty=false;
//}

//BrdDeck::BrdDeck(BrdCard **cards) {
//    deckCnt++;
//    for(int i=0;i<MAX;i++) {
//        BrdCard card(*(cards+i));
//        bDeck[i]=card;
//    }
//    isEmpty=false;
//}

BrdCard BrdDeck::getCrd(int index) {
    BrdCard card=bDeck[index];
    return card;
}