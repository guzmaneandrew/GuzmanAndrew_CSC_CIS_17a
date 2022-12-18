/* 
 * File:   Caller.h
 * Author: andrewguzman
 * Caller Class Specification
 * Created on December 7, 2022, 10:45 AM
 */

#ifndef CALLER_H
#define CALLER_H
#include <fstream>
#include "Player.h"
#include "Deck.h"
#include "Card.h"

class Caller:public Player {
    private:
        Deck<Card> *deck;
        string name;
    public:
        Caller():Player(){
            deck=nullptr;
        }
        Caller(string n,Board *brd,fstream &file,string fileName):Player(n,brd){
            name=n;
            deck=new Deck<Card>(file,fileName);
        }
        ~Caller() { delete deck; }
        string getName() { return name; }
        void display() {
            cout<<"Player: "<<name<<endl;
            cout<<"The Caller Doesn't Use Tokens Or A Board For The Game."<<endl;
        }
        void dispDck() {
            deck->display();
        }
        void dispCrd(int &index) {
            deck[index].display();
        }
        void shuffle() {
            deck->shuffle();
        }
        Card* pick(int &index) {
            return deck->pick(index);
        }
        void check(int &index) {
            deck->check(index);
        }
};

#endif /* CALLER_H */

