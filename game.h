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
#include <ctime>

//TODO: can a container of base classes hold derived class objects? or vice versa?

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
    //check if game ended
    bool is_game_over() const;
    //return completion status
    bool is_complete() const;
    //return number of moves
    unsigned get_num_moves() const;
    //return current time
    std::pair<time_t, time_t> get_current_time() const;
    //return user score
    unsigned get_score() const;
    //update user score
    void update_score(bool add);
    //starting banner and introduction
    virtual void game_starting() = 0;
    //ending banner and message
    virtual void game_ending() const = 0;
    
private:
    friend class User;
    const size_t NUM_SUITS = 4;
    const size_t NUM_RANKS = 13;
    const size_t NUM_CARDS = 52;
    const size_t MAX_COLS = 7;
    const size_t MAX_ROWS = 20;
    //unordered set of suit characters to check against input
    const std::unordered_set<char> SUIT_CHECK = {'H', 'S', 'D', 'C'};
    //score multipliers
    const int ADD_SCORE = 10;
    const int REMOVE_SCORE = 15;
    const double TIME_MULTIPLIER = 1.5;
    const double MOVE_MULTIPLIER = 1.5;
    const double TIME_DECREASE = 0.1;
    const double MOVE_DECREASE = 0.1;
    const unsigned TIME_UPDATE = 180;
    const unsigned MOVE_UPDATE = 52;
    //const time_t TIME_LIMIT = 3600;
    //game containers for cards
    std::deque<Card> deck;
    std::vector<std::vector<Card>> tableau;
    std::vector<std::stack<Card>> foundations;
    //print hidden hand alongside flipped card when draw from hand
    bool drawn = false;
    //end game when user wins
    bool game_over = false;
    //statuses for each suit foundation completion
    bool heart, spade, diamond, club = false;
    //track start time to compare for output time
    time_t start_time = 0;
    //number of moves in game
    unsigned num_moves = 0;
    //track score as game progresses
    unsigned score = 0;
};

#endif /* game_h */
