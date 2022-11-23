/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 * Card Class Implementation
 */

#include <iostream>
using namespace std;
#include "Card.h"
#include "Image.h"

const int NUMELMS=52;
const int ROW=4;
const int COL=4;

void Card::create(int num,Image* img) {
    this->setNum(num);
    this->img=img;
    this->setFnd(false);
//    cardCnt++;        //Increment static variable count of Card objects
}

void Card::setNum(int num) {
    if(num>0&&num<NUMELMS) {
        this->num=num;
    } else {
        cout<<"Invalid card number."<<endl;
        exit(EXIT_FAILURE);
    }
}

void Card::setXIdx(int x) {
    if(x>0&&x<ROW) {
        xIndx=x;
    } else {
        cout<<"Invalid X index."<<endl;
        exit(EXIT_FAILURE);
    }
}

void Card::setYIdx(int y) {
    if(y>0&&y<COL) {
        yIndx=y;
    } else {
        cout<<"Invalid Y index."<<endl;
        exit(EXIT_FAILURE);
    }
}

void Card::display() {
    cout<<"Name: "<<img->getName()<<endl;
    cout<<"Riddle: "<<img->getRddl()<<endl;
    cout<<"Card Number: "<<num<<endl;
    cout<<"Found: "<<found<<endl;
    
}
