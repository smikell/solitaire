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

enum class Suit {None, Spade, Heart, Club, Diamond};
enum class Value {None, Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King};

struct Card {
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

//turn card function
//get suit and get rank
//check if matching suit
//check if opposite suit
//check if less

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
    //draw card from hand
    virtual void draw() = 0;
    //move card from hand to foundation
    virtual void move_hand_to_foundation(char suit) = 0;
    //move card from hand to tableau
    virtual void move_hand_to_tableau() = 0;
    //move card from tableau to foundation
    virtual void move_tableau_to_foundation() = 0;
    //move card from foundation to tableau
    virtual void move_foundation_to_tableau() = 0;
    //move card within tableau columns
    virtual void move_in_tableau() = 0;
    
private:
    friend class User;
    std::deque<Card> deck;
    std::vector<std::vector<Card>> tableau;
    std::vector<std::stack<Card>> foundations;
    unsigned num_moves = 0;
    //print hidden hand alongside flipped card when draw from hand
    bool drawn = false;
};

#endif /* game_h */
