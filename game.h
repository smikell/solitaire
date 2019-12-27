//
//  game.h
//  solitaire
//
//  Created by Sam Mikell on 12/24/19.
//  Copyright © 2019 Sam Mikell. All rights reserved.
//

#ifndef game_h
#define game_h

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

enum class Suit {Spade, Diamond, Club, Heart};
enum class Value {Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King};

struct Card {
    Suit suit;
    Value value;
};

std::ostream& operator<<(std::ostream& out, Suit& s);
std::ostream& operator<<(std::ostream& out, Value& v);


class Game {
public:
    Game() {
        deck.resize(52);
        tableau.resize(7, std::vector<Card>(20));
        foundations.resize(4, std::vector<Card>(13));
    }
    
    void shuffle() {
        //create iterable containers for suits and values
        std::vector<Suit> suits {Suit::Spade, Suit::Diamond, Suit::Club, Suit::Heart};
        std::vector<Value> values {Value::Ace, Value::Two, Value::Three, Value::Four,
            Value::Five, Value::Six, Value::Seven, Value::Eight, Value::Nine, Value::Ten,
            Value::Jack, Value::Queen, Value::King};
        
        //load deck
        size_t pos = 0;
        for (Suit s : suits) {
            for (Value v : values) {
                deck[pos++] = Card{s, v};
            }
        }
        
        //generate seed from system clock time
        long long seed = std::chrono::system_clock::now().time_since_epoch().count();
        //use seed with mersenne twister to shuffle deck randomly
        std::shuffle(deck.begin(), deck.end(), std::mt19937(static_cast<unsigned>(seed)));
        
        //TEST SHUFFLE
        for (Card c : deck) {
            std::cout << c.suit << c.value << "\n";
        }
    }
    
private:
    std::vector<Card> deck;
    std::vector<std::vector<Card>> tableau;
    std::vector<std::vector<Card>> foundations;
};

#endif /* game_h */
