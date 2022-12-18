/* 
 * File:   BrdBrdDeck.h
 * Author: andrewguzman
 * BrdDeck Class Implementation
 * Created on December 5, 2022, 1:12 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Card.h"
#include "BrdDeck.h"

int BrdDeck::bDckCnt=0;

BrdDeck::BrdDeck(fstream &file,string fileName):Deck(file,fileName){
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    bDckCnt++;
    names=crtArr(file,fileName);
    bCards=new BrdCard*[MAX];
    index=new int[MAX];
    for(int i=0;i<MAX;i++) {
        bCards[i]=new BrdCard(i+1,*(names+i));
        index[i]=i;
    }
    isEmpty=false;
}

//BrdDeck::BrdDeck(string *n) {
//    bDckCnt++;
//    names=new string[MAX];
//    for(int i=0;i<MAX;i++) {
//        names[i]=*(n+i);
//    }
//    bCards=new Card*[MAX];
//    index=new int[MAX];
//    for(int i=0;i<MAX;i++) {
//        bCards[i]=new Card(i+1,*(names+i));
//        index[i]=i;
//    }
//}

BrdDeck::~BrdDeck() {
    delete []names;
    for(int i=0;i<MAX;i++) {
        delete bCards[i];
    }
    delete []bCards;
    delete []index;
}

void BrdDeck::display() {
    for(int i=0;i<MAX;i++) {
        bCards[i]->display();
    }
    cout<<endl;
}

void BrdDeck::shuffle() {
    int rndIndx;        //Random card index
    
    for(int shffl=1;shffl<7;shffl++) {
        for(int index=0;index<MAX;index++) {
            do {        //Random index must not equal to current index
                rndIndx=rand()%MAX;
            }while(index==rndIndx);
            //Swap card at current index with card at random index
            BrdCard *temp=bCards[index];
            bCards[index]=bCards[rndIndx];
            bCards[rndIndx]=temp;
        }
    }
}

BrdCard* BrdDeck::pick(int &index) {
    BrdCard *bCrdPtr=bCards[index];
    
    index++;                        //Increment curIndx to pick next card 
    return bCrdPtr;
}

string* BrdDeck::crtArr(fstream &file,string filName) {
    string *array=new string[MAX];
    
    if(openFil(file,filName)) {
        filToAr(file,array);
        file.close();
    } else {
        cout<<"File open error!"<<endl;
    } 
    
    return array;
}

bool BrdDeck::openFil(fstream &file,string name) {
    file.open(name,ios::in);    //Open file for input
    
    if(file.fail()) {
        return false;
    } else
        return true;
}

void BrdDeck::filToAr(fstream &file,string *array) {
    string line;
    for(int i=0;i<MAX;i++) {
        getline(file,line,'\n');    //Get a line from text file
        *(array+i)=line;            //Add line to array of strings
    }
}