#include "deck.h"

Deck::Deck(){
    Card myCards[SIZE] = {
            Card(1, Card::spades),
            Card(2, Card::spades),
            Card(3, Card::spades),
            Card(4, Card::spades),
            Card(5, Card::spades),
            Card(6, Card::spades),
            Card(7, Card::spades),
            Card(8, Card::spades),
            Card(9, Card::spades),
            Card(10, Card::spades),
            Card(11, Card::spades),
            Card(12, Card::spades),
            Card(13, Card::spades),
            Card(1, Card::hearts),
            Card(2, Card::hearts),
            Card(3, Card::hearts),
            Card(4, Card::hearts),
            Card(5, Card::hearts),
            Card(6, Card::hearts),
            Card(7, Card::hearts),
            Card(8, Card::hearts),
            Card(9, Card::hearts),
            Card(10, Card::hearts),
            Card(11, Card::hearts),
            Card(12, Card::hearts),
            Card(13, Card::hearts),
            Card(1, Card::diamonds),
            Card(2, Card::diamonds),
            Card(3, Card::diamonds),
            Card(4, Card::diamonds),
            Card(5, Card::diamonds),
            Card(6, Card::diamonds),
            Card(7, Card::diamonds),
            Card(8, Card::diamonds),
            Card(9, Card::diamonds),
            Card(10, Card::diamonds),
            Card(11, Card::diamonds),
            Card(12, Card::diamonds),
            Card(13, Card::diamonds),
            Card(1, Card:: clubs),
            Card(2, Card:: clubs),
            Card(3, Card:: clubs),
            Card(4, Card:: clubs),
            Card(5, Card:: clubs),
            Card(6, Card:: clubs),
            Card(7, Card:: clubs),
            Card(8, Card:: clubs),
            Card(9, Card:: clubs),
            Card(10, Card:: clubs),
            Card(11, Card:: clubs),
            Card(12, Card:: clubs),
            Card(13, Card:: clubs),
    };
    myIndex = 0;
}

void Deck::shuffle(){

}

Card Deck::dealCard(){

}

int Deck::size() const {

}