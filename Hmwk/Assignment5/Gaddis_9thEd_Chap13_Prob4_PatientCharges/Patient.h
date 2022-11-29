/* 
 * File:   Patient.h
 * Author: andrewguzman
 * Patient Class Specification
 * Created on November 28, 2022, 9:57 PM
 */

#ifndef PATIENT_H
#define PATIENT_H
#include <string>
using namespace std;

class Patient {
private:
    string fName;       //first name
    string mName;       //middle name
    string lName;       //last name
    string address;     //address
    string city;        //city
    string state;       //state
    int zip;            //zip code
    string phone;       //phone 
    string eContct;     //emergency contact
    string ePhone;      //emergency phone
public:
    Patient(string,string,string,string,string,string,int,string,string,string);  
    void setFName(string);
    void setMName(string);
    void setLName(string);
    void setAddr(string);
    void setCity(string);
    void setStat(string);
    void setZip(int);
    void setPhne(string);
    void setECont(string);
    void setEPhn(string);
    string getFName() { return fName;}
    string getMName() { return mName;}
    string getLName() { return lName;}
    string getAddr() { return address;}
    string getCity() { return city;}
    string getStat() { return state;}
    int getZip() {    return zip;}
    string getPhne() { return phone;}
    string getECon() { return eContct;}
    string getEPhn() { return ePhone;}
    void prntInf();
};

#endif /* PATIENT_H */

