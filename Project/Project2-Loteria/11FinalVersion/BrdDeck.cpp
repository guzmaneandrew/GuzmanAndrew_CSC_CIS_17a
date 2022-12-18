/* 
 * File:   BrdBrdDeck.h
 * Author: andrewguzman
 * BrdDeck Class Implementation
 * Created on December 5, 2022, 1:12 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Card.h"
#include "BrdDeck.h"

BrdDeck::~BrdDeck() {
    delete []names;
    for(int i=0;i<MAX;i++) {
        delete cards[i];
    }
    delete []cards;
    delete []index;
}