///*
// * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
// * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
// * Image Class Implementation
// */
//
#include <iostream>
#include <string>
#include "Image.h"
using namespace std;

//Define static variables outside of the class
int Image::imgCnt=0;

Image::Image() {
    imgCnt++;     //Increment static variable count of Image objects
    this->setRddl("");
    this->setName("");
}

Image::Image(string riddle,string name) {
    imgCnt++;     //Increment static variable count of Image objects
    this->setRddl(riddle);
    this->setName(name);
}

Image::Image(const Image &obj) {
    riddle=obj.riddle;
    name=obj.name;
}

void Image::display() {
    cout<<this->getRddl()<<endl;
    cout<<this->getName()<<endl;
}