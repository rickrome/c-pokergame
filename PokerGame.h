//
//  PokerGame.h
//  PokerGame
//
//  Created by Ricky Romero on 1/27/16.
//  Copyright © 2016 RickyRomero. All rights reserved.
//  Email: rickyromero@my.unt.edu


#ifndef PokerGame_h
#define PokerGame_h
#include <ctime>
#include "Player.h"
#include "Deck.h"
#include "Card.h"

string ScoreTitle[10] = {"High Card", "2 of a Kind", "2 Pair", "Three of a Kind", "Straight", "Flush", "Full House", "Four of a Kind", "Straight Flush", "Royal Flush"};

int CardCount = 0;
int top = 0;

Card * Deal_Hand(Card *Deck) {
    
    Card *Stack = new Card[5];
    
    for(int i=0; i<5; i++) {
        top--;
        Stack[i] = Deck[top+1];
        CardCount++;
    }

    return Stack;
    
}
Card * Sort_Hand(Card *Deck) {
    
    Card tempCard;
    
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            if(Deck[i].rank < Deck[j].rank){
                tempCard = Deck[i];
                Deck[i] = Deck[j];
                Deck[j] = tempCard;
            }
        }
    }
    
    return Deck;
    
}
Card * discard(Card *Deck, int i){
    
    Card *Stack = new Card[5];

    top--;
    Stack[i] = Deck[top+1];
    
    return Deck;

}
//MARK: POKERGAME CLASS
class PokerGame{
    
private:
    
    
    
    
public:
    Deck deck;
    Card *Hand = new Card[5];

    void startGame();
    void Deal();
    void Discard();
    void Redeal();
    void printTable();
};

void PokerGame::Deal(){
    Hand = Deal_Hand(deck.cards);
}

void PokerGame::Discard(){
    
    
    
}
void PokerGame::Redeal(){
    
    
    
}
void PokerGame::printTable(){
    
    cout << "\n---\tPlayer Cards\t---\n";
    for(int i=0; i<5; i++) {
        cout<<i+1<<".) "<<ranks[Hand[i].rank]<<" of "<<suits[Hand[i].suit]<<endl;
    }

    
}


int score_Hand(Card *hand){
    //{"High Card", "2 of a Kind", "2 Pair", "Three of a Kind", "Straight", "Flush", "Full House", "Four of a Kind", "Straight Flush", "Royal Flush"};
    
    bool straight = false, flush= false, three= false,Royal = false,
    four= false,fullHouse= false,two_pair= false,two_Kind = false;
    
    int straight_count = 0, Royal_count = 0;
    int k;
    k = 0;
    

//    cout << "\nrank number\n" << hand[0].rank << " "<< hand[1].rank <<" "<< hand[2].rank <<" "<< hand[3].rank << " " << hand[4].rank << endl;
   
    
    
/*checks for Royal*/
    if(hand[0].rank == 0) {
        for (int i=0;i<4;i++){
            if(hand[i+1].rank == 9+i){
                Royal_count++;
            }
        }
//        cout << "Royal_count " << Royal_count << endl;
        if(Royal_count == 4)
            Royal = true;
    }

  
    
    
/*checks for flush*/
    if(hand[0].suit == hand[1].suit && hand[0].suit == hand[2].suit && hand[0].suit == hand[3].suit && hand[0].suit == hand[4].suit){
        
        flush = true;
    }
    
    
/* checks for straight*/
    for (int i=1;i<=4;i++){
        
        if((hand[0].rank+i) == hand[i].rank){
            straight_count++;
        }
        if(straight_count == 4){
            
            straight = true;
        }
//        cout << i << ": straight_count: " << straight_count << endl;

    }

    
/* checks for fours 
(X-X-X-X-O) or (O-X-X-X-X)
 */
    if((hand[0].rank == hand[1].rank  && hand[1].rank == hand[2].rank && hand[2].rank == hand[3].rank) ||
       (hand[1].rank == hand[2].rank  && hand[2].rank == hand[3].rank && hand[3].rank == hand[4].rank)) {
        four = true;
    }

    
/*checks for threes and fullhouse

 i=0 (X-X-X-O-O) <-check if (O-O) match if yes full house
 i=1 (O-X-X-X-O)
 i=2 (O-O-X-X-X) <-check if (O-O) match if yes full house
 */
    for (int i=0;i<=2;i++){
    //    cout << i <<": " << hand[i].rank << " " << hand[i+1].rank << " " << hand[i+2].rank << endl;
        
        if(hand[i].rank == hand[i+1].rank &&  hand[i+1].rank == hand[i+2].rank){
            three = true;

            if(i==0){
                if (hand[3].rank==hand[4].rank){
                    fullHouse = true;
                }
            }
            else if(i==2){
                if (hand[0].rank==hand[1].rank){
                    fullHouse = true;
                }
  
            }

        }
    }
    /* checks for pairs
     pair = P
     
     P1-P1-P2-P2-X  i=0
     P1-P1-X -P2-P2 i=0
      X-P1-P1-P2-P2 i=1
     */
    
    for (int i=0;i<=2;i++){

        if(hand[i].rank == hand[i+1].rank){
            two_Kind = true;
            
            if(i==0){
                for (int i=2;i<=3;i++){
                    if(hand[i].rank == hand[i+1].rank){
                        two_pair = true;
                    }
                }
            }
            if(i==1){
                if(hand[3].rank == hand[4].rank)
                    two_pair = true;
            }
            
        }//end two_Kind check
    }//end of for loop
    
    /* send back score */
    if (Royal&&flush)
        return 9;
    else if(straight&&flush)
        return 8;
    else if(four)
        return 7;
    else if(fullHouse)
        return 6;
    else if(flush)
        return 5;
    else if(straight)
        return 4;
    else if(three)
        return 3;
    else if(two_pair)
        return 2;
    else if(two_Kind)
        return 1;
    else
        return 0;
}



