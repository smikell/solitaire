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

enum struct Suit {None, Heart, Spade, Diamond, Club, Empty};
enum struct Rank {None, Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Empty};

class Card {
public:
    //MODIFIES: suit and rank of constructed Card
    //EFFECTS: Default Ctor for Card object
    Card();
    
    //MODIFIED: suit and rank of constructed Card
    //EFFECTS: Custom Ctor for Card object, calls default, turns and/or sets tableau status
    //         depending on input suit and rank (foundation or empty placeholder)
    Card(Suit s, Rank r);
    
    //EFFECTS: returns Card object's suit
    Suit get_suit() const;
    
    //EFFECTS: returns Card object's rank
    Rank get_rank() const;
    
    //EFFECTS: returns true if Card is face up
    bool is_turned() const;
    
    //EFFECTS: returns true if Card is in tableau
    bool is_in_tableau() const;
    
    //EFFECTS: returns true if Card is a red suit
    bool is_red() const;
    
    //EFFECTS: returns true if Card is a black suit
    bool is_black() const;
    
    //MODIFIES: up member of Card
    //EFFECTS: changes faced up status to opposite
    void turn();
    
    //MODIFIES: in member of Card
    //EFFECTS: changes in tableau status to opposite
    void change_tableau_status();
    
    //EFFECTS: returns true if added Card's suit matches current Card's suit
    bool match_suit(const Card& added) const;
    
    //EFFECTS: returns true if added Card's suit is opposite of current Card's suit
    bool opposite_suit(const Card& added) const;
    
    //EFFECTS: returns true if added Card's rank is succeeding rank of current Card's rank
    bool next_rank(const Card& added) const;
    
    //EFFECTS: returns true if added Card's rank is preceding rank of current Card's rank
    bool prev_rank(const Card& added) const;

private:
    Suit suit;
    Rank rank;
    //card faced up
    bool up = false;
    //card in tableau
    bool in = false;
};

//EFFECTS: prints associated char for passed Suit
std::ostream& operator<<(std::ostream& out, const Suit& s);

//EFFECTS: prints associated char for passed Rank
std::ostream& operator<<(std::ostream& out, const Rank& r);

//EFFECTS: prints Card suit and rank chars if Card is face up or ** if not face up
std::ostream& operator<<(std::ostream& out, const Card& c);

#endif /* card_h */
