/* 
 * File:   Board.h
 * Author: andrewguzman
 * Board Class Implementation
 * Created on November 26, 2022, 10:39 PM
 */

#include "Board.h"
#include "BrdCard.h"
#include "BrdDeck.h"
#include <iostream>
#include <iomanip>
#include <string>

int Board::brdCnt=0;        //Define static variables outside of the class

Board::Board() {
    brdCnt++;
    brdNum=0;
    
    board=new BrdCard*[ROWS];       //Initialize array of pointers
    for(int i=0;i<ROWS;i++) {
        board[i]=new BrdCard[COLS]; //Initialize each pointer
    }
}

Board::Board(int n,Deck<BrdCard> *brdDeck) {
    brdCnt++;
    brdNum=n;

    board=new BrdCard*[ROWS];       //Initialize array of pointers
    for(int i=0;i<ROWS;i++) {
        board[i]=new BrdCard[COLS]; //Initialize each pointer
    }
    
    int index=0;
    for(int r=0;r<4;r++) {
        for(int c=0;c<4;c++) {
            BrdCard temp=brdDeck->getCrd(index);    //Get a card from the deck
            board[r][c]=temp;                       //Set card to card at r,c in board
            index++;                                //Increment index, ends when index=16
        }
    }        
}

Board::~Board() {
    for(int i=0;i<ROWS;i++) {
        delete[] board[i];  //Delete each individual pointer
    }
    delete[] board;         //Delete array of pointers
}


void Board::miniBrd() {
    cout<<setw(10)<<left;
    cout<<"Board #"<<getBNum()<<endl;
    for(int r=0;r<ROWS;r++) {
        for(int c=0;c<COLS;c++) {
            if(board[r][c].getFnd()==true) {
                cout<<"| * |";
            }
            else {
                cout<<"|   |";
            }
        }
        cout<<endl;
    }
    cout<<endl;
}

void Board::display() {
    int brdWdth=60;     //Set width to 60 variable for width
    
    cout<<endl;
    cout<<"LOTERIA"<<setw(brdWdth-8)<<"BOARD "<<getBNum()<<endl;
    for(int j=0;j<4;j++) {
        //Print out top border of board
        for(int i=0;i<brdWdth;i++) cout<<"_";
        cout<<endl;
        //Print first row containing card numbers of 4 cards in top row
        for(int i=0;i<4;i++) {
            cout<<setw(brdWdth/4-1)<<left<<board[j][i].getNum()
                <<setw(1)<<right<<"|";       
        }
        cout<<endl;
        //Print out rows 2-7 containing stars in place of images
        for(int n=0;n<4;n++) {
            for(int i=0;i<4;i++) {
                cout<<setw(4)<<left<<" "
                <<setw(6)<<"------"
                <<setw(4)<<left<<" "
                <<"|";
            } cout<<endl;
        }
        //Print out blank row 9
        for(int i=0;i<4;i++) {
            cout<<setw(15)<<right<<"|";
        }
        cout<<endl;        
    }
    //Print out bottom border of board
        for(int i=0;i<brdWdth;i++) cout<<"_";
        cout<<endl;

    cout<<endl;
}

void Board::brd2Fil(int num) {
    ofstream file;
    string filName;
    
    filName="Board"+to_string(num)+".txt";
    // Open the file in output mode.
    file.open(filName,ios::out);
    
    int brdWdth=60;         //Set width to 60 variable for width
    file<<endl;
    file<<"LOTERIA"<<setw(brdWdth-8)<<"BOARD "<<getBNum()<<endl;
    for(int j=0;j<4;j++) {
        //Print out top border of board
        for(int i=0;i<brdWdth;i++) file<<"_";
        file<<endl;
        //Print first row containing card numbers of 4 cards in top row
        for(int i=0;i<4;i++) {
            file<<setw(brdWdth/4-1)<<left<<board[j][i].getNum()
                <<setw(1)<<right<<"|";       
        }
        file<<endl;
        //Print out rows 2-7 containing stars in place of images
        for(int n=0;n<6;n++) {  //5 rows
            for(int i=0;i<4;i++) {
                file<<setw(4)<<left<<" "
                <<setw(6)<<"------"
                <<setw(4)<<left<<" "
                <<"|";
            } file<<endl;         
        }
        //Print out blank row 9
        for(int i=0;i<4;i++) {
            file<<setw(15)<<right<<"|";
        }
        file<<endl;        
    }
    //Print out bottom border of board
        for(int i=0;i<brdWdth;i++) file<<"_";
        file<<endl;

    //Print the card names and numbers underneath the board
        for(int r=0;r<ROWS;r++) {
            for(int c=0;c<COLS;c++) {
                file<<board[r][c].getNum()<<" ";
                file<<board[r][c].getName()<<endl;
            }
        }
    file<<endl;
  
    file.close();
}