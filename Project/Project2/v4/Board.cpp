/* 
 * File:   Board.h
 * Author: andrewguzman
 * Board Class Implementation
 * Created on November 26, 2022, 10:39 PM
 */

#include "Board.h"
#include <iostream>

//Define static variables outside of the class
int Board::brdCnt=0;

Board::Board() {
    brdCnt++;
    brdNum=1;
    
    board=new BrdCard*[ROWS];
    for(int i=0;i<ROWS;i++) {
        board[i]=new BrdCard[COLS];
    }
    
//    for(int i=0;i<54;i++) {
//        for(int r=0;r<4;r++) {
//            board[i]=new Card();
//            for(int c=0;c<4;c++) {
//                Card card;
//                board[r][c]=card;
//            }
//        }        
//    }
}

//Board::Board(int n,Deck *brdCrds) {
//    brdCnt++;
//    brdNum=n;
//
//    board=new BrdCard*[ROWS];
//    for(int i=0;i<ROWS;i++) {
//        board[i]=new BrdCard[COLS];
//    }
//    
//    int index=0;
//    for(int r=0;r<4;r++) {
//        for(int c=0;c<4;c++) {
//            BrdCard temp=brdCrds->getCrd(index);
//            board[r][c]=temp;
//            index++;
////            board[r][c]=brdsCrds->getCrd(index);
//        }
//    }        
//}

//Board::Board(int n,Card **cards) {
//    brdCnt++;
//    brdNum=n;
//    
//    int index=0;
//    for(int r=0;r<4;r++) {
//        for(int c=0;c<4;c++) {
//            Card temp=*(*(cards+index));
//            board[r][c]=temp;
//            index++;
//        }
//    }        
//}

Board::~Board() {
    for(int i=0;i<ROWS;i++) {
        delete[] board[i];
    }
    delete[] board;
}

void Board::display() {
    cout<<"Board "<<brdNum<<endl;
    for(int r=0;r<4;r++) {
        for(int c=0;c<4;c++) {
//            
            board[r][c].display();
        }
    } 
    cout<<endl;
}