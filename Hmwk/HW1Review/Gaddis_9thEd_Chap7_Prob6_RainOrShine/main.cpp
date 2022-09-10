/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created on September 7, 2022, 11:51 PM
 * Purpose: Keeps track of weather conditions during the past year's three-month
 * summer season.
 */

//System Libraries
#include <iostream>  //Input/output Library
#include <fstream>  //File stream
using namespace std;

//User Libraries

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only

//Function Prototypes

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Set the Random Number Seed

    //Declare Variables
    const int NUM_MONTHS = 3;   //3-month summer
    const int NUM_DAYS = 30;    //no data for 31st day of month
    const int june = 0, july = 1, aug = 2;  //subscr for month column in 2d arr
    char weather[NUM_MONTHS][NUM_DAYS]; //Array with 3 rows and 30 columns
    int     junRain , junSun, junCldy, //# of rainy, sunny, cloudy days in June
            julRain, julSun, julCldy, //# of rainy, sunny, cloudy days in July
            augRain, augSun, augCldy, //# of rainy, sunny, cloudy days in August
            totRain, totSun, totCldy; //total # rainy, sunny, cloudy days 3 months
    ifstream inputFile; //Input file stream object
    int month, day; //loop counters
    char c; //character for weather on a given day
    
    //Open the file
    inputFile.open("RainOrShine.txt");

    //Initial Variables
    junRain = 0, junSun = 0, junCldy = 0,
    julRain = 0, julSun = 0, julCldy = 0,
    augRain = 0, augSun = 0, augCldy = 0,
    totRain = 0, totSun = 0, totCldy = 0; 

    //Map the Inputs to the Outputs
    //Nested loops to add char c from file to 2d array one by one
    for(month = 0; month <= NUM_MONTHS; month++) {
        for(day = 0; day <= NUM_DAYS; day++) {
            inputFile.get(c);
            weather[month][day] = c;
        }
    }

    //Display the Inputs and Outputs
    //Loop through array to determine num days rainy, sunny, cloudy
    for(month = 0; month < NUM_MONTHS; month++) {
        for(day = 0; day < NUM_DAYS; day++) {
            c = weather[month][day];
            
            switch(month) {
                case june:
                    if     (c == 'R')   ++junRain;
                    else if(c == 'S')   ++junSun;
                    else if(c == 'C')   ++junCldy;
                    break;
                case july:
                    if     (c == 'R')   ++julRain;
                    else if(c == 'S')   ++julSun;
                    else if(c == 'C')   ++julCldy;
                    break;
                case aug:
                    if     (c == 'R')   ++augRain;
                    else if(c == 'S')   ++augSun;
                    else if(c == 'C')   ++augCldy;
                    break;
            }
        }
        cout << endl;
    }
    
    cout << "June: " << junRain << " " << junSun << " " << junCldy << endl;
    cout << "July: " << julRain << " " << julSun << " " << julCldy << endl;
    cout << "Aug: " << augRain << " " << augSun << " " << augCldy << endl;
    
    //Close the file
    inputFile.close();

    //Exit the code
    return 0;
}

