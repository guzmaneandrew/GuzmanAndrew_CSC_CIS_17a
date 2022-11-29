/* 
 * File:   Patient.h
 * Author: andrewguzman
 * Patient Class Implementation
 * Created on November 28, 2022, 9:57 PM
 */
#include <iostream>
#include "Patient.h"

Patient::Patient(string fName,string mName,string lName,string address,
        string city,string state,int zip,string phone,string eContct,string ePhone) {
    this->fName=fName;
    this->mName=mName;
    this->lName=lName;
    this->address=address;
    this->city=city;
    this->state=state;
    this->zip=zip;
    this->phone=phone;
    this->eContct=eContct;
    this->ePhone=ePhone;
}

void Patient::setFName(string fName) {
    this->fName=fName;
}

void Patient::setMName(string mName) {
    this->mName=mName;
}

void Patient::setLName(string lName) {
    this->lName=lName;
}

void Patient::setAddr(string address) {
    this->address=address;
}

void Patient::setCity(string city) {
    this->city=city;
}

void Patient::setStat(string state) {
    this->state=state;
}

void Patient::setZip(int zip) {
    this->zip=zip;
}

void Patient::setPhne(string phone) {
    this->phone=phone;
}

void Patient::setECont(string eContct){
    this->eContct=eContct;
}

void Patient::setEPhn(string ePhone) {
    this->ePhone=ePhone;
}

void Patient::prntInf() {
    cout<<"Full Name: ";
    cout<<fName<<" "<<mName<<" "<<lName<<endl;
    cout<<"Home Address: ";
    cout<<address<<" "<<city<<" "<<state<<" "<<zip<<endl;
    cout<<"Phone: ";
    cout<<phone<<endl;
    cout<<"Emergency Contant and Phone: ";
    cout<<eContct<<" "<<ePhone<<endl;
}