/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Image.h
 * Author: andrewguzman
 * Purpose: Image Class Specification: no constructor used
 * so I can create an array of Image objects
 * Created on November 22, 2022, 8:15 PM
 */

#ifndef IMAGE_H
#define IMAGE_H
#include <string>
using namespace std;

class Image {
    private:
        string riddle;
        string name;
//        static int imgCnt;     //Static variable count of Image objects
    public:
        Image(string,string);                       //Image Constructor
        void setRddl(string riddle){this->riddle=riddle;} //Set Image object riddle
        void setName(string name){this->name=name;} //Set Image object name
//        int getCnt() const {return imgCnt;}       //Get count of Image objects
        void display();                           //Display Image riddle and name
        string getRddl() {return riddle;}           //Get riddle
        string getName() {return name;}             //Get name
};

//Define static variables outside of the class
//int Image::imgCnt=0;

#endif /* IMAGE_H */

