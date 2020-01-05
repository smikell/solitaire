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
    std::cout << "**  1. Tableau cards opposite color, descend rank **\n";
    std::cout << "**  2. Foundation cards match suit, ascend rank   **\n";
    std::cout << "**  3. E in Tableau or Hand means Empty           **\n";
    std::cout << "**  4. User input accepted after the % prompt     **\n";
    std::cout << "**  5. If press enter with incomplete arguments,  **\n";
    std::cout << "**     program waits for finish before executing  **\n";
    std::cout << "**  6. Letters may be lower or upper case         **\n";
    std::cout << "**  7. Input line after valid move is ignored     **\n";
    std::cout << "**  8. SUIT {HSDC}, 0 < COL <= 7, 0 < ROW <= 20    **\n";
    std::cout << "**  9. Below are acceptable moves and formats     **\n";
    std::cout << "**                                                **\n";
    std::cout << "**  Input Format: <TO> <FROM>                     **\n";
    std::cout << "**                                                **\n";
    std::cout << "**  Draw card to Pile from Hand (implicit):       **\n";
    std::cout << "**  D                                             **\n";
    std::cout << "**                                                **\n";
    std::cout << "**  Move to Tableau from Tableau:                 **\n";
    std::cout << "**  T <COL> <ROW> T <COL> <ROW> ex. T 1 1 T 2 2   **\n";
    std::cout << "**                                                **\n";
    std::cout << "**  Move to Tableau from Hand:                    **\n";
    std::cout << "**  T <COL> <ROW> H ex. T 1 1 H                   **\n";
    std::cout << "**                                                **\n";
    std::cout << "**  Move to Tableau from Foundation:              **\n";
    std::cout << "**  T <COL> <ROW> F <SUIT> ex. T 1 1 F S          **\n";
    std::cout << "**                                                **\n";
    std::cout << "**  Note: The <TO> Tableau <COL> and <ROW> should **\n";
    std::cout << "**  be treated as the card you want to place the  **\n";
    std::cout << "**  <FROM> card on top of                         **\n";
    std::cout << "**  Example: T 1 1 T 2 2 attempts to place card   **\n";
    std::cout << "**  at Column 2 Row 2 on top of the card at       **\n";
    std::cout << "**  Column 1 Row 1                                **\n";
    std::cout << "**                                                **\n";
    std::cout << "**  Move to Foundation from Tableau:              **\n";
    std::cout << "**  F <SUIT> T <COL> <ROW> ex. F S T 1 1          **\n";
    std::cout << "**                                                **\n";
    std::cout << "**  Move to Foundation from Hand:                 **\n";
    std::cout << "**  F <SUIT> H ex. F S H                          **\n";
    std::cout << "**                                                **\n";
    std::cout << "**  10. Enter '?' to reprint move options         **\n";
    std::cout << "**                                                **\n";
    std::cout << "**  11. Score multiplier information:             **\n";
    std::cout << "**                                                **\n";
    std::cout << "**  Each card added to foundation is 10 pts       **\n";
    std::cout << "**  Each card removed from foundation is -15 pts  **\n";
    std::cout << "**  Move and Time independent multiplers are x1.5 **\n";
    std::cout << "**  Every 25 moves and 90 seconds, respective     **\n";
    std::cout << "**      multiplier decreases by 0.1 until x1      **\n";
    std::cout << "**                                                **\n";
    std::cout << "**  12. You may play to completion or enter 'q'   **\n";
    std::cout << "**      to quit the game if you get stuck         **\n";
    std::cout << "**                                                **\n";
    std::cout << "**  13. Game will automatically end after 1 hour  **\n";
    std::cout << "**                                                **\n";
    std::cout << "****************************************************\n";
    std::cout << "**                     Enjoy!                     **\n";
    std::cout << "****************************************************\n\n";
    
    //retrieve name from user
    std::cout << "What is your name? % ";
    getline(std::cin, name);
    
    std::cout << "Welcome " << get_name() << "! game starting...\n";
    
    //TODO: SAVE STARTING TIME
}

