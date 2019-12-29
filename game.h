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
#include <deque>
#include <stack>
#include <algorithm>
#include <random>
#include <chrono>

enum class Suit {None, Spade, Diamond, Club, Heart};
enum class Value {None, Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King};

class Card {
public:
    Card() : suit{Suit::Spade}, value{Value::Ace} {}
    Card(Suit s, Value v) : suit{s}, value{v} {}
    Card(Suit s, Value v, bool placeholder) : Card(s, v) { up = placeholder; }
    Suit suit;
    Value value;
    //card faced up
    bool up = false;
    //card in tableau
    bool in = false;
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
        tableau.resize(20, std::vector<Card>(7));
        foundations.resize(4);
    }
    
    //shuffle deck prior to starting game
    void shuffle();
    //deal deck into tableau
    void deal();
    //print hand, foundations, and tableau to screen
    void print_game();
    
private:
    std::deque<Card> deck;
    std::vector<std::vector<Card>> tableau;
    std::vector<std::stack<Card>> foundations;
    //print hidden hand alongside flipped card when player draws
    bool drawn = false;
};

#endif /* game_h */
