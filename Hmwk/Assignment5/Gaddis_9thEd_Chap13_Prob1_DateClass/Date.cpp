/*
 * Date Class Implementation
 */
#include "Date.h"
#include <iostream>
#include <string>
using namespace std;

void Date::setMonth() {
    do{
        cout<<"Enter month: ";
        cin>>month;
    } while(month<1||month>12);
}

void Date::setDay() {
    
    do{
        cout<<"Enter day: ";
        cin>>day;
    } while(day<1||day>31);

}

void Date::setYear() {
    cout<<"Enter year: ";
    cin>>year;
}

int Date::getMonth() {
    return month;
}

int Date::getDay() {
    return day;
}

int Date::getYear() {
    return year;
}

void Date::printv1() {
    cout<<getMonth()<<"/"<<getDay()<<"/"<<getYear()<<endl;
}

void Date::printv2() {
    getMStr();
    cout<<" "<<getDay()<<", "<<getYear()<<endl;
}

void Date::printv3() {
    cout<<getDay()<<" ";
    getMStr();
    cout<<" "<<getYear()<<endl;
}

void Date::getMStr() {
    switch(getMonth()) {
        case 1:
            cout<<"January ";
            break;
        case 2:
            cout<<"February ";
            break;
        case 3:
            cout<<"March ";
            break;   
        case 4:
            cout<<"April ";
            break;  
        case 5:
            cout<<"May ";
            break;
        case 6:
            cout<<"June ";
            break;
        case 7:
            cout<<"July ";
            break;   
        case 8:
            cout<<"August ";
            break;  
        case 9:
            cout<<"September ";
            break;
        case 10:
            cout<<"October ";
            break;
        case 11:
            cout<<"November ";
            break;   
        case 12:
            cout<<"December ";
            break;  
    }
}