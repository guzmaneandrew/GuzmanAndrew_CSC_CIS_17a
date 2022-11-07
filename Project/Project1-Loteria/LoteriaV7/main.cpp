/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: November 3, 2022 @ 11:00 AM
 * Purpose: v7: Implement binary files. Refactor code to us structures and arrays
 * of structures vs pointers to structures and pointers to pointers to structures.
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
enum BrdWin {FULL=1,ROW=2,COL=3,DIAGS=4};   //Winning board patterns

//Global Constants
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
    int xIndex;     //X Index in the board
    int yIndex;     //Y Index in the board 
    bool found;     //Flag to mark if card is found on board
    Image img;     //Image in card structure
};

struct Deck {
    vector<Card> cards; //Deck of cards
    int maxSize;        //Maximum size of deck
};

struct Board {
    int brdNum;                 //Number printed on the board
    Card board[ROWS][COLS];     //2d array of cards makes up the board
};

struct Player {
    string name;    //Name of the player
    int plyrTkn;    //Number of tokens used during game
    Board* board;   //Pointer to a board in player structure
};

//Function Prototypes
Image newImg(string,string);   //Creates 1 new image structure
Image* newImgs(string *,string *); //Creates array of image structures
Card newCrd(Image,int);      //Creates 1 new card structure
Card* newCrds(Image *);       //Creates array of card structures
void crtDck(Deck &,Card *);    //Creates a deck of cards using array of cards
void shufDck(Deck &);           //Shuffles deck of cards
vector<int> rndCrds();          //Generates 16 random card numbers for board
Board* newBrd(Card *,int);     //Creates a random board
int winPtrn();                  //Sets winning pattern for the game
int setTkns(int);               //Set the number of tokens for players to share
void chkBrd(string,Player *,int &); //Checks board and updates player if match found
bool openFil(fstream &,string); //Opens a file for input
string* filToAr(fstream &);     //Saves file contents to memory
ofstream plyrFil(Player *);      //Create new text file to save player game data to
void prntCrd(const Card);       //Prints 1 card structure
void prntDck(const Deck &);     //Print deck of cards
void dispBrd(const Player *);    //Display player's mini boards on screen
void prntPlyr(Player *);        //Displays player game data to the screen
void prntBrd(const Board *);    //Prints 1 board
void brd2Fil(const Board *,ofstream &); //Prints a board to a file
void wrt2Bin(Player,fstream &);      //Writes contents of player to binary files
void dispBin(Player,fstream &);     //Displays contents of binary file

