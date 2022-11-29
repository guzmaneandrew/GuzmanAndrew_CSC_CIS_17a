/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "Numbers.h"
#include <iostream>
#include <string>
using namespace std;

Numbers::Numbers(int number) {
    if(number>=0) this->number=number;
    else {
        cout<<"ERROR: Invalid number.\n";
        exit(0);
    }
}

void Numbers::print() {
    unsigned short n2Cnvrt;
    string num="";

    //Initialize Variables
    n2Cnvrt=static_cast<short>(number);

    //Check for a valid input
    if(n2Cnvrt>=1 && n2Cnvrt<=9999){
    //Process or map Inputs to Outputs
    //Determine digits for 1000's, 100's, 10's, 1's
    unsigned int n1000s,n100s,n10s,n1s;
    n1000s=n2Cnvrt/1000;   //Shift 3 places to the left
    n100s=n2Cnvrt%1000/100;//Remainder of division of 1000 then shift 2 left
    n10s=n2Cnvrt%100/10;   //Remainder of division of 100 then shift 1 left
    n1s=n2Cnvrt%10;        //Remainder of division by 10

    //Output the number of 1000's in Roman Numerals
    //Using the Switch Statement
    switch(n1000s){
    case 9:
      num=num+ones[8]+thous;
      break;
    case 8:
      num=num+ones[7]+thous;
      break;
    case 7:
      num=num+ones[6]+thous;
      break;
    case 6:
      num=num+ones[5]+thous;
      break;
    case 5:
      num=num+ones[4]+thous;
      break;
    case 4:
      num=num+ones[3]+thous;
      break;
    case 3:
      num=num+ones[2]+thous;
      break;
    case 2:
      num=num+ones[1]+thous;
      break;
    case 1:
      num=num+ones[0]+thous;
      break;
    }

    //Output the number of 100's
    //Using the Ternary Operator
    num=num+(n100s==9?ones[8]+hund:
           n100s==8?ones[7]+hund:
           n100s==7?ones[6]+hund:
           n100s==6?ones[5]+hund:
           n100s==5?ones[4]+hund:
           n100s==4?ones[3]+hund:
           n100s==3?ones[2]+hund:
           n100s==2?ones[1]+hund:
           n100s==1?ones[0]+hund:"");
  
    //Output the number of 10's
    //Using Independent If Statements
    if(n10s==9)        num=num+tens[8];
    if(n10s==8)        num=num+tens[7];
    if(n10s==7)        num=num+tens[6];
    if(n10s==6)        num=num+tens[5];
    if(n10s==5)        num=num+tens[4];
    if(n10s==4)        num=num+tens[3];
    if(n10s==3)        num=num+tens[2];
    if(n10s==2)        num=num+tens[1];
    if(n10s==1&&n1s==0)num=num+tens[0];
    //Output the "teen" numbers
    if(n10s==1&&n1s==9) num=num+teens[8];
    if(n10s==1&&n1s==8) num=num+teens[7];
    if(n10s==1&&n1s==7) num=num+teens[6];
    if(n10s==1&&n1s==6) num=num+teens[5];
    if(n10s==1&&n1s==5) num=num+teens[4];
    if(n10s==1&&n1s==4) num=num+teens[3];
    if(n10s==1&&n1s==3) num=num+teens[2];
    if(n10s==1&&n1s==2) num=num+teens[1];
    if(n10s==1&&n1s==1) num=num+teens[0];
    //Output the number of 1's
    //Using Dependent If Statements
    if     (n1s==9&&n10s!=1)num=num+ones[8];
    else if(n1s==8&&n10s!=1)num=num+ones[7];
    else if(n1s==7&&n10s!=1)num=num+ones[6];
    else if(n1s==6&&n10s!=1)num=num+ones[5];
    else if(n1s==5&&n10s!=1)num=num+ones[4];
    else if(n1s==4&&n10s!=1)num=num+ones[3];
    else if(n1s==3&&n10s!=1)num=num+ones[2];
    else if(n1s==2&&n10s!=1)num=num+ones[1];
    else if(n1s==1&&n10s!=1)num=num+ones[0];
    }
    
    //Output zero
    if(n2Cnvrt==0) num=zero;

    cout<<num<<endl;
}