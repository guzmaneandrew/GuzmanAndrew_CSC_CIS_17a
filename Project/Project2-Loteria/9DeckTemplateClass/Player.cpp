/* 
 * File:   Player.cpp
 * Author: andrewguzman
 * Player Class Implementation
 * Created on December 5, 2022, 9:14 PM
 */

#include <iostream>
#include <string>
#include "Player.h"

int Player::pCnt=0;        //Define static variables outside of the class

Player::Player() {
    pCnt++;
    name=" ";
    board=nullptr;
    numTkns=0;
}

Player::Player(string n,Board *brd) {
    pCnt++;
    name=n;
    board=brd;
    numTkns=0;
}

Player::~Player() {
    delete board;
}

void Player::addTkns() {
    numTkns++;
}

void Player::display() {
    cout<<"Player: "<<name<<endl;
    if(board!=nullptr) {
        cout<<"Number of Tokens Used: "<<numTkns<<endl;
        board->display();        
    }
}

void Player::dispMBrd() {
    cout<<name<<endl;
    if(board!=nullptr) {
        cout<<"Number of Tokens Used: "<<numTkns<<endl;
        board->miniBrd();        
    }
}

void Player::chkBrd() {
    if(numTkns==16) {
        cout<<"Loteria!"<<endl;
    } else {
        cout<<"Not Loteria"<<endl;
    }
}