//help message for move format
void User::help_message() {
    std::cout << "\n";
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
    std::cout << "**                Patience is Key!                **\n";
    std::cout << "****************************************************\n";
    
    print_game();
}

//return user name
std::string User::get_name() const {
    return name;
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
    std::cout << "\n";
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
    std::cout << "**          github.com/smikell/solitaire          **\n";
    std::cout << "****************************************************\n";
}

//check suit input validity
void User::check_suit(char input) const {
    if (SUIT_CHECK.find(toupper(input)) == SUIT_CHECK.end()) {
        //eat remaining line
        std::string junk;
        getline(std::cin, junk);
        //throw error
        throw InvalidInput("Invalid Input, invalid suit");
    }
}

//check coords input validity
void User::check_coords(size_t& row, size_t& col) const {
    if (row > MAX_ROWS || col > MAX_COLS || row == 0 || col == 0) {
        //eat remaining line
        std::string junk;
        getline(std::cin, junk);
        //throw error
        throw InvalidInput("Invalid Input, invalid coordinates (ROW or COL)");
    }
    //otherwise, if coords are valid, convert each to 0-based index
    row -= 1;
    col -= 1;
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
    std::cout << "\nSuccessful Move: Card drawn from hand\n";
    print_game();
}

//checks move for validity and calls appropriate move
void User::move(UserInput input) {
    //all input valid at this point since checked in main
    //branches will determine which valid move combination is called
    if (toupper(input.to) == 'F') {
        //suit index to add card to in foundations
        size_t dest_suit = toupper(input.to_suit) == 'H' ? 0 :
                           toupper(input.to_suit) == 'S' ? 1 :
                           toupper(input.to_suit) == 'D' ? 2 :
                           toupper(input.to_suit) == 'C' ? 3 : std::numeric_limits<size_t>::infinity();
        if (toupper(input.from) == 'H') {
            move_to_foundation_from_hand(dest_suit);
        }
        else if (toupper(input.from) == 'T') {
            move_to_foundation_from_tableau(dest_suit, std::make_pair(input.from_row, input.from_col));
        }
        else {
            throw FoundationError("Invalid Move, cannot move from one foundation to another");
        }
        update_score();
    }
    else if (toupper(input.to) == 'T') {
        //coordinates to add card to in tableau
        std::pair<size_t, size_t> dest_coords = std::make_pair(input.to_row, input.to_col);
        if (toupper(input.from) == 'H') {
            move_to_tableau_from_hand(dest_coords);
        }
        else if (toupper(input.from) == 'F') {
            size_t source_suit = toupper(input.from_suit) == 'H' ? 0 :
                                 toupper(input.from_suit) == 'S' ? 1 :
                                 toupper(input.from_suit) == 'D' ? 2 :
                                 toupper(input.from_suit) == 'C' ? 3 : std::numeric_limits<size_t>::infinity();
            move_to_tableau_from_foundation(dest_coords, source_suit);
        }
        else if (toupper(input.from) == 'T') {
            move_to_tableau_from_tableau(dest_coords, std::make_pair(input.from_row, input.from_col));
        }
    }
    //game updates
    ++num_moves;
    print_game();
}

void User::move_to_foundation_from_hand(const size_t dest) {
    //if no card drawn or deck is empty, throw error
    if (!drawn || deck.empty()) {
        throw FoundationError("Foundation, no card to move from Hand");
    }
    //if card from deck does not match foundation suit, throw error
    if (!foundations[dest].top().match_suit(deck.front())) {
        throw FoundationError("Foundation, card from Hand does not match suit");
    }
    //if card from deck is not next rank for foundation, throw error
    if (!foundations[dest].top().next_rank(deck.front())) {
        throw FoundationError("Foundation, card from Hand is not next rank");
    }
    //add card to foundation
    foundations[dest].push(deck.front());
    //remove card from deck
    deck.pop_front();
    //now no card is drawn
    drawn = false;
    //print success
    std::cout << "\nSuccessful Move: Card added to Foundation from Hand\n";
}

