/* 
 * File:   BrdCard.h
 * Author: andrewguzman
 * Board Card Class Specification
 * Created on November 28, 2022, 9:08 PM
 */

#ifndef BRDCARD_H
#define BRDCARD_H
#include "Card.h"


class BrdCard:public Card {
private:
    static int bCrdCnt;
    int xIndx;     //X Index in the board
    int yIndx;     //Y Index in the board 
    bool found;    //Flag to mark if card is found on board
public:
    BrdCard();                         //Default Constructor
    BrdCard(int,Image *);
    BrdCard(int,Image *,int,int,bool);    //Constructor
    BrdCard(BrdCard *);                    //Constructor
    BrdCard(const BrdCard &);             //Cop constructor 
    ~BrdCard();                        //Destructor 
    void setXIdx(int);              //Set card X index
    void setYIdx(int);              //Set card Y index
    void setFnd(bool found) {this->found=found;}  //Set found flag
    int getCnt() const {return bCrdCnt;}    //Return count of objects
    int getXIdx() const {return xIndx;}     //Get card X index
    int getYIdx() const {return yIndx;}     //Get card Y index
    bool getFnd() const {return found;}     //Get value of found flag
    const BrdCard operator=(const BrdCard &);   //Overloaded assignment operator
};

#endif /* BRDCARD_H */

