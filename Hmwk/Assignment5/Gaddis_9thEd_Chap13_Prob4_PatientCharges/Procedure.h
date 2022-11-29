/* 
 * File:   Procedure.h
 * Author: andrewguzman
 * Procedure Class Specification
 * Created on November 28, 2022, 10:15 PM
 */

#ifndef PROCEDURE_H
#define PROCEDURE_H
#include <string>
using namespace std;

class Procedure {
private:
    static int prcdCnt;
    string name;
    string date;
    string docName;
    float price;
public:
    Procedure(string,string,string,float);
    void setName(string);
    void setDate(string);
    void setDoc(string);
    void setPrce(float);
    int getCnt() { return prcdCnt;}
    string getName() { return name;}
    string getDate() { return date;}
    string getDoc() { return docName;}
    float getPrce() { return price;}
    void prntSum();
};


#endif /* PROCEDURE_H */

