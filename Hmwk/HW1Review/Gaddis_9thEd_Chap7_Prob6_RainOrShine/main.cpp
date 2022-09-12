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
const int NUM_MONTHS = 3;   //3-month summer
const int NUM_DAYS = 30;    //no data for 31st day of month

//Function Prototypes
int summTot(int, int, int);  //Calculate # rainy, sunny, cloudy days for summer
int most(int []);  //Determine which month has highest number of weather type

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Set the Random Number Seed

    //Declare Variables
    char weather[NUM_MONTHS][NUM_DAYS]; //Array with 3 rows and 30 columns
    int     junRain , junSun, junCldy, //# of rainy, sunny, cloudy days in June
            julRain, julSun, julCldy, //# of rainy, sunny, cloudy days in July
            augRain, augSun, augCldy, //# of rainy, sunny, cloudy days in August
            totRain, totSun, totCldy; //total # rainy, sunny, cloudy days 3 months
    int mnthRain[NUM_MONTHS]; //array to hold number of rainy days per month
    int mstRain;    //month with most rain
    ifstream inputFile; //Input file stream object
    int month, day; //loop counters
    char c; //character for weather on a given day
    string months[NUM_MONTHS];  // string for month name
    
    //Open the file
    inputFile.open("RainOrShine.txt");
    //Test with different files
    //inputFile.open("RainOrShine2.txt");
    //inputFile.open("RainOrShine3.txt");

    //Initial Variables
    const int jun = 0, jul = 1, aug = 2;  //subscr for month column in 2d arr
    months[jun] = "June";
    months[jul] = "July";
    months[aug] = "August";
    junRain = 0, junSun = 0, junCldy = 0,
    julRain = 0, julSun = 0, julCldy = 0,
    augRain = 0, augSun = 0, augCldy = 0,
    totRain = 0, totSun = 0, totCldy = 0; 

    //Map the Inputs to the Outputs
    //Read data from file, add char c from file to 2d array one by one
    for(month = 0; month <= NUM_MONTHS; month++) {
        for(day = 0; day <= NUM_DAYS; day++) {
            inputFile.get(c);   //save char from file to c variable
            weather[month][day] = c;    //set element at [month][day] to char c
        }
    }

    //Determine num of rainy, cloudy, and sunny days for each month
    //Loop through array to determine num days rainy, sunny, cloudy
    for(month = 0; month < NUM_MONTHS; month++) {
        for(day = 0; day < NUM_DAYS; day++) {
            c = weather[month][day];    
            
            switch(month) {
                case jun:
                    if     (c == 'R')   ++junRain;
                    else if(c == 'S')   ++junSun;
                    else if(c == 'C')   ++junCldy;
                    break;
                case jul:
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
    }
    
    //Calculate total number of days of rain, sunny, cloudy for 3 month period
    totRain = summTot(junRain, julRain, augRain);
    totSun = summTot(junSun, julSun, augSun);
    totCldy = summTot(junCldy, julCldy, augCldy);
    
    //Determine month with greatest number of rainy days
    //Add number of rainy days to an array
    mnthRain[jun] = junRain;
    mnthRain[jul] = julRain;
    mnthRain[aug] = augRain;
    mstRain = most(mnthRain);
    
    //Display the Inputs and Outputs
    cout << "Weather Conditions for Last Summer Season" << endl << endl;
    cout << "Time Period" << setw(8) << "Rainy" << setw(8) << "Sunny" << setw(8) << "Cloudy" << endl;
    cout << left << setw(10) << "June" << right << setw(7) << junRain << setw(8) << junSun << setw(8) << junCldy << endl;
    cout << left << setw(10) << "July" << right << setw(7) << julRain << setw(8) << julSun << setw(8) << julCldy << endl;
    cout << left << setw(10) << "August" << right << setw(7) << augRain << setw(8) << augSun << setw(8) << augCldy << endl;
    cout << left << setw(10) << "Summer" << right << setw(7) << totRain << setw(8) << totSun << setw(8) << totCldy << endl;
    cout << endl;
    cout << "The month with the largest number of rainy days is " << months[mstRain] << "." << endl;
    
    //Close the file
    inputFile.close();

    //Exit the code
    return 0;
}

int summTot(int jun, int jul, int aug) {
    //Declare Variables
    int total;  //total for 3 months of given weather type
    
    //Initial variables
    total = jun + jul + aug;
    
    //Exit the code
    return total;
}

int most(int summer[]) {
    //Declare Variables
    int month, highest;
    
    //Initial variables
    highest = 0;    //set first subscr to highest
    
    //Map inputs to outputs
    for(month = 0; month < NUM_MONTHS; month++) {
        if(summer[month] > summer[highest]) highest = month;
    }

    //Exit the code
    return highest;
}

