/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Car.h
 * Author: andrewguzman
 * Purpose: Car Class Specification
 * Created on November 8, 2022, 9:11 PM
 */

#include <string>
using namespace std;
#ifndef CAR_H
#define CAR_H

class Car {
    private:
        int yearModel;      //car's year model
        string make;        //make of the car
        int speed;          //car's current speed
    public:
        Car(int,string);
        int getYrMdl();
        string getMake();
        int getSpeed();
        void accelerate();
        void brake();
};

#endif /* CAR_H */

