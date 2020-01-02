//
//  game.h
//  solitaire
//
//  Created by Sam Mikell on 12/24/19.
//  Copyright © 2019 Sam Mikell. All rights reserved.
//

#ifndef game_h
#define game_h

#include "card.h"
#include <deque>
#include <stack>
#include <algorithm>
#include <random>
#include <chrono>
#include <unordered_set>

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
    void print_game() const;
    
    //draw card from hand
    virtual void draw() = 0;
    //move card to foundation
    //virtual void move_foundation() = 0;
    //move card to or within tableau
    //virtual void move_tableau() = 0;
    
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
    const size_t MAX_COLS = 7;
    const size_t MAX_ROWS = 20;
    //unordered set of suit characters to check against input
    const std::unordered_set<char> SUIT_CHECK = {'H', 'S', 'D', 'C'};
    std::deque<Card> deck;
    std::vector<std::vector<Card>> tableau;
    std::vector<std::stack<Card>> foundations;
    unsigned num_moves = 0;
    //print hidden hand alongside flipped card when draw from hand
    bool drawn = false;
};

#endif /* game_h */
