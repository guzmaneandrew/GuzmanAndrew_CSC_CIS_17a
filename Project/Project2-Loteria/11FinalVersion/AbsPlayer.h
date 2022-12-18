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
    virtual int getCnt() = 0;       //Get count of Player objects
    virtual string getName() = 0;   //Get Player's name
    virtual void display() = 0;     //Display board
};

#endif /* ABSPLAYER_H */

