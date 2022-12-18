/* 
 * File:   Deck.cpp
 * Author: andrewguzman
 * Deck Class Implementation
 * Created on December 6, 2022, 1:32 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Card.h"
#include "Deck.h"

int Deck::dckCnt=0;

Deck::Deck(fstream &file,string fileName) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    dckCnt++;
    names=crtArr(file,fileName);
    cards=new Card*[MAX];
    index=new int[MAX];
    for(int i=0;i<MAX;i++) {
        cards[i]=new Card(i+1,*(names+i));
        index[i]=i;
    }
    isEmpty=false;
}

Deck::Deck(string *n) {
    dckCnt++;
    names=new string[MAX];
    for(int i=0;i<MAX;i++) {
        names[i]=*(n+i);
    }
    cards=new Card*[MAX];
    index=new int[MAX];
    for(int i=0;i<MAX;i++) {
        cards[i]=new Card(i+1,*(names+i));
        index[i]=i;
    }
}

Deck::~Deck() {
    delete []names;
    for(int i=0;i<MAX;i++) {
        delete cards[i];
    }
    delete []cards;
    delete []index;
}

void Deck::display() {
    for(int i=0;i<MAX;i++) {
        cards[i]->display();
    }
    cout<<endl;
}

void Deck::shuffle() {
    int rndIndx;        //Random card index
    
    for(int shffl=1;shffl<7;shffl++) {
        for(int index=0;index<MAX;index++) {
            do {        //Random index must not equal to current index
                rndIndx=rand()%MAX;
            }while(index==rndIndx);
            //Swap card at current index with card at random index
            Card *temp=cards[index];
            cards[index]=cards[rndIndx];
            cards[rndIndx]=temp;
        }
    }
}

Card* Deck::pick(int &index) {
    Card *crdPtr=cards[index];
    
    index++;                        //Increment curIndx to pick next card 
    return crdPtr;
}

void Deck::check(int &index) {
    if(index==MAX) {
        isEmpty=true;
        cout<<"The deck is empty.\n\n";
    } else {
        cout<<"The deck is not empty.\n\n";
    }
}

string* Deck::crtArr(fstream &file,string filName) {
    string *array=new string[MAX];
    
    if(openFil(file,filName)) {
        filToAr(file,array);
        file.close();
    } else {
        cout<<"File open error!"<<endl;
    } 
    
    return array;
}

bool Deck::openFil(fstream &file,string name) {
    file.open(name,ios::in);    //Open file for input
    
    if(file.fail()) {
        return false;
    } else
        return true;
}

void Deck::filToAr(fstream &file,string *array) {
    string line;
    for(int i=0;i<MAX;i++) {
        getline(file,line,'\n');    //Get a line from text file
        *(array+i)=line;            //Add line to array of strings
    }
}