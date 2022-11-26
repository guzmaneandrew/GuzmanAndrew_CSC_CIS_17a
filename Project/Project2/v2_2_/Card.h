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
#include "Image.h"
#include <string>
using namespace std;

class Card {
    private:
        static int cardCnt; //Static variable count of card objects
        int num;       //Number displayed on card
        Image* img;    //Card  HAS-A image
        int xIndx;     //X Index in the board
        int yIndx;     //Y Index in the board 
        bool found;    //Flag to mark if card is found on board
    public:
        Card();                         //Default Constructor
        Card(int,Image *);              //Constructor
        Card(Card *);             //Constructor
        Card(const Card &);             //Copy constructor 1
        ~Card();                        //Destructor 2
        void display();                 //Display Card data
        void setNum(int);               //Set card number
        void setImg(Image *);           //Set Image member
        void setXIdx(int);              //Set card X index
        void setYIdx(int);              //Set card Y index
        void setFnd(bool found) {this->found=found;}  //Set found flag
        int getCnt() const {return cardCnt;} //Get count of card objects
        int getNum() const {return num;}       //Get card number
        Image* getImg() const;                  //Returns pointer to Image object
        int getXIdx() const {return xIndx;}     //Get card X index
        int getYIdx() const {return yIndx;}     //Get card Y index
        bool getFnd() const {return found;}     //Get value of found flag
        const Card operator=(const Card &);   //Overloaded assignment operator
};

#endif /* CARD_H */

