//
//  Deck.h
//  PokerGame
//
//  Created by Ricky Romero on 1/27/16.
//  Copyright © 2016 RickyRomero. All rights reserved.
//  Email: rickyromero@my.unt.edu


#ifndef Deck_h
#define Deck_h
#include "Card.h"
#include <list>

//MARK: DECK CLASS
class Deck{
private:
    
    list<Card> Hand_list;

    
public:
    
    Card cards[52];

    Deck();
    void print();
    void shuffle_Deck();
    void Deal_Cards();
    
};




Deck::Deck(){
    
        for (int i=0;i<4;i++){
            for (int j=0;j<13;j++){
                cards[i*13+j].suit = i;
                cards[i*13+j].rank = j;
            }
        }
}
void Deck::shuffle_Deck(){
    
    int x;
    Card tempCard;
    
    for(int i = 0; i <52; i++){
        x = rand() % 52;
        tempCard = cards[i];
        cards[i] = cards[x];
        cards[x] = tempCard;
    }

    
}




#endif /* Deck_h */




