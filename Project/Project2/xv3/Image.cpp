///*
// * Image Class Implementation
// */
//
#include <iostream>
#include <string>
#include "Image.h"

    int Image::imgCnt=0;        //Define static variables outside of the class

    Image::Image() {
        imgCnt++;     //Increment static variable count of Image objects
        riddle="";
        name="";
    }

    Image::Image(string riddle,string name) {
        imgCnt++;
        this->riddle=riddle;
        this->name=name;
    }

    Image::Image(const Image &obj) {
        imgCnt++;     //Increment static variable count of Image objects
        this->riddle=obj.riddle;
        this->name=obj.name;
    }

    void Image::display() {
        cout<<this->imgCnt<<endl;
        cout<<this->getRddl()<<endl;
        cout<<this->getName()<<endl;
    }

    const Image Image::operator=(const Image &rhs) {
        riddle=rhs.riddle;
        name=rhs.name;      

        return *this;
    }