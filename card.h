//
//  card.h
//  solitaire
//
//  Created by Sam Mikell on 12/30/19.
//  Copyright © 2019 Sam Mikell. All rights reserved.
//

#ifndef card_h
#define card_h

#include <iostream>
#include <vector>

enum struct Suit {None, Heart, Spade, Diamond, Club, Empty};
enum struct Rank {None, Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Empty};

class Card {
public:
    //default constructor
    Card();
    //custom constructor for suit and rank
    Card(Suit s, Rank r);
    //custom constructor for foundation placeholders
    Card(Suit s, Rank r, bool placeholder);
    //return suit for output
    Suit get_suit() const;
    //return rank for output
    Rank get_rank() const;
    //check if turned for output
    bool is_turned() const;
    //check if in tableau for output
    bool is_in_tableau() const;
    //check if red suit for moves
    bool is_red() const;
    //check if black suit for moves
    bool is_black() const;
    //flip card
    void turn();
    //change when add or remove from tableau
    void change_tableau_status();
    //check if added card is matching suit
    bool match_suit(const Card added) const;
    //check if added card is opposite suit
    bool opposite_suit(const Card added) const;
    //check if added card is subsequent rank
    bool next_rank(const Card added) const;
    //check if added card is previous rank
    bool prev_rank(const Card added) const;

private:
    Suit suit;
    Rank rank;
    //card faced up
    bool up = false;
    //card in tableau
    bool in = false;
};

//overload for Suit enum to print to screen
std::ostream& operator<<(std::ostream& out, const Suit& s);
//overload for Rank enum to print to screen
std::ostream& operator<<(std::ostream& out, const Rank& r);
//overload for Card to print to screen
std::ostream& operator<<(std::ostream& out, const Card& c);


#endif /* card_h */
