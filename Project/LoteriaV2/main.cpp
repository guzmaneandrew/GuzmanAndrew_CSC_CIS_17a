/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: October 27, 2022 @ 10:36 AM
 * Purpose: v3: Implement randomization for shuffling cards and creating boards
 * of random cards.
 */

//System Libraries
#include <iostream>  //Input/output Library
#include <iomanip>
#include <vector>
#include <fstream>
#include <cstdlib>
using namespace std;

//User Libraries
enum BrdWin {FULL=1,DIAGS=2,ROW=3,COL=4,CRNRS=5,SQX2=6,SQX3=7};

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only
const int NUMELMS=54;   //# of elements(lines in files,names,riddles,images,cards/deck)
const int ROWS=4;       //Number of rows in board
const int COLS=4;       //Number of columns in board

//Structure Definitions 
struct Image { 
    string riddle;  //Riddle that corresponds to an image 
    string name;    //Name that corresponds to an image and printed on the card
};

struct Card { 
    int num;        //Number displayed on card
    int index;      //Index in the array of 54 cards 
    bool found;     //Flag to mark if card is found on board
//    string name;    //Name printed on card
    Image* img;     //Pointer to image in card structure
};

struct Deck {
    vector<Card> cards; //Deck of cards
    int maxSize;        //Maximum size of deck
};

struct Board {
    int brdNum;         //Number printed on the board
    Card board[4][4];   //2d array of cards makes up the board
};

struct Player {
    string name;    //Name of the player
    int tokens;     //Number of tokens
    Board* board;   //Pointer to a board in player structure
};

//Function Prototypes
bool openFil(fstream &,string); //Opens a file for input
void showContents(fstream &);   //Displays file contents to screen line by line
string* filToAr(fstream &);     //Saves file contents to memory
void prntAr(const string *);    //Prints contents of an array
Image* newImg(string,string);   //Creates 1 new image
void prntImg(const Image *);    //Prints 1 image
Image** newImgs(string *,string *); //Creates array of pointers to pointers to all images
void prntImgs(const Image **);  //Prints all 54 images
Card* newCrd(Image *,int);      //Creates 1 new card
void prntCrd(const Card *);     //Prints 1 card using pointer
void prntCrd(const Card);       //Prints 1 card 
Card** newCrds(Image **);       //Creates array of pointers to pointers to all cards
void prntCrds(Card **);         //Prints all 54 cards
void crtDck(Deck &,Card **);    //Creates a deck of cards from cards created
void prntDck(const Deck &);     //Print deck of cards
Board* newBrd(Card **);         //Create 1 new board
void prntBrd(const Board *);    //Prints a board
Player* newPlyr(string);        //Creates 1 player
void prntPlyr(const Player *);  //Displays player game data to the screen
void newFil(Player*);           //Create new file to save player game data to
//void brdCrd(const Card);       //Prints 1 card
//REMOVE FOR V2 and keep for v3
void winPtrn();                 //Sets winning pattern for the game
int setTkns();                  //Set the number of tokens to give each players

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    fstream dataFile;
    string plyr1="Player1",plyr2="Player2",
        *names=nullptr,     //Array used create images and cards
        *riddles=nullptr;   //Array to create images and cards
    int tokens;             //Number of tokens given to each player
    Image **images;
    Card **cards;
    Deck deck;
    Board *board=nullptr;
    
    //User sets the winning pattern
    winPtrn();
    //User sets the number of tokens for each player to use
    tokens=setTkns();
