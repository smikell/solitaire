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
    //MODIFIES: deck, tableau, and foundations containers
    //EFFECTS: Default Ctor, modified containers are resized according to const members
    User();
    
    //MODIFIES: user name, starting time
    //EFFECTS: prints starting message, prompts/receives user name, saves starting time
    void game_starting() override;
    
    //EFFECTS: prints help message for valid moves, reprints game layout
    void help_message();
    
    //EFFECTS: returns user entered name
    std::string get_name() const;
    
    //EFFECTS: prints ending message for user depending on if complete or quit
    void end_print(const std::string output) const;
    
    //EFFECTS: prints score or move stats for user
    void end_print(const char type) const;
    
    //EFFECTS: prints final time for user
    void end_print(const std::pair<time_t, time_t> time) const;
    
    //EFFECTS: prints ending message and calls necessary print helpers
    void game_ending() const override;
    
    //EFFECTS: checks user input for valid suit or throws exception
    void check_suit(const char input) const;
    
    //EFFECTS: checks user input for valid coordinates or throws exception
    void check_coords(size_t& row, size_t& col) const;
    
    //MODIFIES: deck, drawn status
    //EFFECTS: pop and push front if already drawn, turns card at front of deck, reprint game
    //         for user, throw exception if drawn errors
    void draw();
    
    //REQUIRES: user input at this point is valid syntactically
    //MODIFIES: game containers, score, num_moves
    //EFFECTS: call matching user move function, throw error if necessary, update score if
    //         move involves foundation, incremement num_moves, print game to user
    void move(UserInput input);
    
    //REQUIRES: dest is a valid suit
    //MODIFIES: deck, foundations, drawn status
    //EFFECTS: moves front card to proper foundation, removes card from deck
    //         or throws relevant error beforehand
    void move_to_foundation_from_hand(const size_t dest);
    
    //REQUIRES: dest is valid suit, source is valid row,col coordinates in tableau
    //MODIFIES: tableau, moved card, foundations
    //EFFECTS: removes card from tableau, adds to proper foundation, adjusts column by either
    //         leaving empty placeholder or turning previous card, or throws relevant error beforehand
    void move_to_foundation_from_tableau(const size_t dest, const std::pair<size_t, size_t> source);
    
    //REQUIRES: dest is valid row,col coordinates in tableau
    //MODIFIES: deck, moved card, tableau
    //EFFECTS: adds card to appropriate position in column depending on if rank King and
    //         change tableau status to mark in, then remove from deck, or throw relevant error beforehand
    void move_to_tableau_from_hand(const std::pair<size_t, size_t> dest);
    
    //REQUIRES: dest is valid row,col coordinates in tableau, source is valid suit
    //MODIFIES: foundations, moved card, tableau
    //EFFECTS: adds card to appropriate position in column depending on if rank King and
    //         change tableau status to mark in, then pop from foundation, or throw relevant error beforehand
    void move_to_tableau_from_foundation(const std::pair<size_t, size_t> dest, const size_t source);
    
    //REQUIRES: dest and source are valid row,col coordinates in tableau
    //MODIFIES: tableau
    //EFFECTS: loop through all cards in source col from source row down to one card below
    //         dest row OR dest row if rank is Empty in dest col, replace with Empty
    //         placeholder if card taken from row 0 otherwise turn card in prev row in col (source)
    //         or throw relevant error
    void move_to_tableau_from_tableau(const std::pair<size_t, size_t> dest,
                                      const std::pair<size_t, size_t> source);
    
private:
    //user entered name
    std::string name;
};

#endif /* user_h */
