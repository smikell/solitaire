//
//  user.cpp
//  solitaire
//
//  Created by Sam Mikell on 12/28/19.
//  Copyright © 2019 Sam Mikell. All rights reserved.
//

#include "user.h"

//draw card from hand
void User::draw() {
    //if card already drawn
    if (drawn) {
        //turn over current card
        deck.front().up = false;
        //move to back
        deck.push_back(deck.front());
        //remove from front
        deck.pop_front();
    }
    //flip front card
    deck.front().up = true;
    //set drawn status
    drawn = true;
    ++num_moves;
    print_game();
}
//move card from hand to foundation
void User::move_hand_to_foundation(char suit) {
    //if not turned, error (can only move a turned card from hand)
    if (!drawn) int exception; //thorw exception
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
