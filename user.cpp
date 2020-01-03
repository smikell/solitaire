//
//  user.cpp
//  solitaire
//
//  Created by Sam Mikell on 12/28/19.
//  Copyright © 2019 Sam Mikell. All rights reserved.
//

#include "user.h"

//default constructor
User::User() : Game() {
    game_starting();
}

//starting banner and introduction
void User::game_starting() {
    std::cout << "****************************************************\n";
    std::cout << "**       Solitaire for the Bored Programmer       **\n";
    std::cout << "****************************************************\n";
    std::cout << "**                                                **\n";
    std::cout << "**  Welcome to Solitaire!                         **\n";
    std::cout << "**  Tableau: main body of cards                   **\n";
    std::cout << "**  Foundations: piles of suits to add cards      **\n";
    std::cout << "**  Hand: top left area to draw remaining cards   **\n";
    std::cout << "**  Pile: top left face up cards drawn from hand  **\n";
    std::cout << "**                                                **\n";
    std::cout << "**  Information:                                  **\n";
    std::cout << "**  1. Tableau cards must alternate color         **\n";
    std::cout << "**  2. Tableau cards must descend in rank         **\n";
    std::cout << "**  3. Foundation cards must match suit           **\n";
    std::cout << "**  4. Foundation cards must ascend in rank       **\n";
    std::cout << "**  5. User input accepted after the % prompt     **\n";
    std::cout << "**  6. Letters may be lower or upper case         **\n";
    std::cout << "**  7. After valid move read, rest of line eaten  **\n";
    std::cout << "**  8. SUIT valid char, ROW <= 19, COL <= 7       **\n";
    std::cout << "**  9. Below are acceptable moves and formats     **\n";
    std::cout << "**                                                **\n";
    std::cout << "**  Input Format: <TO> <FROM>                     **\n";
    std::cout << "**                                                **\n";
    std::cout << "**  Draw card to Pile from Hand (implicit):       **\n";
    std::cout << "**  D                                             **\n";
    std::cout << "**                                                **\n";
    std::cout << "**  Move to Tableau from Tableau:                 **\n";
    std::cout << "**  T <ROW> <COL> T <ROW> <COL> ex. T 1 1 T 2 2   **\n";
    std::cout << "**                                                **\n";
    std::cout << "**  Move to Tableau from Hand:                    **\n";
    std::cout << "**  T <ROW> <COL> H ex. T 1 1 H                   **\n";
    std::cout << "**                                                **\n";
    std::cout << "**  Move to Tableau from Foundation:              **\n";
    std::cout << "**  T <ROW> <COL> F <SUIT> ex. T 1 1 F S          **\n";
    std::cout << "**                                                **\n";
    std::cout << "**  Note: The <TO> Tableau <ROW> and <COL> should **\n";
    std::cout << "**  be treated as the card you want to place the  **\n";
    std::cout << "**  <FROM> card on top of                         **\n";
    std::cout << "**  Example: T 1 1 T 2 2 attempts to place card   **\n";
    std::cout << "**  at [2][2] on top of the card at [1][1]        **\n";
    std::cout << "**                                                **\n";
    std::cout << "**  Move to Foundation from Tableau:              **\n";
    std::cout << "**  F <SUIT> T <ROW> <COL> ex. F S T 1 1          **\n";
    std::cout << "**                                                **\n";
    std::cout << "**  Move to Foundation from Hand:                 **\n";
    std::cout << "**  F <SUIT> H ex. F S H                          **\n";
    std::cout << "**                                                **\n";
    std::cout << "**  10. You may play to completion or enter 'q'   **\n";
    std::cout << "**  to quit the game if you get stuck             **\n";
    std::cout << "**                                                **\n";
    std::cout << "**  11. Enter '?' to reprint move options         **\n";
    std::cout << "**                                                **\n";
    std::cout << "****************************************************\n";
    std::cout << "**                     Enjoy!                     **\n";
    std::cout << "****************************************************\n\n\n";
    
    //retrieve name from user
    std::cout << "What is your name? % ";
    getline(std::cin, name);
    
    std::cout << "Welcome " << get_name() << "! game starting...\n\n";
}

