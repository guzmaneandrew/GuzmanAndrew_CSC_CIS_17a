/*
 * Board Class Implementation
 */
#include "Board.h"
#include <iostream>

//Define static variables outside of the class
int Board::brdCnt=0;

Board::Board() {
    brdNum=0;
    for(int i=0;i<54;i++) {
        for(int r=0;r<4;r++) {
            for(int c=0;c<4;c++) {
                Card card;
                board[r][c]=card;
            }
        }        
    }
}

Board::Board(int n,Card **cards) {
    brdCnt++;
    brdNum=n;
    
    int index=0;
    for(int r=0;r<4;r++) {
        for(int c=0;c<4;c++) {
            Card temp=*(*(cards+index));
            board[r][c]=temp;
            index++;
        }
    }        
}

//~Matrix() {
//    for (int i = 0; i < _rows; i++) {
//        delete[] _arr[i];
//    }
//    delete[] _arr;
//}

void Board::display() {
    cout<<"Board "<<brdNum<<endl;
    for(int r=0;r<4;r++) {
        for(int c=0;c<4;c++) {
            board[r][c].display();
        }
    } 
    cout<<endl;
}