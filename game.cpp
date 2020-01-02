//
//  game.cpp
//  solitaire
//
//  Created by Sam Mikell on 12/24/19.
//  Copyright © 2019 Sam Mikell. All rights reserved.
//

#include "game.h"

//shuffle deck prior to starting game
void Game::shuffle() {
    //create iterable containers for suits and ranks
    std::vector<Suit> suits {Suit::Heart, Suit::Spade, Suit::Diamond, Suit::Club};
    std::vector<Rank> ranks { Rank::Ace, Rank::Two, Rank::Three, Rank::Four, Rank::Five,
        Rank::Six, Rank::Seven, Rank::Eight, Rank::Nine, Rank::Ten, Rank::Jack, Rank::Queen, Rank::King };
    //load foundation placeholders
    size_t suit = 0;
    for (std::stack<Card>& pile : foundations) {
        pile.push(Card(suits[suit++], Rank::None, true));
    }
    //load deck
    size_t pos = 0;
    for (Suit s : suits) {
        for (Rank r : ranks) {
            deck[pos++] = Card(s, r);
        }
    }
    //generate seed from system clock time
    long long seed = std::chrono::system_clock::now().time_since_epoch().count();
    //use seed with mersenne twister to shuffle deck randomly
    std::shuffle(deck.begin(), deck.end(), std::mt19937(static_cast<unsigned>(seed)));
}

//deal deck into tableau
void Game::deal() {
    //deck index
    size_t pos = 0;
    //for each column
    for (size_t c = 0; c < 7; ++c) {
        //add proper number of cards
        for (size_t r = 0; r < c; ++r) {
            //add card
            tableau[r][c] = deck[pos];
            //remove from deck
            deck.erase(deck.begin() + pos);
            //mark card as in tableau
            tableau[r][c].change_tableau_status();
            //next position
            ++pos;
        }
        //last card added
        tableau[c][c] = deck[pos];
        //remove from deck
        deck.erase(deck.begin() + pos);
        //turn last card
        tableau[c][c].turn();
        //mark card as in tableau
        tableau[c][c].change_tableau_status();
        //next position
        ++pos;
    }
    print_game();
}

//print hand, foundations, and tableau to screen
void Game::print_game() {
    //print hand
    if (deck.empty()) {
        std::cout << "          ";
    }
    else if (drawn) {
        std::cout << deck[1] << " " << deck.front() << "    ";
    }
    else {
        std::cout << deck.front() << "       ";
    }
    //print foundations
    for (std::stack<Card>& pile : foundations) {
        std::cout << pile.top() << " ";
    }
    std::cout << "\n\n";
    std::cout << "1  2  3  4  5  6  7  \n";
    //print tableau
    unsigned row_num = 0;
    for (std::vector<Card> row : tableau) {
        //stops printing blank cards after whole row of blanks printed
        unsigned blanks = 0;
        for (Card c : row) {
            if (c.is_in_tableau()) {
                std::cout << c << " ";
            }
            else {
                std::cout << "   ";
                ++blanks;
            }
        }
        //at most 7 cards in row
        if (blanks == 7) {
            std::cout << "\n";
            break;
        }
        std::cout << " " << ++row_num;
        std::cout << "\n";
    }
}
