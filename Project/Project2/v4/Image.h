/* 
 * File:   Image.h
 * Author: andrewguzman
 * Purpose: Image Class Specification
 * Created on November 22, 2022, 8:15 PM
 */

#ifndef IMAGE_H
#define IMAGE_H
#include "Constants.h"
#include <string>
using namespace std;

class Image {
    private:
        static int imgCnt;     //Static variable count of Image objects
        string riddle;
        string name;
    public:
        Image();                                    //Default constructor
        Image(string,string);                       //Constructor
        Image(Image *);                             //Constructor
        ~Image();                                   //Destructor
        void display();                             //Display Image data
        void setName(string name){this->name=name;} //Set Image object name
        void setRddl(string riddle){this->riddle=riddle;} //Set Image object riddle
        int getCnt() const {return imgCnt;}         //Get count of Image objects
        string getRddl() {return riddle;}           //Get riddle
        string getName() {return name;}             //Get name
//        Image(const Image &);                       //Copy constructor
//        const Image operator=(const Image &rhs);    //Overloaded equality operator
};

#endif /* IMAGE_H */