//    User generates a random board for each player
//    Display boards player boards to the screen and corresponding files
//    User shuffles the deck of cards
    //User pulls a card
    //Display card and corresponding riddle on the screen
    //Send the cards riddle to the computer players
    //Computer players take in riddle, match the riddle to a name, and
        //search for the corresponding card on their board.
    //Display on the screen an update on each player after every card pulled
        //-"Player1 found a match on their board at R,C"
        //-"Player2 didn't have a match"
    //Append to their game stats file
        //(append not update so we can see history)
        //Board
        //Round 1: Found match at R,C.
        //Round 2: No match found.
        //Round X: Loteria!
    //Repeat at line 103 until:
        //-no more tokens left
        //-a player fills their board
        //-if num of cards called=54, reshuffle the deck
    
    //Get names from cardNames.txt file and save to an array   
    if(openFil(dataFile,"cardNames.txt")) {
        //showContents(dataFile);
        names=filToAr(dataFile);
        //prntAr(names);
        dataFile.close();
        //cout<<"names from cardnames.txt saved to array."<<endl;
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
    
//    //Create 1 image
//    Image* img=newImg(names[14],riddles[14]);
//    //Print 1 image
//    prntImg(img);
//    //Create 1 card from image
//    Card* card=newCrd(img,14);
//    //Print 1 card
//    prntCrd(card);

    //Create all images
    images=newImgs(names,riddles);
    //Print all images
//    prntImgs(images);

    //Create all cards using the images
    cards=newCrds(images);
//    //Print all cards
//    cout<<"Printing out cards..."<<endl;
//    prntCrds(cards);
//    cout<<"Done printing out cards..."<<endl;
    
    //Create deck of cards
    crtDck(deck,cards);
    //Print deck of cards
    cout<<"Printing out deck..."<<endl;
    prntDck(deck);
    cout<<"Done printing deck..."<<endl;
    
    //Shuffle the deck of cards
            
    //Create 1 player, with it's own random board
    Player* plyr=newPlyr(plyr1);
    board=newBrd(cards);
    plyr->board=board;
    prntPlyr(plyr); 

    //Create new file to save player board and data to
    newFil(plyr);
//    showContents(dataFile);

    //Initial Variables

    //Map the Inputs to the Outputs

    //Display the Inputs and Outputs
   
    //Clean up the dynamic stuff
    delete images;
    delete cards;
    delete plyr;
    delete board;
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
    for(int i=0;i<NUMELMS;i++) {
        getline(file,line,'\n');
        cout<<line<<endl;
    }
}

string* filToAr(fstream &file) {
    string *items=new string[NUMELMS];
    string line;
    for(int i=0;i<NUMELMS;i++) {
        getline(file,line,'\n');
        *(items+i)=line;
    }
    
    return items;
}

void prntAr(const string *s) {
    for(int i=0;i<NUMELMS;i++) {
        cout<<*(s+i)<<endl;
    }
}

Image* newImg(string name,string riddle) {
    Image* img=new Image;
    img->name=name;
    img->riddle=riddle;
    return img;
}

void prntImg(const Image *img) {
    cout<<"name: "<<img->name<<endl;
    cout<<"Riddle: "<<img->riddle<<endl;
}

Image** newImgs(string* names,string* riddles) {
    Image **imgs=nullptr;

    //Dynamically allocate an array of 54 pointers to Images
    imgs=new Image*[NUMELMS];          //Array of pointers
    for(int i=0;i<NUMELMS;i++) {
        *(imgs+i)=newImg(names[i],riddles[i]);
    }
   
    return imgs;
}

void prntImgs(const Image **imgs) {
    for(int i=0;i<NUMELMS;i++) {
        prntImg(*(imgs+i));
    }
}

Card* newCrd(Image *img,int num) {
    Card *card=new Card;
    card->img=img;
    card->num=num+1;
//    card->name=img->name;
    return card;
}

void prntCrd(const Card *c) { 
    //Print out top border of the card
    for(int i=0;i<14;i++) {
        cout<<"_";
    }
    
    //Print out starting where an image would be (represented by *)
    cout<<endl<<" "<<setw(14);
    cout<<setw(3)<<right<<c->num<<endl;
    
    
    //Change into nested array
    for(int i=0;i<6;i++) {
        cout<<setw(4)<<left<<" ";
        cout<<"******"<<endl;
        if(i==5) cout<<endl;
    }
    
    //Print out the name
    for(int i=0;i<c->img->name.length();i++) {
        if(i>=0 && i<=c->img->name.length()) {
            cout<<c->img->name[i];
        }
    }
    cout<<endl;
    
    //Print out bottom border of the card
    for(int i=0;i<14;i++) {
        cout<<"_";
    }
    cout<<endl;
    cout<<endl<<"Riddle: "<<c->img->riddle<<endl<<endl;
}

void prntCrd(const Card c) { 
    //Print out top border of the card
    for(int i=0;i<14;i++) {
        cout<<"_";
    }
    
    //Print out starting where an image would be (represented by *)
    cout<<endl<<" "<<setw(14);
    cout<<setw(3)<<right<<c.num<<endl;
    
    
    //Change into nested array
    for(int i=0;i<6;i++) {
        cout<<setw(4)<<left<<" ";
        cout<<"******"<<endl;
        if(i==5) cout<<endl;
    }
    
    //Print out the name
    for(int i=0;i<c.img->name.length();i++) {
        if(i>=0 && i<=c.img->name.length()) {
            cout<<c.img->name[i];
        }
    }
    cout<<endl;
    
    //Print out bottom border of the card
    for(int i=0;i<14;i++) {
        cout<<"_";
    }
    cout<<endl;
    cout<<endl<<"Riddle: "<<c.img->riddle<<endl<<endl;
}

Card** newCrds(Image **imgs) {
    Card **cards=nullptr;
    
    cards=new Card*[NUMELMS];
    for(int i=0;i<NUMELMS;i++) {
        *(cards+i)=newCrd(*(imgs+i),i);
    }
    
    return cards;
}

