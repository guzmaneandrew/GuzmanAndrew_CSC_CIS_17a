/* 
 * File:   BrdCard.h
 * Author: andrewguzman
 * Board Card Class Specification
 * Created on December 5, 2022, 12:03 AM
 */

#ifndef BRDCARD_H
#define BRDCARD_H
#include "Card.h"

class BrdCard:public Card {
private:
    static const int ROWS=4;    //Number of rows in board to set location in board
    static const int COLS=4;    //Number of cols in board to set location in board
    int xIndx;     //X Index in the board
    int yIndx;     //Y Index in the board 
    bool found;    //Flag to mark if card is found on board
public:
    BrdCard();                      //Default Constructor
    BrdCard(int,string);            //Constructor
    ~BrdCard();                     //Destructor 
    void setXIdx(int);              //Set card X index
    void setYIdx(int);              //Set card Y index
    void setFnd(bool found) {this->found=found;}  //Set found flag
    int getXIdx() const {return xIndx;}     //Get card X index
    int getYIdx() const {return yIndx;}     //Get card Y index
    bool getFnd() const {return found;}     //Get value of found flag
};

#endif /* BRDCARD_H */



