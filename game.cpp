//
//  game.cpp
//  solitaire
//
//  Created by Sam Mikell on 12/24/19.
//  Copyright © 2019 Sam Mikell. All rights reserved.
//

#include "game.h"

//overload for Suit enum to print to screen
std::ostream& operator<<(std::ostream& out, Suit& s) {
    if (s == Suit::Spade) {
        out << 'S';
    }
    else if (s == Suit::Heart) {
        out << 'H';
    }
    else if (s == Suit::Club) {
        out << 'C';
    }
    else if (s == Suit::Diamond) {
        out << 'D';
    }
    else {
        out << ' ';
    }
    return out;
}

//overload for Value enum to print to screen
std::ostream& operator<<(std::ostream& out, Value& v) {
    if (v == Value::Ace) {
        out << 'A';
    }
    else if (v == Value::Two) {
        out << 2;
    }
    else if (v == Value::Three) {
        out << 3;
    }
    else if (v == Value::Four) {
        out << 4;
    }
    else if (v == Value::Five) {
        out << 5;
    }
    else if (v == Value::Six) {
        out << 6;
    }
    else if (v == Value::Seven) {
        out << 7;
    }
    else if (v == Value::Eight) {
        out << 8;
    }
    else if (v == Value::Nine) {
        out << 9;
    }
    else if (v == Value::Ten) {
        out << 10;
    }
    else if (v == Value::Jack) {
        out << 'J';
    }
    else if (v == Value::Queen) {
        out << 'Q';
    }
    else if (v == Value::King) {
        out << 'K';
    }
    else {
        out << ' ';
    }
    return out;
}

//overload for Card to print to screen
std::ostream& operator<<(std::ostream& out, Card& c) {
    if (!c.up) out << "**";
    else out << c.suit << c.value;
    return out;
}

//shuffle deck prior to starting game
void Game::shuffle() {
    //create iterable containers for suits and values
    std::vector<Suit> suits {Suit::Spade, Suit::Heart, Suit::Club, Suit::Diamond};
    std::vector<Value> values {Value::Ace, Value::Two, Value::Three, Value::Four,
        Value::Five, Value::Six, Value::Seven, Value::Eight, Value::Nine, Value::Ten,
        Value::Jack, Value::Queen, Value::King};
    //load foundation placeholders
    size_t suit = 0;
    for (std::stack<Card>& pile : foundations) {
        pile.push(Card(suits[suit++], Value::None, true));
    }
    //load deck
    size_t pos = 0;
    for (Suit s : suits) {
        for (Value v : values) {
            deck[pos++] = Card(s, v);
        }
    }
    //generate seed from system clock time
    long long seed = std::chrono::system_clock::now().time_since_epoch().count();
    //use seed with mersenne twister to shuffle deck randomly
    std::shuffle(deck.begin(), deck.end(), std::mt19937(static_cast<unsigned>(seed)));
}

//deal deck into tableau
void Game::deal() {
    //deck index
    size_t pos = 0;
    //for each column
    for (size_t c = 0; c < 7; ++c) {
        //add proper number of cards
        for (size_t r = 0; r < c; ++r) {
            //add card
            tableau[r][c] = deck[pos++];
            //mark card as in tableau
            tableau[r][c].in = true;
        }
        //last card gets added then turned
        tableau[c][c] = deck[pos++];
        tableau[c][c].up = true;
        //mark card as in tableau
        tableau[c][c].in = true;
    }
    print_game();
}

//print hand, foundations, and tableau to screen
void Game::print_game() {
    //print hand
    if(drawn) {
        std::cout << deck[1] << " " << deck.front() << "    ";
    }
    else {
        std::cout << deck.front() << "       ";
    }
    //print foundations
    for (std::stack<Card> pile : foundations) {
        std::cout << pile.top() << " ";
    }
    std::cout << "\n\n";
    std::cout << "1  2  3  4  5  6  7  \n";
    //print tableau
    unsigned row_num = 0;
    for (std::vector<Card> row : tableau) {
        //stops printing blank cards after whole row of blanks printed
        unsigned blanks = 0;
        for (Card c : row) {
            if (c.in) {
                std::cout << c << " ";
            }
            else {
                std::cout << "   ";
                ++blanks;
            }
        }
        //at most 7 cards in row
        if (blanks == 7) {
            std::cout << "\n";
            break;
        }
        std::cout << " " << ++row_num;
        std::cout << "\n";
    }
}

//when move cards, decrease each card's sub column by the sub col moved in the old
//increase each card's sub column by the sub col moved in the new