void prntCrds(Card **cards) {
    for(int i=0;i<NUMELMS;i++) {
        prntCrd(*(cards+i));
    }
}

void crtDck(Deck &d,Card **cards) {
    d.maxSize=NUMELMS;
    for(int i=0;i<d.maxSize;i++) {
        Card card=*(*(cards+i));
        d.cards.push_back(card);
    }
}

void prntDck(const Deck& d) {
    for(int i=0;i<d.maxSize;i++) {
        prntCrd(d.cards[i]);
    }
    cout<<endl;
}

Board* newBrd(Card **cards) {
    Board *b=new Board;
    int index=0;
    for(int r=0;r<4;r++) {
        for(int c=0;c<4;c++) {
            if(index!=16) {
                b->board[r][c]=*(*(cards)+index);
                b->board[r][c].found=false; //Found flag false at beg of game 
                
            }
            index++;
        }
    }
    
    return b;
}

void prntBrd(const Board *b) {
    //Set width to 60 variable for width
    //Print out top border of row1
    //Print first row containing card numbers of 4 cards in top row
    //Print out rows 2-7 containing stars in place of images
    //Print out blank row 9
    //Print the name of the card to row 9
    //Print bottom border of row1
    //Continue for 3 more rows for total of 4 rows
    
    for(int r=0;r<4;r++) {
        for(int c=0;c<4;c++) {
            if(b->board[r][c].found) {
                cout<<"Found"<<endl;
            } else {
                cout<<"Not found"<<endl;
            }
        }
    }

}

Player* newPlyr(string name) {
    Player* player=new Player;
    player->name=name;
    player->tokens=16;
//    Board* board=newBrd(player->name);
//    player->board=board;
//    board->brdNum=rand()%21;
    
    return player;
}

void prntPlyr(const Player *p) {
    cout<<"Player Name: "<<p->name<<endl;
    cout<<"Number of Beans: "<<p->tokens<<endl;
    cout<<"Printing out your board..."<<endl;
    //Create function to output to player file
    prntBrd(p->board);
//    cout<<"Done printing out your board..."<<endl;
//    cout<<endl;
}

void newFil(Player* p) {
    ofstream dataFile;
    string filName;
    
    filName="data"+p->name+".txt";

    cout<<"Creating and opening player file..."<<endl;
    // Open the file in output mode.
    dataFile.open(filName, ios::out);
    dataFile<<"Player Name: "<<p->name<<endl;
    dataFile<<"Number of Beans: "<<p->tokens<<endl;
    //Create function to output to player file
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

//void brdCrd(const Card c) { 
//    //Print out top border of the card
//    for(int i=0;i<14;i++) {
//        cout<<"_";
//    }
//    
//    //Print out starting where an image would be (represented by *)
//    cout<<endl<<" "<<setw(14);
//    cout<<setw(3)<<right<<c.num<<endl;
//    
//    
//    //Change into nested array
//    for(int i=0;i<6;i++) {
//        cout<<setw(4)<<left<<" ";
//        cout<<"******"<<endl;
//        if(i==5) cout<<endl;
//    }
//    
//    //Print out the name
//    for(int i=0;i<c.img->name.length();i++) {
//        if(i>=0 && i<=c.img->name.length()) {
//            cout<<c.img->name[i];
//        }
//    }
//    cout<<endl;
//    
//    //Print out bottom border of the card
//    for(int i=0;i<14;i++) {
//        cout<<"_";
//    }
//    cout<<endl;
//}

//REMOVE FROM V2 AND keep for V3
void winPtrn() {
    int option;
    
    cout<<"Set the Winning Pattern";
    cout<<"Options: 1=Full, 2=Diagonals, 3=Row, 4=Column\n";
    
    do{
        cout<<"Enter Pattern #";
        cin>>option;
    } while(option!=1&&option!=2&&option!=3&&option!=4);
    
    cout<<"Winning Pattern: ";
    
    switch(option) {
        case FULL:
          cout<<"Full"<<endl;
//          for(int r=0;r<ROWS;r++) {
//              for(int c=0;c<COLS;c++) {
//                  cout<<"| * |";
//              }
//              cout<<endl;
//          }
          break;
        case DIAGS:
          cout<<"Diagonals\n";
          break;
        case ROW:
          cout<<"Row\n";
          break;
        case COL:
          cout<<"Columns\n";
          break;
      }
}

int setTkns() {
    int numTkns;
    
    do {
        cout<<"Set the Number of Tokens for Each Player(16 to 50): ";
        cin>>numTkns;       
    }while(numTkns<16||numTkns>50);
    
    cout<<"Number of Tokens: "<<numTkns<<endl;
    
    return numTkns;
}