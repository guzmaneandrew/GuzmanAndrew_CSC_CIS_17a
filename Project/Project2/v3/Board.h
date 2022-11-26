/* 
 * File:   Board.h
 * Author: andrewguzman
 * Board Class Specification
 * Created on November 24, 2022, 12:30 AM
 */

#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include "Constants.h"
#include "Card.h"

class Board {
private:
    static int brdCnt;
    int brdNum;                 //Number printed on the board
    vector<vector<Card> > board; //2D vector for board
//    Card board;     //2d array of cards makes up the board
public:
    Board();                        //Default Board constructor
    Board(int, Card **);            //Board constructor
//    Board(const Board &);           //Copy constructor
    void display();                 //Display board
    void setNum(int n) {brdNum=n;}  //Set board number 
    int getCnt() const {return brdCnt;}   //Get total number of instances of board  
    int getNum() const {return brdNum;}   //Get board number
};

#endif /* BOARD_H */

