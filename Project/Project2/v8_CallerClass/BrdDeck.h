/* 
 * File:   BrdDeck.h
 * Author: andrewguzman
 *
 * Created on December 5, 2022, 1:12 AM
 */

#ifndef BRDDECK_H
#define BRDDECK_H
#include "BrdCard.h"
#include "Deck.h"
#include <string>

class BrdDeck:public Deck {
    private:
        static int const MAX=54;
        static int bDckCnt;
        BrdCard bDeck[MAX];
        bool isEmpty;
    public:
        BrdDeck();                      //Default Constructor
        BrdDeck(BrdCard **);           //Constructor
        void setDeck(BrdCard **);      //Create deck of cards from cards
        int getCnt(){ return bDckCnt;}//Get count of Deck objects
        void display();                   //Display board card
        BrdCard getCrd(int);             //Gets a card from deck for boards
        void shuffle();                 //shuffles the deck of board cards
};

#endif /* BRDDECK_H */

