/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "Inventory.h"
#include <iostream>
using namespace std;

Inventory::Inventory() {
    itemNumber=0;
    quantity=0;
    perUCost=0.0;
    totalCost=0.0;
}

Inventory::Inventory(int n,int qty,float cost) {
    itemNumber=n;
    quantity=qty;
    perUCost=cost;
    setTotalCost();
}

void Inventory::setItemNumber(int n) {
    itemNumber=n;
}

void Inventory::setQuantity(int qty) {
    quantity=qty;
}

void Inventory::setCost(float cost) {
    perUCost=cost;
}

void Inventory::setTotalCost() {
    totalCost=quantity*perUCost;
}

int Inventory::getItemNum() {
    return itemNumber;
}

int Inventory::getQuantity() {
    return quantity;
}

float Inventory::getCost() {
    return perUCost;
}

float Inventory::getTotalCost() {
    return totalCost;
}