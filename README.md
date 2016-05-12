#poker game in C++

Programming Assignment I did for my Software Engineering class. This Assignment was just a warm up to the project. I got a 100%
on this assignment.



In your preferred programming language, create a partial implementation of the Poker game discussed in class on January 22nd.
In this implementation, there is no need for a graphical UI or additional players beyond the first. Your program must contain 
the following:

For 80% of programming grade
* A representation of all 52 legal playing cards [2-10, Jack, Queen, King, Ace of Clubs, Diamonds, Hearts, and Spades].

* A deck containing all 52 cards. The deck must be able to deal it's current top card. Dealing this card removes it from the 
deck. The deck must also be able to shuffle, shuffling the deck first refills the deck, and then randomizes the order of the 
cards within.

* A game which references a single deck of cards, from which a 5 card hand is dealt to the player. The game will output to the
screen the player's current hand. The game will notify the player of the score of that hand, and prompt them if they wish to 
play again. If yes, the deck is shuffled and a new hand dealt. If no, the program terminates 

* You may implement a Player class containing the current hand if you wish. As this assignment requires only a single player, 
the player functionality may be folded into the Game class.

For 100% of programming grade
*After notifying the player of the current score of their hand, ask if they wish to discard any card(s) from their hand.
If so, the player will indicate which cards they wish to discard. Those cards indicated will be removed from the player's 
hand, and new cards will be dealt from the deck into their hand. The game will then score the new hand, and query the player
if they wish to play again, as above.
