/* 
 * File:   Board.h
 * Author: andrewguzman
 * Board Class Specification
 * Created on November 26, 2022, 10:39 PM
 */

#ifndef BOARD_H
#define BOARD_H
#include <fstream>
#include "BrdCard.h"
#include "BrdDeck.h"

class Board {
private:
    static int brdCnt;
    static const int ROWS=4;
    static const int COLS=4;
    int brdNum;                 //Number printed on the board
    BrdCard **board;     //Dynamic allocated 2d array of cards makes up the board
public:
    Board();                        //Default Board constructor
    Board(int,Deck<BrdCard> *);            //Constructor
    Board(int,BrdCard **);            //Constructor
    ~Board();                        //Destructor
    void setNum(int n) {brdNum=n;}  //Set board number 
    int getCnt() const {return brdCnt;}   //Get total number of instances of board  
    int getBNum() const {return brdNum;}   //Get board number
    void display();                     //Display board
    void miniBrd();                     //Displays mini board to screen
    void brd2Fil(int);                 //Output board to a file
};

#endif /* BOARD_H */