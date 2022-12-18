/* 
 * File:   BrdDeck.h
 * Author: andrewguzman
 * BrdDeck Class Specification
 * Created on December 5, 2022, 1:12 AM
 */

#ifndef BRDDECK_H
#define BRDDECK_H
#include "BrdCard.h"
#include "Deck.h"
#include <string>

class BrdDeck:public Deck {
    private:
        static int bDckCnt;     //Count of objects
        static int const MAX=54; //Max size of deck
        string *names;          //Array of names on board cards
        BrdCard **bCards;       //Array of board cards
        int *index;             //Array of indexes
        bool isEmpty;           //Flag to mark if deck is empty
        string *crtArr(fstream &,string);       //Create arrays from file input
        bool openFil(fstream &,string);             //Opens a file for input
        void filToAr(fstream &,string *);           //Saves file contents to memory
        
    public:
        BrdDeck(fstream &,string); //Constructor - use file to construct file
//        BrdDeck(string *);         //Constructor
        ~BrdDeck();                //Destructor
        int getCnt(){ return bDckCnt;}//Get count of Deck objects
        void display();                   //Display board card
        BrdCard getCrd(int);             //Gets a card from deck for boards
        void shuffle();                 //shuffles the deck of board cards
        BrdCard* pick(int &);           //Picks top card from the board deck
};

#endif /* BRDDECK_H */

