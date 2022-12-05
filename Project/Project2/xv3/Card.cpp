/*
 * Card Class Implementation
 */
#include <iostream>
using namespace std;

#include "Constants.h"
#include "Card.h"
#include "Board.h"

//Define static variables outside of the class
int Card::cardCnt=0;

Card::Card() {
    cardCnt++;      
    num=0;
    img=nullptr;
    xIndx=0;
    yIndx=0;
    found=false;
}

Card::Card(int num,Image* img) {
    cardCnt++;        //Increment static variable count of Card objects
    this->num=num;
    this->img=new Image;
    this->img->setRddl(img->getRddl());
    this->img->setName(img->getName());
    this->found=false;
}

Card::Card(int x,int y) {
    cardCnt++;
    xIndx=x;
    yIndx=y;
}

Card::Card(Card *crdPtr) {
    cardCnt++;
    num=crdPtr->num;
    this->img=new Image(crdPtr->img->getRddl(),crdPtr->img->getName());
//    this->img=new Image;
//    this->img->setRddl(crdPtr->img->getRddl());
//    this->img->setName(crdPtr->img->getName());
    xIndx=crdPtr->xIndx;
    yIndx=crdPtr->yIndx;
    found=crdPtr->found;
}

Card::Card(const Card &obj) {
    cardCnt++;
    num=obj.num;
//    this->img=new Image(obj.img->getRddl(),obj.img->getName());
    this->img=new Image;
    this->img->setRddl(obj.img->getRddl());
    this->img->setName(obj.img->getName());
    xIndx=obj.xIndx;
    yIndx=obj.yIndx;
    found=obj.found;
}

//Card::~Card() { 
//    delete []img;
//}

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
    if(x>0&&x<ROWS) {        //Validate input for X index
        xIndx=x;
    } else {
        cout<<"Invalid X index."<<endl;
        exit(EXIT_FAILURE);
    }
}

void Card::setYIdx(int y) {
    if(y>0&&y<COLS) {        //Validate input for Y index
        yIndx=y;
    } else {
        cout<<"Invalid Y index."<<endl;
        exit(EXIT_FAILURE);
    }
}

const Card Card::operator=(const Card &rhs) {
    num=rhs.num;
    img=rhs.img;
    xIndx=rhs.xIndx;
    yIndx=rhs.yIndx;
    found=rhs.found;        

    return *this;
}
