/*
 * Card Class Implementation
 */
#include <iostream>
#include <iomanip>
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
    //Print out top border of the card
    for(int i=0;i<14;i++) {
        cout<<"_";
    }
    //Print out starting where an image would be (represented by -)
    cout<<endl<<" "<<setw(14);
    cout<<setw(3)<<right<<num<<endl;
    for(int i=0;i<5;i++) {
        cout<<setw(4)<<left<<" ";
        cout<<"------"<<endl;
        if(i==5) cout<<endl;
    }
    //Print out the name
    cout<<getName()<<endl;
    //Print out bottom border of the card
    for(int i=0;i<14;i++) {
        cout<<"_";
    }cout<<endl;
}

void Card::setNum(int num) {
    if(num>=1&&num<=numCards) {
        this->num=num;
    } else {
        cout<<"Invalid card number."<<endl;
    }
}