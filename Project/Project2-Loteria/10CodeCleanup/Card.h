/* 
 * File:   Card.h
 * Author: andrewguzman
 * Card Class Specification
 * Created on December 6, 2022, 1:07 PM
 */

#ifndef CARD_H
#define CARD_H
#include <string>
using namespace std;

class Card {
protected:
    static int count;      //Count of Card objects
    string name;            //Card name
    int num;                //Card number
public:
    Card() {name=" ",num=0;}                //Default Constructor
    Card(int,string);                       //Constructor
    void setName(string n) { name=n; }      //Setters
    void setNum(int n) { num=n; }   
    string getName() { return name; }       //Getters
    int getNum() { return num; }
    int getCnt() const { return count; }    
    void display();                         //Display Card data
};
#endif /* CARD_H */

