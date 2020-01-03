//
//  user.h
//  solitaire
//
//  Created by Sam Mikell on 12/28/19.
//  Copyright © 2019 Sam Mikell. All rights reserved.
//

#ifndef user_h
#define user_h

#include "game.h"
#include <string>

class InputError : public std::exception {
public:
    InputError() : msg{"Input Error: "} {}
    std::string error() const {
        return msg;
    }
    void update_msg(std::string add) {
        msg += add;
    }
private:
    std::string msg;
};

class BadInput : public InputError {
public:
    BadInput(const std::string& error) {
        update_msg(error);
    }
};

class InvalidInput : public InputError {
public:
    InvalidInput(const std::string& error) {
        update_msg(error);
    }
};

class MoveError : public std::exception {
public:
    MoveError() : msg{"Move Error: "} {}
    std::string error() const {
        return msg;
    }
    void update_msg(std::string add) {
        msg += add;
    }
private:
    std::string msg;
};

class DrawError : public MoveError {
public:
    DrawError(const std::string& error) {
        update_msg(error);
    }
};

//foundaiton error

//tableau error

class User : public Game {
public:
    //default constructor
    User();
    //starting banner and introduction
    void game_starting();
    //check if game ended
    bool is_game_over() const;
    //return user name
    std::string get_name() const;
    //set user score
    void set_score();
    //return user score
    unsigned get_score() const;
    //return completion status
    bool is_complete() const;
    //print appropriate message and spaces
    void end_print(const std::string output) const;
    void end_print(const char type) const;
    //ending banner and message
    void game_ending() const;
    //check suit input validity
    void check_suit(const char input) const;
    //check coords input validity
    void check_coords(const size_t row, const size_t col) const;
    //draw card from hand
    void draw() override;
    
    //move card to foundation
    //dest is destination suit
    //move is tableau or hand
    //optional pair of coordinates
    void move_foundation(const char dest, const char move,
                         const std::pair<size_t, size_t> move_coords={0,0}) override;
    
    //move card to or within tableau
    //move is tableau or hand
    //optional pair of coordinates
    void move_tableau(const char dest, const std::pair<size_t, size_t> dest_coords,
                      const char move, const std::pair<size_t, size_t> move_coords={0,0}) override;
    
private:
    //track user score as game progresses
    unsigned score = 0;
    //user entered name
    std::string name;
    //statuses for each suit foundation completion
    bool heart, spade, diamond, club = false;
    //end game when user wins
    bool game_over = false;
    //when move multiple cards, loop through from that row to bottom (if statement to check if up, then move below other)
};

#endif /* user_h */
