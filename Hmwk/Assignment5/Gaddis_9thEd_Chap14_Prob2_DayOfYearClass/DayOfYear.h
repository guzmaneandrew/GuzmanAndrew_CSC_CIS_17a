/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   DayOfYear.h
 * Author: andrewguzman
 *
 * Created on November 21, 2022, 1:39 PM
 */

#ifndef DAYOFYEAR_H
#define DAYOFYEAR_H
#include <string>
using namespace std;

class DayOfYear {
    private:
        int dayNum;
        string months[12]={"January ","February ","March ","April ",
                           "May ","June ","July ","August ",
                           "September ","October ","November ","December "};
        //running total of days in year
        int yrDaySum[12]={31,59,90,120,151,181,212,243,273,304,334,365};    
    public:
        DayOfYear(int num);
        void print();
};


#endif /* DAYOFYEAR_H */

