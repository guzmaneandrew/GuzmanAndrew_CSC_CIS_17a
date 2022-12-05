/* 
 * File:   Deck.h
 * Author: andrewguzman
 * Deck Class Specification
 * Created on November 25, 2022, 3:24 PM
 */

#ifndef DECK_H
#define DECK_H
#include "Card.h"
#include <string>

class Deck {
    private:
        static const int MAX=54;    //Max size of deck
        static int deckCnt;         //Static count of number of deck objects
        Card deck[MAX];             //Deck of cards
        bool isEmpty;               //Flag to check if deck is empty
    public:
        Deck();                     //Default constructor
        Deck(Card **);              //Constructor
        void setDeck(Card **);      //Create deck of cards from cards
        int getCnt(){ return deckCnt; }//Get count of Deck objects
        void display();             //Display deck
        Card* pick(int &);           //Returns pointer to top card of the deck
        void check(int &);          //Check if deck is empty
        void shuffle();             //Shuffle the deck
        friend class BrdDeck;
};

#endif /* DECK_H */