//help message for move format
void User::help_message() {
    std::cout << "****************************************************\n";
    std::cout << "**                   Move Table                   **\n";
    std::cout << "****************************************************\n";
    std::cout << "**                                                **\n";
    std::cout << "**  Input Format: <TO> <FROM>                     **\n";
    std::cout << "**                                                **\n";
    std::cout << "**  Draw card to Pile from Hand (implicit):       **\n";
    std::cout << "**  D                                             **\n";
    std::cout << "**                                                **\n";
    std::cout << "**  Move to Tableau from Tableau:                 **\n";
    std::cout << "**  T <ROW> <COL> T <ROW> <COL> ex. T 1 1 T 2 2   **\n";
    std::cout << "**                                                **\n";
    std::cout << "**  Move to Tableau from Hand:                    **\n";
    std::cout << "**  T <ROW> <COL> H ex. T 1 1 H                   **\n";
    std::cout << "**                                                **\n";
    std::cout << "**  Move to Tableau from Foundation:              **\n";
    std::cout << "**  T <ROW> <COL> F <SUIT> ex. T 1 1 F S          **\n";
    std::cout << "**                                                **\n";
    std::cout << "**  Note: The <TO> Tableau <ROW> and <COL> should **\n";
    std::cout << "**  be treated as the card you want to place the  **\n";
    std::cout << "**  <FROM> card on top of                         **\n";
    std::cout << "**  Example: T 1 1 T 2 2 attempts to place card   **\n";
    std::cout << "**  at [2][2] on top of the card at [1][1]        **\n";
    std::cout << "**                                                **\n";
    std::cout << "**  Move to Foundation from Tableau:              **\n";
    std::cout << "**  F <SUIT> T <ROW> <COL> ex. F S T 1 1          **\n";
    std::cout << "**                                                **\n";
    std::cout << "**  Move to Foundation from Hand:                 **\n";
    std::cout << "**  F <SUIT> H ex. F S H                          **\n";
    std::cout << "**                                                **\n";
    std::cout << "****************************************************\n";
    std::cout << "**                 Patience is Key!               **\n";
    std::cout << "****************************************************\n\n\n";
    
    print_game();
}

//check if game ended
bool User::is_game_over() const {
    return game_over;
}

//return user name
std::string User::get_name() const {
    return name;
}

//set user score
void User::set_score() {
    //TODO: score adjustment according to timing
}

//return user score
unsigned User::get_score() const {
    return score;
}

//return completion status
bool User::is_complete() const {
    return heart && spade && diamond && club;
}

//print appropriate message and spaces
static void add_spaces(const unsigned length, const unsigned remaining) {
    for (unsigned i = 0; i < remaining - length; ++i) {
        std::cout << " ";
    }
}
void User::end_print(const std::string output) const {
    unsigned remaining;
    if (is_complete()) {
        std::cout << "**  Congratulations " << output << "!";
        remaining = 29;
    }
    else {
        std::cout << "**  Thanks for playing " << output << "!";
        remaining = 26;
    }
    add_spaces(static_cast<unsigned>(output.length()), remaining);
    std::cout << "**\n";
}
void User::end_print(const char type) const {
    unsigned remaining = 39;
    unsigned num = type == 'S' ? get_score() : get_num_moves();
    std::string stat = type == 'S' ? "Score: " : "Moves: ";
    std::cout << "**  " << stat << num;
    add_spaces(static_cast<unsigned>(std::to_string(num).length()), remaining);
    std::cout << "**\n";
}

//ending banner and message
void User::game_ending() const {
    std::cout << "****************************************************\n";
    std::cout << "**       Solitaire for the Bored Programmer       **\n";
    std::cout << "****************************************************\n";
    std::cout << "**                                                **\n";
    end_print(get_name());
    std::cout << "**                                                **\n";
    std::cout << "**  Game Ended with...                            **\n";
    end_print('S');
    end_print('M');
    std::cout << "**  Time: ?                                       **\n";
    std::cout << "**                                                **\n";
    std::cout << "****************************************************\n";
    std::cout << "**               github.com/smikell               **\n";
    std::cout << "****************************************************\n";
}

//check suit input validity
void User::check_suit(char input) const {
    if (SUIT_CHECK.find(input) == SUIT_CHECK.end()) {
        throw InvalidInput("Invalid Input, invalid suit");
    }
}

//check coords input validity
void User::check_coords(const size_t row, const size_t col) const {
    if (row > MAX_ROWS || col > MAX_COLS) {
        throw InvalidInput("Invalid Input, invalid coordinates (ROW or COL)");
    }
}

//draw card from hand
void User::draw() {
    //if no more cards to draw, throw error
    if (deck.empty()) {
        throw DrawError("Draw Error, no more cards to draw");
    }
    //if card already drawn
    if (drawn) {
        //turn over current card
        deck.front().turn();
        //move to back
        deck.push_back(deck.front());
        //remove from front
        deck.pop_front();
    }
    //flip front card
    deck.front().turn();
    //set drawn status
    drawn = true;
    ++num_moves;
    print_game();
}

//move card to foundation
void User::move_foundation(const char dest, const char move,
                           const std::pair<size_t, size_t> move_coords) {
    //TODO: Handle Dest errors in main
    //TODO: error check for proper suit, proper coordinates if passed (move is T)
    //TODO: error check for moves based on dest and source
    //TODO: error check: invalid move
        //if source is tableau, check if coordinates
    
    //move from tableau
    if (move == 'T') {
        //error check for proper coordinates (within bounds)
        //error check for proper coordinates (card is up && in)
        //error check for proper coordinates (next row down is not up && not in)
        //check move card is match suit for dest card
        
    }
    //move from hand
    else if (move == 'H'){
        
    }
    //otherwise invalid move input
    else {
        
    }
    
    //check move card is match suit for dest card
    //check move card is next rank for dest card
    //remove move card from old position
    //incrememnt num moves
    //update score
}

//move card to or within tableau
void User::move_tableau(const char dest, const std::pair<size_t, size_t> dest_coords,
                        const char move, const std::pair<size_t, size_t> move_coords) {
    //TODO: error checks
    
    
    //check move card is opposite suit for dest card
    //check move card is prev rank for dest card
    //remove card from old position
    //increment num moves
    //update score
}
