/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "Card.h"

void Card::setNum(int i) {
    number=(i>=1&&i<=52)?i:1;
}

int Card::getNum() {return number;}

char Card::fVal() {
    char faceVal[]={'A','2','3','4','5','6','7','8','9','10','J','Q','K'};
    return faceVal[(number-1)%13];
}

char Card::sVal() {
    char suits[]={'S','D','C','H'};
    return suits[(number-1)/13];
}

int Card::nVal() {
    int val=(number-1)%13+1;
    return val>10?10:val;
}