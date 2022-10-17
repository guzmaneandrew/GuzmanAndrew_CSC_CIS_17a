/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: October 14, 2022 @ 10:00 PM
 * Purpose: Uses a structure to store data on a company division and write to a file.
 */

//System Libraries
#include <iostream>  //Input/output Library
#include <iomanip>
#include <fstream>  //File stream Library
using namespace std;

//User Libraries

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only
const int NAME_SIZE=8;

//Structure Definitions
struct Division {
    char name[NAME_SIZE];
    float q1Sales;
    float q2Sales;
    float q3Sales;
    float q4Sales;
    float totalSls;   //Total annual sales
    float avgSls;     //Avg quarter sales  
};

//Function Prototypes
void getData(Division *);
void calcTot(Division *); //Calculate total annual sales
void calcAvg(Division *); //Calculate avg quarter sales
void print(Division);
long byteNum(int);

//Program Execution Begins Here!!!
int main(int argc, char** argv) {
    //Initialize the Random Number Seed

    //Declare Variables
    Division north,south,east,west;
    
    //Open file for binary output
    fstream sales("sales.dat",ios::out|ios::binary);
    
    if(!sales) {
        cout<<"Error opening file. Program aborting."<<endl;
        return 0;
    }

    //Initial Variables
    //Set name for struct
    cout<<"Enter division (North, West, East, South) : ";
    cin.getline(north.name, NAME_SIZE);
    //Get sales data for division
    getData(&north);
    //Calculate the total annual sales
    calcTot(&north);
    //Calculate avg total sales
    calcAvg(&north);
    //Write contents of the division structure to the file
    sales.write(reinterpret_cast<char *>(&north),sizeof(north));
    //Print info of division from the file
    sales.seekg(byteNum(0),ios::beg);
    sales.read(reinterpret_cast<char *>(&north),sizeof(north));
    print(north);
    cout<<endl;
    
    //Set name for struct
    cout<<"Enter division (North, West, East, South) : ";
    cin.ignore();
    cin.getline(west.name, NAME_SIZE);
    //Get sales data for division
    getData(&west);
    //Calculate the total annual sales
    calcTot(&west);
    //Calculate avg total sales
    calcAvg(&west);
    //Write contents of the division structure to the file
    sales.write(reinterpret_cast<char *>(&west),sizeof(west));
    //Print total annual sales and avg quarterly sales
    sales.seekg(byteNum(1),ios::beg);
    sales.read(reinterpret_cast<char *>(&west),sizeof(west));
    print(west);
    cout<<endl;

    //Set name for struct
    cout<<"Enter division (North, West, East, South) : ";
    cin.ignore();
    cin.getline(east.name, NAME_SIZE);
    //Get sales data for division
    getData(&east);
    //Calculate the total annual sales
    calcTot(&east);
    //Calculate avg total sales
    calcAvg(&east);
    //Write contents of the division structure to the file
    sales.write(reinterpret_cast<char *>(&east),sizeof(east));
    //Print total annual sales and avg quarterly sales
    sales.seekg(byteNum(2),ios::beg);
    sales.read(reinterpret_cast<char *>(&north),sizeof(north));
    print(east);
    cout<<endl;
    
    //Set name for struct
    cout<<"Enter division (North, West, East, South) : ";
    cin.ignore();
    cin.getline(south.name, NAME_SIZE);
    //Get sales data for division
    getData(&south);
    //Calculate the total annual sales
    calcTot(&south);
    //Calculate avg total sales
    calcAvg(&south);
    //Write contents of the division structure to the file
    sales.write(reinterpret_cast<char *>(&south),sizeof(south));
    //Print total annual sales and avg quarterly sales
    sales.seekg(byteNum(3),ios::beg);
    sales.read(reinterpret_cast<char *>(&south),sizeof(south));
    print(south);
    
    //Clean up the dynamic stuff

    //Close files
    sales.close();
    
    //Exit the code
    return 0;
}

void getData(Division *d) {
    //Get q1 sales
    do{
    cout<<"Enter first-quarter sales:"<<endl;
    cin>>d->q1Sales;
    }while(d->q1Sales<0);
    
    //Get q2 sales
    do{
    cout<<"Enter second-quarter sales:"<<endl;
    cin>>d->q2Sales;
    }while(d->q2Sales<0);
    
    //Get q3 sales
    do{
    cout<<"Enter third-quarter sales:"<<endl;
    cin>>d->q3Sales;
    }while(d->q3Sales<0);
    
    //Get q4 sales
    do{
    cout<<"Enter fourth-quarter sales:"<<endl;
    cin>>d->q4Sales;
    }while(d->q4Sales<0);
}

void calcTot(Division *d) {
    float total;
    
    total=(d->q1Sales)+(d->q2Sales)+(d->q3Sales)+(d->q4Sales);
    d->totalSls=total;
}

void calcAvg(Division *d) {
    float avg;
    
    avg=(d->q1Sales+d->q2Sales+d->q3Sales+d->q4Sales)/4;
    d->avgSls=avg;
}

void print(Division d) {
    cout<<d.name<<endl;
    cout<<fixed<<showpoint<<setprecision(2);
    cout<<"Total Q1 sales:$"<<d.q1Sales<<endl;
    cout<<"Total Q2 sales:$"<<d.q2Sales<<endl;
    cout<<"Total Q3 sales:$"<<d.q3Sales<<endl;
    cout<<"Total Q4 sales:$"<<d.q4Sales<<endl;
    cout<<"Total Annual sales:$"<<d.totalSls<<endl;
    cout<<"Average Quarterly Sales:$"<<d.avgSls;
}

long byteNum(int recNum) {
    return sizeof(Division) * recNum;
}
