/*
 * Card Class Implementation
 */
#include <iostream>
using namespace std;
#include "Card.h"

//Define static variables outside of the class
int Card::cardCnt=0;

Card::Card() {
    cardCnt++;
    num=0;
    name="";
}

Card::Card(int num,string name) {
    cardCnt++;        //Increment static variable count of Card objects
    this->num=num;
    this->name=name;
}

void Card::display() {
    cout<<"Name: "<<getName()<<endl;
    cout<<"Number: "<<num<<endl;
}

void Card::setNum(int num) {
    if(num>=1&&num<=numCards) {
        this->num=num;
    } else {
        cout<<"Invalid card number."<<endl;
    }
}