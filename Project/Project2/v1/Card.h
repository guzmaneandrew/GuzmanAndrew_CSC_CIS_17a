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

class Card {
    private:
        static int cardCnt; //Static variable count of card objects
        int num;            //Number displayed on card
        string name;        //Name on card
    public:
        Card();                         //Default Card constructor
        Card(int,string);               //Card constructor
        void setNum(int);               //Set card number
        void setName(string);           //Set card name
        int getCnt() const { return cardCnt; } //Get count of card objects
        int getNum() { return num; }       //Get card number
        string getName() { return name; }   //Get card name
        void display();                 //Display Card data

};

#endif /* CARD_H */

