/* 
 * File:   Caller.h
 * Author: andrewguzman
 * Caller Class Specification
 * Created on December 7, 2022, 10:45 AM
 */

#ifndef CALLER_H
#define CALLER_H
#include <fstream>
#include "Player.h"
#include "Deck.h"
#include "Card.h"

class Caller:public Player {
    protected:
        Deck<Card> *deck;
        string name;
    public:
        Caller();
        Caller(string,Board *,fstream &,string);
        ~Caller();
        int getCnt() { return pCnt; }
        void display();
        void dispDck();
        void dispCrd(int &);
        void shuffle();
        Card* pick(int &);
        void check(int &);
};

#endif /* CALLER_H */

