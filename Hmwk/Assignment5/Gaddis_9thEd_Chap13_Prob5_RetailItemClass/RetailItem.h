/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   RetailItem.h
 * Author: andrewguzman
 *
 * Created on November 8, 2022, 9:46 PM
 * RetailItem Class Specification
 */

#ifndef RETAILITEM_H
#define RETAILITEM_H
#include <string>
using namespace std;


class RetailItem {
    private:
        string description;
        int unitsOnHand;
        float price;
    public:
        RetailItem();
        RetailItem(string desc,int n,float price);
        void setDesc();
        void setUnits();
        void setPrice();
        string getDesc();
        int getUnits();
        float getPrice();
};

#endif /* RETAILITEM_H */

