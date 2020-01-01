//
//  card.cpp
//  solitaire
//
//  Created by Sam Mikell on 12/30/19.
//  Copyright © 2019 Sam Mikell. All rights reserved.
//

#include "card.h"

//default constructor
Card::Card() : suit{Suit::Spade}, rank{Rank::Ace} {}

//custom constructor for suit and rank
Card::Card(Suit s, Rank r) : suit{s}, rank{r} {}

//custom constructor for foundation placeholders
Card::Card(Suit s, Rank r, bool placeholder) : Card(s, r) {
    up = placeholder;
}

//return suit for output
Suit Card::get_suit() {
    return suit;
}

//return rank for output
Rank Card::get_rank() {
    return rank;
}

//check if turned for output
bool Card::is_turned() {
    return up;
}

//check if in tableau for output
bool Card::is_in_tableau() {
    return in;
}

//check if red suit for moves
bool Card::is_red() {
    return suit == Suit::Heart || suit == Suit::Diamond;
}

//check if black suit for moves
bool Card::is_black() {
    return suit == Suit::Spade || suit == Suit::Club;
}

//flip card
void Card::turn() {
    if (up) up = false;
    else up = true;
}

//check if matching suit
bool Card::match_suit(Card added, Card current) {
    if (added.suit == current.suit) {
        return true;
    }
    return false;
}

//check if opposite suit
bool Card::opposite_suit(Card added, Card current) {
    if ((added.is_red() && current.is_black()) || (added.is_black() && current.is_red())) {
        return true;
    }
    return false;
}

//check if subsequent rank
bool Card::next_rank(Card added, Card current) {
    //TODO: EDGE CASES: adding to a king, adding the king itself, adding ace to none
    //search through vector for current, check if added's rank is next index
    for (size_t i = 0; i < ranks.size() - 1; ++i) {
        if (current.get_rank() == ranks[i] && added.get_rank() == ranks[i + 1]) {
            return true;
        }
    }
    return false;
}

//check if previous rank
bool Card::prev_rank(Card added, Card current) {
    //TODO: EDGE CASES: adding to a king, adding an ace to a two, adding to an ace
    //search through vector for current, check if added's rank is previous index
    for (size_t i = 1; i < ranks.size(); ++i) {
        if (current.get_rank() == ranks[i] && added.get_rank() == ranks[i - 1]) {
            return true;
        }
    }
    return false;
}

//overload for Suit enum to print to screen
std::ostream& operator<<(std::ostream& out, Suit& s) {
    if (s == Suit::Spade) {
        out << 'S';
    }
    else if (s == Suit::Heart) {
        out << 'H';
    }
    else if (s == Suit::Club) {
        out << 'C';
    }
    else if (s == Suit::Diamond) {
        out << 'D';
    }
    else {
        out << ' ';
    }
    return out;
}

//overload for Rank enum to print to screen
std::ostream& operator<<(std::ostream& out, Rank& r) {
    if (r == Rank::Ace) {
        out << 'A';
    }
    else if (r == Rank::Two) {
        out << 2;
    }
    else if (r == Rank::Three) {
        out << 3;
    }
    else if (r == Rank::Four) {
        out << 4;
    }
    else if (r == Rank::Five) {
        out << 5;
    }
    else if (r == Rank::Six) {
        out << 6;
    }
    else if (r == Rank::Seven) {
        out << 7;
    }
    else if (r == Rank::Eight) {
        out << 8;
    }
    else if (r == Rank::Nine) {
        out << 9;
    }
    else if (r == Rank::Ten) {
        out << 10;
    }
    else if (r == Rank::Jack) {
        out << 'J';
    }
    else if (r == Rank::Queen) {
        out << 'Q';
    }
    else if (r == Rank::King) {
        out << 'K';
    }
    else {
        out << ' ';
    }
    return out;
}

//overload for Card to print to screen
std::ostream& operator<<(std::ostream& out, Card& c) {
    if (!c.is_turned()) out << "**";
    else {
        //TODO: dont know why need to do this
        Suit s = c.get_suit();
        Rank r = c.get_rank();
        out << s << r;
    }
    return out;
}
