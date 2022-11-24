/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Board.h
 * Author: andrewguzman
 * Board Class Specification
 * Created on November 24, 2022, 12:30 AM
 */

#ifndef BOARD_H
#define BOARD_H
#include "Card.h"
#include <vector>

class Board {
private:
    static const int ROWS=4;
    static const int COLS=4;
    static int brdCnt;
    int brdNum;                 //Number printed on the board
    Card board[][COLS];     //2d array of cards makes up the board
public:
    Board();                        //Default Board constructor
    Board(int);             //Board constructor
////    Board(const Board &);           //Copy constructor
    void setNum(int n) {brdNum=n;}  //Set board number
    void display();                 //Display board
    int getNum() {return brdNum;}   //Get board number
    int getCnt() {return brdCnt;}     //Get total number of instances of boards
};

#endif /* BOARD_H */

