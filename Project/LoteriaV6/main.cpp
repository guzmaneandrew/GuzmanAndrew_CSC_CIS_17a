/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: November 1, 2022 @ 10:00 AM
 * Purpose: v6: Implementation of game logic for a 2 player game.
 */

//System Libraries
#include <iostream>  //Input/output Library
#include <iomanip>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <random>
using namespace std;

//User Libraries
enum BrdWin {FULL=1,ROW=2,COL=3,DIAGS=4};

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
    int xIndex;      //X Index in the board
    int yIndex;     //Y Index in the board 
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
string* filToAr(fstream &);     //Saves file contents to memory
Image* newImg(string,string);   //Creates 1 new image
Image** newImgs(string *,string *); //Creates array of pointers to pointers to all images
Card* newCrd(Image *,int);      //Creates 1 new card
void prntCrd(const Card *);     //Prints 1 card using pointer
void prntCrd(const Card);       //Prints 1 card 
Card** newCrds(Image **);       //Creates array of pointers to pointers to all cards
void crtDck(Deck &,Card **);    //Creates a deck of cards from cards created
void prntDck(const Deck &);     //Print deck of cards
void shufDck(Deck &);           //Shuffles deck of cards
vector<int> rndCrds(int);       //Generates 16 random card numbers of the possible 1 -54
Board* newBrd(Card **,int);     //Creates a random board
void prntBrd(const Board *);    //Prints a board
Player* newPlyr(string,int);    //Creates 1 player
void prntPlyr(Player *);        //Displays player game data to the screen
void brd2Fil(const Board *,ofstream &); //Prints a board to a file
void crtFile(Player*);           //Create new file to save player game data to
void winPtrn();                 //Sets winning pattern for the game
int setTkns();                  //Set the number of tokens to give each players
//FUNCTIONS NEEDED DURING DEVELOPMENT - NOT USED IN FINAL PROJECT
//void brdCrd(const Card);       //Prints 1 card
//void showContents(fstream &);   //Displays file contents to screen line by line
//void prntAr(const string *);    //Prints contents of an array
void prntImg(const Image *);    //Prints 1 image
//void prntImgs(const Image **);  //Prints all 54 images
//void prntCrds(Card **);         //Prints all 54 cards
//Board* newBrd(Card **);         //Create 1 new board

