/* 
 * File:   BrdDeck.h
 * Author: andrewguzman
 * BrdDeck Class Specification
 * Created on November 29, 2022, 1:44 PM
 */

#ifndef BRDDECK_H
#define BRDDECK_H
#include "BrdCard.h"
#include "Deck.h"
#include "Constants.h"
#include <string>

class BrdDeck:public Deck {
    private:
        static int deckCnt;
        BrdCard bDeck[MAX];
        bool isEmpty;
    public:
        BrdDeck();                      //Default Constructor
        BrdDeck(BrdCard **);           //Constructor
//        void display();             //Display deck
//        void setDeck(Card **);      //Create deck of cards from cards
//        int getCnt(){ return deckCnt;}//Get count of Deck objects
//        Card* pick(int &);    //Gets a pointer to top card from the deck
        BrdCard getCrd(int);             //Gets a card from deck for boards
//        void check(int &);             //Check if deck is empty
//        void shuffle();             //Shuffle the deck
};

#endif /* BRDDECK_H */

