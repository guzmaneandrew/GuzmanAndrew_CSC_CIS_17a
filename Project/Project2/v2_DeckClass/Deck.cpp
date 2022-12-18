/* 
 * File:   Deck.h
 * Author: andrewguzman
 * Deck Class Implementation
 * Created on November 25, 2022, 3:24 PM
 */

#include <string>
#include <iostream>
#include <fstream>
#include "Card.h"
#include "Deck.h"

int Deck::deckCnt=0;        //Define static variables outside of the class

Deck::Deck() {
    deckCnt++;
    index=new int[MAX];
    for(int i=0;i<MAX;i++) {
        Card card(i," ");
        deck[i]=card;
        index[i]=i;     //save index
    }
}

Deck::Deck(Card **cards) {
    deckCnt++;
    for(int i=0;i<MAX;i++) {
        deck[i]=*(*(cards+i));
    }
}

Deck::~Deck(){
    delete []index;
}

void Deck::setDeck(Card **cards) {
    for(int i=0;i<MAX;i++) {
        deck[i]=*(*(cards+i));
    }
}

void Deck::display() {
    cout<<"Deck"<<endl;
    for(int i=0;i<MAX;i++) {
        deck[i].display();
    }
    cout<<endl;
}

Card* Deck::pick(int &index) {
    Card *crdPtr=&deck[index];
    
    index++;                        //Increment curIndx to pick next card 
    return crdPtr;
}

void Deck::check(int &index) {
    if(index==MAX) {
        cout<<"The deck is empty.\n\n";
        isEmpty=true;
    } else {
        cout<<"The deck is not empty.\n\n";
    }
}

//void Deck::shuffle() {
//    int rndIndx;        //Random card index
//    
//    cout<<"Shuffled ";
//    for(int shffl=1;shffl<7;shffl++) {
//        for(int index=0;index<MAX;index++) {
//            do {        //Random index must not equal to current index
//                rndIndx=rand()%MAX;
//            }while(index==rndIndx);
//            //Swap card at current index with card at random index
//            Card temp=deck[index];
//            deck[index]=deck[rndIndx];
//            deck[rndIndx]=temp;
//        }
//    }
//}

void Deck::shuffle() {
    for(int shffl=1;shffl<=7;shffl++) {
        for(int crd=0;crd<MAX;crd++) {
            int temp=rand()%MAX;
            int card=index[crd];
            index[crd]=index[temp];
            index[temp]=crd;
        }
    }
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

void Deck::crtArr(fstream &file,string filName,string *array) {
    if(openFil(file,filName)) {
        filToAr(file,array);
        file.close();
    } else {
        cout<<"File open error!"<<endl;
    } 
}