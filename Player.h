//
//  Player.h
//  PokerGame
//
//  Created by Ricky Romero on 1/27/16.
//  Copyright © 2016 RickyRomero. All rights reserved.
//  Email: rickyromero@my.unt.edu

#include "Card.h"


//MARK: PLAYER CLASS
class Player{
    
    
public:
    string name;
    int money;
    Card Player_hand[5];

    void Hand();

    
};

