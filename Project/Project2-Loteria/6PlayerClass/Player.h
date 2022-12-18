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
    static int pCnt;        //Count of Player objects
    string name;            //Name of player
    Board *board;           //Pointer to board
    int numTkns;            //Number of tokens used
public:
    Player(string,Board *);
    ~Player();
    int getCnt() { return pCnt; }
    string getName(){ return name; }
    void prntBrd();
};

#endif /* PLAYER_H */

