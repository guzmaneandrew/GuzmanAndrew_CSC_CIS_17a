/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Numbers.h
 * Author: andrewguzman
 *
 * Created on November 20, 2022, 7:58 PM
 */
#ifndef NUMBERS_H
#define NUMBERS_H
#include <string>
using namespace std;

class Numbers {
    private:
        int number;
        string thous="thousand ";
        string hund="hundred ";
        string tens[9]={"ten ","twenty ","thirty ", "fourty ",
                        "fifty ","sixty ","seventy ","eighty ","ninety "};
        string teens[9]={"eleven ","twelve ","thirteen ","fourteen ", "fifteen",
            "sixteen ","seventeen ","eighteen ","nineteen "};
        string ones[9]={"one ","two ","three ","four ",
            "five ","six ","seven ","eight ","nine "};
        string zero="zero";
    public:
        Numbers(int num);
        void print();
};

#endif /* NUMBERS_H */

