/* 
 * File:   Player.h
 * Author: andrewguzman
 * Player Class Specification
 * Created on December 5, 2022, 9:14 PM
 */

#include "Board.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player {
private:
    static int pCnt;
    string name;
    Board *board;
    int numTkns;
public:
    Player(string);
    ~Player();
    void setBrd(Board *);
    int getPCnt() { return pCnt; }
    string getName(){ return name; }
    void prntBrd();
};

#endif /* PLAYER_H */

