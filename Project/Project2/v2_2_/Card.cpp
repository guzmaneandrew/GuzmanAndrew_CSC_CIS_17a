/*
 * Card Class Implementation
 */

#include <iostream>
#include "Card.h"
#include "Image.h"

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
    this->img=new Image(img->getRddl(),img->getName());
    this->found=false;
}

Card::Card(Card *crdPtr) {
    cardCnt++;
    num=crdPtr->num;
    img=crdPtr->getImg();
//    this->img=new Image(crdPtr->img->getRddl(),crdPtr->img->getName());
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
    img=new Image(obj.img->getRddl(),obj.img->getName());
//    this->img=new Image;
//    this->img->setRddl(obj.img->getRddl());
//    this->img->setName(obj.img->getName());
    xIndx=obj.xIndx;
    yIndx=obj.yIndx;
    found=obj.found;
}

Card::~Card() {
    cardCnt--;
    delete img;
    img=nullptr;
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

void Card::setImg(Image *img) {
    this->img=new Image(img);
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

Image* Card::getImg() const{
    return img;
}

const Card Card::operator=(const Card &rhs) {
    if(this!=&rhs) {
        delete img;
        num=rhs.num;
        setImg(rhs.img);
//        img=rhs.img;
//        img=new Image(rhs.img->getRddl(),rhs.img->getName());
        xIndx=rhs.xIndx;
        yIndx=rhs.yIndx;
        found=rhs.found;
    }
    
    return *this;
}