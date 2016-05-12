//
//  Card.h
//  PokerGame
//
//  Created by Ricky Romero on 1/27/16.
//  Copyright © 2016 RickyRomero. All rights reserved.
//  Email: rickyromero@my.unt.edu


#ifndef Card_h
#define Card_h
using namespace std;
#include <algorithm>    // std::shuffle

string suits[4] = {"Spades" , "Hearts", "Clubs", "Diamonds"};
string ranks[13] = {"Ace", "2", "3" , "4", "5", "6", "7", "8", "9", "10", "Jack" , "Queen", "King"};


//MARK: CARD CLASS
class Card{
public:
    int suit;
    int rank;
    void SetValues(int a_Suit, int a_Number);

};

void Card::SetValues(int Suit, int Number) {
    suit = Suit;
    rank = Number;
}

#endif /* Card_h */