void PokerGame::startGame(){
    
    Card *Hand_sorted = new Card[5];  //initialize the member Hand of type CARD

    char choice;
    char discardYN;
    int discard_num;
    srand(time(0));
    int x = rand() % 5 + 2;
    int score;
    int Num_players;
    
    
    
    
    cout<< "How many player? 1-4";
    cout << ": ";
    cin >> Num_players;
    if(Num_players != 1){
    cout << "\nLooking for Players...\n";
    sleep(2);
    cout << "Looking for Players......\n";
    sleep(2);
    cout << "Sorry all players are offline\n";
    sleep(1);
    }
    cout << "Going to single player mode\n";
    do{
        
        cout << "\n shuffling the cards \n";
        //Shuffle
        for(int i=0; i< x + x; i++) {   //shuffle sequence
            deck.shuffle_Deck();
        }
        top = 51;
        sleep(1);
        
/*  Deal 5 cards */
        Deal();
        

/*  sort hand   */
        Hand_sorted = Sort_Hand(Hand);
        
        
/*  show cards  */
        printTable();
 
        
/*  Test   
 you can test the scoring hands by changing the data below
 
 In "score = score_Hand(Hand_sorted); " change  Hand_sorted to Test_Hand.

*/
/*
     Card *Test_Hand = new Card[5];  //initialize the member Hand of type CARD
        Test_Hand[0].rank = 2;
        Test_Hand[1].rank = 4;
        Test_Hand[2].rank = 4;
        Test_Hand[3].rank = 6;
        Test_Hand[4].rank = 6;
        
        Test_Hand[0].suit = 2;
        Test_Hand[1].suit = 1;
        Test_Hand[2].suit = 1;
        Test_Hand[3].suit = 1;
        Test_Hand[4].suit = 1;
        
        Test_Hand = Sort_Hand(Test_Hand);

        cout << "\n Test Hand " << endl;
        for(int i=0; i<5; i++) {
            cout<<i+1<<".) "<<ranks[Test_Hand[i].rank]<<" of "<<suits[Test_Hand[i].suit]<<endl;
            
        }
 */
//   End of test
       
        
/*  score Hand Card */
        score = score_Hand(Hand_sorted);
//        cout << "\nsocre number: " << score << endl;
        cout<<"\nHand: "<<ScoreTitle[score]<<endl;

/*  Discard  */
        discard_num = 0;
        cout << "Discard?" << endl;
        cout << "Y/N: ";
        cin>>discardYN;
       
        if(discardYN == 'y'){
            
            int amount = 0, discard_num2 = 0, discard_num3 = 0;
            
            cout << "Number of cards?" << endl;
            cout << "(1-3) ";
            cin >> amount;
            
            if(amount == 1){
                cout << "Pick 1-5" << endl;
                cout << "#";
                cin >> discard_num;
                --discard_num;
                
                top--;
                Hand_sorted[discard_num] = deck.cards[top+1];
                
                Hand_sorted = Sort_Hand(Hand_sorted);
                printTable();
                score = score_Hand(Hand_sorted);
                cout<<"\nHand: "<<ScoreTitle[score]<<endl;
            }
            else if (amount == 2){
                cout << "1st Card? " << endl;
                cout << "#";
                cin >> discard_num;
                --discard_num;
                cout << "2nd Card? " << endl;
                cout << "#";
                cin >> discard_num2;
                --discard_num2;
                
                top--;
                Hand_sorted[discard_num] = deck.cards[top+1];
                top--;
                Hand_sorted[discard_num2] = deck.cards[top+1];
            }
            else if (amount == 3){
                cout << "1st Card? " << endl;
                cout << "#";
                cin >> discard_num;
                --discard_num;
                cout << "2nd Card? " << endl;
                cout << "#";
                cin >> discard_num2;
                --discard_num2;

                cout << "3rd Card? " << endl;
                cout << "#";
                cin >> discard_num3;
                --discard_num3;
                
                top--;
                Hand_sorted[discard_num] = deck.cards[top+1];
                top--;
                Hand_sorted[discard_num2] = deck.cards[top+1];
                top--;
                Hand_sorted[discard_num3] = deck.cards[top+1];

            }


            
            
            Hand_sorted = Sort_Hand(Hand_sorted);
            printTable();
            score = score_Hand(Hand_sorted);
            cout<<"\nHand: "<<ScoreTitle[score]<<endl;

        }
        
        
        /*
        cout << "Pick 1-5" << endl;
        cin >> discard_num;
        --discard_num;
        cout << top << endl;
        top--;
        cout << top << endl;
        Hand_sorted[discard_num] = deck.cards[top+1];
        
        Hand_sorted = Sort_Hand(Hand_sorted);
        printTable();
        score = score_Hand(Hand_sorted);
        cout<<"\nHand: "<<ScoreTitle[score]<<endl;
        
        //Win
        goto top_discard;
        */
        cout<<"\nContinue?"<<endl;
        cout<<"Y/N: " << endl;
        cin>>choice;

        
    }while (choice == 'y');
    
    // End Game
}






#endif /* PokerGame_h */
