/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: November 5, 2022 @ 9:20 PM
 * Purpose: v10: Memory de-allocation & code clean up - no major changes. Final version.
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
enum BrdWin {NONE=0,FULL=1,ROW=2,COL=3,DIAGS=4};   //Winning board patterns

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
    bool win;       //Flag to set to true if player wins
    int plyrTkn;    //Number of tokens used during game
    Board* board;   //Pointer to a board in player structure
};

struct Game {
    int tkns;       //Number of tokens available for game
    int pattern;    //Winning pattern set for game
    int numWins;    //Number of winners for given game
    int numRnds;    //Number of rounds in game
};

//Function Prototypes
Image crtImg(string,string);   //Creates 1 image structure
Image* crtImgs(string *,string *); //Returns array of image structures
Card crtCrd(Image,int);         //Creates 1 card structure
Card* crtCrds(Image *);         //Returns array of card structures
void crtDck(Deck &,Card *);    //Creates a deck of cards using array of cards
void shufDck(Deck &);           //Shuffles deck of cards
vector<int> rndCrds();          //Generates 16 random card numbers for board
Board* newBrd(Card *,int);     //Returns pointer to a random board
void setPtrn(Game &);           //Sets winning pattern for the game
void setTkns(Game &);           //Sets the number of tokens for players to share
void chkBrd(Card,string *,Player *,Game &); //Checks board and updates player and game data
bool ezRddle(string,const string *); //Checks if a riddle is "easy"
char* strToC(const string);     //Returns pointer to char array
bool match(string,string);      //Searches for string in another string
bool openFil(fstream &,string); //Opens a file for input
string* filToAr(fstream &);     //Saves file contents to memory
ofstream plyrFil(Player *);      //Create text file to save player game data to
string word(int);               //Returns word for winning pattern set
void prntCrd(const Card);       //Prints 1 card structure
void prntDck(const Deck &);     //Print deck of cards
void miniBrd(const Player *);    //Prints player's mini boards on screen
void prntPlyr(Player *);        //Prints player game data to the screen
void prntBrd(const Board *);    //Prints 1 board to the screen
void brd2Fil(const Board *,ofstream &); //Prints a board to a file
void wrt2Bin(Player,fstream &);      //Outputs contents of player to binary files
void dispBin(Player,fstream &);     //Prints contents of binary file
void dispDat(Game);                 //Prints game data

