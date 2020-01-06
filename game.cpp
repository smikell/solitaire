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
    std::vector<Rank> ranks { Rank::Ace, Rank::Two, Rank::Three, Rank::Four, Rank::Five, Rank::Six,
        Rank::Seven, Rank::Eight, Rank::Nine, Rank::Ten, Rank::Jack, Rank::Queen, Rank::King };
    //load foundation placeholders
    size_t suit = 0;
    for (std::stack<Card>& pile : foundations) {
        pile.push(Card(suits[suit++], Rank::None));
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
    //for each column
    for (size_t c = 0; c < MAX_COLS; ++c) {
        //add proper number of cards
        for (size_t r = 0; r < c; ++r) {
            //add card
            tableau[r][c] = deck.front();
            //remove from deck
            deck.pop_front();
            //mark card as in tableau
            tableau[r][c].change_tableau_status();
        }
        //last card added
        tableau[c][c] = deck.front();
        //remove from deck
        deck.pop_front();
        //turn last card
        tableau[c][c].turn();
        //mark card as in tableau
        tableau[c][c].change_tableau_status();
    }
    print_game();
}

//print hand, foundations, and tableau to screen
void Game::print_game() const {
    std::cout << "\n";
    std::pair<time_t, time_t> time = get_current_time();
    std::cout << "Time: " << time.first << "m " << time.second << "s ";
    std::cout << "      ";
    std::cout << "Moves: " << get_num_moves();
    std::cout << "\n";
    //print hand
    if (deck.empty()) {
        std::cout << "E             ";
    }
    else if (drawn) {
        if (deck.size() == 1) std::cout << "E  ";
        else std::cout << "** ";
        std::cout << deck.front() << "        ";
    }
    else {
        std::cout << deck.front() << "          ";
    }
    //print foundations
    for (const std::stack<Card>& f : foundations) {
        std::cout << f.top() << "  ";
    }
    std::cout << "\n\n";
    std::cout << "1   2   3   4   5   6   7   \n";
    //print tableau
    unsigned row_num = 0;
    for (std::vector<Card> row : tableau) {
        //stops printing blank cards after whole row of blanks printed
        unsigned blanks = 0;
        for (const Card& c : row) {
            if (c.is_in_tableau()) {
                std::cout << c;
                if (c.get_rank() == Rank::Ten && c.is_turned()) {
                    std::cout << " ";
                }
                else {
                    std::cout << "  ";
                }
            }
            else {
                std::cout << "    ";
                ++blanks;
            }
        }
        //at most 7 cards in row
        if (blanks == MAX_COLS) {
            std::cout << "\n";
            break;
        }
        std::cout << " " << ++row_num;
        std::cout << "\n";
    }
    std::cout << "Score: " << get_score();
    std::cout << "\n";
}

//check if game ended
bool Game::is_game_over() const {
    return game_over;
}

//return completion status
bool Game::is_complete() const {
    return heart && spade && diamond && club;
}

//return current time
std::pair<time_t, time_t> Game::get_current_time() const {
    //get time difference
    time_t game_time = time(NULL) - start_time;
    //exit program if game has run for longer than 1 hour (3600 seconds)
    if (game_time >= TIME_LIMIT) {
        std::cerr << "\nGame has been running for over 1 hour, terminating program\n";
        exit(1);
    }
    //convert to minutes and seconds
    time_t minutes = game_time / 60;
    time_t seconds = game_time - (minutes * 60);
    return std::make_pair(minutes, seconds);
}

//return number of moves
unsigned Game::get_num_moves() const {
    return num_moves;
}

//return user score
unsigned Game::get_score() const {
    return score;
}

//update user score
void Game::update_score(bool add) {
    //adjust score
    if (!add) {
        //if removed card, decrease score
        score -= static_cast<unsigned>(REMOVE_SCORE);
    }
    else {
        //otherwise, added card, so increase score based on multipliers
        //score multiplier increase
        double move_decrease = MOVE_DECREASE * (get_num_moves() / MOVE_UPDATE);
        double move_multiplier = std::max(1.0, MOVE_MULTIPLIER - move_decrease);
        unsigned add_from_move = static_cast<unsigned>(static_cast<double>(ADD_SCORE) * (move_multiplier));
        //time multiplier increase
        std::pair<time_t, time_t> time = get_current_time();
        time_t total_seconds = (time.first * 60) + time.second;
        double time_decrease = TIME_DECREASE * (total_seconds / TIME_UPDATE);
        double time_multiplier = std::max(1.0, TIME_MULTIPLIER - time_decrease);
        unsigned add_from_time = static_cast<unsigned>(ceil(static_cast<double>(ADD_SCORE) * (time_multiplier)));
        //add to score
        score += add_from_move + add_from_time - static_cast<unsigned>(ADD_SCORE);
    }
    //update complete booleans
    heart = foundations[0].top().get_rank() == Rank::King;
    spade = foundations[1].top().get_rank() == Rank::King;
    diamond = foundations[2].top().get_rank() == Rank::King;
    club = foundations[3].top().get_rank() == Rank::King;
    //update game_over
    if (is_complete()) game_over = true;
}
