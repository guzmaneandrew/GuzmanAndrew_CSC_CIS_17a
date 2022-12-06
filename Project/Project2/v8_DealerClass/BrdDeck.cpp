/* 
 * File:   BrdDeck.h
 * Author: andrewguzman
 * BrdDeck Class Implementation
 * Created on December 5, 2022 1:16 AM
 */
#include <string>
#include <iostream>
#include "BrdCard.h"
#include "BrdDeck.h"

int BrdDeck::bDckCnt=0;        //Define static variables outside of the class

BrdDeck::BrdDeck():Deck() {
    bDckCnt++;
    isEmpty=true;
    //deck in Deck class of type Card
    //Declaring the deck uses the default constructor for Card which creates
    //deck of empty cards pointing to nullptr
    //code below creates bugs with making more cards and images than we need
//    for(int i=0;i<MAX;i++) {
//        Image img=new Image();
//        Image *imgPtr=&img;
//        Card card=new Card(i+1,imgPtr);
//        Card card=new Card();
//        deck[i]=card;
//    }
}

//BrdDeck::BrdDeck(BrdCard **cards):Deck() {
//    bDckCnt++;
//    for(int i=0;i<MAX;i++) {
//        BrdCard card(*(cards+i));
////        bDeck[i]=*(cards+i);
//    }
//    isEmpty=false;
//}

BrdDeck::BrdDeck(BrdCard **cards) {
    bDckCnt++;
    for(int i=0;i<MAX;i++) {
        bDeck[i]=*(*(cards+i));
    }
    isEmpty=false;
}

void BrdDeck::setDeck(BrdCard **cards) {
    for(int i=0;i<MAX;i++) {
        bDeck[i]=*(*(cards+i));
    }
}

void BrdDeck::display() {
    for(int i=0;i<MAX;i++) {
        bDeck[i].display();
    }
    cout<<endl;
}

BrdCard BrdDeck::getCrd(int index) {
    BrdCard card=bDeck[index];
    return card;
}

void BrdDeck::shuffle() {
    int rndIndx;        //Random card index
    
    for(int shffl=1;shffl<7;shffl++) {
        for(int index=0;index<MAX;index++) {
            do {        //Random index must not equal to current index
                rndIndx=rand()%MAX;
            }while(index==rndIndx);
            //Swap card at current index with card at random index
            BrdCard temp=bDeck[index];
            bDeck[index]=bDeck[rndIndx];
            bDeck[rndIndx]=temp;
        }
    }
}