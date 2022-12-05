/* 
 * File:   Image.h
 * Author: andrewguzman
 * Purpose: Image Class Specification
 * Created on November 22, 2022, 8:15 PM
 */

#ifndef IMAGE_H
#define IMAGE_H
#include <string>
using namespace std;

class Image {
    private:
        static int imgCnt;     //Static variable count of Image objects
        string riddle;
        string name;
    public:
        Image();                                    //Default Image constructor
        Image(string,string);                       //Image constructor
        Image(const Image &);                       //Image copy constructor
        void display();                             //Display Image data
        void setRddl(string riddle){this->riddle=riddle;} //Set Image object riddle
        void setName(string name){this->name=name;} //Set Image object name
        int getCnt() const {return imgCnt;}         //Get count of Image objects
        string getRddl() const {return riddle;}     //Get riddle
        string getName() const {return name;}       //Get name
        const Image operator=(const Image &rhs);    //Overloaded equality operator
};

#endif /* IMAGE_H */

