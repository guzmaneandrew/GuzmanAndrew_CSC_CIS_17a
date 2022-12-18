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
    static int pCnt;        //Count of Player objects
    string name;            //Name of player
    Board *board;           //Pointer to board
    int numTkns;            //Number of tokens used
public:
    Player();                           //Default constructor
    Player(string,Board *);             //Constructor
    ~Player();                          //Destructor
    void addTkns();                     //Increment number of tokens
    int getCnt() { return pCnt; }       //Return number of Player objects
    string getName(){ return name; }    //Get name of Player
    virtual void display();             //Display's Player's data to the screen
    void dispMBrd();                    //Same as display() - but with mini board
    void chkBrd();                      //Checks if board is filled with tokens
};

#endif /* PLAYER_H */

