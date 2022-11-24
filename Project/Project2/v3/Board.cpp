/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 * Board Class Implementation
 */
#include "Board.h"
#include "Card.h"
#include <iostream>

//Define static variables outside of the class
int Board::brdCnt=0;

Board::Board() {
    brdNum=0;
    brdCnt++;
}

Board::Board(int n) {
    brdNum=n;
    brdCnt++;
}

void Board::display() {
    cout<<brdNum<<endl;
}