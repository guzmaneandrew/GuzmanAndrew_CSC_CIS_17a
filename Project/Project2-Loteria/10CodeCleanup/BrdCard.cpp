/* 
 * File:   BrdCard.h
 * Author: andrewguzman
 * Board Card Class Implementation
 * Created on December 5, 2022, 12:03 AM
 */

#include <string>
#include <iostream>
#include "BrdCard.h"
#include "Card.h"

BrdCard::BrdCard():Card() {
    count++;
    xIndx=0;
    yIndx=0;
    found=false;
}

BrdCard::BrdCard(int num, string name):Card(num,name) {
    count++;
    xIndx=0;
    yIndx=0;
    found=false;
}

BrdCard::~BrdCard() {
    count--;
}

void BrdCard::setXIdx(int x) {
    if(x>0&&x<ROWS) {        //Validate input for X index
        xIndx=x;
    } else {
        cout<<"Invalid X index."<<endl;
        exit(EXIT_FAILURE);
    }
}

void BrdCard::setYIdx(int y) {
    if(y>0&&y<COLS) {        //Validate input for Y index
        yIndx=y;
    } else {
        cout<<"Invalid Y index."<<endl;
        exit(EXIT_FAILURE);
    }
}