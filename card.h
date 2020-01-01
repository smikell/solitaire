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

enum struct Suit {None, Spade, Heart, Club, Diamond};
enum struct Rank {None, Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King};

class Card {
public:
    //iterable container of ranks in order
    std::vector<Rank> ranks { Rank::None, Rank::Ace, Rank::Two, Rank::Three, Rank::Four, Rank::Five,
        Rank::Six, Rank::Seven, Rank::Eight, Rank::Nine, Rank::Ten, Rank::Jack, Rank::Queen, Rank::King };
    //default constructor
    Card();
    //custom constructor for suit and rank
    Card(Suit s, Rank r);
    //custom constructor for foundation placeholders
    Card(Suit s, Rank r, bool placeholder);
    //return suit for output
    Suit get_suit();
    //return rank for output
    Rank get_rank();
    //check if turned for output
    bool is_turned();
    //check if in tableau for output
    bool is_in_tableau();
    //check if red suit for moves
    bool is_red();
    //check if black suit for moves
    bool is_black();
    //flip card
    void turn();
    //change when add or remove from tableau
    void change_tableau_status();
    //check if matching suit
    bool match_suit(Card added, Card current);
    //check if opposite suit
    bool opposite_suit(Card added, Card current);
    //check if subsequent rank
    bool next_rank(Card added, Card current);
    //check if previous rank
    bool prev_rank(Card added, Card current);

private:
    Suit suit;
    Rank rank;
    //card faced up
    bool up = false;
    //card in tableau
    bool in = false;
};

//overload for Suit enum to print to screen
std::ostream& operator<<(std::ostream& out, Suit& s);
//overload for Rank enum to print to screen
std::ostream& operator<<(std::ostream& out, Rank& r);
//overload for Card to print to screen
std::ostream& operator<<(std::ostream& out, Card& c);


#endif /* card_h */
