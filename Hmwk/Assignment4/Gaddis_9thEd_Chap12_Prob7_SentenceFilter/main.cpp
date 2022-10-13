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

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Initialize the Random Number Seed

    //Declare Variables
    fstream file1,file2;
    string f1name,f2name,ext=".txt",sntence;    //file names,extension,sentence
    bool frstLtr=true;  //Flag to track first letter in sentence
    int indx; //Index of first letter in the sentence(possible multiple spaces)

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
    if(file1) {
        //Read in a sentence from the file
        getline(file1,sntence,'.');
        
        //While the last read operation was successful, continue
        while(file1) {
            //Update contents of first file and output to second file
            for(int i=0;i<sntence.length();i++) {
                //Uppercase first letter
                while(sntence[i]!=' '&&frstLtr) {   
                    file2<<char(toupper(sntence[i]));
                    frstLtr=false;
                    indx=i;
                }
                //Lowercase remaining letters
                if(frstLtr==false&&indx!=i) file2<<char(tolower(sntence[i]));
                
                //Append period at the end of the sentences
                if(i==sntence.length()-1) file2<<". ";
            }
            frstLtr=true;   //Reset flag for next sentence
            //Read the next sentence
            getline(file1,sntence,'.');
        }
        
        //Close the file
        file1.close();
        
    } else {
        cout<<"ERROR Unable to open the file: "<<f1name<<endl;
    }
    
    //

    //Display the Inputs and Outputs

    //Clean up the dynamic stuff

    //Close the files
    file1.close();
    file2.close();
    
    //Exit the code
    return 0;
}

