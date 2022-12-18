/* 
 * File:   Player.h
 * Author: andrewguzman
 * Player Class Implementation
 * Created on December 5, 2022, 9:14 PM
 */

#include "Player.h"

int Player::pCnt=0;        //Define static variables outside of the class

Player::Player(string n) {
    pCnt++;
    name=n;
}

Player::~Player() {
    
}
 
void Player::setBrd(Board *brd) {
    board=brd;
}

void Player::prntBrd() {
    board->dispBrd();
}

