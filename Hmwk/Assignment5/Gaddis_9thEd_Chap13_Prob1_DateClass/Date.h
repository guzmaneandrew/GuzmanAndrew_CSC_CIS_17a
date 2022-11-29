/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Date.h
 * Author: andrewguzman
 *
 * Created on November 8, 2022, 8:34 PM
 * Purpose: Date Class Specification
 */

#ifndef DATE_H
#define DATE_H

class Date {
    private:
        int month;
        int day;
        int year;

    public:
        void setMonth();
        void setDay();
        void setYear();
        int getMonth();
        int getDay();
        int getYear();
        void getMStr();
        void printv1();
        void printv2();
        void printv3();
};


#endif /* DATE_H */

