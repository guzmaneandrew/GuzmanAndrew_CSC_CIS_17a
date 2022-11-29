/* 
 * File:   DayOfYear.h
 * Author: andrewguzman
 * DayOfYear Class Specification
 * Created on November 21, 2022, 1:39 PM
 */

#ifndef DAYOFYEAR_H
#define DAYOFYEAR_H
#include <string>
using namespace std;

class DayOfYear {
    private:
        int dayNum;
        int day;
        string month;
        string months[12]={"January","February","March","April",
                           "May","June","July","August",
                           "September","October","November","December"};
        //running total of days in year
        int yrDaySum[12]={31,59,90,120,151,181,212,243,273,304,334,365};   
        int numDays[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    public:
        DayOfYear(int num);
        DayOfYear(string,int);
        void print();
        void setDayNm(int dayNum)     {this->dayNum=dayNum;}
        void setMnth(string mon) {month=mon;}
        void setDay(int day)     {this->day=day;}
        int getDayN();          
        DayOfYear operator++();
        DayOfYear operator++(int);
        DayOfYear operator--();
        DayOfYear operator--(int);
};


#endif /* DAYOFYEAR_H */

