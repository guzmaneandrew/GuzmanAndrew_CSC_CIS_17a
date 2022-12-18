/* 
 * File:   Deck.h
 * Author: andrewguzman
 * Deck Class Specification
 * Created on December 6, 2022, 1:32 PM
 */

#ifndef DECK_H
#define DECK_H

#include "Card.h"

class Deck {
protected:
    static int dckCnt;      //Count of Deck objects
    static const int MAX=54;    //Max size of deck
    string *names;          //Array of names for creating cards in deck
    Card **cards;           //Array of cards
    int *index;             //Array of indexes
    bool isEmpty;           //Flag to mark if deck is empty
    string *crtArr(fstream &,string);       //Create arrays from file input
    bool openFil(fstream &,string);             //Opens a file for input
    void filToAr(fstream &,string *);           //Saves file contents to memory
public:
    Deck(fstream &,string); //Constructor - use file to construct file
//    Deck(string *);         //Constructor
    ~Deck();                //Destructor
    int getCnt() { return dckCnt; }     //Get count of Deck objects
    void display();         //Display the deck
    void shuffle();         //Shuffle the deck
    Card* pick(int &);      //Picks top card from the deck
    void check(int &);      //Check if the deck is empty
};


#endif /* DECK_H */