//Program Execution Begins Here!!!
int main(int argc, char** argv) {
    //Random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    fstream dataFile;       //Input files
    ofstream p1File,p2File; //Player files to output to
    string p1Name,p2Name;   //Name of players
    Card topCrd;             //Card pulled from top of the deck
    Deck deck;              //Deck of cards
    int input;            //Input for user
    
    //Initial Variables
    input=0;
    string *riddles=nullptr,    ////String array of riddles used create images
           *names=nullptr;      //String array of names used create images and cards
    Image *images=nullptr;  //Array of images
    Card *cards=nullptr;    //Array of cards
    Board *board1=nullptr,*board2=nullptr;      //Pointers to boards
    p1Name="player1",p2Name="player2";
    Player plyr1={p1Name,false},plyr2={p2Name,false};       //Initialize player structures
    Player *plyr1Ptr=&plyr1,*plyr2Ptr=&plyr2;   //Pointers to player structures
    Game gameDat={NONE,0,0,0};
    
    //Get card names from cardNames.txt file and save to names array   
    if(openFil(dataFile,"cardNames.txt")) {
        names=filToAr(dataFile);    
        dataFile.close();
    } else {
        cout<<"File open error!"<<endl;
    }
   
    //Get card riddles from cardRiddles.txt file and save to riddles array
    if(openFil(dataFile,"cardRiddles.txt")) {
        riddles=filToAr(dataFile);  
        dataFile.close();
    } else {
        cout<<"File open error!"<<endl;
    }

    //Create all images
    images=crtImgs(names,riddles);

    //Create all cards using the images
    cards=crtCrds(images);
    
    //Create deck of cards
    crtDck(deck,cards);
    
     //Display game title
    cout<<"LOTERÍA\n"<<endl;
        
    //Display game prompt
    cout<<"This is a game of Lotería with 2 computer players and 1 caller.\n"
          "You are the caller of this game."<<endl;
             
//Game Begins
    //User sets the winning pattern for this 
    setPtrn(gameDat);
    
    //User sets the number of tokens for player to use during game
    setTkns(gameDat);
    
    //User shuffles the deck of cards
    shufDck(deck);
    
    //Create and display player 1 board
    do {                  
        cout<<"Press 1 to View Player 1's Board: ";
        cin>>input;
    } while(input!=1);
    board1=newBrd(cards,1);         //Create a random board for player1
    plyr1Ptr->board=board1;         //Assign board to player1
    p1File=plyrFil(plyr1Ptr);       //Create new file to save player1 data to
    prntPlyr(plyr1Ptr);
    cout<<"------------------------------------------------------------"<<endl;
    
    //Create and display player 2 board
    do {                        
        cout<<"Press 2 to View Player 2's Board: ";
        cin>>input;
    } while(input!=2);
    board2=newBrd(cards,2);     //Create a random board for player2   
    plyr2Ptr->board=board2;        //Assign board to player2
    plyrFil(plyr2Ptr);             //Create file to save player2 data to 
    prntPlyr(plyr2Ptr);
      
    //Play game while deck is not empty, tokens still available,and no win
    while(!deck.cards.empty()&&gameDat.tkns>0&&plyr1Ptr->win==false&&plyr2Ptr->win==false) {
        gameDat.numRnds++;
        cout<<"------------------------------------------------------------"<<endl;
        cout<<"ROUND "<<gameDat.numRnds<<": "<<endl;
        cout<<"Number of Tokens Remaining: "<<gameDat.tkns<<endl<<endl;
        do {
            cout<<"Press 9 to Pull a Card From the Deck: ";
            cin>>input;
        }while(input!=9);
        
        if(input==9) {
            //Caller pulls a card from the deck     
            topCrd=deck.cards.front();
            //Display pulled card and corresponding riddle on the screen
            prntCrd(topCrd);
            //Send the card info to the computer players to check their boards
            chkBrd(topCrd,names,plyr1Ptr,gameDat);
            chkBrd(topCrd,names,plyr2Ptr,gameDat);
            //Display mini board pattern on screen
            miniBrd(plyr1Ptr);
            miniBrd(plyr2Ptr);
            //Remove called card from deck
            deck.cards.erase(deck.cards.begin(),deck.cards.begin()+1); 
            //Check if players have a full board
            if(plyr1Ptr->plyrTkn==16) {
                plyr1Ptr->win=true;
                gameDat.numWins++;
                cout<<plyr1Ptr->name<<": LOTERÍA!\n\n";
            }
            if(plyr2Ptr->plyrTkn==16) {
                plyr2Ptr->win=true;
                gameDat.numWins++;
                cout<<plyr2Ptr->name<<": LOTERÍA!\n\n";
            }
        }
    }
    
    cout<<"-----------------------GAME OVER----------------------------"<<endl;
    //Write to binary files and display contents from binary files
    wrt2Bin(plyr1,dataFile);
    wrt2Bin(plyr2,dataFile);
    dispBin(plyr1,dataFile);
    dispBin(plyr2,dataFile);
    dispDat(gameDat);
    
    //Clean up the dynamic stuff
    delete []riddles;
    riddles=nullptr;
    delete []names;
    names=nullptr;
    delete []images;
    images=nullptr;
    delete []cards;
    cards=nullptr;
    delete board1;
    board1=nullptr;
    delete board2;
    board1=nullptr;
    
    //Exit the code
    return 0;
}

Image crtImg(string name,string riddle) {
    Image img;  //Create image using name and riddle
    img.name=name;
    img.riddle=riddle;
    return img;
}

Image* crtImgs(string* names,string* riddles) {
    Image *imgs=new Image[NUMELMS]; //Dynamically allocate & fill array of images
    for(int i=0;i<NUMELMS;i++) {
        *(imgs+i)=crtImg(names[i],riddles[i]);
    }
    return imgs;
}

Card crtCrd(Image img,int num) {
    Card card;  //Create card using image and riddle
    card.img=img;
    card.num=num+1;
    return card;
}

Card* crtCrds(Image *imgs) {
    Card *cards=new Card[NUMELMS]; //Dynamically allocate & fill an array of cards
    for(int i=0;i<NUMELMS;i++) {
        *(cards+i)=crtCrd(*(imgs+i),i);
    } 
    return cards;
}