void User::move_to_foundation_from_tableau(const size_t dest, const std::pair<size_t, size_t> source) {
    //if card not in tableau, throw error
    if (!tableau[source.first][source.second].is_in_tableau()) {
        throw FoundationError("Foundation, card not in Tableau");
    }
    //if card not faced up, throw error
    if (!tableau[source.first][source.second].is_turned()) {
        throw FoundationError("Foundation, card not faced up in Tableau");
    }
    //if card has cards below it in col (card one row down is in tableau), throw error
    if (tableau[source.first + 1][source.second].is_in_tableau()) {
        throw FoundationError("Foundation, cannot move card from Tableau if cards below");
    }
    //if card from tableau does not match foundation suit, throw error
    if (!foundations[dest].top().match_suit(tableau[source.first][source.second])) {
        throw FoundationError("Foundation, card from Tableau does not match suit");
    }
    //if card from tableau is not next rank for foundation, throw error
    if (!foundations[dest].top().next_rank(tableau[source.first][source.second])) {
        throw FoundationError("Foundation, card from Tableau is not next rank");
    }
    //remove card tableau in status, add card to foundation
    tableau[source.first][source.second].change_tableau_status();
    foundations[dest].push(tableau[source.first][source.second]);
    //remove card from tableau
    if (source.first == 0) {
        //if card from row 0 removed, replace with empty placeholder
        tableau[source.first][source.second] = Card(Suit::Empty, Rank::Empty);
    }
    else {
        //otherwise, replace card with default
        tableau[source.first][source.second] = Card();
        //turn previous card in column if not turned already
        if (!tableau[source.first - 1][source.second].is_turned()) {
            tableau[source.first - 1][source.second].turn();
        }
    }
    //print success
    std::cout << "\nSuccessful Move: Card added to Foundation from Tableau\n";
}

void User::move_to_tableau_from_hand(const std::pair<size_t, size_t> dest) {
    //if destination card not in tableau, throw error
    if (!tableau[dest.first][dest.second].is_in_tableau()) {
        throw TableauError("Tableau, destination card not in Tableau");
    }
    //if destination card not faced up, throw error
    if (!tableau[dest.first][dest.second].is_turned()) {
        throw TableauError("Tableau, destination card not faced up in Tableau");
    }
    //if destination card not last in row (card one row down is in tableau), throw error
    if (tableau[dest.first + 1][dest.second].is_in_tableau()) {
        throw TableauError("Tableau, destination card not last in row");
    }
    //if no card drawn or deck is empty, throw error
    if (!drawn || deck.empty()) {
        throw TableauError("Tableau, no card to move from Hand");
    }
    //if card from deck is not opposite suit as destination in tableau, throw error
    if (!tableau[dest.first][dest.second].opposite_suit(deck.front())) {
        throw TableauError("Tableau, card from Hand is not opposite suit color");
    }
    //if card from deck is not prev rank from destination in tableau, throw error
    if (!tableau[dest.first][dest.second].prev_rank(deck.front())) {
        throw TableauError("Tableau, card from Hand is not previous rank");
    }
    //add card to tableau, already turned since shown in hand
    if (deck.front().get_rank() == Rank::King) {
        //if adding king to tableau, replace at coordinates since empty is there
        tableau[dest.first][dest.second] = deck.front();
        tableau[dest.first][dest.second].change_tableau_status();
    }
    else {
        //otherwise, adding other card to row below destination
        tableau[dest.first + 1][dest.second] = deck.front();
        tableau[dest.first + 1][dest.second].change_tableau_status();
    }
    //remove card from deck
    deck.pop_front();
    //now no card is drawn
    drawn = false;
    //print success
    std::cout << "\nSuccessful Move: Card added to Tableau from Hand\n";
}

