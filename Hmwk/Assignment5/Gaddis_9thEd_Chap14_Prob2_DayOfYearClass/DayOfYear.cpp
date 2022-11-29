/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "DayOfYear.h"
#include <iostream>
#include <string>
using namespace std;

DayOfYear::DayOfYear(int num) {
    if(num>=1&&num<=365) {
        dayNum=num; 
    } else {
        cout<<"ERROR: Invalid input.\n";
        exit(0);
    }
}

void DayOfYear::print() {
    string month="",date="";
    int day;
    
    //Print month string
    if(dayNum>=1&&dayNum<=yrDaySum[0])           month=months[0];
    if(dayNum>yrDaySum[0]&&dayNum<=yrDaySum[1])  month=months[1];
    if(dayNum>yrDaySum[1]&&dayNum<=yrDaySum[2])  month=months[2];
    if(dayNum>yrDaySum[2]&&dayNum<=yrDaySum[3])  month=months[3];
    if(dayNum>yrDaySum[3]&&dayNum<=yrDaySum[4])  month=months[4];
    if(dayNum>yrDaySum[4]&&dayNum<=yrDaySum[5])  month=months[5];
    if(dayNum>yrDaySum[5]&&dayNum<=yrDaySum[6])  month=months[6];
    if(dayNum>yrDaySum[6]&&dayNum<=yrDaySum[7])  month=months[7];
    if(dayNum>yrDaySum[7]&&dayNum<=yrDaySum[8])  month=months[8];
    if(dayNum>yrDaySum[8]&&dayNum<=yrDaySum[9])  month=months[9];
    if(dayNum>yrDaySum[9]&&dayNum<=yrDaySum[10]) month=months[10];
    if(dayNum>yrDaySum[10]&&dayNum<=yrDaySum[11])month=months[11];
    
    //Print day string
    if(month=="January ")   day=dayNum;
    if(month=="February ")  day=dayNum-yrDaySum[0];
    if(month=="March ")     day=dayNum-yrDaySum[1];
    if(month=="April ")     day=dayNum-yrDaySum[2];
    if(month=="May ")       day=dayNum-yrDaySum[3];
    if(month=="June ")      day=dayNum-yrDaySum[4];
    if(month=="July ")      day=dayNum-yrDaySum[5];
    if(month=="August ")    day=dayNum-yrDaySum[6];
    if(month=="September ") day=dayNum-yrDaySum[7];
    if(month=="October ")   day=dayNum-yrDaySum[8];
    if(month=="November ")  day=dayNum-yrDaySum[9];
    if(month=="December ")  day=dayNum-yrDaySum[10];
    
    //Concat date string
    date=month+to_string(day);
    
    cout<<date<<endl;
}