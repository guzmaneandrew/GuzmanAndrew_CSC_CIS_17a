/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: October 28, 2022 @ 7:00 PM
 * Purpose: v1: Implementation of 1 file,1 image,1 card,1 player.
 */

//System Libraries
#include <iostream>  //Input/output Library
#include <iomanip>
#include <vector>
#include <fstream>
#include <cstdlib>
using namespace std;

//User Libraries

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only
const int NUMIMGS=54;
const int NUMWRDS=54;
const int DECK_SIZE=54;
const int NUM_BRDS=10;
const int MAXPLYR=10;
const int TBL_ROWS=4;
const int TBL_COLS=4;

//Structure Definitions 
struct Image { 
    string riddle;	//or char* riddle;	//PARALLEL 
    string word;	//or char* word;	//ARRAYS 
};

struct Card { 
    int num; 
    int index; //index in the array of 54 cards 
    Image* img;
};

struct Deck {
    vector<Card> cards;
    int size;
};

struct Board {
    string plyrNme; //Player name
    int brdNum;
    Image* brdTbl;   //Board table
};

struct Player {
    string name;
    int numBeans;
    Board* board;
};

//Function Prototypes
bool openFil(fstream &,string);     //Opens a file for input
void showContents(fstream &);       //Display one contents of file to the screen
string* filToAr(fstream &);     //Save file contents to memory
void prntAr(string *);          //Print contents of an array
Image* newImg(string,string);   //Create a new image
void prntImg(Image *);      //Prints an image
Card* newCrd(Image*,int);          //Create 1 card
void prntCrd(Card *);       //Prints 1 card
Player* newPlyr(string);    //Create a player
void prntPlyr(Player *);       //Prints a single card
Board* newBrd(string);  //Create a new board
void prntBrd(Board *);          //Prints a board
void newFil(Player*);    //Create new file
Deck* newDck(fstream &);      //Creates a deck of cards from list of images
void prntDck(Deck *);       //Print deck of cards

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    fstream dataFile;
    string plyrName,*words,*riddles;
    int numPlyr;
    
    //Words to be used to create images and cards
    //Get words from cardWords.txt file and save to an array   
    if(openFil(dataFile,"cardWords.txt")) {
        //showContents(dataFile);
        words=filToAr(dataFile);
        //prntAr(words);
        dataFile.close();
        //cout<<"Words from cardWords.txt saved to array."<<endl;
    } else {
        cout<<"File open error!"<<endl;
    }
    
    //Get riddles from cardRiddles.txt file and save to an array
    if(openFil(dataFile,"cardRiddles.txt")) {
        //showContents(dataFile);
        riddles=filToAr(dataFile);
        //prntAr(riddles);
        dataFile.close();
        //cout<<"Riddles from cardRiddles.txt saved to array."<<endl;
    } else {
        cout<<"File open error!"<<endl;
    }
    
    //Create 1 image
    Image* img=newImg(words[14],riddles[14]);
    //Print 1 image
    prntImg(img);
    //Create 1 card from image
    Card* card=newCrd(img,14);
    //Print 1 card
    prntCrd(card);
    
    //Create a deck of cards
    
    //Shuffle the deck of cards
    
    //Create 20 boards of random 4x4 2d arrays of cards
        
    //Create 1 player, give each player a board
    cout<<"Enter your name: ";
    getline(cin,plyrName);
    Player* plyr=newPlyr(plyrName);
    prntPlyr(plyr);
    
    //Create new file to save player board and data to
    newFil(plyr);
//    showContents(dataFile);

    //Initial Variables

    //Map the Inputs to the Outputs

    //Display the Inputs and Outputs
   
    //Clean up the dynamic stuff
    delete img;
    delete card;
    delete plyr;
    //Exit the code
    return 0;
}

bool openFil(fstream &file,string name) {
    //Open file for input
    file.open(name,ios::in);
    
    if(file.fail()) {
        return false;
    } else
        return true;
}

void showContents(fstream &file) {
    string line;
    for(int i=0;i<54;i++) {
        getline(file,line,'\n');
        cout<<line<<endl;
    }
}

string* filToAr(fstream &file) {
    string *items=new string[54];
    string line;
    for(int i=0;i<54;i++) {
        getline(file,line,'\n');
        *(items+i)=line;
    }
    
    return items;
}

void prntAr(string *s) {
    for(int i=0;i<54;i++) {
        cout<<*(s+i)<<endl;
    }
}

Image* newImg(string word,string riddle) {
    Image* img=new Image;
    img->word=word;
    img->riddle=riddle;
    return img;
}

void prntImg(Image *img) { 
    cout<<"Word: "<<img->word<<endl;
    cout<<"Riddle: "<<img->riddle<<endl;
}

Card* newCrd(Image* img,int num) {
    Card* card=new Card;
    card->img=img;
    card->num=num+1;
    return card;
}

void prntCrd(Card *c) { 
    //Print out top border of the card
    for(int i=0;i<12;i++) {
        cout<<"_";
    }
    //Print out starts where an image would be
    cout<<endl<<" "<<setw(11);
    cout<<left<<c->num<<right<<"|"<<endl;
    for(int i=0;i<5;i++) {
        if(i==0) cout<<"   ";
        for(int j=0;j<5;j++) {
            cout<<"*";
                //IDEA FOR BOARD
//            if(i==2&&j==2) cout<<"O";
//            else cout<<"-";
        }
        cout<<"    |"<<endl<<"   ";
    }
    cout<<endl;
    
    //Print out the word
    for(int i=0;i<c->img->word.length();i++) {
        if(i>=0 && i<=c->img->word.length()) {
            if(i==0) cout<<" ";
            if(c->img->word.length()>=12)
                if(i==3) cout<<endl<<" ";
            cout<<c->img->word[i];
        }
    }
    cout<<endl;
    
    //Print out bottom border of the card
    for(int i=0;i<=12;i++) {
        cout<<"_";
    }
    cout<<endl<<"Riddle: "<<c->img->riddle<<endl<<endl;
}

Player* newPlyr(string name) {
    Player* player=new Player;
    player->name=name;
    player->numBeans=16;
//    Board* board=newBrd(player->name);
//    player->board=board;
//    board->brdNum=rand()%21;
    
    return player;
}

void prntPlyr(Player *p) {
    cout<<"Player Name: "<<p->name<<endl;
    cout<<"Number of Beans: "<<p->numBeans<<endl;
//    prntBrd(p->board);
    cout<<endl;
}

void newFil(Player* p) {
    ofstream dataFile;
    string filName;
    
    filName="data"+p->name+".txt";

    cout<<"Creating and opening player file...";
    // Open the file in output mode.
    dataFile.open(filName, ios::out);
    dataFile<<"Player Name: "<<p->name<<endl;
    dataFile<<"Number of Beans: "<<p->numBeans<<endl;
//    prntBrd(p->board);
    cout<<endl<<"Now closing the file.\n";
    dataFile.close();							// Close the file

    //When updating the file, don't open in append more. We need to override
    //what's currently in the file with new player game data
//    cout << "Opening the file again...\n";
//    // Open the file in append mode.
//    dataFile.open(filName, ios::out | ios::app);
//    cout << "Writing more data to the file.\n";
//    dataFile << "No changes";						
//    cout << "Now closing the file.\n";
//    dataFile.close();							// Close the file

    cout<<"Done.\n";
}

//Deck* newDck(fstream &) {
//   
//}
//void prntDck(Deck *) {
//    
//}