/* 
 * File:   Procedure.h
 * Author: andrewguzman
 * Procedure Class Implementation
 * Created on November 28, 2022, 10:15 PM
 */     
#include <iostream>
#include <string>
#include <iomanip>
#include "Procedure.h"

int Procedure::prcdCnt=0;           //count of procedure objects

Procedure::Procedure(string name,string date,string docName,float price) {
    prcdCnt++;
    this->name=name;
    this->date=date;
    this->docName=docName;
    this->price=price;
}

void Procedure::setName(string name) {
    this->name=name;
}

void Procedure::setDate(string date) {
    this->date=date;
}

void Procedure::setDoc(string docName) {
    this->docName=docName;
}

void Procedure::setPrce(float price) {
    this->price=price;
}

void Procedure::prntSum() {
    cout<<fixed<<setprecision(2);
    cout<<"Procedure Name: "<<name<<endl;
    cout<<"Date: "<<date<<endl;
    cout<<"Practitioner: "<<docName<<endl;
    cout<<"Charge: $"<<price<<endl<<endl;
}