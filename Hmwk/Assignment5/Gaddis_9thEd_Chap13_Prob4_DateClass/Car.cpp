/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 * Car Class Implementation
 */

#include <iostream>
#include <string>
using namespace std;

#include "Car.h"

Car::Car(int yrMdl,string mk) {
    yearModel=yrMdl;
    make=mk;
    speed=0;
}

int Car::getYrMdl() {
    return yearModel;
}

string Car::getMake() {
    return make;
}

int Car::getSpeed() {
    return speed;
}

void Car::accelerate() {
    speed+=5;
}

void Car::brake() {
    speed-=5;
}