/* 
 * File:   Deck.h
 * Author: andrewguzman
 * Deck Class Specification
 * Created on December 6, 2022, 1:32 PM
 */

#ifndef DECK_H
#define DECK_H
#include <iostream>
#include "BrdCard.h"

template<class T>
class Deck {
    protected:
        static int count;           //Count of Deck objects
        static const int MAX=54;    //Max size of deck
        string *names;              //Array of names for creating cards in deck
        T **cards;                  //Array of cards
        int *index;                 //Array of indexes
        bool isEmpty;               //Flag to check if deck is empty
        int getCnt();               //Get count of Deck objects
        string *crtArr(fstream &,string);       //Create arrays from file input
        bool openFil(fstream &,string);         //Opens a file for input
        void filToAr(fstream &,string *);       //Saves file contents to memory
    public:
        Deck(fstream &,string); //Constructor - uses file to construct cards in deck
        ~Deck();                //Destructor
        void display();         //Display the deck
        void shuffle();         //Shuffle the deck
        T* pick(int &);         //Return pointer to card to the "top" of the deck
        void check(int);        //Check if the deck is empty
        T getCrd(int);          //Returns a card from the deck
};

template<class T> int Deck<T>::count=0;

template<class T>
int Deck<T>::getCnt() { return count; }     //Get count of Deck objects

template<class T>
Deck<T>::Deck(fstream &file,string fileName) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));

    count++;
    names=crtArr(file,fileName);
    cards=new T*[MAX];
    index=new int[MAX];
    for(int i=0;i<MAX;i++) {
        cards[i]=new T(i+1,*(names+i)); //Initialize Card using names array
        index[i]=i;
    }
    isEmpty=false;
}

template<class T>
Deck<T>::~Deck() {
    delete []names;
    for(int i=0;i<MAX;i++) { //Delete each instance of a card
        delete cards[i];
    }
    delete []cards;         //Delete array of card pointers
    delete []index;
}

template<class T>
void Deck<T>::display() {
    for(int i=0;i<MAX;i++) {
        cards[i]->display();        //Display card one by one
    }
    cout<<endl;
}

template<class T>
void Deck<T>::shuffle() {
    int rndIndx;        //Random card index

    for(int shffl=1;shffl<7;shffl++) {
        for(int index=0;index<MAX;index++) {
            do {        //Random index must not equal to current index
                rndIndx=rand()%MAX;
            }while(index==rndIndx);
            //Swap card at current index with card at random index
            T *temp=cards[index];
            cards[index]=cards[rndIndx];
            cards[rndIndx]=temp;
        }
    }
}

template<class T>
T* Deck<T>::pick(int &index) {
    T *crdPtr=cards[index];         //Set pointer equal to pointer to card at index

    index++;                        //Increment index to pick next card 
    return crdPtr;                  //Return pointer
}

template<class T>
void Deck<T>::check(int index) { 
    if(index==MAX) {
        isEmpty=true;
        cout<<"The deck is empty.\n\n";
    } else {
        cout<<"The deck is not empty.\n\n";
    }
}

template<class T>
T Deck<T>::getCrd(int index) {
    T card=*(*(cards+index));  //De-reference pointer to pointer to card to get card
    return card;               //Return the card
}

template<class T>
string* Deck<T>::crtArr(fstream &file,string filName) {
    string *array=new string[MAX];

    if(openFil(file,filName)) {
        filToAr(file,array);
        file.close();
    } else {
        cout<<"File open error!"<<endl;
    } 
    return array;
}

template<class T>
bool Deck<T>::openFil(fstream &file,string name) {
    file.open(name,ios::in);    //Open file for input

    if(file.fail()) {
        return false;
    } else
        return true;
}

template<class T>
void Deck<T>::filToAr(fstream &file,string *array) {
    string line;
    for(int i=0;i<MAX;i++) {
        getline(file,line,'\n');    //Get a line from text file
        *(array+i)=line;            //Add line to array of strings
    }
}
#endif /* DECK_H */