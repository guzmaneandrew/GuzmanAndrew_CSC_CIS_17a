/* 
 * File:   Board.h
 * Author: andrewguzman
 * Board Class Specification
 * Created on November 26, 2022, 10:39 PM
 */

#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include "Constants.h"
#include "Card.h"
#include "Deck.h"

class Board {
private:
    static int brdCnt;
//    static const ROWS=4;
//    static const COLS=4;
    int brdNum;                 //Number printed on the board
    Card **board;     //Dynamic allocated 2d array of cards makes up the board
public:
    Board();                        //Default Board constructor
//    Board(int,Deck *);            //Constructor
    Board(int, Card **);            //Constructor
    ~Board();                        //Destructor
    void display();                 //Display board
    void setNum(int n) {brdNum=n;}  //Set board number 
    int getCnt() const {return brdCnt;}   //Get total number of instances of board  
    int getNum() const {return brdNum;}   //Get board number
};

#endif /* BOARD_H */

//class Screen {
//    private:
//        char **data;
//        int rows;
//        int columns;
//
//    public:
//        Screen(int num_rows, int num_cols); 
//}; 
//
//Screen::Screen(int num_rows, int num_cols) {
//    data = new char * [num_rows];
//    for (int i = 0; i < num_rows; ++i) {
//        data[i] = new char[num_cols];
//    }
//    rows = num_rows;
//    columns = num_cols;
//}