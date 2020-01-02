//
//  user.cpp
//  solitaire
//
//  Created by Sam Mikell on 12/28/19.
//  Copyright © 2019 Sam Mikell. All rights reserved.
//

#include "user.h"

//check suit input validity
bool User::check_suit(char input) const {
    if (SUIT_CHECK.find(input) != SUIT_CHECK.end()) {
        return true;
    }
    return false;
}

//draw card from hand
void User::draw() {
    //if no more cards to draw, throw error
    if (deck.empty()) {
        //TODO: error
    }
    
    //if card already drawn
    if (drawn) {
        //turn over current card
        deck.front().turn();
        //move to back
        deck.push_back(deck.front());
        //remove from front
        deck.pop_front();
    }
    //flip front card
    deck.front().turn();
    //set drawn status
    drawn = true;
    ++num_moves;
    print_game();
}

//move card to foundation
void User::move_foundation(char dest, char move,
                           std::pair<size_t, size_t> move_coords) {
    //TODO: Handle Dest errors in main
    //TODO: error check for proper suit, proper coordinates if passed (move is T)
    //TODO: error check for moves based on dest and source
    //TODO: error check: invalid move
        //if source is tableau, check if coordinates
    
    //move from tableau
    if (move == 'T') {
        //error check for proper coordinates (within bounds)
        //error check for proper coordinates (card is up && in)
        //error check for proper coordinates (next row down is not up && not in)
        //check move card is match suit for dest card
        
    }
    //move from hand
    else if (move == 'H'){
        
    }
    //otherwise invalid move input
    else {
        
    }
    
    //check move card is match suit for dest card
    //check move card is next rank for dest card
    //remove move card from old position
    //incrememnt num moves
    //update score
}

//move card to or within tableau
void User::move_tableau(char dest, std::pair<size_t, size_t> dest_coords,
                        char move, std::pair<size_t, size_t> move_coords) {
    //TODO: error checks
    
    
    //check move card is opposite suit for dest card
    //check move card is prev rank for dest card
    //remove card from old position
    //increment num moves
    //update score
}

//move card from hand to foundation
void User::move_hand_to_foundation(char suit) {
    //if not turned, error (can only move a turned card from hand)
    //if (!drawn) int exception; //thorw exception
    //take front of deck, move to specified foundation
    
    //increment num moves
    //update score
    //check that card moved matches the suit and is in correct order
    //otherwise throw error
    //move error, suit error, value error
}
//move card from hand to tableau
void User::move_hand_to_tableau() {
    //check that opposite suit and less by one than previous card
}
//move card from tableau to foundation
void User::move_tableau_to_foundation() {
    
}
//move card from foundation to tableau
void User::move_foundation_to_tableau() {
    
}
//move card within tableau columns
void User::move_in_tableau() {
    
}
