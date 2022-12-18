/* 
 * File:   AbsPlayer.h
 * Author: andrewguzman
 * Abstract Player Class Specification
 * Created on December 6, 2022, 12:10 AM
 */

#ifndef ABSPLAYER_H
#define ABSPLAYER_H

#include <string>
using namespace std;

#include "Board.h"

class AbsPlayer {
public:
    virtual void addTkns() = 0;     //Increment number of tokens used by Player
    virtual int getCnt() = 0;       //Get count of Player objects
    virtual string getName() = 0;   //Get Player's name
    virtual void display() = 0;     //Display board
    virtual void dispMBrd() =0;     //Display mini board
    virtual void chkBrd() = 0;      //Check if board is filled
};

#endif /* ABSPLAYER_H */

