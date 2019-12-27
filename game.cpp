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
    else if (s == Suit::Diamond) {
        out << 'D';
    }
    else if (s == Suit::Club) {
        out << 'C';
    }
    else if (s == Suit::Heart) {
        out << 'H';
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
    return out;
}

//overload for Card to print to screen
std::ostream& operator<<(std::ostream& out, Card& c) {
    out << c.suit << c.value;
    return out;
}

//shuffle deck prior to starting game
void Game::shuffle() {
    //create iterable containers for suits and values
    std::vector<Suit> suits {Suit::Spade, Suit::Diamond, Suit::Club, Suit::Heart};
    std::vector<Value> values {Value::Ace, Value::Two, Value::Three, Value::Four,
        Value::Five, Value::Six, Value::Seven, Value::Eight, Value::Nine, Value::Ten,
        Value::Jack, Value::Queen, Value::King};
    
    //load deck
    size_t pos = 0;
    for (Suit s : suits) {
        for (Value v : values) {
            deck[pos++] = Card{s, v};
        }
    }
    
    //generate seed from system clock time
    long long seed = std::chrono::system_clock::now().time_since_epoch().count();
    //use seed with mersenne twister to shuffle deck randomly
    std::shuffle(deck.begin(), deck.end(), std::mt19937(static_cast<unsigned>(seed)));
}

//deal deck into tableau
void Game::deal() {
    
    //TEST TABLAEU LAYOUT
    
    //for each column
    for (size_t c = 0; c < 7; ++c) {
        //add proper number of cards
        for (size_t r = 0; r < c; ++r) {
            
        }
        //last card gets turned then added
        
    }
}