void crtDck(Deck &d,Card *cards) {
    d.maxSize=NUMELMS;      //Max size of deck depends on number of elements
    for(int i=0;i<d.maxSize;i++) {
        Card card=*(cards+i);
        d.cards.push_back(card);    //Add card to vector
    }
}

void shufDck(Deck &d) {
    Deck shufDck;
    int rndIndx;
    int option;
    
    do {
        cout<<"Press 0 to Shuffle The Deck of Cards: ";
        cin>>option;
    } while(option!=0);
    cout<<"Deck Shuffled!"<<endl;
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
    
    index=0;
    b->brdNum=num;
    v=rndCrds();    //random card numbers to be used to make a random board
    for(int r=0;r<ROWS;r++) {
        for(int c=0;c<COLS;c++) {
            //De-reference pointer to get card to be placed in board
            b->board[r][c]=*(cards+v[index]);
            //Set the found flag of the card on the board to false
            b->board[r][c].found=false;
            index++;   //Index 0-15
        }
    }    
    return b;
}

void setPtrn(Game &gameDat) {
    int option;
    cout<<"------------------------------------------------------------"<<endl;
    cout<<"SET THE WINNING PATTERN\n";
    cout<<"Options: #1=Full, #2=Row, #3=Column, #4=Diagonals\n\n";
    do{
        cout<<"Enter Pattern #: ";
        cin>>option;
    } while(option!=1&&option!=2&&option!=3&&option!=4);
    gameDat.pattern=option;
    cout<<"Players Must Match One of The Following Patterns to Win:\n";
    switch(option) {
        case FULL:
          cout<<word(FULL)<<endl;
          for(int r=0;r<ROWS;r++) {
              for(int c=0;c<COLS;c++) {
                  cout<<"| * |";
              }
              cout<<endl;
          }
          break;
        case ROW:
          for(int i=0;i<4;i++) {
              cout<<word(ROW)<<i+1<<endl;
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
              cout<<word(COL)<<i+1<<endl;
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
          cout<<word(DIAGS)<<"1"<<endl;
          for(int i=0;i<4;i++) {
              for(int j=0;j<4;j++) {
                  if(i==j) cout<<"| * |";
                  else     cout<<"|   |";
              }
              cout<<endl;
          }
          cout<<endl;

          cout<<word(DIAGS)<<"2"<<endl;
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

void setTkns(Game &gameDat) {
    int pattern=gameDat.pattern;
    int numTkns,
        minTk=2*ROWS,               //Amount tokens for non-full pattern
        maxTk=2*ROWS*COLS-ROWS,     
        minTkFu=ROWS*COLS,          //Amount tokens for full pattern
        maxTkFu=2*ROWS*COLS;       
    cout<<"------------------------------------------------------------"<<endl;
    cout<<"SET THE NUMBER OF TOKENS\nTokens are Shared Among Players.\n";
    do {
        if(pattern!=1) { 
            cout<<"Enter Number of Tokens("<<minTk<<" to "<<maxTk<<"): ";
            cin>>numTkns;
        } else {        
            cout<<"Enter Number of Tokens("<<minTkFu<<" to "<<maxTkFu<<"): ";
            cin>>numTkns;
        }
    }while(((numTkns<minTk||numTkns>maxTk)&&pattern!=1)||((numTkns<minTkFu||numTkns>maxTkFu)&&pattern==1));
    gameDat.tkns=numTkns;       //Set number of tokens for game data
    cout<<"------------------------------------------------------------"<<endl;
}

void chkBrd(Card card,string *names,Player *p,Game &gameDat) {   
    bool ez=ezRddle(card.img.riddle,names);
    
    //If riddle is easy, use card name to search board
    if(ez) {
        for(int r=0;r<ROWS;r++) {
            for(int c=0;c<COLS;c++) {
                if(p->board->board[r][c].img.name==card.img.name) {
                    cout<<p->name<<" Found a Match At "<<r+1<<", "<<c+1<<"."<<endl; 
                    p->board->board[r][c].found=true;   //set found to true
                    p->plyrTkn++;   //Increment number of tokens used by player
                    gameDat.tkns--;     //Decrement number of tokens available for game 
                }
            }
        }
    //If riddle not easy, use riddle to search the board
    } else {
        for(int r=0;r<ROWS;r++) {
            for(int c=0;c<COLS;c++) {
                if(p->board->board[r][c].img.riddle==card.img.riddle) {
                    cout<<p->name<<" Found a Match At "<<r+1<<", "<<c+1<<"."<<endl; 
                    p->board->board[r][c].found=true;   //set found to true
                    p->plyrTkn++;   //Increment number of tokens used by player
                    gameDat.tkns--;     //Decrement number of tokens available for game 
                }
            }
        }
    }
    cout<<endl;
}

bool ezRddle(string riddle,const string *names) { 
    string currStr;
    for(int i=0;i<NUMELMS;i++) {        //Go through names array 
        currStr=(*(names+i)).substr(0,(*(names+i)).length()); //bug
        if(match(riddle,currStr)) { // Search the riddle for match of name
            return true;
        }
    }
    return false;       //If not match found, return true
}

bool match(string riddle,string name) {
    char *ridStr=strToC(riddle);        //return char * to cstr copy of riddle
    const char *nameStr=name.c_str();
    char *strPtr=nullptr; // To point to the found word in riddle
    
    strPtr=strstr(ridStr,nameStr); // Search the array for a matching substring
    if (strPtr!=nullptr) {  //Return true if name found in riddle
        return true;
    } else {
        return false;
    }
    //De-allocate memory
    delete []ridStr;    
    ridStr=nullptr;
    delete []nameStr;    
    ridStr=nullptr;
    delete []strPtr;    
    ridStr=nullptr;
}

char* strToC(const string str) {    //c_str() returns const char *, needed char *
    char *cStr=new char[str.length()+1];

    for(int index=0;index<str.length();index++){
      cStr[index]=str[index];              //Copy string to cstring
    }
    cStr[str.length()]='\0';              //Append null character to cstring

    return cStr;
}

bool openFil(fstream &file,string name) {
    file.open(name,ios::in);    //Open file for input
    
    if(file.fail()) {
        return false;
    } else
        return true;
}

string* filToAr(fstream &file) {
    string *items=new string[NUMELMS];
    string line;
    for(int i=0;i<NUMELMS;i++) {
        getline(file,line,'\n');    //Get a line from text file
        *(items+i)=line;            //Add line to array of strings
    }
    return items;
}

ofstream plyrFil(Player* p) {
    ofstream file;
    string filName;
    
    filName=p->name+"Board.txt";
    // Open the file in output mode.
    file.open(filName,ios::out);
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
    }cout<<endl;
    //Print out bottom border of the card
    for(int i=0;i<14;i++) {
        cout<<"_";
    }cout<<endl;
    cout<<endl<<"Riddle: "<<c.img.riddle<<endl<<endl;
}

void prntDck(const Deck& d) {
    cout<<"Printing shuffled deck..."<<endl;
    for(int i=0;i<NUMELMS;i++) {
        prntCrd(d.cards[i]);
    }cout<<endl;
    cout<<"Done printing shuffled deck.\n"<<endl;
}

void miniBrd(const Player *p) {
    cout<<setw(10)<<left;
    cout<<p->name<<" ";
    cout<<setw(5)<<right<<p->plyrTkn<<"/"<<ROWS*COLS<<endl;
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
    prntBrd(p->board);
}

void prntBrd(const Board *b) {
    int brdWdth=60;     //Set width to 60 variable for width
    
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
    int brdWdth=60;         //Set width to 60 variable for width
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
    fstream plyrDat(p.name+".dat",ios::out|ios::binary);
    //Wite contents of structure to binary file
    cout<<"Saving "<<p.name<<" Game Data..."<<endl;
    plyrDat.write(reinterpret_cast<char *>(&p),sizeof(p));
    plyrDat.close();   // Close the file.
}

void dispBin(Player p,fstream &file) {
    // Open the file for binary input.
    fstream plyrDat(p.name+".dat",ios::in|ios::binary);
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
    plyrDat.close();    // Close the file.
}

void dispDat(Game game) {
    cout<<"Displaying Game Data..."<<endl;
    cout<<"Pattern: "<<word(game.pattern)<<endl;
    cout<<"Number of Rounds: "<<game.numRnds<<endl;
    cout<<"Number of Tokens Remaining: "<<game.tkns<<endl;
    cout<<"Number of Winners: "<<game.numWins<<endl;
    cout<<endl;
}

string word(int num) {
    string word;
    if(num==1)      word="Full ";
    else if(num==2) word="Row ";
    else if(num==3) word="Column ";
    else if(num==4) word="Diagonal ";
    return word;
}