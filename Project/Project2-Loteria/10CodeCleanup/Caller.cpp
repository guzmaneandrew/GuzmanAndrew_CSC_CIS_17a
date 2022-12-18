/* 
 * File:   Caller.cpp
 * Author: andrewguzman
 * Caller Class Implementation
 * Created on December 7, 2022, 10:45 AM
 */

#include <string>
#include <iostream>
#include "Caller.h"
#include "Player.h"
#include "Deck.h"
#include "Card.h"

Caller::Caller():Player(){
    deck=nullptr;
}
Caller::Caller(string n,Board *brd,fstream &file,string fileName):Player(n,brd){
    name=n;
    deck=new Deck<Card>(file,fileName);
}
Caller::~Caller() { 
    delete deck; 
}

void Caller::display() {
    cout<<"Player: "<<name<<endl;
    cout<<"The Caller Doesn't Use Tokens Or A Board For The Game."<<endl;
}

void Caller::dispDck() {
    deck->display();
}

void Caller::dispCrd(int &index) {
    deck[index].display();
}

void Caller::shuffle() {
    deck->shuffle();
}

Card* Caller::pick(int &index) {
    return deck->pick(index);
}

void Caller::check(int &index) {
    deck->check(index);
}