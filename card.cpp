//
//  card.cpp
//  solitaire
//
//  Created by Sam Mikell on 12/30/19.
//  Copyright © 2019 Sam Mikell. All rights reserved.
//

#include "card.h"

//MODIFIES: suit and rank of constructed Card
//EFFECTS: Default Ctor for Card object
Card::Card() : suit{Suit::None}, rank{Rank::None} {}

//MODIFIED: suit and rank of constructed Card
//EFFECTS: Custom Ctor for Card object, calls default, turns and/or sets tableau status
//         depending on input suit and rank (foundation or empty placeholder)
Card::Card(Suit s, Rank r) : suit{s}, rank{r} {
    //if foundation placeholder, turn card
    if (suit != Suit::None && rank == Rank::None) {
        turn();
    }
    //if empty placeholder for tableau, turn card and mark in
    if (suit == Suit::Empty && rank == Rank::Empty) {
        turn();
        change_tableau_status();
    }
}

//EFFECTS: returns Card object's suit
Suit Card::get_suit() const {
    return suit;
}

//EFFECTS: returns Card object's rank
Rank Card::get_rank() const {
    return rank;
}

//EFFECTS: returns true if Card is face up
bool Card::is_turned() const {
    return up;
}

//EFFECTS: returns true if Card is in tableau
bool Card::is_in_tableau() const {
    return in;
}

//EFFECTS: returns true if Card is a red suit
bool Card::is_red() const {
    //OR Empty is meant for case where king is added to empty tableau position
    return get_suit() == Suit::Heart || get_suit() == Suit::Diamond || get_suit() == Suit::Empty;
}

//EFFECTS: returns true if Card is a black suit
bool Card::is_black() const {
    //OR Empty is meant for case where king is added to empty tableau position
    return get_suit() == Suit::Spade || get_suit() == Suit::Club || get_suit() == Suit::Empty;
}

//MODIFIES: up member of Card
//EFFECTS: changes faced up status to opposite
void Card::turn() {
    if (is_turned()) up = false;
    else up = true;
}

//MODIFIES: in member of Card
//EFFECTS: changes in tableau status to opposite
void Card::change_tableau_status() {
    if (is_in_tableau()) in = false;
    else in = true;
}

//EFFECTS: returns true if added Card's suit matches current Card's suit
bool Card::match_suit(const Card& added) const {
    if (added.get_suit() == get_suit()) {
        return true;
    }
    return false;
}

//EFFECTS: returns true if added Card's suit is opposite of current Card's suit
bool Card::opposite_suit(const Card& added) const {
    if ((added.is_red() && is_black()) || (added.is_black() && is_red())) {
        return true;
    }
    return false;
}

//EFFECTS: returns true if added Card's rank is succeeding rank of current Card's rank
bool Card::next_rank(const Card& added) const {
    //create iterable container of ranks in order
    std::vector<Rank> ranks { Rank::None, Rank::Ace, Rank::Two, Rank::Three, Rank::Four, Rank::Five, Rank::Six,
        Rank::Seven, Rank::Eight, Rank::Nine, Rank::Ten, Rank::Jack, Rank::Queen, Rank::King, Rank::Empty };
    //search through vector for current, check if added's rank is next index
    for (size_t i = 0; i < ranks.size() - 1; ++i) {
        if (get_rank() == ranks[i] && added.get_rank() == ranks[i + 1]) {
            return true;
        }
    }
    return false;
}

//EFFECTS: returns true if added Card's rank is preceding rank of current Card's rank
bool Card::prev_rank(const Card& added) const {
    //create iterable container of ranks in order
    std::vector<Rank> ranks { Rank::None, Rank::Ace, Rank::Two, Rank::Three, Rank::Four, Rank::Five, Rank::Six,
        Rank::Seven, Rank::Eight, Rank::Nine, Rank::Ten, Rank::Jack, Rank::Queen, Rank::King, Rank::Empty };
    //search through vector for current, check if added's rank is previous index
    for (size_t i = 1; i < ranks.size(); ++i) {
        if (get_rank() == ranks[i] && added.get_rank() == ranks[i - 1]) {
            return true;
        }
    }
    return false;
}

//EFFECTS: prints associated char for passed Suit
std::ostream& operator<<(std::ostream& out, const Suit& s) {
    if (s == Suit::Heart) {
        out << 'H';
    }
    else if (s == Suit::Spade) {
        out << 'S';
    }
    else if (s == Suit::Diamond) {
        out << 'D';
    }
    else if (s == Suit::Club) {
        out << 'C';
    }
    else if (s == Suit::Empty) {
        out << 'E';
    }
    else {
        out << ' ';
    }
    return out;
}

//EFFECTS: prints associated char for passed Rank
std::ostream& operator<<(std::ostream& out, const Rank& r) {
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

//EFFECTS: prints Card suit and rank chars if Card is face up or ** if not face up
std::ostream& operator<<(std::ostream& out, const Card& c) {
    if (!c.is_turned()) out << "**";
    else {
        //TODO: dont know why need to do this and can't directly print getter results
        Suit s = c.get_suit();
        Rank r = c.get_rank();
        out << s << r;
    }
    return out;
}
