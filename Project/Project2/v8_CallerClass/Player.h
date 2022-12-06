/* 
 * File:   Player.h
 * Author: andrewguzman
 * Player Class Specification
 * Created on December 5, 2022, 9:14 PM
 */

#include "Board.h"
#include "AbsPlayer.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player:public AbsPlayer {
protected:
    static int pCnt;
    string name;
    Board *board;
    int numTkns;
public:
    Player(string);
    ~Player();
    void setBrd(Board *);
    void setTkns(int n) { numTkns=n; }
    int getPCnt() { return pCnt; }
    string getName(){ return name; }
    int getTkns() { return numTkns; }
    void prntBrd();
};

#endif /* PLAYER_H */

