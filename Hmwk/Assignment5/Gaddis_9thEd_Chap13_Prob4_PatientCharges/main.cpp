/* 
 * File:   main.cpp
 * Author: Andrew Guzman
 * Created: November 28, 2022 @ 9:52 PM
 * Purpose: Patient Class
 */

//System Libraries
#include <iostream>  //Input/output Library
using namespace std;

//User Libraries
#include "Patient.h"
#include "Procedure.h"

//Global Constants
//Physics/Chemistry/Math/Conversion Higher Dimension Only

//Structure Definitions

//Function Prototypes

//Program Execution Begins Here!!!

int main(int argc, char** argv) {
    //Initialize the Random Number Seed

    //Declare Variables
    int i=0;            //counter for number of procedures
    Patient patient("Joaquin","Saul","Huerta","1600","3rd Street","Riverside",
                    92507,"458-895-6548","Rosalia Villa","489-458-7895");
    Procedure procd1("Physical Exam","Today's Date","Dr.Irvine",250.00);
    Procedure procd2("FFS","Today's Date","Dr.Quintanilla",500.00);
    Procedure procd3("Blood Test","Today's date","Dr.Coogler",200.00);
    
    //Initial Variables

    //Map the Inputs to the Outputs

    //Display the Inputs and Outputs
    cout<<"PATIENT SUMMARY\n";
    patient.prntInf();
    cout<<"\nTotal Number of Procedures: "<<procd1.getCnt()<<endl<<endl;
    cout<<"Procedure #"<<++i<<endl;
    procd1.prntSum();
    cout<<"Procedure #"<<++i<<endl;
    procd2.prntSum();
    cout<<"Procedure #"<<++i<<endl;
    procd3.prntSum();


    //Clean up the dynamic stuff

    //Exit the code
    return 0;
}