//Program Execution Begins Here!!!
int main(int argc, char** argv) {
    //Declare Variables
    fstream dataFile;
    string p1Name,p2Name;
    int tokens;             //Number of tokens given to each player
    Image **images;         //Pointers to pointers to images
    Card **cards;           //Pointers to pointers to cards
    Deck deck;              //1 deck of cards
    int option;             //Input for user
        
    //Initial Variables
    p1Name="Player1";
    p2Name="Player2";
    string *riddles=nullptr,  //String array used to create images
           *names=nullptr;    //String array used create images and cards
    Board *board1=nullptr,*board2=nullptr;  //Pointers to boards
    Player *plyr1=nullptr,*plyr2=nullptr;   //Pointers to players
    
//Set up for the game
    //Get names from cardNames.txt file and save to names array   
    if(openFil(dataFile,"cardNames.txt")) {
        names=filToAr(dataFile);    //Dynamically allocated
        dataFile.close();
    } else {
        cout<<"File open error!"<<endl;
    }
   
    //Get riddles from cardRiddles.txt file and save to riddles array
    if(openFil(dataFile,"cardRiddles.txt")) {
        riddles=filToAr(dataFile);  //Dynamically allocated
        dataFile.close();
    } else {
        cout<<"File open error!"<<endl;
    }

    //Create all images
    images=newImgs(names,riddles);

    //Create all cards using the images
    cards=newCrds(images);
    
    //Create deck of cards
    crtDck(deck,cards);
             
//Game Begins
    cout<<"LOTERÍA GAME\n"<<endl;
    cout<<"You are the caller of the game. The caller is responsible "
        "for shuffling the deck of cards and calling out cards one-by-one.\n"
        "Instead of calling out the name on the card, you will call out a riddle "
        "to the players.\n"
        "The players will take in the riddle and search their boards "
        "for the card with the corresponding image.\n"<<endl;
    
    //User shuffles the deck of cards
    shufDck(deck);
    //Print shuffled deck
    cout<<"Printing shuffled deck..."<<endl;
    prntDck(deck);
    cout<<"Done printing shuffled deck.\n"<<endl;
    
    //User sets the winning pattern
    winPtrn();
    //User sets the number of tokens for each player to use
    tokens=setTkns();
    
    //Create player 1, with it's own random board
    plyr1=newPlyr(p1Name,tokens);
    board1=newBrd(cards,1);
    plyr1->board=board1;
    //Create new file to save player 1 data to
    crtFile(plyr1);
    
    //Create player 2, with it's own random board
    plyr2=newPlyr(p2Name,tokens);
    board2=newBrd(cards,2);
    plyr2->board=board2;
    //Create new file to save player 1 data to
    crtFile(plyr2);
    
    //Display player 1 and 2 board to the screen
    do {
        cout<<"Press 1 to View Player 1 Game Data: ";
        cin>>option;
    } while(option!=1);
    
    cout<<"------------------------------------------------------------"<<endl;
    prntPlyr(plyr1); 
    
    do {
        cout<<"Press 2 to View Player 2 Game Data: ";
        cin>>option;
    } while(option!=2);
    cout<<"------------------------------------------------------------"<<endl;
    prntPlyr(plyr2);
        
    //Caller pulls a card from the deck
    //Display pulled card and corresponding riddle on the screen
    //Send the cards riddle to the computer players
    //Computer players take in riddle, match the riddle to a name, and
        //search for the corresponding card on their board.
    //Display on the screen an update on each player after every card pulled
    //Append to their game stats file after board
        //Append not update so we can see their board and history
    //Repeat until:
        //-players have 0 tokens
        //-a player fills their board
        //-if num of cards called=54, reshuffle the deck line 102.
   
    //Clean up the dynamic stuff
//    delete images;
//    delete cards;
    delete plyr1;
    delete plyr2;
    delete board1;
    delete board2;
    
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

string* filToAr(fstream &file) {
    string *items=new string[NUMELMS];
    string line;
    for(int i=0;i<NUMELMS;i++) {
        getline(file,line,'\n');
        *(items+i)=line;
    }
    
    return items;
}

Image* newImg(string name,string riddle) {
    //Create new image using name and riddle
    Image* img=new Image;
    img->name=name;
    img->riddle=riddle;
    return img;
}

void prntImg(const Image *img) {
    cout<<"Name: "<<img->name<<endl;
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

Card* newCrd(Image *img,int num) {
    Card *card=new Card;
    card->img=img;
    card->num=num+1;
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
    
    //Placeholder for where images would be on the cards
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
}

Card** newCrds(Image **imgs) {
    Card **cards=nullptr;
    
    cards=new Card*[NUMELMS];
    for(int i=0;i<NUMELMS;i++) {
        *(cards+i)=newCrd(*(imgs+i),i);
    }
    
    return cards;
}

void crtDck(Deck &d,Card **cards) {
    d.maxSize=NUMELMS;
    for(int i=0;i<d.maxSize;i++) {
        Card card=*(*(cards+i));
        d.cards.push_back(card);
    }
}

void prntDck(const Deck& d) {
    for(int i=0;i<NUMELMS;i++) {
        prntCrd(d.cards[i]);
    }
    cout<<endl;
}

void prntBrd(const Board *b) {
    //Set width to 60 variable for width
    int brdWdth=60;
    
    cout<<endl;
    cout<<"LOTERIA"<<setw(brdWdth-8)<<"BOARD "<<b->brdNum<<endl;
    for(int j=0;j<4;j++) {
        //Print out top border of board
        for(int i=0;i<brdWdth;i++) cout<<"_";
        cout<<endl;
        //Print first row containing card numbers of 4 cards in top row
        for(int i=0;i<4;i++) {
            cout<<setw(brdWdth/4-1)<<left<<b->board[j][i].num
                <<setw(1)<<right<<"|";       
        }
        cout<<endl;

        //Print out rows 2-7 containing stars in place of images
        for(int i=0;i<4;i++) {
            cout<<setw(4)<<left<<" "
            <<setw(6)<<"------"
            <<setw(4)<<left<<" "
            <<"|";
        } cout<<endl;
        for(int i=0;i<4;i++) {
            cout<<setw(4)<<left<<" "
            <<setw(6)<<"------"
            <<setw(4)<<left<<" "
            <<"|";
        } cout<<endl;
        for(int i=0;i<4;i++) {
            cout<<setw(4)<<left<<" "
            <<setw(6)<<"------"
            <<setw(4)<<left<<" "
            <<"|";
        } cout<<endl;
        for(int i=0;i<4;i++) {
            cout<<setw(4)<<left<<" "
            <<setw(6)<<"------"
            <<setw(4)<<left<<" "
            <<"|";
        } cout<<endl;
        for(int i=0;i<4;i++) {
            cout<<setw(4)<<left<<" "
            <<setw(6)<<"------"
            <<setw(4)<<left<<" "
            <<"|";
        } cout<<endl;

        //Print out blank row 9
        for(int i=0;i<4;i++) {
            cout<<setw(15)<<right<<"|";
        }
        cout<<endl;        
    }
    //Print out bottom border of board
        for(int i=0;i<brdWdth;i++) cout<<"_";
        cout<<endl;
    
    
    //Goal is to print the name on the board
    //Temporarily print the card names and numbers underneath the board
        for(int r=0;r<4;r++) {
            for(int c=0;c<4;c++) {
                cout<<b->board[r][c].num<<" ";
                cout<<b->board[r][c].img->name<<endl;
            }
        }
    cout<<endl;

}

Player* newPlyr(string name,int tokens) {
    Player* player=new Player;
    player->name=name;
    player->tokens=tokens;
    
    return player;
}

void prntPlyr(Player *p) {
    cout<<"Player Name: "<<p->name<<endl;
    prntBrd(p->board);
}

void crtFile(Player* p) {
    ofstream dataFile;
    string filName;
    
    filName="data"+p->name+".txt";

    // Open the file in output mode.
    dataFile.open(filName, ios::out);
    dataFile<<"Player Name: "<<p->name<<endl;
    dataFile<<"Number of Beans: "<<p->tokens<<endl;
    brd2Fil(p->board,dataFile);
    dataFile.close();						

    //When updating the file, don't open in append more. We need to override
    //what's currently in the file with new player game data
//    cout << "Opening the file again...\n";
//    // Open the file in append mode.
//    dataFile.open(filName, ios::out | ios::app);
//    cout << "Writing more data to the file.\n";
//    dataFile << "No changes";						
//    cout << "Now closing the file.\n";
//    dataFile.close();							
}

void brd2Fil(const Board *b,ofstream &file) {
        //Set width to 60 variable for width
    int brdWdth=60;
    
    file<<endl;
    file<<"LOTERIA"<<setw(brdWdth-8)<<"BOARD "<<b->brdNum<<endl;
    for(int j=0;j<4;j++) {
        //Print out top border of board
        for(int i=0;i<brdWdth;i++) file<<"_";
        file<<endl;
        //Print first row containing card numbers of 4 cards in top row
        for(int i=0;i<4;i++) {
            file<<setw(brdWdth/4-1)<<left<<b->board[j][i].num
                <<setw(1)<<right<<"|";       
        }
        file<<endl;

        //Print out rows 2-7 containing stars in place of images
        for(int i=0;i<4;i++) {
            file<<setw(4)<<left<<" "
            <<setw(6)<<"------"
            <<setw(4)<<left<<" "
            <<"|";
        } file<<endl;
        for(int i=0;i<4;i++) {
            file<<setw(4)<<left<<" "
            <<setw(6)<<"------"
            <<setw(4)<<left<<" "
            <<"|";
        } file<<endl;
        for(int i=0;i<4;i++) {
            file<<setw(4)<<left<<" "
            <<setw(6)<<"------"
            <<setw(4)<<left<<" "
            <<"|";
        } file<<endl;
        for(int i=0;i<4;i++) {
            file<<setw(4)<<left<<" "
            <<setw(6)<<"------"
            <<setw(4)<<left<<" "
            <<"|";
        } file<<endl;
        for(int i=0;i<4;i++) {
            file<<setw(4)<<left<<" "
            <<setw(6)<<"------"
            <<setw(4)<<left<<" "
            <<"|";
        } file<<endl;

        //Print out blank row 9
        for(int i=0;i<4;i++) {
            file<<setw(15)<<right<<"|";
        }
        file<<endl;        
    }
    //Print out bottom border of board
        for(int i=0;i<brdWdth;i++) file<<"_";
        file<<endl;
    
    
    //Goal is to print the name on the board
    //Temporarily print the card names and numbers underneath the board
        for(int r=0;r<4;r++) {
            for(int c=0;c<4;c++) {
                file<<b->board[r][c].num<<" ";
                file<<b->board[r][c].img->name<<endl;
            }
        }
    file<<endl;

}

void winPtrn() {
    int option;
    
    cout<<"Set the Pattern Needed to Win\n";
    cout<<"Options: #1=Full, #2=Row, #3=Column, #4=Diagonals\n";
    
    do{
        cout<<"Enter Pattern #: ";
        cin>>option;
    } while(option!=1&&option!=2&&option!=3&&option!=4);
    
    cout<<"Players Must Match One of The Following Patterns to Win:\n";
    
    switch(option) {
        case FULL:
          cout<<"Full"<<endl;
          for(int r=0;r<ROWS;r++) {
              for(int c=0;c<COLS;c++) {
                  cout<<"| * |";
              }
              cout<<endl;
          }
          break;
        case ROW:
          for(int i=0;i<4;i++) {
              cout<<"Row "<<i+1<<endl;
            for(int r=0;r<ROWS;r++) {
              for(int c=0;c<COLS;c++) {
                  if(r==i) cout<<"| * |";
                  else     cout<<"|   |";
              }
              cout<<endl;
            }     
          }
          break;
        case COL:
          for(int i=0;i<4;i++) {
              cout<<"Column "<<i+1<<endl;
            for(int r=0;r<ROWS;r++) {
              for(int c=0;c<COLS;c++) {
                  if(c==i) cout<<"| * |";
                  else     cout<<"|   |";
              }
              cout<<endl;
            }     
          }
          break;
        case DIAGS:
          cout<<"Diagonal 1"<<endl;
          for(int i=0;i<4;i++) {
              for(int j=0;j<4;j++) {
                  if(i==j) cout<<"| * |";
                  else     cout<<"|   |";
              }
              cout<<endl;
          }
          cout<<endl;

          cout<<"Diagonal 2"<<endl;
          for(int i=0;i<4;i++) {
              for(int j=0;j<4;j++) {
                  if(i+j==3){
                      cout<<"| * |";
                  } else {
                      cout<<"|   |";
                  }
              }
              cout<<endl;
          }
          break;
      }
    
    cout<<endl;
}

int setTkns() {
    int numTkns;
    
    do {
        cout<<"Set the Number of Tokens for Each Player(16 to 50): ";
        cin>>numTkns;       
    }while(numTkns<16||numTkns>50);
    
    cout<<endl;
    return numTkns;
}

void shufDck(Deck &d) {
    Deck shufDck;
    int rndIndx;
    int option;
    
    do {
        cout<<"Press 1 to shuffle the deck of cards: ";
        cin>>option;
    } while(option!=1);
    
    while(!d.cards.empty()) {
        rndIndx=rand()%d.cards.size();
        shufDck.cards.push_back(d.cards[rndIndx]);
        d.cards.erase(d.cards.begin()+rndIndx);
    }
    
    d=shufDck;
}

vector<int> rndCrds(int numCrds) {
    vector<int> v(numCrds);

    iota(v.begin(),v.end(),0);

//    for(int i=0;i<numCrds;i++) {
//        cout<<v[i]+1<<' ';
//    }
//    cout<<endl;
    
    random_device rd;   //random number generator
    mt19937 g(rd());    //needed for the shuffle function

    shuffle(v.begin(),v.end(),g);

//    for(int i=0;i<numCrds;i++) {
//        cout<<v[i]+1<<' ';
//    }
    
    return v;
}

Board* newBrd(Card **cards,int num) {
    Board *b=new Board;
    b->brdNum=num;
    //Generate vector of random card numbers to be used to make random board
    vector<int> v=rndCrds(54);
    //Print out contents of vector to verify 
//    for(int i=0;i<16;i++) {
//        cout<<v[i]+1<<' ';
//    }
//    cout<<endl;

    int index=0;
    for(int r=0;r<4;r++) {
        for(int c=0;c<4;c++) {
            //Take de-reference pointer to pointer to card to be placed in board
            b->board[r][c]=*(*(cards+v[index]));
            //Set the found flag of the card on the board to false
            b->board[r][c].found=false;
            index++;   //Index 0-15
        }
    }    
    return b;
}

//Board* newBrd(Card **cards) {
//    Board *b=new Board;
//    int index=0;
//    for(int r=0;r<4;r++) {
//        for(int c=0;c<4;c++) {
//            if(index!=16) {
//                b->board[r][c]=*(*(cards)+index);
//                b->board[r][c].xIndex=r;    //Set the xIndex of the card in the board
//                b->board[r][c].yIndex=c;    //Set the yIndex of the card in the board
//                b->board[r][c].found=false; //Found flag false at beg of game 
//            }
//            index++;
//        }
//    }
//    
//    return b;
//}

//void showContents(fstream &file) {
//    string line;
//    for(int i=0;i<NUMELMS;i++) {
//        getline(file,line,'\n');
//        cout<<line<<endl;
//    }
//}

//void prntAr(const string *s) {
//    for(int i=0;i<NUMELMS;i++) {
//        cout<<*(s+i)<<endl;
//    }
//}

//void prntImgs(const Image **imgs) {
//    for(int i=0;i<NUMELMS;i++) {
//        prntImg(*(imgs+i));
//    }
//}

//void prntCrds(Card **cards) {
//    for(int i=0;i<NUMELMS;i++) {
//        prntCrd(*(cards+i));
//    }
//}