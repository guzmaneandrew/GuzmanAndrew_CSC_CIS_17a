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
    virtual void setBrd(Board *) = 0;
    virtual void setTkns(int) = 0;
    virtual int getPCnt() = 0;
    virtual string getName() = 0;
    virtual void prntBrd() = 0;
};

#endif /* ABSPLAYER_H */

