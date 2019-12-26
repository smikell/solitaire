//
//  game.cpp
//  solitaire
//
//  Created by Sam Mikell on 12/24/19.
//  Copyright © 2019 Sam Mikell. All rights reserved.
//

#include "game.h"

std::ostream& operator<<(std::ostream& out, Suit& s) {
    if (s == Suit::Spade) {
        out << 'S';
    }
    else if (s == Suit::Diamond) {
        out << 'D';
    }
    else if (s == Suit::Club) {
        out << 'C';
    }
    else if (s == Suit::Heart) {
        out << 'H';
    }
    return out;
}

std::ostream& operator<<(std::ostream& out, Value& v) {
    if (v == Value::Ace) {
        out << 'A';
    }
    else if (v == Value::Two) {
        out << 2;
    }
    else if (v == Value::Three) {
        out << 3;
    }
    else if (v == Value::Four) {
        out << 4;
    }
    else if (v == Value::Five) {
        out << 5;
    }
    else if (v == Value::Six) {
        out << 6;
    }
    else if (v == Value::Seven) {
        out << 7;
    }
    else if (v == Value::Eight) {
        out << 8;
    }
    else if (v == Value::Nine) {
        out << 9;
    }
    else if (v == Value::Ten) {
        out << 10;
    }
    else if (v == Value::Jack) {
        out << 'J';
    }
    else if (v == Value::Queen) {
        out << 'Q';
    }
    else if (v == Value::King) {
        out << 'K';
    }
    return out;
}
