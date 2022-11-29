/* 
 * File:   DayOfYear.cpp
 * Author: andrewguzman
 * DayOfYear Class Implementation
 * Created on November 21, 2022, 1:39 PM
 */

#include "DayOfYear.h"
#include <iostream>
#include <string>
using namespace std;

DayOfYear::DayOfYear(int num) {
    if(num>=1&&num<=365) {
        if(num>=1&&num<=yrDaySum[0]) {
            month=months[0];
            dayNum=num;
        }
        if(num>yrDaySum[0]&&num<=yrDaySum[1]) {
            month=months[1];
            dayNum=num-yrDaySum[0];
        }
        if(num>yrDaySum[1]&&num<=yrDaySum[2]) {
            month=months[2];
            dayNum=num-yrDaySum[1];
        }
        if(num>yrDaySum[2]&&num<=yrDaySum[3]) {
            month=months[3];
            dayNum=num-yrDaySum[2];
        }
        if(num>yrDaySum[3]&&num<=yrDaySum[4]) {
            month=months[4];
            dayNum=num-yrDaySum[3];
        }
        if(num>yrDaySum[4]&&num<=yrDaySum[5]) {
            month=months[5];
            dayNum=num-yrDaySum[4];
        }
        if(num>yrDaySum[5]&&num<=yrDaySum[6]) {
            month=months[6];
            dayNum=num-yrDaySum[5];
        }
        if(num>yrDaySum[6]&&num<=yrDaySum[7]) {
            month=months[7];
            dayNum=num-yrDaySum[6];
        }
        if(num>yrDaySum[7]&&num<=yrDaySum[8]) {
            month=months[8];
            dayNum=num-yrDaySum[7];
        }
        if(num>yrDaySum[8]&&num<=yrDaySum[9]) {
            month=months[9];
            dayNum=num-yrDaySum[8];
        }
        if(num>yrDaySum[9]&&num<=yrDaySum[10]) {
            month=months[10];
            dayNum=num-yrDaySum[9];
        }
        if(num>yrDaySum[10]&&num<=yrDaySum[11]) {
            month=months[11];
            dayNum=num-yrDaySum[10];
        }
    } else {
        cout<<"ERROR: Invalid input.\n";
        exit(0);
    }
}

DayOfYear::DayOfYear(string month,int num) {
    if((month=="January"||month=="February"||month=="March"||month=="April"||month=="May"||
       month=="June"||month=="July"||month=="August"||month=="September"||
       month=="October"||month=="November"||month=="December"))  {
        this->month=month;
        if(month=="January"&&num>0&&num<=numDays[0])        dayNum=num;
        else if(month=="February"&&num>0&&num<=numDays[1])  dayNum=num+yrDaySum[0];
        else if(month=="March"&&num>0&&num<=numDays[2])     dayNum=num+yrDaySum[1];
        else if(month=="April"&&num>0&&num<=numDays[3])     dayNum=num+yrDaySum[2];
        else if(month=="May"&&num>0&&num<=numDays[4])       dayNum=num+yrDaySum[3];
        else if(month=="June"&&num>0&&num<=numDays[5])      dayNum=num+yrDaySum[4];
        else if(month=="July"&&num>0&&num<=numDays[6])      dayNum=num-yrDaySum[5];
        else if(month=="August"&&num>0&&num<=numDays[7])    dayNum=num+yrDaySum[6];
        else if(month=="September"&&num>0&&num<=numDays[8]) dayNum=num+yrDaySum[7];
        else if(month=="October"&&num>0&&num<=numDays[9])   dayNum=num+yrDaySum[8];
        else if(month=="November"&&num>0&&num<=numDays[10])  dayNum=num+yrDaySum[9];
        else if(month=="December"&&num>0&&num<=numDays[11])  dayNum=num+yrDaySum[10];
        else {
            cout<<"ERROR: Invalid input.\n";
            exit(0);
        }
    }

}

int DayOfYear::getDayN() {
    return dayNum;
}

DayOfYear DayOfYear::operator++() {
    if(dayNum==365) {
        dayNum=1;
    } else if(dayNum<365) {
        dayNum++;
    }
    
    return *this;
}

DayOfYear DayOfYear::operator++(int dummy) {
//    if(dayNum==365) {
//        DayOfYear temp1=*this;
//        temp1;setDayNm(1);
//        return temp1;
//    } else if(dayNum!=365){
//        DayOfYear temp2=*this;
//        temp2.setDayNm(++dayNum);
//        return temp2;
//    }
    
    if(dayNum<365) {
        DayOfYear temp1=*this;
        ++(*this);
        return temp1;
    } else if(dayNum==365){
        DayOfYear temp2(++dayNum);
        return temp2;
    }
}

DayOfYear DayOfYear::operator--() {
    if(dayNum==1) {
        dayNum=365;
    } else {
        dayNum--;
    }
    
    return *this;
}

DayOfYear DayOfYear::operator--(int dummy) {
//    if(dayNum<365) {
//        DayOfYear temp1=*this;
//        temp1.setDayNm(--dayNum);
//        return temp1;
//    } else if(dayNum==1){
//        DayOfYear temp2=*this;
//        temp2.setDayNm(365);
//        return temp2;
//    }
    
    if(dayNum==1) {
        DayOfYear temp1=*this;
        temp1;setDayNm(365);
        return temp1;
    } else if(dayNum!=1){
        DayOfYear temp2=*this;
        temp2.setDayNm(--dayNum);
        return temp2;
    }
}