/* 
 * File:   BrdDeck.h
 * Author: andrewguzman
 * BrdDeck Class Specification
 * Created on December 5, 2022, 1:12 AM
 */

#ifndef BRDDECK_H
#define BRDDECK_H
#include "BrdCard.h"
#include "Deck.h"
#include <string>

class BrdDeck:public Deck<BrdCard> {
    private:
//    all protected variables are inherited from Deck<BrdCard>
    public:
//    public member functions are inherited from Deck<BrdCard>
        ~BrdDeck();                //Destructor

};

#endif /* BRDDECK_H */

