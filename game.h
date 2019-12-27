//
//  game.h
//  solitaire
//
//  Created by Sam Mikell on 12/24/19.
//  Copyright © 2019 Sam Mikell. All rights reserved.
//

#ifndef game_h
#define game_h

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

enum class Suit {Spade, Diamond, Club, Heart};
enum class Value {Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King};

struct Card {
    Suit suit;
    Value value;
    bool up = false;
};

//overload for Suit enum to print to screen
std::ostream& operator<<(std::ostream& out, Suit& s);
//overload for Value enum to print to screen
std::ostream& operator<<(std::ostream& out, Value& v);
//overload for Card to print to screen
std::ostream& operator<<(std::ostream& out, Card& c);

class Game {
public:
    //ctor for Game, resizes members appropriately
    Game() {
        deck.resize(52);
        tableau.resize(7, std::vector<Card>(20));
        foundations.resize(4, std::vector<Card>(13));
    }
    
    //shuffle deck prior to starting game
    void shuffle();
    //deal deck into tableau
    void deal();
    
private:
    std::vector<Card> deck;
    std::vector<std::vector<Card>> tableau;
    std::vector<std::vector<Card>> foundations;
};

#endif /* game_h */
