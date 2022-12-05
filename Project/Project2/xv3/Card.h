/* 
 * File:   Card.h
 * Author: andrewguzman
 * Purpose: Card Class Specification
 * Created on November 22, 2022, 8:33 PM
 */

#ifndef CARD_H
#define CARD_H
#include "Image.h"

class Card {
    private:
        static int cardCnt; //Static variable count of card objects
        int num;       //Number displayed on card
        Image* img;    //Points to Image
        int xIndx;     //X Index in the board
        int yIndx;     //Y Index in the board 
        bool found;    //Flag to mark if card is found on board
        //Private member function to create Image pointer
        
    public:
        Card();                         //Default Card constructor
        Card(int,Image *);              //Card constructor
        Card(int,int);                  //Card constructor
        Card(Card *);                   //Card constructor
        Card(const Card &obj);          //Copy constructor
//        ~Card();                        //Destructor
        void display();                 //Display Card data
        void setNum(int);               //Set card number
        void setXIdx(int);              //Set card X index
        void setYIdx(int);              //Set card Y index
        void setFnd(bool found) {this->found=found;}  //Set found flag
        int getCnt() const {return cardCnt;}          //Get static member cardCnt
        int getNum() const {return num;}       //Get card number
        int getXIdx() const {return xIndx;}     //Get card X index
        int getYIdx() const {return yIndx;}     //Get card Y index
        bool getFnd() const{return found;}     //Get value of found flag
        const Card operator=(const Card &);   //Overloaded assignment operator
};

#endif /* CARD_H */

