/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 * Retail Item Class Implementation
 */

#include <string>
#include <iostream>
#include "RetailItem.h"

RetailItem::RetailItem() {
    description=" ";
    unitsOnHand=0;
    price=0.0;
}

RetailItem::RetailItem(string desc,int units,float newPrice) {
    description=desc;
    unitsOnHand=units;
    price=newPrice;
}

void RetailItem::setDesc() {
    cout<<"Enter Description: ";
    cin>>description;
}

void RetailItem::setUnits() {
    cout<<"Enter Units on Hand: ";
    cin>>unitsOnHand;
}

void RetailItem::setPrice() {
    cout<<"Enter Price: ";
    cin>>price;
}

string RetailItem::getDesc() {
    return description;
}

int RetailItem::getUnits() {
    return unitsOnHand;
}

float RetailItem::getPrice() {
    return price;
}