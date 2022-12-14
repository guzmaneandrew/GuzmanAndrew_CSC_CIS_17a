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
        static const int MAX=54;
        static int deckCnt;
        Card deck[MAX];
        bool isEmpty;
    public:
        Deck();                     //Default constructor
        Deck(Card **);              //Constructor
        void display();             //Display deck
        void setDeck(Card **);      //Create deck of cards from cards
        int getCnt(){ return deckCnt;}//Get count of Deck objects
        Card pick(int &);           //Gets a card from the deck, increments reference variable
        Card getCrd(int);             //Gets a card at index in board cards
        void check(int &);             //Check if deck is empty
        void shuffle();             //Shuffle the deck
};



#endif /* DECK_H */

