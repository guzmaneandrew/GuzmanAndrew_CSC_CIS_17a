/* 
 * File:   Card.cpp
 * Author: andrewguzman
 * Card Class Implementation
 * Created on December 6, 2022, 1:07 PM
 */

#include <iostream>
#include <iomanip>
#include "Card.h"
using namespace std;

int Card::crdCnt=0;

Card::Card(int num,string name) {
    crdCnt++;
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