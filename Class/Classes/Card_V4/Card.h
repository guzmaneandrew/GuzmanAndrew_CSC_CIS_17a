/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Card.h
 * Author: andrewguzman
 *
 * Created on November 7, 2022, 10:01 PM
 */

#ifndef CARD_H
#define CARD_H

class Card {
    private:
        char number;
    public:
        void setNum(int);   //Set card number
        int getNum();       //Get card number
        char fVal();        //Face value
        char sVal();        //Suit value
        int nVal();         //Numerical value
};


#endif /* CARD_H */

