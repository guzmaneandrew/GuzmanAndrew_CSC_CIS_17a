/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: September 30, 2022 @ 11:17 PM
 * Purpose: Reads contents for first file, changes all letters to lowercase
 *          and stores updated contents in a second file
 */

//System Libraries
#include <iostream>  //Input/output library
#include <string>
#include <fstream>  //File stream library
using namespace std;

//User Libraries

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only

//Structure Definitions

//Function Prototypes
bool opnFile(fstream &,string);
void filter(fstream &,string,fstream &);

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Declare Variables
    fstream file1,file2;
    string f1name,f2name,ext=".txt";    //file names,extension
    //Initial Variables
    //Ask user for two file names
    cout<<"Enter a name for the first file: ";
    cin>>f1name;
    f1name.append(ext);
    
    cout<<"Enter a name for the second file: ";
    cin>>f2name;
    f2name.append(ext);
    
    //Open the text files
    file1.open(f1name,ios::in);
    file2.open(f2name,ios::out);
    
    //Map the Inputs to the Outputs
    //Read contents of first file
    if(opnFile(file1,f1name)&&opnFile(file2,f2name)) {
        cout<<"Files opened successfully.\n"<<endl;
        cout<<"Now filtering sentences from the first file.\n"<<endl;
        filter(file1,f1name,file2);
        cout<<"Closing files.\n"<<endl;
        //Close the files
        file1.close();
        file2.close();
        cout<<"Done."<<endl;
    } else {
        cout<<"ERROR Unable to open the file: "<<f1name<<endl;
    }
    
    //Exit the code
    return 0;
}

bool opnFile(fstream &file,string filName) {
    if(file) return true;
    else return false;
}

void filter(fstream &inFile,string inName,fstream &outFile) {
        string sntence;
        bool frstLtr=true;  //Flag to determine if searching for first letter
        int indx; //Index of first letter in the sentence(possible multiple spaces)
        
        cout<<"Outputting filtered sentences to the second file.\n"<<endl;
        
        //Read in a sentence from the input file
        getline(inFile,sntence,'.');
        
        //While the last read operation was successful, continue
        while(inFile) {
            //Update contents of first file and output to second file
            for(int i=0;i<sntence.length();i++) {
                //Uppercase first letter, skip over white spaces
                while(sntence[i]!=' '&&frstLtr) {   
                    outFile<<char(toupper(sntence[i]));
                    frstLtr=false;      //Update flag now that first letter found
                    indx=i;
                }
                //Lowercase remaining letters
                if(frstLtr==false&&indx!=i) outFile<<char(tolower(sntence[i]));
                
                //Append period at the end of the sentences
                if(i==sntence.length()-1) outFile<<". ";
            }
            frstLtr=true;   //Reset flag for next sentence
            //Read the next sentence
            getline(inFile,sntence,'.');
        }
}
