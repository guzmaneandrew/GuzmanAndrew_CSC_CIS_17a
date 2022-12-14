/* 
 * File:   BrdCard.h
 * Author: andrewguzman
 * Board Card Class Implementation
 * Created on November 28, 2022, 9:08 PM
 */

#include <string>
#include <iostream>
#include "BrdCard.h"
#include "Card.h"

int BrdCard::bCrdCnt=0;

BrdCard::BrdCard():Card() {
    bCrdCnt++;
    xIndx=0;
    yIndx=0;
    found=false;
}

BrdCard::BrdCard(int num,Image *img):Card(num,img) {
    bCrdCnt++;
    xIndx=0;
    yIndx=0;
    found=false;
}

BrdCard::BrdCard(int num,Image *img,int x,int y,bool found):Card(num,img) {
    bCrdCnt++;
    xIndx=x;
    yIndx=y;
    this->found=found;
}

BrdCard::BrdCard(BrdCard *crdPtr):Card(crdPtr){
    bCrdCnt++;
    xIndx=crdPtr->xIndx;
    yIndx=crdPtr->yIndx;
    found=crdPtr->found;
}

BrdCard::BrdCard(const BrdCard &obj):Card(obj) {
    bCrdCnt++;
    xIndx=obj.xIndx;
    yIndx=obj.yIndx;
    found=obj.found;
}

BrdCard::~BrdCard() {
    bCrdCnt--;
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

const BrdCard BrdCard::operator=(const BrdCard &rhs) {
    if(this!=&rhs) {
        delete this->getImg();
        this->num=rhs.getNum();
        this->img=rhs.getImg();
        //Possibly revisit overloaded operator for problem with boardcard count
//        delete img;
//        num=rhs.num;
//        setImg(rhs.img);
//        img=rhs.img;
//        img=new Image(rhs.img->getRddl(),rhs.img->getName());
        
        xIndx=rhs.xIndx;
        yIndx=rhs.yIndx;
        found=rhs.found;
    }
    
    return *this;
}

