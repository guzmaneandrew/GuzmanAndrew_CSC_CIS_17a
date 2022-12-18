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
private:
    static int pCnt;        //Count of Player objects
    string name;            //Name of player
    Board *board;           //Pointer to board
    int numTkns;            //Number of tokens used
public:
    Player(string,Board *);
    ~Player();
    void addTkns();          //Increment number of tokens
    int getCnt() { return pCnt; }   //Return number of Player objects
    string getName(){ return name; }    //Get name of Player
    void prntBrd();             //Print Player's board
};

#endif /* PLAYER_H */