//Program Execution Begins Here!!!
int main(int argc, char** argv) {
    //Random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    fstream dataFile;       //Input files
    ofstream p1File,p2File; //Player files to output to
    string p1Name,p2Name;   //Name of players
    Image *images;         //Array of images
    Card *cards,           //Array of cards
        topCrd;             //Card pulled from top of the deck
    Deck deck;              //Deck of cards
    int input,              //Input for user
        pattern,            //Winning pattern for game
        gamTkns,            //Number of tokens available for the game
        numRnds;            //Number of rounds for game
        
    //Initial Variables
    char game[]="LOTERÍA";  //Store name of game in c-string
    string *riddles,
           *names;      //String array of names used create images and cards
    Board *board1=nullptr,*board2=nullptr;      //Pointers to boards
    p1Name="Player1",p2Name="Player2";
    Player plyr1={p1Name},plyr2={p2Name};       //Initialize player structures
    Player *plyr1Ptr=&plyr1,*plyr2Ptr=&plyr2;   //Pointers to player structures
    numRnds=0;
    
//Set up for the game
    //Get card names from cardNames.txt file and save to names array   
    if(openFil(dataFile,"cardNamesEN.txt")) {
        names=filToAr(dataFile);    
        dataFile.close();
    } else {
        cout<<"File open error!"<<endl;
    }
   
    //Get card riddles from cardRiddles.txt file and save to riddles array
    if(openFil(dataFile,"cardRiddlesEN.txt")) {
        riddles=filToAr(dataFile);  
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
    //Display game title
    int index=0;
    while(game[index]!='\0') {
        cout<<game[index];
        index++;
    }
    cout<<endl;
    
    //Display game prompt
    cout<<"This is a game of Lotería with 2 computer players and 1 caller.\n"
          "You are the caller of this game."<<endl;
    
    //User sets the winning pattern
    pattern=winPtrn();
    
    //User sets the number of tokens for player to use during game
    //pass in pattern because number depends on what pattern is set
    gamTkns=setTkns(pattern);
    
    //User shuffles the deck of cards
    shufDck(deck);
    //Print shuffled deck
//    prntDck(deck);    

    //Create random board and assign to player 1
    board1=newBrd(cards,1);         //Create a random board for player1
    plyr1Ptr->board=board1;         //Assign board to player1
    p1File=plyrFil(plyr1Ptr);       //Create new file to save player1 data to
    
        do {                    //Display player 1 board to the screen
        cout<<"Press 1 to View Player 1's Board: ";
        cin>>input;
    } while(input!=1);
    prntPlyr(plyr1Ptr);
    cout<<"------------------------------------------------------------"<<endl;
    
    //Create random board and assign to player 2
    board2=newBrd(cards,2);     //Create a random board for player2   
    plyr2Ptr->board=board2;        //Assign board to player2
    plyrFil(plyr2Ptr);             //Create new file to save player2 data to 
    do {                        //Display player 2 board to the screen
        cout<<"Press 2 to View Player 2's Board: ";
        cin>>input;
    } while(input!=2);
    prntPlyr(plyr2Ptr);
      
    //Game continue while deck is not empty, tokens still available,and no win
    while(!deck.cards.empty()&&gamTkns>0) {
        numRnds++;
        cout<<"------------------------------------------------------------"<<endl;
        cout<<"ROUND "<<numRnds<<": "<<endl;
        cout<<"Number of Tokens Remaining: "<<gamTkns<<endl<<endl;
        do {
            cout<<"Press 1 to Pull a Card From the Deck: ";
            cin>>input;
        }while(input!=1);
        
        if(input==1) {
            //Caller pulls a card from the deck     
            topCrd=deck.cards.front();
            //Display pulled card and corresponding riddle on the screen
            prntCrd(topCrd);
            //Send the cards riddle to the computer players to check their boards
            chkBrd(topCrd.img.riddle,plyr1Ptr,gamTkns);
            chkBrd(topCrd.img.riddle,plyr2Ptr,gamTkns);
            //Display mini board pattern on screen
            dispBrd(plyr1Ptr);
            dispBrd(plyr2Ptr);
            //Remove called card from deck
            deck.cards.erase(deck.cards.begin(),deck.cards.begin()+1);            
        }
    }
   
    wrt2Bin(plyr1,dataFile);
    dispBin(plyr1,dataFile);
    wrt2Bin(plyr2,dataFile);
    dispBin(plyr2,dataFile);
    
    //Clean up the dynamic stuff
    delete board1;
    delete board2;
    
    //Exit the code
    return 0;
}

Image newImg(string name,string riddle) {
    Image img;  //Create new image using name and riddle
    img.name=name;
    img.riddle=riddle;
    return img;
}

Image* newImgs(string* names,string* riddles) {
    //Dynamically allocate and fill array of 54 images
    Image *imgs=new Image[NUMELMS];
    for(int i=0;i<NUMELMS;i++) {
        *(imgs+i)=newImg(names[i],riddles[i]);
    }
    return imgs;
}

Card newCrd(Image img,int num) {
    Card card;  //Create new card using image and riddle
    card.img=img;
    card.num=num+1;
    return card;
}

Card* newCrds(Image *imgs) {
    //Dynamically allocate and fill an array of 54 cards
    Card *cards=new Card[NUMELMS];
    for(int i=0;i<NUMELMS;i++) {
        *(cards+i)=newCrd(*(imgs+i),i);
    } 
    return cards;
}

void crtDck(Deck &d,Card *cards) {
    d.maxSize=NUMELMS;      //Max size of deck depends on number of elements
    for(int i=0;i<d.maxSize;i++) {
        Card card=*(cards+i);
        d.cards.push_back(card);
    }
}

void shufDck(Deck &d) {
    Deck shufDck;
    int rndIndx;
    int option;
    
    do {
        cout<<"Press 1 to Shuffle The Deck of Cards: ";
        cin>>option;
    } while(option!=1);
    cout<<"------------------------------------------------------------"<<endl;
    
    while(!d.cards.empty()) {
        srand(time(NULL));
        rndIndx=rand()%d.cards.size();  //generate random index
        shufDck.cards.push_back(d.cards[rndIndx]);  //push to card at random index
                                                    //to shuffled deck
        d.cards.erase(d.cards.begin()+rndIndx);     //remove card from original deck
    }
    
    d=shufDck;      //deck is passed by reference
}

vector<int> rndCrds() {
    vector<int> crdNums(NUMELMS);   //vector to hold card numbers

    iota(crdNums.begin(),crdNums.end(),0);  //fill the range with values 0-54
    
    random_device rd;   //uniform random number generator
    mt19937 g(rd());    //needed for the shuffle function
    shuffle(crdNums.begin(),crdNums.end(),g);   //randomly rearrange the elements in the range 
    
    return crdNums;
}

Board* newBrd(Card *cards,int num) {
    int index;
    Board *b=new Board;
    vector<int> v;      //vector of random card numbers
    
    b->brdNum=num;
    v=rndCrds();    //random card numbers to be used to make random board

    index=0;
    for(int r=0;r<ROWS;r++) {
        for(int c=0;c<COLS;c++) {
            //De-reference pointer to pointer to get card to be placed in board
            b->board[r][c]=*(cards+v[index]);
            //Set the found flag of the card on the board to false
            b->board[r][c].found=false;
            index++;   //Index 0-15
        }
    }    
    return b;
}

int winPtrn() {
    int option;
    cout<<"------------------------------------------------------------"<<endl;
    cout<<"SET THE WINNING PATTERN\n";
    cout<<"Options: #1=Full, #2=Row, #3=Column, #4=Diagonals\n\n";
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
    return option;
}

int setTkns(int pattern) {
    int numTkns,
        minTk=2*ROWS,             //Minimum amount of tokens for non-full pattern
        maxTk=2*ROWS*COLS-ROWS,
        minTkFu=ROWS*COLS,
        maxTkFu=2*ROWS*COLS;        //Use only when pattern set to full
    cout<<"------------------------------------------------------------"<<endl;
    cout<<"SET THE NUMBER OF TOKENS\nTokens are Shared Among Players.\n";
    do {
        if(pattern!=1) { //win pattern not set to FULL (min tokens 2*ROWS or 2*COLS
            cout<<"Enter Number of tokens("<<minTk<<" to "<<maxTk<<"): ";
            cin>>numTkns;
        } else {        //win pattern not set to FULL(needs 2*ROWS*COLS tokens)
            cout<<"Enter Number of tokens("<<minTkFu<<" to "<<maxTkFu<<"): ";
            cin>>numTkns;
        }
    }while(((numTkns<minTk||numTkns>maxTk)&&pattern!=1)||((numTkns<minTkFu||numTkns>maxTkFu)&&pattern==1));
    cout<<"------------------------------------------------------------"<<endl;
    return numTkns;
}

void chkBrd(string riddle,Player *p,int &gamTkns) {    
    for(int r=0;r<ROWS;r++) {
        for(int c=0;c<COLS;c++) {
            //Check the riddle has the name from our names array - flag, 
            //Use c-string tokenizer to tokenize the riddle get word
            //If true
                //check board for the word
            //Else if not
                //Check with riddle
            if(p->board->board[r][c].img.riddle==riddle) {
                cout<<p->name<<": match found "<<r+1<<", "<<c+1<<"."<<endl; 
                p->board->board[r][c].found=true;   //set found to true
                p->plyrTkn++;   //Increment number of tokens used by player
                gamTkns--;     //Decrement number of tokens available for game 
            }
        }
    }
    cout<<endl;
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

ofstream plyrFil(Player* p) {
    ofstream file;
    string filName;
    
    filName="data"+p->name+".txt";
    // Open the file in output mode.
    file.open(filName, ios::out);
    file<<"Player Name: "<<p->name<<endl;
    brd2Fil(p->board,file);
    file.close();						
    
    return file;
}

void prntCrd(const Card c) {
    //Print out top border of the card
    for(int i=0;i<14;i++) {
        cout<<"_";
    }
    
    //Print out starting where an image would be (represented by -)
    cout<<endl<<" "<<setw(14);
    cout<<setw(3)<<right<<c.num<<endl;
    for(int i=0;i<5;i++) {
        cout<<setw(4)<<left<<" ";
        cout<<"------"<<endl;
        if(i==5) cout<<endl;
    }
    
    //Print out the name
    for(int i=0;i<c.img.name.length();i++) {
        if(i>=0 && i<=c.img.name.length()) {
            cout<<c.img.name[i];
        }
    }
    cout<<endl;
    
    //Print out bottom border of the card
    for(int i=0;i<14;i++) {
        cout<<"_";
    }
    cout<<endl;
    cout<<endl<<"Riddle: "<<c.img.riddle<<endl<<endl;
}

void prntDck(const Deck& d) {
    cout<<"Printing shuffled deck..."<<endl;
    for(int i=0;i<NUMELMS;i++) {
        prntCrd(d.cards[i]);
    }
    cout<<endl;
    cout<<"Done printing shuffled deck.\n"<<endl;
}

void dispBrd(const Player *p) {
    
    cout<<p->name<<endl;
    cout<<"Board "<<p->plyrTkn<<"/"<<ROWS*COLS<<" Full"<<endl;
    for(int r=0;r<ROWS;r++) {
        for(int c=0;c<COLS;c++) {
            if(p->board->board[r][c].found==true) {
                cout<<"| * |";
            }
            else {
                cout<<"|   |";
            }
        }
        cout<<endl;
    }
    cout<<endl;
}

void prntPlyr(Player *p) {
    cout<<"\nPlayer Name: "<<p->name<<endl;
    cout<<"Number of Tokens to Win: "<<p->plyrTkn<<endl;
    prntBrd(p->board);
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
        for(int n=0;n<4;n++) {
            for(int i=0;i<4;i++) {
                cout<<setw(4)<<left<<" "
                <<setw(6)<<"------"
                <<setw(4)<<left<<" "
                <<"|";
            } cout<<endl;
        }

        //Print out blank row 9
        for(int i=0;i<4;i++) {
            cout<<setw(15)<<right<<"|";
        }
        cout<<endl;        
    }
    //Print out bottom border of board
        for(int i=0;i<brdWdth;i++) cout<<"_";
        cout<<endl;
    //Print the card names and numbers underneath the board
        for(int r=0;r<ROWS;r++) {
            for(int c=0;c<COLS;c++) {
                cout<<b->board[r][c].num<<" ";
                cout<<b->board[r][c].img.name<<endl;
            }
        }
    cout<<endl;
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
        for(int n=0;n<6;n++) {  //5 rows
            for(int i=0;i<4;i++) {
                file<<setw(4)<<left<<" "
                <<setw(6)<<"------"
                <<setw(4)<<left<<" "
                <<"|";
            } file<<endl;         
        }
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
        for(int r=0;r<ROWS;r++) {
            for(int c=0;c<COLS;c++) {
                file<<b->board[r][c].num<<" ";
                file<<b->board[r][c].img.name<<endl;
            }
        }
    file<<endl;
}

void wrt2Bin(Player p,fstream &file) {
	// Open the file for binary output.
	fstream plyrDat("bin"+p.name+".dat",ios::out|ios::binary);

	//Wite contents of structure to binary file
        cout<<"Saving "<<p.name<<" Game Data..."<<endl;
        plyrDat.write(reinterpret_cast<char *>(&p),sizeof(p));
        // Close the file.
	plyrDat.close();   
}

void dispBin(Player p,fstream &file) {
    	// Open the file for binary input.
	fstream plyrDat("bin"+p.name+".dat",ios::in|ios::binary);

	// Now read and display the records.
        cout<<"Displaying "<<p.name<<" Game Data..."<<endl;
	plyrDat.read(reinterpret_cast<char *>(&p),sizeof(p));
	while(!plyrDat.eof()){
		cout<< "Name: ";
		cout<< p.name << endl;
		cout<< "Number of Matches Found This Round: ";
		cout<< p.plyrTkn << endl;
		plyrDat.read(reinterpret_cast<char *>(&p),
		        sizeof(p));
                cout<<endl;
	}

	// Close the file.
	plyrDat.close();
}

//FUNCTIONS NEEDED DURING DEVELOPMENT - NOT USED IN FINAL PROJECT
//void brdCrd(const Card);       //Prints 1 card
//void showContents(fstream &);   //Displays file contents to screen line by line
//void prntAr(const string *);    //Prints contents of an array
//void prntImg(const Image *);    //Prints 1 image
//void prntImgs(const Image **);  //Prints all 54 images
//void prntCrds(Card **);         //Prints all 54 cards
//Board* newBrd(Card **);         //Create 1 new board
//void prntCrd(const Card *);     //Prints 1 card using pointer
//Player* newPlyr(string);        //Creates 1 player

//Player* newPlyr(string name) {
//    Player* player=new Player;
//    player->name=name;
//    player->plyrTkn=0;  //starts at 0 before game
//    return player;
//}

//void prntCrd(const Card *c) { 
//    //Print out top border of the card
//    for(int i=0;i<14;i++) {
//        cout<<"_";
//    }
//    
//    //Print out starting where an image would be (represented by *)
//    cout<<endl<<" "<<setw(14);
//    cout<<setw(3)<<right<<c->num<<endl;
//    
//    //Placeholder for where images would be on the cards
//    for(int i=0;i<6;i++) {
//        cout<<setw(4)<<left<<" ";
//        cout<<"******"<<endl;
//        if(i==5) cout<<endl;
//    }
//    
//    //Print out the name
//    for(int i=0;i<c->img.name.length();i++) {
//        if(i>=0 && i<=c->img.name.length()) {
//            cout<<c->img.name[i];
//        }
//    }
//    cout<<endl;
//    
//    //Print out bottom border of the card
//    for(int i=0;i<14;i++) {
//        cout<<"_";
//    }
//    cout<<endl;
//    cout<<endl<<"Riddle: "<<c->img.riddle<<endl<<endl;
//}

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

//void prntImg(const Image img) {
//    cout<<"Name: "<<img.name<<endl;
//    cout<<"Riddle: "<<img.riddle<<endl;
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