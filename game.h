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
#include <unordered_map>

class Game {
public:
    //ctor for Game, resizes members appropriately
    Game() {
        deck.resize(NUM_CARDS);
        tableau.resize(MAX_ROWS, std::vector<Card>(MAX_COLS));
        foundations.resize(NUM_SUITS);
    }
    
    //shuffle deck prior to starting game
    void shuffle();
    //deal deck into tableau
    void deal();
    //print hand, foundations, and tableau to screen
    void print_game() const;
    //return number of moves
    unsigned get_num_moves() const;
    //draw card from hand
    virtual void draw() = 0;
    //MOVE FUNCTION THAT USES BRANCHES TO CHECK <TO> <FROM> VALIDITY
    //move card to foundation
    virtual void move_foundation(const char dest_suit, const char move_from,
                                 const std::pair<size_t, size_t> move_coords={0,0}) = 0;
    //move card to or within tableau
    virtual void move_tableau(const std::pair<size_t, size_t> dest_coords,
                              const char move_from, const std::pair<size_t, size_t> move_coords={0,0}) = 0;
    
private:
    friend class User;
    const size_t NUM_SUITS = 4;
    const size_t NUM_RANKS = 13;
    const size_t NUM_CARDS = 52;
    const size_t MAX_COLS = 7;
    const size_t MAX_ROWS = 19;
    //unordered set of suit characters to check against input
    const std::unordered_set<char> SUIT_CHECK = {'H', 'S', 'D', 'C'};
    //game containers for cards
    std::deque<Card> deck;
    std::vector<std::vector<Card>> tableau;
    std::vector<std::stack<Card>> foundations;
    //print hidden hand alongside flipped card when draw from hand
    bool drawn = false;
    //number of moves in game
    unsigned num_moves = 0;
};

#endif /* game_h */
