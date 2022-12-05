/* 
 * File:   Board.h
 * Author: andrewguzman
 * Board Class Specification
 * Created on November 26, 2022, 10:39 PM
 */

#ifndef BOARD_H
#define BOARD_H
#include "BrdCard.h"
#include "Deck.h"

class Board {
private:
    static int brdCnt;
    static const int ROWS=4;
    static const int COLS=4;
    int brdNum;                 //Number printed on the board
    BrdCard **board;     //Dynamic allocated 2d array of cards makes up the board
public:
    Board();                        //Default Board constructor
    Board(int,Deck *);            //Constructor
    Board(int,BrdCard **);            //Constructor
    ~Board();                        //Destructor
    void display();                 //Display board
    void setNum(int n) {brdNum=n;}  //Set board number 
    int getCnt() const {return brdCnt;}   //Get total number of instances of board  
    int getNum() const {return brdNum;}   //Get board number
};

#endif /* BOARD_H */