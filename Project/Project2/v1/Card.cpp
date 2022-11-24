/*
 * Card Class Implementation
 */
#include <iostream>
using namespace std;
#include "Card.h"
#include "Image.h"

const int NUMELMS=54;
const int ROW=4;
const int COL=4;

//Define static variables outside of the class
int Card::cardCnt=0;

Card::Card() {
    cardCnt++;
    this->setNum(0);
    this->img=nullptr;
    this->setFnd(false);
}

Card::Card(int num,Image* img) {
    cardCnt++;        //Increment static variable count of Card objects
    this->setNum(num);
    this->img=img;
    this->setFnd(false);
}

void Card::display() {
    cout<<"Name: "<<img->getName()<<endl;
    cout<<"Riddle: "<<img->getRddl()<<endl;
    cout<<"Card Number: "<<num<<endl;
}

void Card::setNum(int num) {
    if(num>=1&&num<=NUMELMS) {
        this->num=num;
    } else {
        cout<<"Invalid card number."<<endl;
        exit(EXIT_FAILURE);
    }
}

void Card::setXIdx(int x) {
    if(x>0&&x<ROW) {        //Validate input for X index
        xIndx=x;
    } else {
        cout<<"Invalid X index."<<endl;
        exit(EXIT_FAILURE);
    }
}

void Card::setYIdx(int y) {
    if(y>0&&y<COL) {        //Validate input for Y index
        yIndx=y;
    } else {
        cout<<"Invalid Y index."<<endl;
        exit(EXIT_FAILURE);
    }
}
