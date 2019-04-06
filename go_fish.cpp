#include <iostream>
#include "card.h"
#include "player.h"
#include "deck.h"
using namespace std;

int main() {
    srand(unsigned (time(0))); //seed random generator
    int numCards = 7; //2 players
    int switchTurns; //Flag for whether or not to switch turns.

    Player p1("Tyler", 0);
    Player p2("Paige", 1);
    Deck d;
    d.shuffle();
    Player *PlayersTurn;  //create a pointer to the person whose turn it is
    Player *notPlayersTurn; //pointer to person whose turn it isn't
    Card c1;  //cards to populate for checkHandForBook
    Card c2;

    for(int i=0; i<numCards; i++) //deal cards
        p1.addCard(d.dealCard());
    for(int i=0; i<numCards; i++)
        p2.addCard(d.dealCard());

    while((p1.getBookSize() + p2.getBookSize()) < 52) { //game over condition
        if(p1.getTurnId() == 1) { //assign turns
            PlayersTurn = &p1;
            notPlayersTurn = &p2;}
        if(p2.getTurnId() == 1){
            PlayersTurn = &p2;
            notPlayersTurn = &p1;}
        bool Lucky = PlayersTurn->checkHandForBook(c1, c2); //check hand first
        if(Lucky)
            PlayersTurn->bookCards(PlayersTurn->removeCardFromHand(c1), PlayersTurn->removeCardFromHand(c2));
        Card goFish = PlayersTurn->chooseCardFromHand(); //pick a card
        PlayersTurn->askForCard(goFish); //ask for the card
        bool answer = notPlayersTurn->sameRankInHand(goFish); //check if opponent has card
        if(answer){                                    //reply
            notPlayersTurn->answerYes(goFish);
            PlayersTurn->bookCards(PlayersTurn->removeCardFromHand(goFish), notPlayersTurn->removeSameRank(goFish));
            switchTurns = 0;                        //set flag to 0, indicating to repeat the turn for PlayersTurn
        }
        else {
            notPlayersTurn->goFish();         //output "Go Fish"
            switchTurns = 1;                   // set flag to 1, indicating to change turns
        }
        if(switchTurns == 1) {              //if PlayersTurn did not book a pair
            if(d.size() > 0)                          //check if deck is empty
                PlayersTurn->addCard(d.dealCard());     //if not, draw a card. if cards match, wait to book until next turn
            p1.turnID = ((p1.turnID) + 1) % 2; //change turns
            p2.turnID = ((p2.turnID) + 1) % 2;
        }
    }
    if(p1.getBookSize() >= 26)
        p1.Victory();
    else if(p2.getBookSize() > 26)
        p2.Victory();
}
