/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Inventory.h
 * Author: andrewguzman
 * Inventory Class Specification
 * Created on November 8, 2022, 10:37 PM
 */

#ifndef INVENTORY_H
#define INVENTORY_H

class Inventory {
private:
    int itemNumber;    //item's item number
    int quantity;    //quantity of items on hand
    float perUCost;     //wholesale per-unit cost of the item
    float totalCost;//total inventory cost of the item (qty*cost)
public: 
    Inventory();
    Inventory(int num,int qty,float cost);
    void setItemNumber(int n);
    void setQuantity(int qty);
    void setCost(float cost);
    void setTotalCost();
    int getItemNum();
    int getQuantity();
    float getCost();
    float getTotalCost();
};


#endif /* INVENTORY_H */

