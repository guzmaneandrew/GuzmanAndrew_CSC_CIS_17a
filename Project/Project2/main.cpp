/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: November 22, 2022 @ 8:12 PM
 * Purpose: v1: Create 1-2 Image and Card objects
 */

//System Libraries
#include <iostream>  //Input/output Library
using namespace std;

//User Libraries
#include "Image.h"
#include "Card.h"

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only

//Structure Definitions

//Function Prototypes

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    string *riddles=nullptr,            //Array of riddle strings for images
           *names=nullptr;              //Array of names for images
    Image img1,img2;
    Card card1,card2;
    
    //Initial Variables
    
    //Create Image objects
    img1.create("He who string with the tail.","Scorpion");
    img2.create("For the sun and the water.","Umbrella");
    
    //Create Card objects
    card1.create(15,&img1);
    card2.create(33,&img2);

    //Map the Inputs to the Outputs

    //Display the Inputs and Outputs
    card1.display();
    card2.display();

    //Clean up the dynamic stuff

    //Exit the code
    return 0;
}

