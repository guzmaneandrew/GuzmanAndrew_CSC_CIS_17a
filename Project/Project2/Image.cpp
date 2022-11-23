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

void Image::create(string riddle,string name) {
    this->setRddl(riddle);
    this->setName(name);
//    imgCnt++;     //Increment static variable count of Image objects
}