void User::move_to_tableau_from_foundation(const std::pair<size_t, size_t> dest, const size_t source) {
    //if destination card not in tableau, throw error
    if (!tableau[dest.first][dest.second].is_in_tableau()) {
        throw TableauError("Tableau, destination card not in Tableau");
    }
    //if destination card not faced up, throw error
    if (!tableau[dest.first][dest.second].is_turned()) {
        throw TableauError("Tableau, destination card not faced up in Tableau");
    }
    //if destination card not last in row (card one row down is in tableau), throw error
    if (tableau[dest.first + 1][dest.second].is_in_tableau()) {
        throw TableauError("Tableau, destination card not last in row");
    }
    //if source foundation is rank none, then placeholder, throw error
    if (foundations[source].top().get_rank() == Rank::None) {
        throw TableauError("Tableau, no card to move from Foundation");
    }
    //if card from foundation is not opposite suit as destination in tableau, throw error
    if (!tableau[dest.first][dest.second].opposite_suit(foundations[source].top())) {
        throw TableauError("Tableau, card from Foundation is not opposite suit color");
    }
    //if card from foundation is not prev rank from destination in tableau, throw error
    if (!tableau[dest.first][dest.second].prev_rank(foundations[source].top())) {
        throw TableauError("Tableau, card from Foundation is not previous rank");
    }
    //add card to tableau, already turned since shown in foundation
    if (foundations[source].top().get_rank() == Rank::King) {
        //if adding king to tableau, replace at coordinates since empty is there
        tableau[dest.first][dest.second] = foundations[source].top();
        tableau[dest.first][dest.second].change_tableau_status();
    }
    else {
        //otherwise, adding other card to row below destination
        tableau[dest.first + 1][dest.second] = foundations[source].top();
        tableau[dest.first + 1][dest.second].change_tableau_status();
    }
    //remove card from foundation
    foundations[source].pop();
    //print success
    std::cout << "\nSuccessful Move: Card added to Tableau from Foundation\n";
}

void User::move_to_tableau_from_tableau(const std::pair<size_t, size_t> dest,
                                        const std::pair<size_t, size_t> source) {
    //if destination card not in tableau, throw error
    if (!tableau[dest.first][dest.second].is_in_tableau()) {
        throw TableauError("Tableau, destination card not in Tableau");
    }
    //if destination card not faced up, throw error
    if (!tableau[dest.first][dest.second].is_turned()) {
        throw TableauError("Tableau, destination card not faced up in Tableau");
    }
    //if destination card not last in row (card one row down is in tableau), throw error
    if (tableau[dest.first + 1][dest.second].is_in_tableau()) {
        throw TableauError("Tableau, destination card not last in row");
    }
    //if source card not in tableau, throw error
    if (!tableau[source.first][source.second].is_in_tableau()) {
        throw TableauError("Tableau, source card not in Tableau");
    }
    //if source card not faced up, throw error
    if (!tableau[source.first][source.second].is_turned()) {
        throw TableauError("Tableau, source card not faced up in Tableau");
    }
    //if destination and source are same, throw error
    if (dest == source) {
        throw TableauError("Tableau, destination and source cards are same");
    }
    //if card from tableau is not opposite suit as destination in tableau, throw error
    if (!tableau[dest.first][dest.second].opposite_suit(tableau[source.first][source.second])) {
        throw TableauError("Tableau, card from Tableau is not opposite suit color");
    }
    //if card from tableau is not prev rank from destination in tableau, throw error
    if (!tableau[dest.first][dest.second].prev_rank(tableau[source.first][source.second])) {
        throw TableauError("Tableau, card from Tableau is not previous rank");
    }
    //variables to be used in loops for add/remove
    size_t dest_row = tableau[dest.first][dest.second].get_rank() == Rank::Empty ? dest.first : dest.first + 1;
    size_t dest_col = dest.second;
    size_t source_row = source.first;
    size_t source_col = source.second;
    //while source card is in tableau
    while (tableau[source_row][source_col].is_in_tableau()) {
        //add source to dest
        tableau[dest_row++][dest_col] = tableau[source_row][source_col];
        //remove from source
        tableau[source_row++][source_col] = Card();
        //cards remain faced up and in tableau
    }
    //handle previous card in source col
    if (source.first == 0) {
        //if card from row 0 removed, replace with empty placeholder
        tableau[source.first][source.second] = Card(Suit::Empty, Rank::Empty);
    }
    else {
        //turn previous card in column if not turned already
        if (!tableau[source.first - 1][source.second].is_turned()) {
            tableau[source.first - 1][source.second].turn();
        }
    }
    //print success
    std::cout << "\nSuccessful Move: Card added to Tableau from Tableau\n";
}
