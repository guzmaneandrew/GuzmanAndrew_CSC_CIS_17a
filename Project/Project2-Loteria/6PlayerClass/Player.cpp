/* 
 * File:   Player.cpp
 * Author: andrewguzman
 * Player Class Implementation
 * Created on December 5, 2022, 9:14 PM
 */

#include "Player.h"

int Player::pCnt=0;        //Define static variables outside of the class

Player::Player(string n,Board *brd) {
    pCnt++;
    name=n;
    board=brd;
}

Player::~Player() {
    
}

void Player::prntBrd() {
    board->display();
}

