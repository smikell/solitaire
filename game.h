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
#include <cstdlib>

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
        //for 4 iterations, going through each suit
            //map by takking the suit + value * 7 % 52
            //map the ace
            //loop through and map 2 through 10
            //map the jack, queen, and king
            //update suit to be mapped
        
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
        
        for (int i = 0; i < 4; ++i) {
            
            /*
            shuffler.insert(Card{suits[i], 'A'});
            
            shuffler.insert(Card{suits[i], '2'});
            shuffler.insert(Card{suits[i], '3'});
            shuffler.insert(Card{suits[i], '4'});
            shuffler.insert(Card{suits[i], '5'});
            shuffler.insert(Card{suits[i], '6'});
            shuffler.insert(Card{suits[i], '7'});
            shuffler.insert(Card{suits[i], '8'});
            shuffler.insert(Card{suits[i], '9'});
            shuffler.insert(Card{suits[i], '1'});
            
            for (char v = '1'; v < '9'; ++v) {
                shuffler.insert(Card{suits[i], v});
            }
            shuffler.insert(Card{suits[i], 'J'});
            shuffler.insert(Card{suits[i], 'Q'});
            shuffler.insert(Card{suits[i], 'K'});
            */
            /*
            //map ace
            int ace_bucket = ((suits[i] + 'A') * 7) % 52;
            deck[ace_bucket] = Card{ suits[i], 'A' };
            //loop through to map 2 through 10
            for (int v = 2; v < 11; ++v) {
                int card_bucket = ((suits[i] + v) * 7) % 52;
                deck[card_bucket] = Card{ suits[i], static_cast<char>(v) };
            }
            //map jack, queen, king
            int jack_bucket = ((suits[i] + 'J') * 7) % 52;
            int queen_bucket = ((suits[i] + 'Q') * 7) % 52;
            int king_bucket = ((suits[i] + 'K') * 7) % 52;
            deck[jack_bucket] = Card{ suits[i], 'J' };
            deck[queen_bucket] = Card{ suits[i], 'Q' };
            deck[king_bucket] = Card{ suits[i], 'K' };
            */
            
        }
        
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
