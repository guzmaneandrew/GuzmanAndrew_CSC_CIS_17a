/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: October 27, 2022 @ 10:36 AM
 * Purpose: 1 card
 */

//System Libraries
#include <iostream>  //Input/output Library
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only

//Structure Definitions 
struct Image { 
    string riddle;	//or char* riddle;	//PARALLEL 
    string word;	//or char* word;	//ARRAYS 
    int index;	//index in the board, 
};

struct Card { 
    string word;  
    int num; 
    int index; //index in the array of 54 cards 
    Image* img;
}; 

//Function Prototypes
void prntCrd(Card *);    //Prints a single card

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    Card* card=new Card;
    card->word="EL VIOLENCILLO";
    card->num=52;
    card->index=0;
    Image* img=new Image;
    card->img=img;
    img->riddle="El que con la cola pica.";
    img->word="EL violencillo";
    img->index=6;

    //Initial Variables

    //Map the Inputs to the Outputs

    //Display the Inputs and Outputs
    prntCrd(card);
//    setCrd(card,"EL VIOLENCILLO",1);
//    setCrd(card,"EL ALACRAN",2);
//    setCrd(card,"EL SOL",3);
//    setCrd(card,"LA LUNA",4);
    

    //Clean up the dynamic stuff
    delete card;

    //Exit the code
    return 0;
}

void prntCrd(Card *c) { 
    //Print out starts where an image would be
    cout<<endl<<" "<<setw(10);
    cout<<left<<c->num<<endl;
    for(int i=0;i<5;i++) {
        if(i==0) cout<<"   ";
        for(int j=0;j<5;j++) {
            if(i==2&&j==2) cout<<"O";
            else cout<<"-";
        }
        cout<<endl<<"   ";
    }
    cout<<endl;
    
    //Print out the word
    for(int i=0;i<c->word.length();i++) {
        if(i>=0 && i<=c->word.length()) {
            if(i==0) cout<<" ";
            if(c->word.length()>10)
                if(i==3) cout<<endl<<" ";
            cout<<c->word[i];
        }
    }
    cout<<endl;
    
    //Print out bottom border of the card
    for(int i=0;i<=12;i++) {
        cout<<"_";
    }
    
}