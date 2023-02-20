/* 
 * File:   D8Time.h
 * Author: Dr. Mark E. Lehr
 * Created on July 21, 2020, 12:54 PM
 * Purpose:  Aggregation: Date-Time Class Specification. 
 */

#ifndef D8TIME_H
#define D8TIME_H
   
//Bring in both classes
#include "DateWS.h"
#include "TimeMEL.h"

class D8Time{
    private:
        //Private data elements that are composed of other classes
        DateWS *datews;     //Create a pointer to both instantiations 
        TimeMEL *timemel;
    public:
        //Constructor must take in data needed to construct Date and Time class
        D8Time(string,string,int,int,int,int);
        //Get rid of pointers when done
        ~D8Time(){
            delete datews;
            delete timemel;
        }
        //Expose the functions from both the functions
        //Call the internal functions of the functions through the pointers
        string getSMon(){return datews->getSMon();}
        int getDay(){return datews->getDay();}
        int getYear(){return datews->getYear();}
        string cnvrtDy(){return datews->cnvrtDy();}
        string getTime(){return timemel->getTime();}
};

//Constructor brings in and instantiates the properties with a new
D8Time::D8Time(string sMonth,string sDay,int year,int hrs,int min,int sec){
    datews=new DateWS(sMonth,sDay,year);
    timemel=new TimeMEL(hrs,min,sec);
}

#endif /* D8TIME_H */

