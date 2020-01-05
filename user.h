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

struct UserInput {
    char to, from, to_suit, from_suit = '\0';
    size_t to_row, to_col, from_row, from_col = 0;
};

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
    BadInput(const std::string& error) : InputError() {
        update_msg(error);
    }
};

class InvalidInput : public InputError {
public:
    InvalidInput(const std::string& error) : InputError() {
        update_msg(error);
    }
};

class MoveError : public std::exception {
public:
    MoveError() : msg{"Move Error: "} {}
    std::string error() const {
        return msg;
    }
    MoveError(const std::string& e_msg) : MoveError() {
        update_msg(e_msg);
    }
    void update_msg(std::string add) {
        msg += add;
    }
private:
    std::string msg;
};

class DrawError : public MoveError {
public:
    DrawError(const std::string& error) : MoveError() {
        update_msg(error);
    }
};

class FoundationError : public MoveError {
public:
    FoundationError(const std::string& error) : MoveError() {
        update_msg(error);
    }
};

class TableauError : public MoveError {
public:
    TableauError(const std::string& error) : MoveError() {
        update_msg(error);
    }
};

class User : public Game {
public:
    //default constructor
    User();
    //starting banner and introduction
    void game_starting() override;
    //help message for move format
    void help_message();
    //return user name
    std::string get_name() const;
    //print appropriate message and spaces
    void end_print(const std::string output) const;
    void end_print(const char type) const;
    //ending banner and message
    void game_ending() const override;
    //check suit input validity
    void check_suit(const char input) const;
    //check coords input validity
    void check_coords(size_t& row, size_t& col) const;
    //draw card from hand
    void draw();
    //checks move for validity and calls appropriate move
    void move(UserInput input);
    void move_to_foundation_from_hand(const size_t dest);
    void move_to_foundation_from_tableau(const size_t dest, const std::pair<size_t, size_t> source);
    void move_to_tableau_from_hand(const std::pair<size_t, size_t> dest);
    void move_to_tableau_from_foundation(const std::pair<size_t, size_t> dest, const size_t source);
    void move_to_tableau_from_tableau(const std::pair<size_t, size_t> dest,
                                      const std::pair<size_t, size_t> source);
    
private:
    //user entered name
    std::string name;
};

#endif /* user_h */
