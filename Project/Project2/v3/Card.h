/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Card.h
 * Author: andrewguzman
 * Purpose: Card Class Specification
 * Created on November 22, 2022, 8:33 PM
 */

#ifndef CARD_H
#define CARD_H
#include <string>
using namespace std;
#include "Image.h"

class Card {
    private:
        static int cardCnt; //Static variable count of card objects
        int num;       //Number displayed on card
        Image* img;    //Card  HAS-A image
        int xIndx;     //X Index in the board
        int yIndx;     //Y Index in the board 
        bool found;    //Flag to mark if card is found on board
    public:
        Card();                         //Default Card constructor
        Card(int,Image *);              //Card constructor
        Card(const Card &obj);          //Copy constructor
        void display();                 //Display Card data
        void setNum(int);               //Set card number
        void setXIdx(int);              //Set card X index
        void setYIdx(int);              //Set card Y index
        void setFnd(bool found) {this->found=found;}  //Set found flag
        int getCnt() const {return cardCnt;} //Get count of card objects
        int getNum() {return num;}       //Get card number
        int getXIdx(){return xIndx;}     //Get card X index
        int getYIdx(){return yIndx;}     //Get card Y index
        bool getFnd(){return found;}     //Get value of found flag
};

#endif /* CARD_H */

